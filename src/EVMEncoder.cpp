#include "EVMEncoder.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include "transpiler/CodeSerializer.h"
#include "../3rdParty/nlohmann/json.hpp"

namespace sol
{
	ElementType::ElementType(std::string typeStr)
	{
		isDynamicArray = (typeStr.find("[]") != std::string::npos);
		ParseType(typeStr);
	}

	void ElementType::SplitString(const std::string& str, std::vector<std::string>& splitStr)
	{
		std::istringstream paramStream(str);
		std::string param;
		while (std::getline(paramStream, param, ',')) {
			param.erase(0, param.find_first_not_of(" "));
			param.erase(param.find_last_not_of(" ") + 1);
			splitStr.push_back(param);
		}
	}

	void ElementType::ParseType(const std::string& str)
	{
		if (str.find('(') != std::string::npos)
		{
			type = Type::Struct;
			std::string structElements = str.substr(str.find('(') + 1, str.find(')') - str.find('(') - 1);
			std::vector<std::string> splitStr;
			SplitString(str, splitStr);
			std::vector<Type> ret; 
			for (auto& elem : splitStr)
			{
				ret.emplace_back(ParseNoStructType(elem));
			}
			structTypes = ret;
		}
		else
			type = ParseNoStructType(str);
	}

	Type ElementType::ParseNoStructType(const std::string& str)
	{
		Type type;
		if (str.find("address") != std::string::npos)
			type = Type::Address;
		else if (str.find("bool") != std::string::npos)
			type = Type::Bool;
		else if (str.find("bytes") != std::string::npos)
		{
			if (5 == str.size() || (isDynamicArray && 7 == str.size()))
				type = Type::Bytes;
			else
				type = Type::FixedBytes;
		}
		else if (str.find("string") != std::string::npos)
			type = Type::String;
		else if (str.find("uint") != std::string::npos)
			type = Type::Uint;
		else
			type = Type::Uint;
		return type;
	}

	BytesType::BytesType(const std::string& bytesStr, bool _dynamic)
		: ElementType(Type::Bytes, _dynamic)
	{
		std::vector<std::string> splitBytes;
		SplitString(bytesStr, splitBytes);
		Parse(splitBytes);
	}

	std::vector<uint8_t> BytesType::GetEncodedData()
	{
		std::vector<uint8_t> ret;
		ret.resize(GetEncodedDataLength());

		auto it_data = ret.begin();
		if (isDynamicArray)
		{
			evmc::bytes32 len(data.size());
			it_data = std::copy(std::begin(len.bytes), std::end(len.bytes), it_data);
			auto it_offset = it_data;
			evmc::bytes32 zero(0);
			for (size_t i = 0; i < data.size(); ++i)
			{
				it_data = std::copy(std::begin(zero.bytes), std::end(zero.bytes), it_data);
			}
			uint32_t offset = data.size() * BYTES32;

			for (auto& bytes : data)
			{
				evmc::bytes32 offset_bytes(offset);
				// encode offset
				it_offset = std::copy(std::begin(offset_bytes.bytes), std::end(offset_bytes.bytes), it_offset);
				// encode count
				evmc::bytes32 count_bytes(bytes.length);
				it_data = std::copy(std::begin(count_bytes.bytes), std::end(count_bytes.bytes), it_data);
				offset += BYTES32;
				// encode data
				for (auto& bytes32 : bytes.data)
					it_data = std::copy(std::begin(bytes32.bytes), std::end(bytes32.bytes), it_data);
				offset += bytes.data.size() * BYTES32;
			}
		}
		else
		{
			for (auto& bytes : data)
			{
				// encode count
				evmc::bytes32 count_bytes(bytes.length);
				it_data = std::copy(std::begin(count_bytes.bytes), std::end(count_bytes.bytes), it_data);
				// encode data
				for (auto& bytes32 : bytes.data)
					it_data = std::copy(std::begin(bytes32.bytes), std::end(bytes32.bytes), it_data);
			}
		}

		return ret;
	}

