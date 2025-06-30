#pragma once
#include "ExtendSolidityBaseListener.h"
#include "CodeSerializer.h"
#include "ExtendSolidityTreeWalker.h"

#define _LOG(str) std::cout << str << std::endl

enum ExtendSolidityExpressionType
{
    postOperation,
    bracket,
    functionCall,
    dot,
    parentheses,
    preOperation,
    newOperation,
    midOperation,
    TernaryConditional,
    primary
};

class CustomErrorListener : public antlr4::BaseErrorListener {
public:
	virtual void syntaxError(antlr4::Recognizer *recognizer, antlr4::Token *offendingSymbol, size_t line, size_t charPositionInLine,
		const std::string &msg, std::exception_ptr e) override{    
		p_errors.push_back(err_file_path + ":" + std::to_string(line) + ":" + std::to_string(charPositionInLine) + ": " + msg);
    }
	std::vector<std::string> p_errors;
	std::string err_file_path;
};

class ExtendSolidityRealListener :
    public ExtendSolidityBaseListener
{
public:
    std::string GetStandardSolidityCode() { return m_codeSerializer.GetCode(); }
public:
    virtual void enterSourceUnit(ExtendSolidityParser::SourceUnitContext* /*ctx*/) override;
    virtual void exitSourceUnit(ExtendSolidityParser::SourceUnitContext* /*ctx*/) override;
    virtual void enterContractDefinition(ExtendSolidityParser::ContractDefinitionContext* /*ctx*/) override;
    virtual void exitContractDefinition(ExtendSolidityParser::ContractDefinitionContext* /*ctx*/) override;
    
    virtual void enterBlock(ExtendSolidityParser::BlockContext* /*ctx*/) override;
    virtual void exitBlock(ExtendSolidityParser::BlockContext* /*ctx*/) override;
    virtual void enterIfWithBlock(ExtendSolidityParser::IfWithBlockContext* /*ctx*/) override;
    virtual void exitIfWithBlock(ExtendSolidityParser::IfWithBlockContext* /*ctx*/) override;
    virtual void enterElseIfWithBlock(ExtendSolidityParser::ElseIfWithBlockContext* /*ctx*/) override;
    virtual void exitElseIfWithBlock(ExtendSolidityParser::ElseIfWithBlockContext* /*ctx*/) override;
    virtual void enterElseWithBlock(ExtendSolidityParser::ElseWithBlockContext* /*ctx*/) override;
    virtual void exitElseWithBlock(ExtendSolidityParser::ElseWithBlockContext* /*ctx*/) override;
    virtual void enterWhileStatement(ExtendSolidityParser::WhileStatementContext* /*ctx*/) override;
    virtual void exitWhileStatement(ExtendSolidityParser::WhileStatementContext* /*ctx*/) override;
    virtual void enterForStatement(ExtendSolidityParser::ForStatementContext* /*ctx*/) override;
    virtual void exitForStatement(ExtendSolidityParser::ForStatementContext* /*ctx*/) override;
    virtual void enterInlineAssemblyStatement(ExtendSolidityParser::InlineAssemblyStatementContext* /*ctx*/) override;
    virtual void exitInlineAssemblyStatement(ExtendSolidityParser::InlineAssemblyStatementContext* /*ctx*/) override;
    virtual void enterDoWhileStatement(ExtendSolidityParser::DoWhileStatementContext* /*ctx*/) override;
    virtual void exitDoWhileStatement(ExtendSolidityParser::DoWhileStatementContext* /*ctx*/) override;
    virtual void enterFunctionDefinition(ExtendSolidityParser::FunctionDefinitionContext* /*ctx*/) override;
    virtual void exitFunctionDefinition(ExtendSolidityParser::FunctionDefinitionContext* /*ctx*/) override;

    virtual void enterContinueStatement(ExtendSolidityParser::ContinueStatementContext* /*ctx*/) override;
    virtual void enterBreakStatement(ExtendSolidityParser::BreakStatementContext* /*ctx*/) override;
    virtual void enterReturnStatement(ExtendSolidityParser::ReturnStatementContext* /*ctx*/) override;
    virtual void enterThrowStatement(ExtendSolidityParser::ThrowStatementContext* /*ctx*/) override;
    virtual void enterEmitStatement(ExtendSolidityParser::EmitStatementContext* /*ctx*/) override;
    virtual void enterRelayStatement(ExtendSolidityParser::RelayStatementContext* /*ctx*/) override;
	virtual void enterRelayLambdaDefinition(ExtendSolidityParser::RelayLambdaDefinitionContext* ctx) override;
    virtual void exitRelayLambdaDefinition(ExtendSolidityParser::RelayLambdaDefinitionContext* /*ctx*/) override;
    virtual void enterExpressionStatement(ExtendSolidityParser::ExpressionStatementContext* /*ctx*/) override;
    virtual void enterLocalVariableDeclaration(ExtendSolidityParser::LocalVariableDeclarationContext* /*ctx*/) override;
	virtual void enterVariableDeclarationStatement(ExtendSolidityParser::VariableDeclarationStatementContext* ctx) override;

private:
    void DefineStateVariable(ExtendSolidityParser::StateVariableDeclarationContext* /*ctx*/);
    void DefineStruct(ExtendSolidityParser::StructDefinitionContext* /*ctx*/);
    void DefineEnum(ExtendSolidityParser::EnumDefinitionContext* /*ctx*/);
    void DeclareFunction(ExtendSolidityParser::FunctionDefinitionContext* /*ctx*/);
    void SearchForCalledRelayFunctions(ExtendSolidityParser::BlockContext* /*ctx*/);
	void DefineEvent(ExtendSolidityParser::EventDefinitionContext* ctx);
    void DefineFunctions();
    void DefineGetShardOrderFunction();
	void DeclareRelayLambdaFunction(ExtendSolidityParser::RelayLambdaDefinitionContext* ctx);

    std::string ProcessParameterList(ExtendSolidityParser::ParameterListContext* /*ctx*/);
    std::string ProcessExpression(ExtendSolidityParser::ExpressionContext* /*ctx*/);
    std::string ProcessPrimaryExpression(ExtendSolidityParser::PrimaryExpressionContext* /*ctx*/);
    std::string ProcessIdentifier_Interval(ExtendSolidityParser::IdentifierContext* /*ctx*/);
    std::string ProcessExpressionList(ExtendSolidityParser::ExpressionListContext* /*ctx*/);
    std::string ProcessFunctionCallArguments(ExtendSolidityParser::FunctionCallArgumentsContext* /*ctx*/);
    std::string ProcessNameValue(ExtendSolidityParser::NameValueContext* /*ctx*/);
    std::string ProcessNameValueList(ExtendSolidityParser::NameValueListContext* /*ctx*/);
    std::string ProcessTupleExpression(ExtendSolidityParser::TupleExpressionContext* /*ctx*/);
    std::string ProcessLocalVariableDeclaration(ExtendSolidityParser::LocalVariableDeclarationContext* /*ctx*/);
    std::string ProcessVariableDeclaration(ExtendSolidityParser::VariableDeclarationContext* /*ctx*/);
    std::string ProcessVariableDeclarationList(ExtendSolidityParser::VariableDeclarationListContext* /*ctx*/);
    std::string ProcessIdentifierList(ExtendSolidityParser::IdentifierListContext* /*ctx*/);
    std::string ProcessDotExpressionInternal(ExtendSolidityParser::ExpressionContext* /*ctx*/);

	bool ResolveExpressionTypeName(ExtendSolidityParser::ExpressionContext* ctx, std::string& out);
	bool ResolveIdentifierTypeName(ExtendSolidityParser::IdentifierContext* ctx, std::string& out);
private:
    CodeSerializer m_codeSerializer;
    ExtendSolidityTreeWalker* m_pWalker = nullptr;
    std::map<std::string, ExtendSolidityParser::StateVariableDeclarationContext*> m_stateVariables;
	std::map<std::string, std::map<std::string, std::string>> m_structDefinitions;
    std::vector<ExtendSolidityParser::FunctionDefinitionContext* > m_functions;
	std::vector<ExtendSolidityParser::RelayLambdaDefinitionContext*> m_relayLambdaFunctions;
	std::map<ExtendSolidityParser::RelayLambdaDefinitionContext*, std::pair<std::string, std::string>> m_declaredRelayLambdaFunctions;
	std::stack<std::map<std::string, std::string>> m_stackBlockLocalVariables;
	std::stack<std::map<std::string, std::string>> m_stackFunctionLocalVariables;
    std::map<std::string, std::string> m_functionDeclarations;
    std::set<std::string> m_calledRelayFunctions;
    bool m_getShardOrder = false;
	bool m_bGenerateCode = false;
	bool m_bPushBlockStack = true;
	bool m_bPopBlockStack = true;

public:
    void SetWalker(ExtendSolidityTreeWalker* pWalker)
    {
        m_pWalker = pWalker;
    }
};

