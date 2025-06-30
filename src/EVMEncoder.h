#pragma once
#include <evmc/evmc.hpp>
#include <evmc/hex.hpp>
#include <vector>
#include <unordered_map>
#include <optional>

#define BYTES32 (32)

namespace sol
{
	enum Type
	{
		Address,
		Bool,
		Bytes,
		FixedBytes,
		String,
		Struct,
		Uint,
		Map
	};

	struct AbstractType
	{
		virtual std::vector<uint8_t> GetEncodedData() = 0;
		virtual uint32_t GetEncodedDataLength() = 0;
	};

	struct ElementType
	{
		bool isDynamicArray;
		Type type;
		std::optional<std::vector<Type>> structTypes;
		ElementType(std::string typeStr);
		ElementType(Type _type, bool _dynamic) :type(_type), isDynamicArray(_dynamic) {}
		virtual void SplitString(const std::string& str, std::vector<std::string>& splitStr);
	private:
		void ParseType(const std::string& str);
		Type ParseNoStructType(const std::string& str);
	};

	struct BytesData
	{
		uint32_t length;
		std::vector<evmc::bytes32> data;
	};

	class BytesType : public AbstractType, public ElementType
	{
	protected:
		std::vector<BytesData> data;
		virtual void Parse(const std::vector<std::string>& bytes);
		virtual BytesData Convert2ByteData(const std::string& byte);
	public:
		BytesType(bool _dynamic = false) : ElementType(Type::Bytes, _dynamic), data() {}
		BytesType(const std::string& bytesStr, bool _dynamic = false);
		virtual std::vector<uint8_t> GetEncodedData();
		virtual uint32_t GetEncodedDataLength();
	};

	class StringType : public BytesType
	{
	public:
		StringType(const std::string& str, bool _dynamic = false);
		virtual Type GetTypeEnum() { return Type::String; }
	protected:
		virtual void SplitString(const std::string& str, std::vector<std::string>& splitStr);
		virtual void Parse(const std::vector<std::string>& strs);
		virtual BytesData Convert2ByteData(const std::string& str);
	};

	class FixedBytesType : public AbstractType, public ElementType
	{
	protected:
		std::vector<evmc::bytes32> data;
		virtual void Parse(std::vector<std::string>& fixedBytes);
		virtual evmc::bytes32 Convert2EvmcBytes(const std::string& fixedByte);
	public:
		FixedBytesType(bool _dynamic = false) : ElementType(Type::FixedBytes, _dynamic), data() {}
		FixedBytesType(const std::string& fixedBytes, bool _dynamic = false);
		virtual std::vector<uint8_t> GetEncodedData();
		virtual uint32_t GetEncodedDataLength() { return (isDynamicArray ? data.size() + 1 : data.size()) * BYTES32; }
	};

	class AddressType : public FixedBytesType
	{
	public:
		AddressType(std::string addressString, bool _dynamic = false);
		virtual evmc::bytes32 Convert2EvmcBytes(const std::string& addressType);
	protected:
		void Parse(const std::vector<std::string>& addresses);
	};

	class BoolType : public FixedBytesType
	{
	public:
		BoolType(const std::string& boolString, bool _dynamic = false);
	protected:
		virtual void Parse(const std::vector<std::string>& bools);
		virtual evmc::bytes32 Convert2EvmcBytes(const std::string& boolType);
	};

	class UintType : public FixedBytesType
	{
	public:
		UintType(const std::string& uintString, bool _dynamic = false);
		virtual evmc::bytes32 Convert2EvmcBytes(const std::string& uintType);
	protected:
		virtual void Parse(const std::vector<std::string>& uints);
	private:
		uint8_t addsToOne(std::string& str);
		uint8_t addsToOne(uint8_t s);
		void divByTwo(std::string& str);
	};

	class StructType : public AbstractType, public ElementType
	{
		std::vector<std::vector<FixedBytesType*>> data;
	public:
		StructType(std::vector<Type> types, const std::string& structStr, bool _dynamic = false);
		virtual ~StructType();
		virtual std::vector<uint8_t> GetEncodedData();
		virtual uint32_t GetEncodedDataLength();
	private:
		void SplitString(const std::string& structStr, std::vector<std::vector<std::string>>& splitStrs);
		void Parse(const std::vector<std::vector<std::string>>& splitStrs);
	};

	struct FunctionSignature
	{
		std::string _Name;
		std::vector<std::string> _Parameters;
		std::vector<ElementType> _ParamTypes;
		std::string _ByteCode;
	};

	class EVMEncoder
	{
		std::unordered_map<std::string, FunctionSignature> _Functions;
		std::unordered_map<std::string, FunctionSignature> _Opcode2FunctionSig;
		std::unordered_map<std::string, std::pair<std::string, std::string>> _OpCode2Function;
	public:
		void GetAbi(std::string abiPaht);
		void GetFunctionSignatures(std::string signaturePath);
		std::vector<uint8_t> GetEncodedData(std::string functionName, const std::vector<std::string>& args);
		std::vector<uint8_t> GetEncodedData(const std::string& typeStr, Type type, bool _dynamic);
		std::vector<uint8_t> GetFunctionSignatureHash(std::string functionName);
		bool GetContractFunction(std::string opcode, std::pair<std::string, std::string>& out);
		std::string GetDecodedString(evmc::bytes32 event_sig, const uint8_t* data, size_t data_size);
	};
	
	struct StateVariable
	{
		std::string label;
		std::vector<StateVariable> NestingTypeExpansion;
		uint32_t offset;
		uint32_t slot;
		Type type;
		bool isDynamicArray;
	};

	class EVMDecoder : public EVMEncoder
	{
	public:
		std::vector<StateVariable> _StateVariables;
		std::string _StorageLayout;
	public:
		void ParseTypesFromLayout(const std::string& typeStr, StateVariable& variableType);
		void Init(const std::string& storageLayoutPath);
	};
	std::vector<uint8_t> hex2uint8(std::string& s);
} // namespace sol