	uint32_t BytesType::GetEncodedDataLength()
	{
		uint32_t ret = 0, len = 0;
		if (isDynamicArray) {
			len += 1;
			for (auto& bytes : data)
				len += (2 + bytes.data.size());	// add offset and count
		}
		else
		{
			for (auto& bytes : data)
				len += (1 + bytes.data.size());	// add offset and count
		}

		ret = len * BYTES32;

		return ret;
	}

	void BytesType::Parse(const std::vector<std::string>& bytes)
	{
		for (auto& byte : bytes)
			data.emplace_back(Convert2ByteData(byte));
	}

	BytesData BytesType::Convert2ByteData(const std::string& byte)
	{
		if (byte.size() < 2 || byte.size() % 2 || byte[0] != '0' || byte[1] != 'x')
		{
			throw std::invalid_argument("Invalid byte string format");
		}
		BytesData result;

		// Remove the '0x' prefix
		std::string raw = byte.substr(2);
		result.length = raw.size() / 2; // convert from hex to bytes

		// Calculate the number of zeros needed for padding
		size_t padding = (64 - raw.size() % 64) % 64;

		// Pad the raw string with zeros on the right
		raw += std::string(padding, '0');


		// Iterate over each 64-character segment of the raw string
		for (size_t i = 0; i < raw.size(); i += 64)
		{
			evmc::bytes32 bytes;
			std::string segment = raw.substr(i, 64);

			// Cast each char to uint8_t and use memcpy for the copy
			for (size_t j = 0; j < 64; j += 2)
			{
				int hex_byte = std::stoi(segment.substr(j, 2), nullptr, 16);
				bytes.bytes[j / 2] = static_cast<uint8_t>(hex_byte);
			}

			result.data.emplace_back(bytes);
		}

		return result;
	}

	StringType::StringType(const std::string& str, bool _dynamic)
		:BytesType(_dynamic)
	{
		type = Type::String;
		std::vector<std::string> splitStrs;
		SplitString(str, splitStrs);
		Parse(splitStrs);
	}

	void StringType::SplitString(const std::string& str, std::vector<std::string>& splitStr)
	{
		std::string segment;
		std::string data = str;
		if (isDynamicArray)
			data = data.substr(1, data.length() - 2);
		for (char ch : data)
		{
			if (ch == ',')
			{
				// Add segment to result vector
				splitStr.emplace_back(segment);
				// Clear segment
				segment.clear();
			}
			else 
				segment += ch;
		}
		if(!segment.empty())
			splitStr.emplace_back(segment);
	}

	void StringType::Parse(const std::vector<std::string>& strs)
	{
		for (auto& str : strs)
			data.emplace_back(Convert2ByteData(str));
	}

	BytesData StringType::Convert2ByteData(const std::string& str)
	{
		BytesData ret;
		ret.length = str.size();
		ret.data.resize((ret.length + 31) / 32);
		for (size_t i = 0; i < str.size(); i += 32)
		{
			evmc::bytes32 tmp(0);
			// copy 32 bytes at a time into tmp, if there aren't 32 bytes left, copy the rest
			std::memcpy(tmp.bytes, str.data() + i, std::min(static_cast<size_t>(32), str.size() -i + 1));
			std::copy(std::begin(tmp.bytes), std::end(tmp.bytes), std::begin(ret.data[i / 32].bytes));
		}

		// If length is not a multiple of 32, pad the last element with zeroes
		if (ret.length % 32 != 0)
		{
			for (size_t i = ret.length % 32; i < 32; ++i)
			{
				ret.data.back().bytes[i] = 0;
			}
		}

		return ret;
	}

	FixedBytesType::FixedBytesType(const std::string& fixedBytes, bool _dynamic)
		: ElementType(Type::FixedBytes, _dynamic)
	{
		std::vector<std::string> splitFixedBytes;
		SplitString(fixedBytes, splitFixedBytes);
		Parse(splitFixedBytes);
	}

