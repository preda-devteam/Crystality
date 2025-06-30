#include "EVMShard.h"
#include "EVMSimulator.h"
#include "EVMHost.h"
#include "EVMScriptRunner.h"
#include "ed25519/ed25519.h"

#ifdef _WIN32
#include <windows.h>
#endif


#ifdef TIMER
extern uint64_t instr_count;
#endif

namespace sol
{
	void RelayEmission::Collect(EVMTxn* txn)
	{
		_RelayTxns.push_back(txn);
	}

	void RelayEmission::Dispatch()
	{
		while (!_RelayTxns.empty())
		{
			EVMTxn* txn = _RelayTxns.front();
			evmc::address relayDest(txn->msg.destination);
			{
				// make sender and receiver right for new relay txn
				txn->msg.destination = txn->msg.sender;
			}
			if (evmc::address(888) == relayDest)
			{
				_Simulator->PushTxn2Global(txn);
			}
			else if (evmc::address(666) == relayDest)
			{
				evmc::address sender;
				std::copy(txn->msg.input_data + 16, txn->msg.input_data + 36, sender.bytes);
				txn->msg.sender = sender;
				_Simulator->PushTxn2Address(txn);
			}
			else if (evmc::address(32) == relayDest)
			{
				_Simulator->PushTxn2Uint32Scope(txn);
			}
			else 
			{
				_Simulator->PushTxn2Shard(txn, relayDest);
			}
			_RelayTxns.pop_front();
		}
	}

	void EVMShard::_BlockProcessRoutineInstance()
	{
#if defined(__linux__) 
        if(!IsGlobal())
        {
		    struct sched_param param;
            param.sched_priority = 99; // Setting priority.

    	    // set the scheduling parameters
    	    pthread_setschedparam(pthread_self(), SCHED_FIFO, &param);

		    cpu_set_t cpuset;
		    pthread_t thread = pthread_self();
		    int core = this->_ShardId;
		    CPU_ZERO(&cpuset);
		    CPU_SET(core, &cpuset);
		    int ret = pthread_setaffinity_np(thread, sizeof(cpuset), &cpuset);
			if (ret != 0) {
   	         	printf("pthread_setaffinity returned %d\n", ret);
    	    }
        }
#elif _WIN32
		if(!IsGlobal())
		{
			HANDLE currentThread = GetCurrentThread();

			if (!SetThreadPriority(currentThread, THREAD_PRIORITY_TIME_CRITICAL)) {
				DWORD dwErr = GetLastError();
				std::cerr << "SetThreadPriority failed, GLE=" << dwErr << std::endl;
			}

			DWORD_PTR mask = (static_cast<DWORD_PTR>(1) << _ShardId);
			DWORD_PTR returnMask = SetThreadAffinityMask(currentThread, mask);
			if (0 == returnMask) {
				DWORD dwErr = GetLastError();
				std::cerr << "SetThreadAffinityMask failed, GLE=" << dwErr << std::endl;
			}
		}
#endif
#ifdef TIMER
        while(!_Stop)
		{
			InTimer timer;
			timer.ReStart();
			std::unique_lock<std::mutex> lck(_Mtx);
			while (!_Ready) {
				_GoNextBlock.wait(lck);
			}
			timer.Stop();
			_WaitTime += timer.Duration();
			_Ready = false;
			_TotalGasBurnt = 0;

			while (_TotalGasBurnt < _Simulator->GetGasLimit())
			{
                timer.ReStart();
			    _PendingTxnMutex.lock();
				if (_PendingTxns.empty()) {
					_PendingTxnMutex.unlock();
					break;
				}
				EVMTxn* txn = _PendingTxns.front();
				_PendingTxns.pop_front();
				_PendingTxnMutex.unlock();
                timer.Stop();

                timer.ReStart();
#ifdef VERIFY_SIG
				if (!txn->is_relay){
					if(!ed25519_verify(&(txn->sig[0]), (const uint8_t*)&txn->msg, sizeof(evmc_message), &(txn->pk[0]))){
						std::cout << "verify sig err" << std::endl;
				 		continue;
					}
				} 
#endif
				evmc::result ret = _Engine.Run(*_Host, txn->msg);
				++_TotalGasBurnt;
				timer.Stop();
				_RunTime += timer.Duration();
                _TxnPool.ReleaseTxn(txn);
			}
			_Txns += _TotalGasBurnt;
            ++_BlockHeight;

			_RelayEmit.Dispatch();
			if (IsGlobal())
			{
				for (uint32_t i = 0; i < _Simulator->GetShardCount(); ++i)
					_Simulator->GetShard(i)->Step();
			}
			else
			{
				_Simulator->SetOneNormalFinished();
			}
		}
#else
while(!_Stop)
		{
			std::unique_lock<std::mutex> lck(_Mtx);
			while (!_Ready) {
				_GoNextBlock.wait(lck);
			}
			_Ready = false;
			_TotalGasBurnt = 0;
			std::vector<EVMTxn*> executed_txns;
			while (_TotalGasBurnt < _Simulator->GetGasLimit())
			{
			    _PendingTxnMutex.lock();
				if (_PendingTxns.empty()) {
					_PendingTxnMutex.unlock();
					break;
				}
				EVMTxn* txn = _PendingTxns.front();
				_PendingTxns.pop_front();
				_PendingTxnMutex.unlock();
#ifdef VERIFY_SIG
				if (!txn->is_relay){
					if(!ed25519_verify(&(txn->sig[0]), (const uint8_t*)&txn->msg, sizeof(evmc_message), &(txn->pk[0]))){
						std::cout << "verify sig err" << std::endl;
				 		continue;
					}
				} 
#endif

				evmc::result ret = _Engine.Run(*_Host, txn->msg);

				if(ret.status_code == EVMC_SUCCESS)
					executed_txns.push_back(txn);
				if (!txn->is_relay)
					++_Txns;
				
                _TxnPool.ReleaseTxn(txn);
				++_TotalGasBurnt;
			}
            ++_BlockHeight;

			_RelayEmit.Dispatch();
			if (IsGlobal())
			{
				for (uint32_t i = 0; i < _Simulator->GetShardCount(); ++i)
					_Simulator->GetShard(i)->Step();
			}
			else
			{
				_Simulator->SetOneNormalFinished();
			}
		}
#endif // TIMER
	}

