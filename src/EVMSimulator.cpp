#include "EVMSimulator.h"
#include "EVMShard.h"
#include "EVMScriptRunner.h"
#include "EVMEncoder.h"
#include <fstream>
#include <iterator>
#include <queue>
#ifdef TIMER
uint64_t analyze_count = 0;
uint64_t execute_count = 0;
uint64_t instr_count = 0;
uint64_t exec_count = 0;
#endif

#ifdef _WIN32
#include <Windows.h>
#endif

namespace sol
{
	EVMTxn* EVMTxnPool::GetTxn() {
		std::lock_guard<std::mutex> lg(m);
		EVMTxn* ret = nullptr;
		if(!freeTxns.empty()){
			ret = freeTxns.front();
			freeTxns.pop_front();
		}
		else 
			ret = new EVMTxn;
        return ret;
	}

	void EVMTxnPool::ReleaseTxn(EVMTxn* txn) {
        freeTxns.push_back(txn);
	}

	EVMSimulator::~EVMSimulator()
	{
		if (_GlobalShard)	delete _GlobalShard;
		for (uint16_t i = 0; i < _ShardCount; ++i)
		{
			if (_Shards[i])		delete _Shards[i];
		}
	}

	void EVMSimulator::InitShard(uint32_t shardOrder, bool ifSharding)
	{
#ifdef _WIN32
		if (!SetPriorityClass(GetCurrentProcess(), REALTIME_PRIORITY_CLASS)) {
			std::cerr << "Failed to set process priority!" << std::endl;
		}
#endif
        memset(_ShardOrder, 0, 32);
		_ifSharding = ifSharding;
		_GlobalShard = new EVMGlobalShard(this);
		_GlobalShard->Init();
		if(ifSharding){
			_ShardOrder[31] = shardOrder;
			_ShardCount = 1 << shardOrder;
			
			for (uint16_t i = 0; i < _ShardCount; ++i)
			{
				_Shards.push_back(new EVMShard(this, _GlobalShard, i));
				_Shards[i]->Init();
			}
		}
		_GasLimit = MAX_TXNS_PER_BLOCK;
        _Stop = false;
	}
	std::vector<uint8_t> EVMSimulator::Compile(std::string contract)
	{
		std::vector<uint8_t> code = _Engine.Compile2ByteCode(contract);
		_Encoder.GetFunctionSignatures(contract + ".signatures");
		_Encoder.GetAbi(contract + ".abi");
		_Decoder.Init(contract + "_storage.json");
		return code;
	}

	evmc::result EVMSimulator::Deploy(const std::vector<uint8_t>& compiledCode, uint64_t address, std::vector<uint8_t>& input_data)
	{
		evmc::result ret = _GlobalShard->Deploy(compiledCode, address, input_data);
		for (uint16_t i = 0; i < _ShardCount && _ifSharding; ++i)
		{
			_Shards[i]->Deploy(compiledCode, address, input_data);
		}
		return ret;
	}

	EVMTxn* EVMSimulator::AddTask(const evmc_address& sender, const evmc_address& receiver, const std::vector<uint8_t>& ByteCodeMsg)
	{
		if (_ifSharding)
			return _Shards[sender.bytes[19] % _ShardCount]->AddTask(sender, receiver, ByteCodeMsg);
		else
			return _GlobalShard->AddTask(sender, receiver, ByteCodeMsg);
	}

	void EVMSimulator::AddTask(const std::vector<uint8_t>& ByteCodeMsg)
	{
		_GlobalShard->AddTask(evmc::address(0), ByteCodeMsg);
	}

	EVMTxn* EVMSimulator::AddGlobalTask(const evmc_address& sender, const evmc_address& receiver, const std::vector<uint8_t>& ByteCodeMsg)
	{
		return _GlobalShard->AddTask(sender, receiver, ByteCodeMsg);
	}

