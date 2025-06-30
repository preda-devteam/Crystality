#pragma once
#include <vector>
#include <string>
#include <list>
#include <mutex>
#include <atomic>
#include <condition_variable>
#include "EVMExecutionEngine.h"
#include "EVMScriptRunner.h"
#include "EVMEncoder.h"

#define GAS_LIMIT 2000000000000
#define MAX_TXNS_PER_BLOCK 10000
#define GLOBAL_SHARD_INDEX UINT32_MAX
// #define TIMER
#define VERIFY_SIG

namespace sol
{
	class EVMShard;
	class EVMGlobalShard;

	struct EVMTxn
	{
		evmc_message 	msg;
		bool			is_relay = false;
		// std::string 	contract_name = "";
		// std::string 	function_name = "";
		// uint32_t 		shard_index = 0;
		// uint32_t 		block_height = 0;
		// EVMTxn*			orign_txn = nullptr;
#ifdef VERIFY_SIG
		uint8_t 		pk[32];
		uint8_t 		sig[64];
#endif
		EVMTxn() :msg() 
		{memset(&msg, 0, sizeof(evmc_message));}

		void CopyAsRelayTxn(const evmc_message& _msg)
		{
            uint8_t* input_data = nullptr;
			if (msg.input_size < _msg.input_size)
			{
				if(msg.input_data) delete[] const_cast<uint8_t*>(msg.input_data);
                input_data = new uint8_t[_msg.input_size];
			}
            else
                input_data = const_cast<uint8_t*>(msg.input_data);
			std::copy(_msg.input_data, _msg.input_data + _msg.input_size, input_data);
			msg = _msg;
            msg.input_data = input_data;
		}

		void Convert2Txn(const evmc_address& sender, const evmc_address& receiver, const std::vector<uint8_t>& ByteCodeMsg)
		{
            uint8_t* input_data = nullptr;
			if (msg.input_size < ByteCodeMsg.size())
			{
				if(msg.input_data) delete[] const_cast<uint8_t*>(msg.input_data);
                input_data = new uint8_t[ByteCodeMsg.size()];
			}
            else
                input_data = const_cast<uint8_t*>(msg.input_data);
			msg.kind = EVMC_CALL;
			msg.gas = GAS_LIMIT;
			msg.sender = sender;
			msg.destination = receiver;
			msg.input_size = ByteCodeMsg.size();
			std::copy(ByteCodeMsg.begin(), ByteCodeMsg.end(), input_data);
            msg.input_data = input_data;
			is_relay = false;
		}

		~EVMTxn()
		{
			if (msg.input_data)
				delete[] const_cast<uint8_t*>(msg.input_data);
		}
	};

	class EVMTxnPool {
	public:
		EVMTxnPool() {}

		~EVMTxnPool() {
			for (auto txn : freeTxns) {
				delete txn;
			}
		}

		EVMTxn* GetTxn();

		void ReleaseTxn(EVMTxn* txn);

	private:
		std::mutex m;
		std::list<EVMTxn*> freeTxns;
	};

	class EVMSimulator
	{
	private:
		uint16_t _ShardCount;
		uint8_t _ShardOrder[32];
		bool _ifSharding;
		std::vector<EVMShard*> _Shards;
		EVMGlobalShard* _GlobalShard;
        EVMExecutionEngine _Engine;
		EVMEncoder _Encoder;
		EVMTxnPool _TxnPool;
		uint64_t _GasLimit;
		EVMDecoder _Decoder;
	private:
        std::mutex _CvNormalFinished;
		std::mutex _NormalMtx;
		std::atomic<uint32_t> _NormalFinishedCount;
		std::condition_variable _NormalShardFinished;
		std::mutex _TxnTraceMtx;
		std::map<EVMTxn*, std::vector<EVMTxn*>> _TxnTrace;
        bool _Stop;
	public:
		EVMSimulator() {}
		~EVMSimulator();
		std::vector<uint8_t> Compile(std::string contract);
		evmc::result Deploy(const std::vector<uint8_t>& compiledCode, uint64_t address, std::vector<uint8_t>& input_data);
		EVMTxn* AddTask(const evmc_address& sender, const evmc_address& receiver, const std::vector<uint8_t>& ByteCodeMsg);
		void AddTask(const std::vector<uint8_t>& ByteCodeMsg);
		EVMTxn* AddGlobalTask(const evmc_address& sender, const evmc_address& receiver, const std::vector<uint8_t>& ByteCodeMsg);
		void AddTaskFromSCV(evmc::address to, std::string csvPath);
		void AddShardingTaskFromCSV(evmc::address to, std::string csvPath);
		void Run();
        bool Stop(){return _Stop;};
		bool Finished();
		void Info(int i = 0);
		bool VizTrace(EVMTxn* orgTxn, const std::string& var_name, size_t index, std::string& out);
		void ExportViz(const std::string& json, const std::string& fileTemplate, const std::string& outputFile) const;
		const EVMDecoder* GetDecoder() const { return &_Decoder; }
	public:
		void InitShard(uint32_t shardOrder = 0, bool ifSharding = false);
		uint32_t GetShardCount() { return _Shards.size(); }
		EVMShard* GetShard(uint32_t i) { return i >= _Shards.size() ? nullptr : _Shards[i]; }
		EVMGlobalShard* GetGlobalShard() { return _GlobalShard; }
		uint64_t GetGasLimit() { return _GasLimit; }
		uint8_t* GetShardOrder() { return &_ShardOrder[0]; }
		EVMTxnPool* GetTxnPool() { return &_TxnPool; }
		void SetGasLimit(uint64_t _gasLimit) { _GasLimit = _gasLimit; }

		void PushTxn2Global(EVMTxn* txn);
		void PushTxn2Shard(EVMTxn* txn, evmc::address dest);
		void PushTxn2Address(EVMTxn* txn);
		void PushTxn2Uint32Scope(EVMTxn* txn);
		void AppendTxnTrace(EVMTxn* origin, EVMTxn* relay);

		void SetOneNormalFinished();

		std::vector<uint8_t> GetEncodeResult(std::string functionSignature, const std::vector<std::string>& in);
		std::vector<uint8_t> GetEncodeResult(const std::vector<std::pair<std::string, std::string>>& in);
		std::vector<uint8_t> GetEncodeResult(std::string type, const std::string& value);
		bool GetContractFunction(std::string opcode, std::pair<std::string, std::string>& out);
		std::string GetDecodedString(evmc::bytes32 event_sig, const uint8_t* data, size_t data_size){ return _Encoder.GetDecodedString(event_sig, data, data_size);}
	};

}


