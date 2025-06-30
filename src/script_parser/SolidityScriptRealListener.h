#pragma once
#include "SolidityScriptBaseListener.h"
#include "SolidityScriptTreeWalker.h"
#include "../EVMScriptRunner.h"
#include "../EVMSimulator.h"
#include <mutex>

namespace sol
{

enum SolidityScriptExpressionType
{
    evmcAddress = 0, 
    randomCall,
    dotExpression,
    numberLiteral,
    boolLiteral,
    stringLiteral,
    stringArray,
    structArray,
    identifier
};

class SolidityScriptRealListener :
    public SolidityScriptBaseListener
{
    SolidityScriptTreeWalker* _Walker;
    sol::Randomizer* _Randomizer;
    sol::StopWatch* _Watch;
    sol::EVMSimulator* _Simulator;

    std::map<std::string, evmc::address> _Contracts;

    struct SolUser {
        evmc::address   addr;
        uint8_t         pk[32];
        uint8_t         sk[64];
    };
    std::vector<SolUser>                _Users;
    std::map<evmc::address, SolUser>    _UserMap;

    std::map<std::string, std::vector<std::string>> _LocalVariables;
	std::map<std::string, std::vector<EVMTxn*>> _Txns;
	std::mutex _TxnLock;
    uint32_t _ShardOrder;
    std::string _ScriptDir;
    std::string json;
public:
    SolidityScriptRealListener(uint32_t order = 2):_Walker(nullptr), _Randomizer(new sol::Randomizer(5)), _Watch(new sol::StopWatch), _Simulator(new sol::EVMSimulator), _ShardOrder(order) {}
    ~SolidityScriptRealListener() { if (_Randomizer) delete _Randomizer; if (_Watch) delete _Watch; if (_Simulator) delete _Simulator; }
    void SetWalker(SolidityScriptTreeWalker* walker) { _Walker = walker; }
    void SetScriptDir(const std::string& path) { _ScriptDir = path; }
    sol::EVMSimulator* GetSimulator() const { return _Simulator; }
    std::string GetVizJson() const { return json; }
    std::string VizualizeStateVar(const std::string& contract, const std::string& varName, evmc::address* addr);
    std::string GetDecodedState(const evmc::bytes32& storage, const StateVariable& var);

public:
    virtual void enterSource(SolidityScriptParser::SourceContext* /*ctx*/) override;
    virtual void enterScript(SolidityScriptParser::ScriptContext* /*ctx*/) override;
    virtual void enterVariableDeclaration(SolidityScriptParser::VariableDeclarationContext* /*ctx*/) override;
    virtual void enterFunctionCall(SolidityScriptParser::FunctionCallContext* /*ctx*/) override;
    std::string ProcessExpression(SolidityScriptParser::ExpressionContext* /*ctx*/);
    std::string ProcessStringArray(SolidityScriptParser::StringArrayContext* /*ctx*/);
    std::string ProcessStructArray(SolidityScriptParser::StructArrayContext* /*ctx*/);
    uint32_t ProcessCount(SolidityScriptParser::CountContext* /*ctx*/);
    std::vector<std::string> ProcessScope(SolidityScriptParser::ScopeContext* /*ctx*/);
    std::vector<std::string> ProcessRandomCall(SolidityScriptParser::RandomCallContext* /*ctx*/);
    std::vector<std::string> ProcessArguments(SolidityScriptParser::ArgumentsContext* /*ctx*/);
	std::vector<uint8_t> ConvertArguments2Bytes(SolidityScriptParser::ArgumentsContext* /*ctx*/);
	void AddERC20TaskFromCSV(const evmc::address& recipient, std::string csvPath);
	void AddNftTaskFromCSV(const evmc::address& recipient, std::string csvPath);
	void AddUser(const evmc::address& addr);
	void IssueTxn(const evmc_address& sender, const evmc_address& recipient, const std::vector<uint8_t>& msg);
};

}