	std::vector<uint8_t> FixedBytesType::GetEncodedData()
	{
		std::vector<uint8_t> ret;
		ret.resize(GetEncodedDataLength());

		auto ret_it = ret.begin();
		if (isDynamicArray)
		{
			evmc::bytes32 len(data.size());
			ret_it = std::copy(std::begin(len.bytes), std::end(len.bytes), ret_it);
		}

		for (auto& bytes : data)
			ret_it = std::copy(std::begin(bytes.bytes), std::end(bytes.bytes), ret_it);

		return ret;
	}

	void FixedBytesType::Parse(std::vector<std::string>& fixedBytes)
	{
		for (auto& fixedByte : fixedBytes)
			data.emplace_back(Convert2EvmcBytes(fixedByte));
	}

	evmc::bytes32 FixedBytesType::Convert2EvmcBytes(const std::string& fixedByte)
	{
		if (fixedByte.size() < 2 || (fixedByte.size() % 2) || fixedByte[0] != '0' || fixedByte[1] != 'x')
		{
			throw std::invalid_argument("Invalid fixedByte format");
		}

		// Remove the '0x' prefix
		std::string raw = fixedByte.substr(2);

		evmc::bytes32 ret(0);

		for (size_t j = 0; j < raw.size(); j += 2)
		{
			int hex_byte = std::stoi(raw.substr(j, 2), nullptr, 16);
			ret.bytes[j / 2] = static_cast<uint8_t>(hex_byte);
		}

		return ret;
	}


	AddressType::AddressType(std::string addressString, bool _dynamic)
		:FixedBytesType(_dynamic)
	{
		type = Type::Address;
		std::vector<std::string> splitAddress;
		SplitString(addressString, splitAddress);
		Parse(splitAddress);
	}

	void AddressType::Parse(const std::vector<std::string>& addressTypes)
	{
		for (auto& addressType : addressTypes)
			data.emplace_back(Convert2EvmcBytes(addressType));
	}

	evmc::bytes32 AddressType::Convert2EvmcBytes(const std::string& addressType)
	{
		if (addressType.size() == 42 && addressType[0] != '0' && addressType[1] != 'x')
		{
			throw std::invalid_argument("Invalid address string format");
		}

		evmc::bytes32 ret(0);

		if(addressType.size() == 42 && addressType[0] == '0' && addressType[1] == 'x'){
			// Remove the '0x' prefix
			std::string raw = addressType.substr(2);

			for (size_t j = 0; j < raw.size(); j += 2)
			{
				int hex_byte = std::stoi(raw.substr(j, 2), nullptr, 16);
				ret.bytes[j / 2 + 12] = static_cast<uint8_t>(hex_byte);
			}
		}
		else{
			uint64_t addr = std::stoull(addressType.c_str());
			ret = evmc::bytes32(addr);
		}
		return ret;
	}

	BoolType::BoolType(const std::string& boolString, bool _dynamic)
		:FixedBytesType(_dynamic)
	{
		type = Type::Bool;
		std::vector<std::string> splitBool;
		SplitString(boolString, splitBool);
		Parse(splitBool);
	}

	void BoolType::Parse(const std::vector<std::string>& boolTypes)
	{
		for (auto& boolType : boolTypes)
			data.emplace_back(Convert2EvmcBytes(boolType));
	}

	evmc::bytes32 BoolType::Convert2EvmcBytes(const std::string& boolType)
	{
		return "true" == boolType ? evmc::bytes32(1) : evmc::bytes32(0);
	}

	UintType::UintType(const std::string& uintString, bool _dynamic)
		:FixedBytesType(_dynamic)
	{
		type = Type::Uint;
		std::vector<std::string> splitUint;
		SplitString(uintString, splitUint);
		Parse(splitUint);
	}