	void EVMSimulator::AddTaskFromSCV(evmc::address to, std::string csvPath)
	{
		std::ifstream file(csvPath);

		if(!file.is_open())
		{
			std::cerr << "Cannot open file: " << csvPath << std::endl;
			return;
		}
		// get header line info
		int fromPos = -1, inputPos = -1, pos = 0;
		std::string str, line;
		std::getline(file, str);
		std::stringstream headerStream(str);

		while(std::getline(headerStream, line, ',') || fromPos == -1 || inputPos == -1)
		{
			if("from" == line) fromPos = pos;
			else if("input" == line) inputPos = pos;
			++pos;
		}

		// add task 
		uint32_t cnt = 0;
		while(std::getline(file, line))
		{
			if (line.size() < 2 || line[0] != '0' || line[1] != 'x')
				continue;
			std::stringstream lineStream(line);
			pos = 0;
			evmc::address from;
			std::vector<uint8_t> input_data;
			while(std::getline(lineStream, str, ',') || (fromPos > pos && inputPos > pos))
			{
				if(pos == fromPos)
				{
					std::string s = str.substr(2);
					std::vector<uint8_t> bytes = sol::hex2uint8(s);
					std::copy(bytes.begin(), bytes.end(), std::begin(from.bytes));
				}
				else if(pos == inputPos)
				{
					std::string s = str.substr(2);
					input_data = sol::hex2uint8(s);
				}
				++pos;
			}
			AddTask(from, to, input_data);
			++cnt;
			if(!(cnt % 100000)) std::cout << cnt << std::endl;
		}
		std::cout << cnt << std::endl;
	}

	void EVMSimulator::AddShardingTaskFromCSV(evmc::address recipient, std::string csvPath)
	{
		std::ifstream file(csvPath);

		if(!file.is_open())
		{
			std::cerr << "Cannot open file: " << csvPath << std::endl;
			return;
		}
		uint32_t cnt = 0;
		std::string line, str, s;
		std::getline(file, line);
		std::vector<std::pair<evmc::address, std::vector<uint8_t>>> data;
		while (std::getline(file, line)) {
			evmc::address sender;
			std::stringstream lineStream(line);
			std::vector<std::string> args;
			std::getline(lineStream, str, ',');
			args.push_back(str);
			std::string raw = str.substr(2);
			for (size_t j = 0; j < raw.size(); j += 2)
			{
				int hex_byte = std::stoi(raw.substr(j, 2), nullptr, 16);
				sender.bytes[j / 2] = static_cast<uint8_t>(hex_byte);
			}
			args.push_back("1000000");
			std::vector<uint8_t> mint_data = GetEncodeResult("mint", args);
			AddTask(sender, recipient, mint_data);
			args.pop_back();
			std::getline(lineStream, str, ',');
			args.push_back(str);
			args.push_back("1");
			std::vector<uint8_t> input_data = GetEncodeResult("transfer", args);
			data.push_back(std::make_pair(sender, input_data));
			++cnt;
			if(!(cnt % 100000)) std::cout << cnt << std::endl;
		}
		Run();
		for (auto& d : data) {
			AddTask(d.first, recipient, d.second);
		}

		//uint32_t cnt = 0;
		//std::string line, str, s;
		//while(std::getline(file, line))
		//{
		//	if (line.size() < 2 || line[0] != '0' || line[1] != 'x')
		//		continue;
		//	std::stringstream lineStream(line);
		//	evmc::address from;
		//	std::string functionName;
		//	std::vector<std::string> args;
		//	// from
		//	std::getline(lineStream, str, ',');
		//	args.push_back(str);
		//	s = str.substr(2);
		//	std::vector<uint8_t> bytes = sol::hex2uint8(s);
		//	std::copy(bytes.begin(), bytes.end(), std::begin(from.bytes));
		//	// function
		//	std::getline(lineStream, str, ',');
		//	functionName = str;
		//	// args
		//	std::getline(lineStream, str);
		//	{
		//		// process args
		//		uint32_t colonPos = 0, end = 0;
		//		while(end < str.length())
		//		{
		//			if(':' == str[end])
		//			{
		//				colonPos = end;
		//				while(',' != str[end] && end < str.length())
		//					++end;
		//				std::string arg = str.substr(colonPos + 1, end - colonPos - 1);
		//				// trim double quotation mark
		//				uint32_t head = 0, tail = arg.length() - 1;
		//				while('\"' == arg[head] || ' ' == arg[head]) ++head;
		//				while('\"' == arg[tail] || ' ' == arg[tail] || '}' == arg[tail]) --tail;
		//				args.push_back(arg.substr(head, tail - head + 1));
		//			}
		//			++end;
		//		}
		//	}
		//	std::vector<uint8_t> input_data = _Encoder.GetEncodedData(functionName, args);

		//	AddTask(from, to, input_data);
		//	++cnt;
		//	if(!(cnt % 100000)) std::cout << cnt << std::endl;
		//}
		//std::cout << cnt << std::endl;
	}