	EVMShard::EVMShard(EVMSimulator* _simulator, EVMGlobalShard* _globalShard, uint32_t _shardId)
		: _Host(new EVMHost),
		_Simulator(_simulator),
		_Engine(),
		_PendingTxnMutex(),
		_PendingTxns(),
		_RelayEmit(),
		_TotalGasBurnt(0),
		_Ready(false),
		_Mtx(),
		_GoNextBlock(),
		_ShardId(_shardId),
		_GlobalShard(_globalShard)
	{}
	EVMShard::EVMShard(EVMSimulator* _simulator)
	:   _Host(new EVMHost),
		_Simulator(_simulator), 
		_GlobalShard(nullptr)
	{}

	EVMShard:: ~EVMShard() 
	{
        Terminate();
        delete _Host;
    }

	void EVMShard::Init()
	{
		_TotalGasBurnt = 0;
		_Stop = false;
		_BlockHeight = 0;
		_Txns = 0;
		_Host->SetShard(this);
		_Host->SetGlobalHost(_GlobalShard == nullptr ? nullptr : _GlobalShard->GetHost());
		_RelayEmit.SetSimulator(_Simulator);
#ifdef _WIN32
		_BlockHandler = std::thread(&EVMShard::_BlockProcessRoutine, this);
#endif
#if defined(__linux__) | defined(__APPLE__)
		pthread_create(&_Thread, nullptr, EVMShard::_BlockProcessRoutine, this);
#endif
	}