	void UintType::Parse(const std::vector<std::string>& uintTypes)
	{
		for (auto& uintType : uintTypes)
			data.emplace_back(Convert2EvmcBytes(uintType));
	}

	evmc::bytes32 UintType::Convert2EvmcBytes(const std::string& uintType)
	{
		evmc::bytes32 ret(0);
		if (uintType == "0")
			return ret;
		std::string str(uintType);
		uint8_t cnt = 0;
		while (str != "0")
		{
			ret.bytes[31 - cnt / 8] |= (addsToOne(str) << (cnt % 8));
			divByTwo(str);
			++cnt;
		}
		return ret;
	}

	uint8_t UintType::addsToOne(std::string& str)
	{
		if (str.empty())
			throw std::invalid_argument("Invalid addsToOne format");

		return (str.back() - '0') % 2;
	}

	uint8_t UintType::addsToOne(uint8_t s)
	{
		return (s - '0') % 2;
	}

	void UintType::divByTwo(std::string& str)
	{
		uint8_t additive = 0, newDigit = 0;
		for (auto& s : str)
		{
			newDigit = (s - '0') / 2 + additive + '0';
			additive = addsToOne(s) * 5;
			s = newDigit;
		}
		if ('0' == str[0] && str.size() > 1)
			str = str.substr(1);
	}

	StructType::StructType(std::vector<Type> types, const std::string& structStr, bool _dynamic)
		:ElementType(Type::Struct, _dynamic)
	{
		structTypes = types;
		std::vector<std::vector<std::string>> splitStruct;
		SplitString(structStr, splitStruct);
		Parse(splitStruct);
	}

	StructType::~StructType()
	{
		for (auto& types : data)
		{
			for (auto type : types)
				delete type;
		}
	}

	std::vector<uint8_t> StructType::GetEncodedData()
	{
		std::vector<uint8_t> ret;
		if (data.empty()) return ret;

		uint32_t retLength = 0, structLen = 0;
		if (isDynamicArray) retLength += BYTES32;
		for (auto elem : data[0])
			structLen += elem->GetEncodedDataLength();
		retLength += structLen * data.size();
		ret.resize(retLength);

		auto ret_it = ret.begin();
		if (isDynamicArray)
		{
			evmc::bytes32 len(data.size());
			ret_it = std::copy(std::begin(len.bytes), std::end(len.bytes), ret_it);
		}

		std::vector<uint8_t> encodedData;
		encodedData.resize(structLen);
		for (auto& types : data)
		{
			auto data_it = encodedData.begin();
			for (auto type : types)
			{
				std::vector<uint8_t> data = type->GetEncodedData();
				data_it = std::copy(std::begin(data), std::end(data), data_it);
			}
			ret_it = std::copy(std::begin(encodedData), std::end(encodedData), ret_it);
		}
		return ret;
	}

	uint32_t StructType::GetEncodedDataLength()
	{
		if (data.empty()) return 0;
		uint32_t ret = 0, length = 0;
		if (isDynamicArray) ret += BYTES32;

		for (auto elem : data[0])
			length += elem->GetEncodedDataLength();
		ret += length * data.size();

		return ret;
	}

	void StructType::SplitString(const std::string& structStr, std::vector<std::vector<std::string>>& splitStrs)
	{
		std::string segment;
		bool withinBrackets = false;

		for (char ch : structStr)
		{
			if (ch == '{')
				withinBrackets = true;
			else if (ch == '}')
			{
				std::vector<std::string> splitSegment;
				ElementType::SplitString(segment, splitSegment);
				splitStrs.emplace_back(splitSegment);
				withinBrackets = false;
				segment.clear();
			}
			else if (withinBrackets)
				segment += ch;
		}
	}