	void EVMSimulator::AppendTxnTrace(EVMTxn* origin, EVMTxn* relay)
	{
		std::unique_lock<std::mutex> _lck(_TxnTraceMtx);
		_TxnTrace[origin].push_back(relay);
	}

	void EVMSimulator::Run()
	{
		_GlobalShard->InitCount();
		for (uint32_t i = 0; i < _ShardCount; ++i) _Shards[i]->InitCount();
#ifdef TIMER
		analyze_count = 0;
        execute_count = 0;
		instr_count = 0;
		exec_count = 0;
#endif
		while (!Finished())
		{
			_NormalFinishedCount = 0;
			_GlobalShard->Step();
			std::unique_lock<std::mutex> _lck(_NormalMtx);
			while (_NormalFinishedCount < _ShardCount) _NormalShardFinished.wait(_lck);
		}
#ifdef TIMER
		// _GlobalShard->RuntimeInfo();
		// for(auto shard : _Shards)
		// 	shard->RuntimeInfo();
		// _GlobalShard->GatherRuntimeInfo();
#endif

	}

	bool EVMSimulator::Finished()
	{
		if (_GlobalShard->GetTxnSize()) return false;
		for (auto Shard : _Shards){
			if (Shard->GetTxnSize()) return false;
		}
		return true;
	}

	void EVMSimulator::Info(int i)
    {
        if(0 == i)
        {
		    _GlobalShard->Info();
		    for (auto Shard : _Shards)
		    {
		    	Shard->Info();
		    }
        }
        else if(1 == i)
        {
            uint32_t totalTxns = 0, intraTxns = 0, crossTxns = 0;
            for(auto shard : _Shards)
            {
                uint32_t total = shard->_PendingTxns.size(), intra = 0, cross = 0;
                for(auto txn : shard->_PendingTxns)
                {
                    if(txn->msg.input_size >= 68 && (*(txn->msg.input_data + 4 + 31) - *(txn->msg.input_data + 4 + 32 + 31)) % _ShardCount) ++cross;
                }
                intra = total - cross;
                printf("\033[1;33mShard#%3d\ttxns: %7d\tintra: %7d\tcross: %7d\033[0m\n", shard->_ShardId, total, intra, cross);
                totalTxns += total;
                intraTxns += intra; 
                crossTxns += cross;
            }
           printf("\033[1;33mtotal-txns: %7d\tintra-txns: %7d\tcross-txns: %7d\033[0m\n", totalTxns, intraTxns, crossTxns); 
        }
	}

	bool EVMSimulator::VizTrace(EVMTxn* orgTxn, const std::string& var_name, size_t index, std::string& out)
	{
		// std::queue<std::pair<EVMTxn*, int>> queue;
		// queue.push({ orgTxn, -1 });
		// int id = 1;
		// std::string json("{\"type\":\"Trace\",\"command\":\"viz.trace ");
		// json += var_name + "[" + std::to_string(index) + "]\",\"content\":[";
		// while (queue.size() > 0)
		// {
		// 	std::pair<EVMTxn*, int> current_pair = queue.front();
		// 	queue.pop();
		// 	EVMTxn* txn = current_pair.first;
		// 	json += "{\"tx_id\":" + std::to_string(id) + ",\"tx_info\":{";
		// 	if (txn->orign_txn == nullptr) {
		// 		json += "\"Target\":" + std::to_string(txn->msg.sender.bytes[19]) + ",";
		// 	}
		// 	json += "\"Contract\":\"";
		// 	json += txn->contract_name + "\",\"Function\":\"" + txn->function_name + "\",\"Height\":" + std::to_string(txn->block_height);
		// 	json += ",\"ShardIndex\":" + (txn->shard_index == 0xffffffff ?  "\"g\"" : std::to_string(txn->shard_index));
		// 	json += ",\"ShardCount\":" + std::to_string(GetShardCount()) + "},\"father\":" + std::to_string(current_pair.second) + "},";
		// 	if (_TxnTrace.find(txn) != _TxnTrace.end())
		// 	{
		// 		std::vector<EVMTxn*> relays = _TxnTrace.find(txn)->second;
		// 		for (EVMTxn* t : relays)
		// 		{
		// 			queue.push({ t, id });
		// 		}
		// 	}
		// 	id++;
		// }
		// if (json.back() == ',')
		// {
		// 	json.pop_back();
		// }
		// json += "]},";
		// // std::cout << json << std::endl;
		// if (out.length() == 0)
		// {
		// 	out = "[";
		// }
		// out += json;
		return true;
	}

