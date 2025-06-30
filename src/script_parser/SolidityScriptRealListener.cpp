#include "SolidityScriptRealListener.h"
#include <thread>
#include <stdio.h>
#include <cstdint>
#include "../transpiler/transpiler.h"
#include "../EVMShard.h"
#include "../EVMHost.h"
#include "../include/ethash/keccak.h"
#include "ed25519/ed25519.h"

std::string ConvertUint32ToString(uint32_t addr)
{
	char buf[43];
	sprintf(buf, "0x%040x", addr);
	return std::string(buf);
}

namespace sol
{

void SolidityScriptRealListener::enterSource(SolidityScriptParser::SourceContext* ctx)
{

}
void SolidityScriptRealListener::enterScript(SolidityScriptParser::ScriptContext* ctx)
{

}

void SolidityScriptRealListener::enterVariableDeclaration(SolidityScriptParser::VariableDeclarationContext* ctx)
{
	_Walker->SkipCurrentRuleSubtree();
	std::string key = ctx->identifier()->getText();
	std::vector<std::string> value{};
	switch ((SolidityScriptExpressionType)ctx->expression()->expressionType)
	{
    case evmcAddress:
        {
            int sz = std::stoi(ctx->expression()->numberLiteral()->getText());
			SolUser s_usr;
			uint8_t seed[64] = { 0 };
			for(int i = 0; i < sz; ++i)
            {
				s_usr.addr = evmc::address(i);
#ifdef VERIFY_SIG
				 ed25519_create_keypair(&s_usr.pk[0], &s_usr.sk[0], &seed[0]);
#endif
				_Users.push_back(s_usr);
				_UserMap[s_usr.addr] = s_usr;

				char addr[45] = "0x";
				char* tmp = &addr[2];
				for (size_t i = 0; i < 20; ++i) {
					snprintf(tmp, 3, "%02x", static_cast<unsigned int>(s_usr.addr.bytes[i]));
					tmp += 2;
				}
				value.push_back(std::string(addr));
            }
        }
        break;
	case randomCall:
		value = ProcessRandomCall(ctx->expression()->randomCall());
		break;
	case numberLiteral:
		value.push_back(ctx->expression()->numberLiteral()->getText());
		break;
	case stringLiteral:
		value.push_back(ctx->expression()->StringLiteral()->getText().substr(1, ctx->expression()->StringLiteral()->getText().size() - 2));
		break;
	case identifier:
		value.push_back(ctx->expression()->identifier()->getText());
		break;
	default:
		break;
	}
	_LocalVariables.insert({ key, value });
}

void SolidityScriptRealListener::enterFunctionCall(SolidityScriptParser::FunctionCallContext* ctx)
{
	_Walker->SkipCurrentRuleSubtree();
	if (ctx->CHAIN())
	{
		if(ctx->DEPLOY())
		{
			uint64_t addr = 0;
			if(ctx->scope() && ctx->scope()->numberLiteral()) 
				addr = std::stoi(ctx->scope()->numberLiteral()->getText());

			std::vector<uint8_t> compiledCode;
			std::string contractName;
			if(ctx->xtlFile()){
				if (Transpile(_ScriptDir + ctx->xtlFile()->getText())) {
					return;
				}
				compiledCode = _Simulator->Compile("./solc/" + GetFileName(ctx->xtlFile()->getText()));
				contractName = ctx->xtlFile()->identifier()->getText();
			}
			else if(ctx->solFile()){
				compiledCode = _Simulator->Compile(ctx->solFile()->getText());
				contractName = ctx->solFile()->identifier()->getText();
			}

			std::vector<uint8_t> input_data;
			if(ctx->arguments())
				input_data = ConvertArguments2Bytes(ctx->arguments());

			evmc::result ret = _Simulator->Deploy(compiledCode, addr, input_data);
			if(EVMC_SUCCESS == ret.status_code)
				_Contracts.insert(std::make_pair(contractName, evmc::address(addr)));
		}
		else if (ctx->identifier() && "init" == ctx->identifier()->getText())
		{
			// if (ctx->chainParams() && ctx->chainParams()->numberLiteral())
			// {
			// 	_ShardOrder = std::stoi(ctx->chainParams()->numberLiteral()->getText());
			// 	_Simulator->InitShard(_ShardOrder, true);
			// }
			// else
				_Simulator->InitShard(_ShardOrder, true);
		}
		else if (ctx->identifier() && "run" == ctx->identifier()->getText())
		{
			_Simulator->Run();
		}
		else if (ctx->identifier() && "info" == ctx->identifier()->getText())
		{
			if(ctx->chainParams() && ctx->chainParams()->numberLiteral())
			{
				uint32_t i = std::stoi(ctx->chainParams()->numberLiteral()->getText());
			    _Simulator->Info(i);
			}
            else
                _Simulator->Info();
		}
	}
	else if (ctx->STOPWATCH())
	{
		if ("restart" == ctx->identifier()->getText())
		{
			_Watch->Restart();
		}
		else if ("report" == ctx->identifier()->getText())
		{
			_Watch->Report();
			uint64_t total_txns = 0;
			total_txns += _Simulator->GetGlobalShard()->GetTxns();
			for(size_t i = 0; i < _Simulator->GetShardCount(); ++i)
			{
				total_txns += _Simulator->GetShard(i)->GetTxns();
			}
			_Watch->Report(total_txns);
		}
        else if ("sleep" == ctx->identifier()->getText())
        {

        }
	}
	else if(ctx->vizTrace())
	{
		auto* vizCtx = ctx->vizTrace();
		std::string trace_identifier = vizCtx->identifier()->getText();
		size_t trace_id = vizCtx->numberLiteral() ? (size_t)std::stoi(vizCtx->numberLiteral()->getText()) : 0;
		if(_Txns.find(trace_identifier) == _Txns.end()){
			std::cout << "unknown identifier " << trace_identifier << std::endl;
			return;
		}
		if(trace_id > _Txns[trace_identifier].size() - 1){
			std::cout << "index out of range in " << trace_identifier << std::endl;
			return;
		}
		_Simulator->VizTrace(_Txns[trace_identifier][trace_id], trace_identifier, trace_id, json);
	}
	else if(ctx->inputCSV())
	{
		if (_Contracts.find(ctx->identifier()->getText()) == _Contracts.end()) return;

		if("NFT" == ctx->identifier()->getText())
			AddNftTaskFromCSV(evmc::address(_Contracts[ctx->identifier()->getText()]), "./" + ctx->inputCSV()->getText());
		else if("ERC20" == ctx->identifier()->getText())
			AddERC20TaskFromCSV(evmc::address(_Contracts[ctx->identifier()->getText()]), "./" + ctx->inputCSV()->getText());
	}
	else if(ctx->expression()->expression())
	{
		std::string contractName = ctx->expression()->expression()->getText();
		if (_Contracts.find(contractName) == _Contracts.end()) return;
		std::string functionName = ctx->expression()->identifier()->getText();
		uint32_t count = ctx->count() ? ProcessCount(ctx->count()) : 1;
		std::vector<std::thread> threads;
		std::string txn_identifier = ctx->identifier() ? ctx->identifier()->getText() : "";

		auto generate_task = [&](uint32_t begin, uint32_t end) {
			std::vector<std::string> scope, args;
			evmc::address sender(0);
			EVMTxn* txn = nullptr;
		    for (uint32_t i = begin; i < end; ++i) {
				if (ctx->scope())
				{
					scope = ProcessScope(ctx->scope());
					for (size_t j = 0; j < scope.size(); ++j) {
						args = ProcessArguments(ctx->arguments());
						sender = _Randomizer->ConvertString2EVMAddress(scope[j]);
						if (scope[j].size() > 43)
						{
							std::string from = scope[j].substr(0, 42), to = scope[j].substr(42, 42);
							args.insert(args.begin(), to);
							args.insert(args.begin(), from);
						}
						else
							args.insert(args.begin(), scope[j]);

						std::vector<uint8_t> input_data = _Simulator->GetEncodeResult(functionName, args);
						if(input_data.empty())
							continue;
						IssueTxn(sender, _Contracts[contractName], input_data);
					}
				}
				else
				{
					sender = _Users[0].addr;
					args = ProcessArguments(ctx->arguments());
					std::vector<uint8_t> input_data = _Simulator->GetEncodeResult(functionName, args);
					if(input_data.empty())
							continue;
					txn = _Simulator->AddGlobalTask(sender, _Contracts[contractName], input_data);
#ifdef VERIFY_SIG
					std::copy(_UserMap[sender].pk, _UserMap[sender].pk + 32, &(txn->pk[0]));
					ed25519_sign(&(txn->sig[0]), (const uint8_t*)&txn->msg, sizeof(evmc_message), &(_UserMap[sender].pk)[0], &(_UserMap[sender].sk)[0]);
#endif
				}
            }
		};

		uint32_t thread_count = 32; // Number of threads
		uint32_t items_per_thread = count / thread_count; // Number of items for each thread to process
		
		// Start each thread
		for (uint32_t i = 0; i < thread_count; ++i) {
		    uint32_t begin = i * items_per_thread;
		    uint32_t end = (i == thread_count - 1) ? count : (begin + items_per_thread); // Last thread takes the remaining items
		    threads.push_back(std::thread(generate_task, begin, end));
		}
		
		// Wait for all threads to finish
		for (auto& thread : threads) {
		    thread.join();
		}
	}
}

std::string SolidityScriptRealListener::ProcessExpression(SolidityScriptParser::ExpressionContext* ctx)
{
	switch ((SolidityScriptExpressionType)ctx->expressionType)
	{
	case randomCall:
	{
		std::vector<std::string> randStr = ProcessRandomCall(ctx->randomCall());
		if (randStr.size())
			return randStr[0];
		break;
	}
	case dotExpression:
		break;
	case numberLiteral:
		return ctx->numberLiteral()->getText();
	case boolLiteral:
		return ctx->boolLiteral()->getText();
	case stringLiteral:
		return ctx->StringLiteral()->getText().substr(1, ctx->StringLiteral()->getText().size() - 2);
	case stringArray:
		return ctx->stringArray()->getText();
	case structArray:
		return ProcessStructArray(ctx->structArray());
	case identifier:
		if (_LocalVariables.find(ctx->identifier()->getText()) != _LocalVariables.end() && _LocalVariables[ctx->identifier()->getText()].size()){
			int i = ctx->numberLiteral() ? std::stoi(ctx->numberLiteral()->getText()) : 0;
			return _LocalVariables[ctx->identifier()->getText()][i];
		}
		break;
	default:
		break;
	}
	return " ";
}

std::string SolidityScriptRealListener::ProcessStringArray(SolidityScriptParser::StringArrayContext* ctx)
{
	std::string ret = "";
	for(auto str : ctx->StringLiteral())
	{
		ret += str->getText().substr(1, str->getText().size() - 2);
		ret += ',';
	}
	ret.pop_back();
	return ret;
}

std::string SolidityScriptRealListener::ProcessStructArray(SolidityScriptParser::StructArrayContext* ctx)
{
	std::string ret = "";
	uint32_t count = ctx->numberLiteral() ? std::stoi(ctx->numberLiteral()->getText()) : 1;
	for (uint32_t i = 0; i < count; ++i)
	{
		std::vector<std::string> structElem = ProcessArguments(ctx->arguments());
		ret += '{';
		for (auto& strc : structElem)
			ret += strc + ',';
		ret.back() = '}';
	}
	return ret;
}

uint32_t SolidityScriptRealListener::ProcessCount(SolidityScriptParser::CountContext* ctx)
{
	if (ctx->numberLiteral())
	{
		return std::stoull(ctx->numberLiteral()->getText());
	}
	else if (ctx->identifier() && _LocalVariables.find(ctx->identifier()->getText()) != _LocalVariables.end())
	{
		return std::stoull(_LocalVariables[ctx->identifier()->getText()][0]);
	}
	else if (ctx->UINT32())
	{
		uint32_t low = std::stoull(ctx->randomCallArguments()->arguments()->argument(0)->getText());
		uint32_t high = std::stoull(ctx->randomCallArguments()->arguments()->argument(1)->getText());
		return _Randomizer->RandomGetUint32(low, high);
	}
	return 0;
}

std::vector<std::string> SolidityScriptRealListener::ProcessScope(SolidityScriptParser::ScopeContext* ctx)
{
	std::vector<std::string> ret;
	if(ctx->numberLiteral())
	{
		ret.push_back(ConvertUint32ToString((uint32_t)std::stoi(ctx->numberLiteral()->getText())));
	}
	else if (ctx->identifier() && _LocalVariables.find(ctx->identifier()->getText()) != _LocalVariables.end())
	{
		std::string idtfr = ctx->identifier()->getText();
		if (ctx->RANDOM())
		{
			ret = _Randomizer->GetRandomVectorString(_LocalVariables[idtfr], 1);
		}
        else if(ctx->INTRA())
        {
            uint32_t sz = _LocalVariables[idtfr].size();
            uint32_t from = _Randomizer->RandomGetUint32(0, sz - 1);
			uint32_t to = (from + from * (1 << _ShardOrder)) % sz;
            std::string str = _LocalVariables[idtfr][from] + _LocalVariables[idtfr][to];
            ret.push_back(str);
        }
        else if(ctx->CROSS())
        {
			uint32_t sz = _LocalVariables[idtfr].size();
			uint32_t from = _Randomizer->RandomGetUint32(0, sz - 1);
			uint32_t to = _Randomizer->RandomGetUint32(1, (1 << _ShardOrder) - 1);
            to = (to + from + to * (1 << _ShardOrder)) % sz; 
			std::string str = _LocalVariables[idtfr][from] + _LocalVariables[idtfr][to];
			ret.push_back(str);
        }
		else if(ctx->numberLiteral())
		{
			int i = std::stoi(ctx->numberLiteral()->getText());
			if(i < _LocalVariables[idtfr].size()){
				ret.push_back(_LocalVariables[idtfr][i]);
			}
		}
		else
		{
			ret = _LocalVariables[idtfr];
		}
	}
	return ret;
}

std::vector<std::string> SolidityScriptRealListener::ProcessRandomCall(SolidityScriptParser::RandomCallContext* ctx)
{
	std::vector<std::string> ret;
	uint32_t count = ctx->randomCallCount() ? std::stoull(ctx->randomCallCount()->numberLiteral()->getText()) : 1;
	uint32_t low = 0, high = UINT32_MAX;
	if (ctx->randomCallArguments())
	{
		low = std::stoull(ctx->randomCallArguments()->arguments()->argument(0)->getText());
		high = std::stoull(ctx->randomCallArguments()->arguments()->argument(1)->getText());
	}
	if (ctx->UINT16())
	{
		ret = _Randomizer->GetRandomStringUint16(count, low, high);
	}
	else if (ctx->UINT32())
	{
		ret = _Randomizer->GetRandomStringUint32(count, low, high);
	}
	else if (ctx->UINT256())
	{
		ret = _Randomizer->GetRandomStringUint256(count);
	}
	else if (ctx->ADDRESS())
	{
		ret = _Randomizer->GetRandomStringAddress(count);
		SolUser s_usr;
		uint8_t seed[64] = { 0 };
		for(auto& addr_str : ret){
			s_usr.addr = _Randomizer->ConvertString2EVMAddress(addr_str);
#ifdef VERIFY_SIG
			ed25519_create_keypair(&s_usr.pk[0], &s_usr.sk[0], &seed[0]);
#endif
			_Users.push_back(s_usr);
			_UserMap[s_usr.addr] = s_usr;
		}
	}
	else if (ctx->BOOL())
	{
		ret = _Randomizer->GetRandomStringBool(count);
	}
	else if (ctx->identifier() && _LocalVariables.find(ctx->identifier()->getText()) != _LocalVariables.end())
	{
		ret = _Randomizer->GetRandomVectorString(_LocalVariables[ctx->identifier()->getText()], count);
	}
	return ret;
}

std::vector<std::string> SolidityScriptRealListener::ProcessArguments(SolidityScriptParser::ArgumentsContext* ctx)
{
	std::vector<std::string> ret;
	if (ctx)
	{
		for (auto arg : ctx->argument())
		{
			if(arg->expression())
				ret.push_back(ProcessExpression(arg->expression()));
		}
	}
	return ret;
}

std::vector<uint8_t> SolidityScriptRealListener::ConvertArguments2Bytes(SolidityScriptParser::ArgumentsContext* ctx)
{
	if(!ctx->argument().size()) return std::vector<uint8_t>();
	std::vector<uint8_t> ret(BYTES32 * ctx->argument().size(), 0);
	auto it = ret.begin();
	for(auto v : ctx->argument())
	{
		if(v->explicitTypeValue()){
			std::string value, type;
			value = v->explicitTypeValue()->StringLiteral()? v->explicitTypeValue()->StringLiteral()->getText().substr(1, v->explicitTypeValue()->StringLiteral()->getText().length() - 2) : v->explicitTypeValue()->numberLiteral()->getText();
			type = v->explicitTypeValue()->type()->getText();
			std::vector<uint8_t> bytes = _Simulator->GetEncodeResult(type, value);
			it = std::copy(bytes.begin(), bytes.end(), it);
		}
		else if(v->expression() && _Contracts.find(v->expression()->getText()) != _Contracts.end())
		{
			evmc::address addr = _Contracts[v->expression()->getText()];
			it += 12;
			it = std::copy(std::begin(addr.bytes), std::end(addr.bytes), it);
		}
	}
	return ret;
}
std::string SolidityScriptRealListener::GetDecodedState(const evmc::bytes32& storage, const StateVariable& var)
{
	std::string result;
	if (var.type == Type::String)
	{
		result = ((char*)(storage.bytes));
	}
	else if (var.type == Type::Uint)
	{
		uint64_t var = evmc::load64be(storage.bytes + 24);
		result = std::to_string(var);
	}
	return result;
}
std::string SolidityScriptRealListener::VizualizeStateVar(const std::string& contract, const std::string& varName, evmc::address* addr)
{
	std::string result;
	std::map<std::string, evmc::address>::iterator iter = _Contracts.find(contract);
	if (iter == _Contracts.end())
	{
		std::cout << "Invalid Contract Name\n";
		return result;
	}
	EVMHost* targetHost = nullptr;
	const EVMDecoder* decoder = _Simulator->GetDecoder();
	uint32_t i = 0;
	StateVariable target;
	for (;i < decoder->_StateVariables.size(); i++)
	{
		if (decoder->_StateVariables[i].label == varName)
		{
			target = decoder->_StateVariables[i];
			break;
		}
	}
	if (i == decoder->_StateVariables.size())
	{
		std::cout << "Invalid State Variable Label\n";
		return result;
	}
	uint32_t slot = target.slot;
	UintType uintt(std::to_string(slot));
	auto getShardIndex = [](evmc::address* addr, uint32_t shardCount) {
		return (evmc::load32be(addr->bytes + 16) % shardCount);
	};
	auto getMapKeyAndSlotHash = [](evmc::bytes32 key, evmc::bytes32 slot) {
		uint8_t bytes[64];
		memcpy(bytes, key.bytes, 32);
		memcpy(bytes + 32, slot.bytes, 32);
		ethash_hash256 hash = ethash_keccak256(bytes, 64);
		evmc::bytes32 result;
		memcpy(result.bytes, hash.bytes, 32);
		return result;
	};
	if (!addr)
	{
		targetHost = _Simulator->GetGlobalShard()->GetHost();
	}
	else
	{
		targetHost = _Simulator->GetShard(getShardIndex(addr, _Simulator->GetShardCount()))->GetHost();
	}
	if (target.type == Type::Struct)
	{
		std::cout << target.label << ":\n";
		for (uint32_t i = 0; i < target.NestingTypeExpansion.size(); i++)
		{
			std::string result = GetDecodedState(targetHost->get_storage(iter->second, uintt.Convert2EvmcBytes(std::to_string(target.slot + target.NestingTypeExpansion[i].slot))), target.NestingTypeExpansion[i]);
			std::cout << target.NestingTypeExpansion[i].label << ":" << result << std::endl;
		}
	}
	else if (target.type == Type::Map)
	{
		std::cout << target.label << ":\n";
		for (uint32_t i = 0; i < target.NestingTypeExpansion.size(); i++)
		{
			//assume @address variable
			if (target.NestingTypeExpansion[i].type == Type::Address && addr == nullptr)
			{
				std::vector<std::string> addrList = _LocalVariables.find("addr")->second;
				for (std::string s : addrList)
				{
					AddressType addrType(s);
					evmc::bytes32 addrByte = addrType.Convert2EvmcBytes(s);
					targetHost = _Simulator->GetShard(getShardIndex((evmc::address*)&addrByte, _Simulator->GetShardCount()))->GetHost();
					evmc::bytes32 keyHashed = getMapKeyAndSlotHash(addrByte, uintt.Convert2EvmcBytes(std::to_string(target.slot)));
					std::string result = GetDecodedState(targetHost->get_storage(iter->second, keyHashed), target.NestingTypeExpansion[1]);
					std::cout << s << ":" << result << std::endl;
				}
			}
		}
	}
	else
	{
		evmc::bytes32 storage = targetHost->get_storage(iter->second, uintt.Convert2EvmcBytes(std::to_string(slot)));
		std::cout << GetDecodedState(storage, target) << std::endl;
	}
	return result;
}

void SolidityScriptRealListener::AddERC20TaskFromCSV(const evmc::address& recipient, std::string csvPath)
{
	std::ifstream file(csvPath);

	if (!file.is_open())
	{
		std::cerr << "Cannot open file: " << csvPath << std::endl;
		return;
	}
	uint32_t cnt = 0;
	std::string line, str, s;
	std::getline(file, line);
	std::vector<std::pair<evmc::address, std::vector<uint8_t>>> data;
	while (std::getline(file, line)) {
		std::stringstream lineStream(line);
		std::vector<std::string> args;
		std::getline(lineStream, str, ',');
		args.push_back(str);
		// std::string raw = str.substr(2);
		// for (size_t j = 0; j < raw.size(); j += 2)
		// {
		// 	int hex_byte = std::stoi(raw.substr(j, 2), nullptr, 16);
		// 	sender.bytes[j / 2] = static_cast<uint8_t>(hex_byte);
		// }
		uint32_t sender_id = std::stoul(str);
		evmc::address sender(sender_id);
		AddUser(sender);

		args.push_back("1000000");
		std::vector<uint8_t> mint_data = _Simulator->GetEncodeResult("mint", args);
		IssueTxn(sender, recipient, mint_data);

		args.pop_back();
		std::getline(lineStream, str, ',');
		args.push_back(str);
		args.push_back("1");
		std::vector<uint8_t> input_data = _Simulator->GetEncodeResult("transfer", args);
		data.push_back(std::make_pair(sender, input_data));
		// if (!(++cnt % 100000)) std::cout << cnt << std::endl;
	}
	_Simulator->Run();
	for (auto& d : data) {
		IssueTxn(d.first, recipient, d.second);
	}
}

void SolidityScriptRealListener::AddNftTaskFromCSV(const evmc::address& recipient, std::string csvPath)
{
	std::ifstream file(csvPath);

	if (!file.is_open())
	{
		std::cerr << "Cannot open file: " << csvPath << std::endl;
		return;
	}
	uint32_t cnt = 0;
	std::string line, str, s;
	std::getline(file, line);
	std::vector<std::vector<std::pair<evmc::address, std::vector<uint8_t>>>> transfer_data_blocks;
	std::vector<std::pair<evmc::address, std::vector<uint8_t>>> data_block;
	std::set<uint32_t> token_set;

	while (std::getline(file, line)) {
		std::stringstream lineStream(line);
		std::vector<std::string> args;
		std::getline(lineStream, str, ',');

		if ("0" == str) {
			std::getline(lineStream, str, ',');
			args.push_back(str);
			uint32_t sender_id = std::stoul(str);
			evmc::address sender(sender_id);
			AddUser(sender);

			std::getline(lineStream, str, ',');
			args.push_back(str);
			std::vector<uint8_t> mint_data = _Simulator->GetEncodeResult("mint", args);
			IssueTxn(sender, recipient, mint_data);
		}
		else {
			args.push_back(str);
			uint32_t sender_id = std::stoul(str);
			evmc::address sender(sender_id);
			AddUser(sender);

			std::getline(lineStream, str, ',');
			args.push_back(str);

			std::getline(lineStream, str, ',');
			args.push_back(str);
			uint32_t token_id = std::stoul(str);

			std::vector<uint8_t> transfer_data = _Simulator->GetEncodeResult("transfer", args);

			if (token_set.find(token_id) != token_set.end()) {
				transfer_data_blocks.push_back(data_block);
				data_block.clear();
				token_set.clear();
			}
			else {
				data_block.push_back(std::make_pair(sender, transfer_data));
				token_set.insert(token_id);
			}
		}

		// if (!(++cnt % 100000)) 
		// 	std::cout << cnt << std::endl;
	}
	if(!data_block.empty()) 
		transfer_data_blocks.push_back(data_block);
	std::cout << cnt << std::endl;

	for (auto& block : transfer_data_blocks) {
		for (auto& d : block) {
			IssueTxn(d.first, recipient, d.second);
		}
		_Simulator->Info();
		_Watch->Restart();
		_Simulator->Run();
		uint64_t total_txns = 0;
		total_txns += _Simulator->GetGlobalShard()->GetTxns();
		for (size_t i = 0; i < _Simulator->GetShardCount(); ++i)
		{
			total_txns += _Simulator->GetShard(i)->GetTxns();
		}
		_Watch->Report(total_txns);
	}

}

void SolidityScriptRealListener::AddUser(const evmc::address& addr)
{
	if (_UserMap.find(addr) != _UserMap.end())
		return;
	SolUser s_usr;
	uint8_t seed[64] = { 0 };
	ed25519_create_keypair(&s_usr.pk[0], &s_usr.sk[0], &seed[0]);
	s_usr.addr = addr;
	_Users.push_back(s_usr);
	_UserMap[s_usr.addr] = s_usr;
}

void SolidityScriptRealListener::IssueTxn(const evmc_address& sender, const evmc_address& recipient, const std::vector<uint8_t>& msg)
{
	EVMTxn* txn = _Simulator->AddTask(sender, recipient, msg);
#ifdef VERIFY_SIG
	std::copy(_UserMap[sender].pk, _UserMap[sender].pk + 32, &(txn->pk[0]));
	ed25519_sign(&(txn->sig[0]), (const uint8_t*)&txn->msg, sizeof(evmc_message), &(_UserMap[sender].pk)[0], &(_UserMap[sender].sk)[0]);
#endif
}

}