	void StructType::Parse(const std::vector<std::vector<std::string>>& splitStrs)
	{
		for (auto& splitStr : splitStrs)
		{
			if (splitStr.size() != structTypes->size())
				continue;
			std::vector<FixedBytesType*> pTypes;
			FixedBytesType* pType = nullptr;
			for (size_t i = 0; i < splitStr.size(); ++i)
			{
				switch (structTypes->at(i))
				{
				case Address:
					pType = new AddressType(splitStr[i]);
					pTypes.push_back(pType);
					break;
				case Bool:
					pType = new BoolType(splitStr[i]);
					pTypes.push_back(pType);
					break;
				case Uint:
					pType = new UintType(splitStr[i]);
					pTypes.push_back(pType);
					break;
				default:
					break;
				}
			}
			data.emplace_back(pTypes);
		}
	}
	void EVMEncoder::GetAbi(std::string abiPath)
	{
		std::ifstream file(abiPath);
		if (!file.is_open()) {
			throw std::runtime_error("Could not open file " + abiPath);
		}
		// split functions
		std::vector<std::string> abi_json_funcs;
		std::string line;
		std::getline(file, line);
		nlohmann::json data = nlohmann::json::parse(line);
		for(size_t i = 0; i < data.size(); ++i){
			std::string name = data[i]["name"];
			if(_Functions.find(name) == _Functions.end())
				continue;
			const auto& inputs = data[i]["inputs"];
			auto& params = _Opcode2FunctionSig[_Functions[name]._ByteCode]._Parameters;
			for(size_t j = 0; j < inputs.size(); ++j)
				params[j] = inputs[j]["name"];
		}
	}

	void EVMEncoder::GetFunctionSignatures(std::string signaturePath)
	{
		std::ifstream file(signaturePath);
		if (!file.is_open()) {
			throw std::runtime_error("Could not open file " + signaturePath);
		}
		auto slashPos = signaturePath.find_last_of('/');
		auto dotPos = signaturePath.find_last_of('.');
		std::string contract_name = slashPos == std::string::npos? signaturePath : signaturePath.substr(slashPos + 1, dotPos - slashPos - 1);
		std::string line;
		// Skip the first line
		std::getline(file, line);

		while (std::getline(file, line)) {
			if (!line.size() || "Function signatures:" == line || "Event signatures:" == line)
				continue;
			FunctionSignature ret;

			auto pos = line.find(":");
			ret._ByteCode = line.substr(0, pos);
			std::string rest = line.substr(pos + 2);

			pos = rest.find("(");
			ret._Name = rest.substr(0, pos);

			std::string parameters = rest.substr(pos + 1);
			parameters.pop_back();

			pos = 0;
			size_t pre = pos;
			bool cut = true;
			while (pos < parameters.size())
			{
				if ('(' == parameters[pos])
					cut = false;
				else if (')' == parameters[pos])
					cut = true;
				else if (',' == parameters[pos] && cut)
				{
					ret._Parameters.emplace_back(parameters.substr(pre, pos - pre));
					pre = pos + 1;
				}
				++pos;
			}
			if(parameters.size()) ret._Parameters.emplace_back(parameters.substr(pre));

			for (auto& str : ret._Parameters)
			{
				ret._ParamTypes.emplace_back(ElementType(str));
			}

			_Functions[ret._Name] = ret;
			_Opcode2FunctionSig[ret._ByteCode] = ret;
			_OpCode2Function[ret._ByteCode] = std::make_pair(contract_name, ret._Name);
		}
		file.close();
	}