	void EVMSimulator::PushTxn2Global(EVMTxn* txn)
	{
		_GlobalShard->PushTxn(txn);
	}

	void EVMSimulator::PushTxn2Shard(EVMTxn* txn, evmc::address dest)
	{
		uint32_t i = (evmc::load32be(dest.bytes + 16) % _ShardCount);
		_Shards[i]->PushTxn(txn);
	}

	void EVMSimulator::PushTxn2Address(EVMTxn* txn)
	{
		if(txn->msg.input_size > 4)
		{
			uint32_t i = (evmc::load32be(txn->msg.input_data + 4 + 28) % _ShardCount);
			_Shards[i]->PushTxn(txn);
		}
		else
			_GlobalShard->PushTxn(txn);
	}

	void EVMSimulator::PushTxn2Uint32Scope(EVMTxn* txn)
	{
		if (txn->msg.input_size > 4)
		{
			uint16_t i = (evmc::load32be(txn->msg.input_data + 4 + 28) % _ShardCount);
			_Shards[i]->PushTxn(txn);
		}
		else
			_GlobalShard->PushTxn(txn);
	}

	void EVMSimulator::SetOneNormalFinished()
	{
        std::unique_lock<std::mutex> lck(_CvNormalFinished);
		++_NormalFinishedCount;
		if(_ShardCount == _NormalFinishedCount) 
			_NormalShardFinished.notify_one();
	}

	std::vector<uint8_t> EVMSimulator::GetEncodeResult(std::string functionName, const std::vector<std::string>& in)
	{
		return _Encoder.GetEncodedData(functionName, in);
	}
	
	std::vector<uint8_t> EVMSimulator::GetEncodeResult(const std::vector<std::pair<std::string, std::string>>& in)
	{
		std::vector<uint8_t> ret;
		ret.resize(BYTES32 * in.size());
		auto it = ret.begin();
		for(auto& param : in)
		{
			std::vector<uint8_t> bytes = _Encoder.GetEncodedData(param.first, ElementType(param.second).type, false);
			it = std::copy(bytes.begin(), bytes.end(), it);
		}
		return ret;
	}

	std::vector<uint8_t> EVMSimulator::GetEncodeResult(std::string type, const std::string& value)
	{
		return _Encoder.GetEncodedData(value, ElementType(type).type, false);		
	}
	
	bool EVMSimulator::GetContractFunction(std::string opcode, std::pair<std::string, std::string>& out)
	{
		return _Encoder.GetContractFunction(opcode, out);
	}

	void EVMSimulator::ExportViz(const std::string& json, const std::string& fileTemplate, const std::string& outputFile) const
	{
		std::string html;
		std::ifstream f(fileTemplate);
		std::string html_template(std::istreambuf_iterator<char>(f), (std::istreambuf_iterator<char>()));
		size_t pos = html_template.find("</HEAD>");
		if(pos == -1) pos = html_template.find("</head>");
		if (pos == -1) return;
		std::string out;
		out = html_template.substr(0, pos);
		out += "\n<script type=\"text/javascript\">\nvar CRYSTALITY_VIZ_LOG = `\n";
		std::string json_tmp = json;
		if (json_tmp.length() > 0 && json_tmp.back() == ',')
		{
			json_tmp.pop_back();
			json_tmp += ']';
		}
		out += json_tmp;
		out += "`;\n</script>\n\n";
		out += html_template.substr(pos);
		std::ofstream outfile;
		outfile.open(outputFile);
		outfile << out;
		outfile.close();
	}

}
