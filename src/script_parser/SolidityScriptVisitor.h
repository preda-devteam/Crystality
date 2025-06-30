
// Generated from SolidityScript.g4 by ANTLR 4.12.0

#pragma once


#include "antlr4-runtime.h"
#include "SolidityScriptParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by SolidityScriptParser.
 */
class  SolidityScriptVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by SolidityScriptParser.
   */
    virtual std::any visitSource(SolidityScriptParser::SourceContext *context) = 0;

    virtual std::any visitScript(SolidityScriptParser::ScriptContext *context) = 0;

    virtual std::any visitVariableDeclaration(SolidityScriptParser::VariableDeclarationContext *context) = 0;

    virtual std::any visitFunctionCall(SolidityScriptParser::FunctionCallContext *context) = 0;

    virtual std::any visitVizTrace(SolidityScriptParser::VizTraceContext *context) = 0;

    virtual std::any visitChainParams(SolidityScriptParser::ChainParamsContext *context) = 0;

    virtual std::any visitContractName(SolidityScriptParser::ContractNameContext *context) = 0;

    virtual std::any visitDeployAddress(SolidityScriptParser::DeployAddressContext *context) = 0;

    virtual std::any visitInputCSV(SolidityScriptParser::InputCSVContext *context) = 0;

    virtual std::any visitCount(SolidityScriptParser::CountContext *context) = 0;

    virtual std::any visitScope(SolidityScriptParser::ScopeContext *context) = 0;

    virtual std::any visitArguments(SolidityScriptParser::ArgumentsContext *context) = 0;

    virtual std::any visitArgument(SolidityScriptParser::ArgumentContext *context) = 0;

    virtual std::any visitExplicitTypeValue(SolidityScriptParser::ExplicitTypeValueContext *context) = 0;

    virtual std::any visitType(SolidityScriptParser::TypeContext *context) = 0;

    virtual std::any visitIdentifier(SolidityScriptParser::IdentifierContext *context) = 0;

    virtual std::any visitExpression(SolidityScriptParser::ExpressionContext *context) = 0;

    virtual std::any visitRandomCall(SolidityScriptParser::RandomCallContext *context) = 0;

    virtual std::any visitStringArray(SolidityScriptParser::StringArrayContext *context) = 0;

    virtual std::any visitStructArray(SolidityScriptParser::StructArrayContext *context) = 0;

    virtual std::any visitRandomCallCount(SolidityScriptParser::RandomCallCountContext *context) = 0;

    virtual std::any visitRandomCallArguments(SolidityScriptParser::RandomCallArgumentsContext *context) = 0;

    virtual std::any visitNumberLiteral(SolidityScriptParser::NumberLiteralContext *context) = 0;

    virtual std::any visitMatchedParentheses(SolidityScriptParser::MatchedParenthesesContext *context) = 0;

    virtual std::any visitSolFile(SolidityScriptParser::SolFileContext *context) = 0;

    virtual std::any visitXtlFile(SolidityScriptParser::XtlFileContext *context) = 0;

    virtual std::any visitDirectivePath(SolidityScriptParser::DirectivePathContext *context) = 0;

    virtual std::any visitBoolLiteral(SolidityScriptParser::BoolLiteralContext *context) = 0;


};