	std::vector<uint8_t> EVMEncoder::GetEncodedData(std::string functionName, const std::vector<std::string>& args)
	{
		std::vector<uint8_t> ret;
		if ("" == functionName || _Functions.find(functionName) == _Functions.end()) 
			return ret;
		std::vector<ElementType>& paramTypes = _Functions[functionName]._ParamTypes;
		if (paramTypes.size() != args.size())
			throw std::invalid_argument("invalid encode data args");

		ret.resize(4 + args.size() * BYTES32);
		std::vector<uint8_t> dynamic_bytes;
		std::vector<uint8_t> functionEncodeData = hex2uint8(_Functions[functionName]._ByteCode);
		auto static_it = std::copy(functionEncodeData.begin(), functionEncodeData.end(), ret.begin());
		auto dynamic_offset = args.size() * BYTES32;

		for (size_t i = 0; i < args.size(); ++i)
		{
			std::vector<uint8_t> byteCodes;
			switch (paramTypes[i].type)
			{
			case sol::Address:
			{
				AddressType addressType(args[i], paramTypes[i].isDynamicArray);
				byteCodes = addressType.GetEncodedData();
			}
			break;
			case sol::Bool:
			{
				BoolType boolType(args[i], paramTypes[i].isDynamicArray);
				byteCodes = boolType.GetEncodedData();
			}
			break;
			case sol::Bytes:
			{
				BytesType bytesType(args[i], paramTypes[i].isDynamicArray);
				byteCodes = bytesType.GetEncodedData();
			}
			break;
			case sol::FixedBytes:
			{
				FixedBytesType fixedBytesType(args[i], paramTypes[i].isDynamicArray);
				byteCodes = fixedBytesType.GetEncodedData();
			}
			break;
			case sol::String:
			{
				StringType stringType(args[i], paramTypes[i].isDynamicArray);
				byteCodes = stringType.GetEncodedData();
			}
			break;
			case sol::Struct:
			{
				StructType structType(*paramTypes[i].structTypes, args[i], paramTypes[i].isDynamicArray);
				byteCodes = structType.GetEncodedData();
			}
			break;
			case sol::Uint:
			{
				UintType uintType(args[i], paramTypes[i].isDynamicArray);
				byteCodes = uintType.GetEncodedData();
			}
			break;
			default:
				break;
			}
			if (paramTypes[i].isDynamicArray || sol::String == paramTypes[i].type || sol::Bytes == paramTypes[i].type)
			{
				evmc::bytes32 offset(dynamic_offset);
				static_it = std::copy(std::begin(offset.bytes), std::end(offset.bytes), static_it);
				dynamic_bytes.insert(dynamic_bytes.end(), byteCodes.begin(), byteCodes.end());
				dynamic_offset += byteCodes.size();
			}
			else
				static_it = std::copy(byteCodes.begin(), byteCodes.end(), static_it);
		}
		ret.insert(ret.end(), dynamic_bytes.begin(), dynamic_bytes.end());
		return ret;
	}

	std::vector<uint8_t> EVMEncoder::GetEncodedData(const std::string& typeStr, Type type, bool _dynamic)
	{
		switch (type)
		{
		case sol::Address:
		{
			AddressType addressType(typeStr, _dynamic);
			return addressType.GetEncodedData();
		}
		case sol::Bool:
		{
			BoolType boolType(typeStr, _dynamic);
			return boolType.GetEncodedData();
		}
		case sol::Bytes:
		{
			BytesType bytesType(typeStr, _dynamic);
			return bytesType.GetEncodedData();
		}
		case sol::FixedBytes:
		{
			FixedBytesType fixedBytesType(typeStr, _dynamic);
			return fixedBytesType.GetEncodedData();
		}
		case sol::String:
		{
			StringType stringType(typeStr, _dynamic);
			return stringType.GetEncodedData();
		}
		case sol::Uint:
		{
			UintType uintType(typeStr, _dynamic);
			return uintType.GetEncodedData();
		}
		default:
			return std::vector<uint8_t>();
		}
	}

	std::vector<uint8_t> EVMEncoder::GetFunctionSignatureHash(std::string functionName)
	{
		std::vector<uint8_t> ret;
		if ("" == functionName || _Functions.find(functionName) == _Functions.end()) 
			return ret;
		return hex2uint8(_Functions[functionName]._ByteCode);
	}