    void EVMShard::InitCount()
    {
        _BlockHeight = 0; 
        _Txns = 0;
#ifdef TIMER
        total_cost = 0; 
        max_cost = 0;
        _DispatchTime = 0;
        _WaitTime = 0;
        _RunTime = 0;
		_RelayTime = 0;
		_Blocks = 0;
		_BlockSchedule.resize(1000);
		_Analyze = 0;
		_Execute = 0;
		intra_relay_cnt = 0;
		cross_relay_cnt = 0;
#endif
    }

	evmc::result EVMShard::Deploy(const std::vector<uint8_t>& code, uint64_t address, std::vector<uint8_t>& input_data)
	{
		return _Engine.Deploy(*_Host, code, address, input_data);
	}

	void EVMShard::Step()
	{
		std::unique_lock<std::mutex> lck(_Mtx);
		_Ready = true;
		_GoNextBlock.notify_one();
	}

	void EVMShard::Terminate()
	{
		_Stop = true;
		Step();
#ifdef _WIN32
		if (_BlockHandler.joinable()) _BlockHandler.join();
#endif 
#if defined(__linux__) | defined(__APPLE__)
		pthread_join(_Thread, nullptr);
#endif
	}

	void EVMShard::Info()
	{
		if(IsGlobal())
			printf("Shard#G: address: %ld txns: %ld\n", _Host->m_accounts[evmc::address(0)].storage.size(), _PendingTxns.size());
		else
			printf("Shard#%d: address: %ld txns: %ld\n", _ShardId, _Host->m_accounts[evmc::address(0)].storage.size(),  _PendingTxns.size());

	}

	void EVMShard::RuntimeInfo()
	{
#ifdef TIMER
		// if(IsGlobal() && _Txns)
		// 	printf("\033[1;31mShard#  G: transactions:%7ld\tintra:%7ld\tcross:%7ld\tTotal:%7.2lf(s)\tavg_txn:%7.3lf(ms)\tmax_txn: %7.2lf(ms)\t"  
		// 	"evm-execute:%7.2lf(s)\tAnalyze:%7.3lf(s)\tExecute:%7.3lf(s)\n\033[0m", 
		// 	_Txns, intra_relay_cnt, cross_relay_cnt, _RunTime * 1e-6, total_cost / _Txns * 1e-3, max_cost * 1e-3,
		// 	total_cost * 1e-6, _Analyze * 1e-6, _Execute * 1e-6);
		// else if(_Txns)
		// 	printf("\033[1;33mShard#%3d: transactions:%7ld\tintra:%7ld\tcross:%7ld\tTotal:%7.2lf(s)\tavg_txn:%7.3lf(ms)\tmax_txn: %7.2lf(ms)\t"
		// 	"evm-execute:%7.2lf(s)\tAnalyze:%7.3lf(s)\tExecute:%7.3lf(s)\n\033[0m", 
		// 	_ShardId, _Txns, intra_relay_cnt, cross_relay_cnt, _RunTime * 1e-6, total_cost / _Txns * 1e-3, max_cost * 1e-3,
		// 	total_cost * 1e-6, _Analyze * 1e-6, _Execute * 1e-6);
		if(IsGlobal() && _Txns)
			printf("\033[1;31mShard#  G: transactions:%7ld\tintra:%7ld\tcross:%7ld\tTotal:%7.2lf(milis)\tavg_txn:%7.3lf(micros)\033[0m", 
			_Txns, intra_relay_cnt, cross_relay_cnt, _RunTime * 1e-3, (double)_RunTime / _Txns);
		else if(_Txns)
			printf("\033[1;33mShard#%3d: transactions:%7ld\tintra:%7ld\tcross:%7ld\tTotal:%7.2lf(milis)\tavg_txn:%7.3lf(micros)\n\033[0m", 
			_ShardId, _Txns, intra_relay_cnt, cross_relay_cnt, _RunTime * 1e-3, (double)_RunTime / _Txns);
#endif
	}

