#pragma once
#include <evmc/evmc.h>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <list>
#include "EVMExecutionEngine.h"
#include "EVMScriptRunner.h"
#include "EVMSimulator.h"

#if defined(__linux__) | defined(__APPLE__)
#include <pthread.h>
#include <sched.h>
#endif

namespace sol
{
	class EVMGlobalShard;
	class EVMHost;

	class RelayEmission {
	private:
		std::list<EVMTxn*> 	_RelayTxns;
		EVMSimulator* 		_Simulator;
		EVMTxn* 			_OrignTxn;
		
	public:
		void Collect(EVMTxn* txn);
		void Dispatch();
		void SetSimulator(EVMSimulator* simulator) { _Simulator = simulator; }
		void SetCurrentOrignTxn(EVMTxn* txn) { _OrignTxn = txn; }
	};

	class EVMShard
	{

    friend class EVMSimulator;

	protected:
		EVMHost* _Host;
		EVMSimulator* _Simulator;
		EVMExecutionEngine _Engine;
        EVMTxnPool _TxnPool;
		std::mutex _PendingTxnMutex;
		std::list<EVMTxn*> _PendingTxns;
		RelayEmission _RelayEmit;
		uint64_t _TotalGasBurnt;
		uint64_t _BlockHeight = 0;
		uint64_t _Txns = 0;

#ifdef TIMER
    public:
        uint64_t total_cost = 0;
        uint64_t max_cost = 0;
        uint64_t _DispatchTime = 0;
        uint64_t _WaitTime = 0;
        uint64_t _RunTime = 0;
		uint64_t _RelayTime = 0;
		uint64_t _Blocks = 0;
		std::vector<std::pair<uint64_t, uint32_t>> _BlockSchedule;
		uint64_t _Analyze = 0;
		uint64_t _Execute = 0;
		uint64_t intra_relay_cnt = 0;
		uint64_t cross_relay_cnt = 0;
#endif

	protected:
		bool _Ready;
		std::mutex _Mtx;
		std::condition_variable _GoNextBlock;
#ifdef _WIN32
		std::thread _BlockHandler;
#endif
#if defined(__linux__) | defined(__APPLE__)
		pthread_t _Thread;
#endif

		static void* _BlockProcessRoutine(void* arg){
			EVMShard* self = static_cast<EVMShard*>(arg);
			self->_BlockProcessRoutineInstance();
			return nullptr;
		}
		
		void _BlockProcessRoutineInstance();
		bool _Stop;

	private:
		uint32_t _ShardId;
		EVMGlobalShard* _GlobalShard;

	public:
		EVMShard(EVMSimulator* _simulator, EVMGlobalShard* _globalShard, uint32_t _ShardId);
		EVMShard(EVMSimulator* _simulator);
		~EVMShard();  
		void Init();
        void InitCount();
		evmc::result Deploy(const std::vector<uint8_t>& code, uint64_t address, std::vector<uint8_t>& input_data);
		void Step();
		void Terminate();
		void PushTxn(EVMTxn* txn);
        EVMTxn* AddTask(const evmc_address& sender, const evmc_address& receiver, const std::vector<uint8_t>& ByteCodeMsg);
		void AddTask(const evmc_address& receiver, const std::vector<uint8_t>& ByteCodeMsg);
		void Relay(const evmc_message& msg);
		void Info();
		void RuntimeInfo();
		void GatherRuntimeInfo();
		evmc::result Execute(const evmc_message& msg);
		void FinalizeTxn(EVMTxn* txn);

		EVMHost* GetHost() { return _Host; }
		uint32_t GetTxnSize() { return _PendingTxns.size(); }
		bool CurrentShard(const evmc_message& msg);
		uint8_t* GetShardOrder();
		bool IsGlobal() { return _GlobalShard == nullptr; }
		uint32_t GetShardId() {return _ShardId;}
		uint64_t GetTxns() {return _Txns;}
		EVMSimulator* GetSimulator() { return _Simulator;}
	};

	class EVMGlobalShard : public EVMShard
	{
	public:
		EVMGlobalShard(EVMSimulator* _simulator);
	};

}