	bool EVMEncoder::GetContractFunction(std::string opcode, std::pair<std::string, std::string>& out)
	{
		if(_OpCode2Function.find(opcode) == _OpCode2Function.end())
			return false;
		out = _OpCode2Function[opcode];
		return true;
	}

	std::string EVMEncoder::GetDecodedString(evmc::bytes32 event_sig, const uint8_t* data, size_t data_size)
	{
		char buffer[65];
		char* tmp = &buffer[0];
		const size_t evm_byte_size = 32;
		for(size_t i = 0; i < 32; ++i){
			snprintf(tmp, 3, "%02x", static_cast<unsigned int>(event_sig.bytes[i]));
			tmp += 2;
		}
		std::string opCode(buffer);
		if(_Opcode2FunctionSig.find(opCode) == _Opcode2FunctionSig.end()) 
			return "";
		nlohmann::json json;
		json["event"] = _Opcode2FunctionSig[opCode]._Name;

		for(size_t i = 0; i < _Opcode2FunctionSig[opCode]._ParamTypes.size(); ++i){
			const auto& type = _Opcode2FunctionSig[opCode]._ParamTypes[i];
			nlohmann::json value;
			const uint8_t* data_ptr = data + evm_byte_size * i;
			if (type.isDynamicArray) data_ptr = data + evmc::load32be(data_ptr + 28);
			switch (type.type)
			{
			case Address:
			{
				auto addrBytes2Str = [](const uint8_t* p){
					char addr[45] = "0x";
					char* tmp = &addr[2];
					p += 12;
					for (size_t i = 0; i < 20; ++i) {
						snprintf(tmp, 3, "%02x", static_cast<unsigned int>(p[i]));
						tmp += 2;
					}
					return std::string(addr);
				};
				if (type.isDynamicArray) {
					uint32_t length = evmc::load32be(data_ptr + 28);
					data_ptr += evm_byte_size;
					for (size_t i = 0; i < length; ++i)
					{
						value[i] = addrBytes2Str(data_ptr);
						data_ptr += evm_byte_size;
					}
				}
				else {
					value = addrBytes2Str(data_ptr);
				}
			}
				break;
			case Bool:
			{
				auto boolBytes2Str = [](const uint8_t* p) {
					evmc::bytes32 b(0);
					if (!memcmp(p, b.bytes, 32))
						return "false";
					return "true";
				};
				if (type.isDynamicArray) {
					uint32_t length = evmc::load32be(data_ptr + 28);
					data_ptr += evm_byte_size;
					for (size_t i = 0; i < length; ++i)
					{
						value[i] = boolBytes2Str(data_ptr);
						data_ptr += evm_byte_size;
					}
				}
				else {
					value = boolBytes2Str(data_ptr);
				}
			}
				break;
			case String:
			{
				uint32_t length = evmc::load32be(data_ptr + 28);
				data_ptr = data + length;
				auto stringBytes2Str = [](const uint8_t* p) {
					return std::string((char*)(p + 32));
				};
				if (type.isDynamicArray) {

					uint32_t length = evmc::load32be(data_ptr + 28);
					data_ptr += evm_byte_size;
					const uint8_t* p = data_ptr;
					for (size_t i = 0; i < length; ++i)
					{
						p = data_ptr + evmc::load32be(data_ptr + evm_byte_size * i + 28);
						value[i] = stringBytes2Str(p);
					}
				}
				else {
					value = stringBytes2Str(data_ptr);
				}
			}
				break;
			case Uint:
			{
				auto uintBytes2Str = [](const uint8_t* p) {
					evmc::bytes32 u(0);
					if (!memcmp(p, u.bytes, 24)) {
						uint64_t var = evmc::load64be(p + 24);
						return std::to_string(var);
					}
					else {
						char buff[67] = "0x";
						char* tmp = &buff[2];
						for (size_t i = 0; i < 32; ++i) {
							snprintf(tmp, 3, "%02x", static_cast<unsigned int>(p[i]));
							tmp += 2;
						}
						return std::string(buff);
					}
				};
				if (type.isDynamicArray)
				{
					uint32_t length = evmc::load32be(data_ptr + 28);
					data_ptr += evm_byte_size;
					for (size_t i = 0; i < length; ++i)
					{
						value[i] = uintBytes2Str(data_ptr);
						data_ptr += evm_byte_size;
					}
				}
				else
					value = uintBytes2Str(data_ptr);
			}
				break;
			default:
				break;
			}
			std::string key = _Opcode2FunctionSig[opCode]._Parameters[i];
			json["data"][key] = value;
		}
		return json.dump();
	}