	void EVMShard::GatherRuntimeInfo()
	{
#ifdef TIMER
		if(IsGlobal())
		{
			uint64_t total_txns = 0, total_intra_relays = 0, total_cross_relays = 0, total_time = 0;
			for(size_t i = 0; i < _Simulator->GetShardCount(); ++i)
			{
				total_txns += _Simulator->GetShard(i)->_Txns;
				total_intra_relays += _Simulator->GetShard(i)->intra_relay_cnt;
				total_cross_relays += _Simulator->GetShard(i)->cross_relay_cnt;
				total_time += _Simulator->GetShard(i)->_RunTime;
			}
			printf("\033[1;34mtotal_txns:%7ld\tintra_relays:%7ld\tcross_relays:%7ld\texecute_avg_time:%7.3lf(us)\t\n\033[0m", total_txns, total_intra_relays, total_cross_relays, (double)total_time / total_txns);
			//printf("\033[1;32mavg_byteCodes_in_execution:%7ld\t\n\033[0m", instr_count / total_txns);
		}
#endif
	}

	evmc::result EVMShard::Execute(const evmc_message& msg)
	{
		return _Engine.Run(*_Host, msg);
	}

	void EVMShard::FinalizeTxn(EVMTxn* txn)
	{
		// if(txn->msg.input_size < 4)
		// 	return;
		// char buffer[3];
		// std::string opcode;
		// for(size_t i = 0; i < 4; ++i) {
		// 	snprintf(buffer, 3, "%02x", static_cast<unsigned int>(txn->msg.input_data[i]));
		// 	opcode += std::string(buffer);
		// }
		// std::pair<std::string, std::string> contract_function;
		// if(!_Simulator->GetContractFunction(opcode, contract_function))
		// 	return;
		// txn->contract_name = contract_function.first;
		// txn->function_name = contract_function.second;
		// txn->shard_index = IsGlobal() ? GLOBAL_SHARD_INDEX : _ShardId;
		// txn->block_height = _BlockHeight;
	}

	void EVMShard::PushTxn(EVMTxn* txn)
	{
		_PendingTxnMutex.lock();
		_PendingTxns.push_back(txn);
		_PendingTxnMutex.unlock();
	}

    EVMTxn* EVMShard::AddTask(const evmc_address& sender, const evmc_address& receiver, const std::vector<uint8_t>& ByteCodeMsg) 
    {
        EVMTxn* txn = _TxnPool.GetTxn();
        txn->Convert2Txn(sender, receiver, ByteCodeMsg);
        PushTxn(txn);
		return txn;
    }

	void EVMShard::AddTask(const evmc_address& receiver, const std::vector<uint8_t>& ByteCodeMsg)
	{
		EVMTxn* txn = _TxnPool.GetTxn();
		evmc::address sender(0);
		txn->Convert2Txn(sender, receiver, ByteCodeMsg);
		PushTxn(txn);
	}

	void EVMShard::Relay(const evmc_message& msg)
	{
		if (evmc::address(777) == evmc::address(msg.destination)) {
			for (uint32_t i = 0; i < _Simulator->GetShardCount(); ++i) {
				EVMTxn* txn = _TxnPool.GetTxn();
				txn->is_relay = true;
				txn->CopyAsRelayTxn(msg);
				txn->msg.destination = evmc::address(i);
				_RelayEmit.Collect(txn);
			}
		}
		else {
			EVMTxn* txn = _TxnPool.GetTxn();
			txn->is_relay = true;
			txn->CopyAsRelayTxn(msg);
			_RelayEmit.Collect(txn);
#ifdef TIMER
			if(IsGlobal()) return;
			if(CurrentShard(msg)) ++intra_relay_cnt;
			else ++cross_relay_cnt;
#endif
		}
	}

	bool EVMShard::CurrentShard(const evmc_message& msg)
	{
		uint16_t relayShard;
		relayShard = (evmc::load32be(msg.input_data + 4 + 28) % _Simulator->GetShardCount());
		return (_ShardId == relayShard);
	}

	uint8_t* EVMShard::GetShardOrder() 
	{ 
		return _Simulator->GetShardOrder(); 
	}

	EVMGlobalShard::EVMGlobalShard(EVMSimulator* _simulator)
	: EVMShard(_simulator)
	{

	}
}