	uint8_t char2int(char input) {
		if (input >= '0' && input <= '9')
			return input - '0';
		if (input >= 'A' && input <= 'F')
			return input - 'A' + 10;
		if (input >= 'a' && input <= 'f')
			return input - 'a' + 10;
		throw std::invalid_argument("Invalid input string");
	}

	std::vector<uint8_t> hex2uint8(std::string& s) {
		if (s.size() % 2 != 0) {
			s = "0" + s;
		}

		std::vector<uint8_t> uint_vec(s.size() / 2);
		for (size_t i = 0; i < s.size(); i += 2) {
			uint_vec[i / 2] = (char2int(s[i]) << 4) | char2int(s[i + 1]);
		}

		return uint_vec;
	}
	void EVMDecoder::ParseTypesFromLayout(const std::string& typeStr, StateVariable& var)
	{
		nlohmann::json data = nlohmann::json::parse(_StorageLayout);
		auto type_json = data["types"];
		if (typeStr == "t_address")
		{
			var.type = Type::Address;
		}
		else if (typeStr.substr(0,6) == "t_uint")
		{
			var.type = Type::Uint;
		}
		else if (typeStr == "t_string_storage")
		{
			var.type = Type::String;
		}
		else if(typeStr.substr(0,8) == "t_struct")
		{
			var.type = Type::Struct;
			auto struct_detail = type_json[typeStr]["members"];
			for (uint32_t i = 0; i < struct_detail.size(); i++)
			{
				StateVariable structMember;
				structMember.label = struct_detail[i]["label"];
				structMember.offset = struct_detail[i]["offset"];
				structMember.slot = std::stoi(std::string(struct_detail[i]["slot"]));
				ParseTypesFromLayout(struct_detail[i]["type"], structMember);
				var.NestingTypeExpansion.push_back(structMember);
				//TODO
				var.isDynamicArray = false;
			}
		}
		else if (typeStr.substr(0, 9) == "t_mapping")
		{
			var.type = Type::Map;
			std::string keyType = type_json[typeStr]["key"];
			std::string valType = type_json[typeStr]["value"];
			StateVariable keyMember;
			ParseTypesFromLayout(keyType, keyMember);
			var.NestingTypeExpansion.push_back(keyMember);
			StateVariable valMember;
			ParseTypesFromLayout(valType, valMember);
			var.NestingTypeExpansion.push_back(valMember);
			//TODO
			var.isDynamicArray = false;
		}
	}
	void EVMDecoder::Init(const std::string& storageLayoutPath)
	{
		std::ifstream f(storageLayoutPath);
		std::string storageLayoutJson(std::istreambuf_iterator<char>(f), (std::istreambuf_iterator<char>()));
		_StorageLayout = storageLayoutJson;
		nlohmann::json data = nlohmann::json::parse(storageLayoutJson);
		auto storage_json = data["storage"];
		for (auto s : storage_json)
		{
			StateVariable var;
			var.label = s["label"];
			var.slot = std::stoi(std::string(s["slot"]));
			var.offset = s["offset"];
			ParseTypesFromLayout(s["type"], var);
			_StateVariables.push_back(var);
			//TODO
			var.isDynamicArray = false;
		}
		auto types_json = data["types"];
	}

} // namespace sol
