
// Generated from SolidityScript.g4 by ANTLR 4.12.0

#pragma once


#include "antlr4-runtime.h"
#include "SolidityScriptParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by SolidityScriptParser.
 */
class  SolidityScriptListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterSource(SolidityScriptParser::SourceContext *ctx) = 0;
  virtual void exitSource(SolidityScriptParser::SourceContext *ctx) = 0;

  virtual void enterScript(SolidityScriptParser::ScriptContext *ctx) = 0;
  virtual void exitScript(SolidityScriptParser::ScriptContext *ctx) = 0;

  virtual void enterVariableDeclaration(SolidityScriptParser::VariableDeclarationContext *ctx) = 0;
  virtual void exitVariableDeclaration(SolidityScriptParser::VariableDeclarationContext *ctx) = 0;

  virtual void enterFunctionCall(SolidityScriptParser::FunctionCallContext *ctx) = 0;
  virtual void exitFunctionCall(SolidityScriptParser::FunctionCallContext *ctx) = 0;

  virtual void enterVizTrace(SolidityScriptParser::VizTraceContext *ctx) = 0;
  virtual void exitVizTrace(SolidityScriptParser::VizTraceContext *ctx) = 0;

  virtual void enterChainParams(SolidityScriptParser::ChainParamsContext *ctx) = 0;
  virtual void exitChainParams(SolidityScriptParser::ChainParamsContext *ctx) = 0;

  virtual void enterContractName(SolidityScriptParser::ContractNameContext *ctx) = 0;
  virtual void exitContractName(SolidityScriptParser::ContractNameContext *ctx) = 0;

  virtual void enterDeployAddress(SolidityScriptParser::DeployAddressContext *ctx) = 0;
  virtual void exitDeployAddress(SolidityScriptParser::DeployAddressContext *ctx) = 0;

  virtual void enterInputCSV(SolidityScriptParser::InputCSVContext *ctx) = 0;
  virtual void exitInputCSV(SolidityScriptParser::InputCSVContext *ctx) = 0;

  virtual void enterCount(SolidityScriptParser::CountContext *ctx) = 0;
  virtual void exitCount(SolidityScriptParser::CountContext *ctx) = 0;

  virtual void enterScope(SolidityScriptParser::ScopeContext *ctx) = 0;
  virtual void exitScope(SolidityScriptParser::ScopeContext *ctx) = 0;

  virtual void enterArguments(SolidityScriptParser::ArgumentsContext *ctx) = 0;
  virtual void exitArguments(SolidityScriptParser::ArgumentsContext *ctx) = 0;

  virtual void enterArgument(SolidityScriptParser::ArgumentContext *ctx) = 0;
  virtual void exitArgument(SolidityScriptParser::ArgumentContext *ctx) = 0;

  virtual void enterExplicitTypeValue(SolidityScriptParser::ExplicitTypeValueContext *ctx) = 0;
  virtual void exitExplicitTypeValue(SolidityScriptParser::ExplicitTypeValueContext *ctx) = 0;

  virtual void enterType(SolidityScriptParser::TypeContext *ctx) = 0;
  virtual void exitType(SolidityScriptParser::TypeContext *ctx) = 0;

  virtual void enterIdentifier(SolidityScriptParser::IdentifierContext *ctx) = 0;
  virtual void exitIdentifier(SolidityScriptParser::IdentifierContext *ctx) = 0;

  virtual void enterExpression(SolidityScriptParser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(SolidityScriptParser::ExpressionContext *ctx) = 0;

  virtual void enterRandomCall(SolidityScriptParser::RandomCallContext *ctx) = 0;
  virtual void exitRandomCall(SolidityScriptParser::RandomCallContext *ctx) = 0;

  virtual void enterStringArray(SolidityScriptParser::StringArrayContext *ctx) = 0;
  virtual void exitStringArray(SolidityScriptParser::StringArrayContext *ctx) = 0;

  virtual void enterStructArray(SolidityScriptParser::StructArrayContext *ctx) = 0;
  virtual void exitStructArray(SolidityScriptParser::StructArrayContext *ctx) = 0;

  virtual void enterRandomCallCount(SolidityScriptParser::RandomCallCountContext *ctx) = 0;
  virtual void exitRandomCallCount(SolidityScriptParser::RandomCallCountContext *ctx) = 0;

  virtual void enterRandomCallArguments(SolidityScriptParser::RandomCallArgumentsContext *ctx) = 0;
  virtual void exitRandomCallArguments(SolidityScriptParser::RandomCallArgumentsContext *ctx) = 0;

  virtual void enterNumberLiteral(SolidityScriptParser::NumberLiteralContext *ctx) = 0;
  virtual void exitNumberLiteral(SolidityScriptParser::NumberLiteralContext *ctx) = 0;

  virtual void enterMatchedParentheses(SolidityScriptParser::MatchedParenthesesContext *ctx) = 0;
  virtual void exitMatchedParentheses(SolidityScriptParser::MatchedParenthesesContext *ctx) = 0;

  virtual void enterSolFile(SolidityScriptParser::SolFileContext *ctx) = 0;
  virtual void exitSolFile(SolidityScriptParser::SolFileContext *ctx) = 0;

  virtual void enterXtlFile(SolidityScriptParser::XtlFileContext *ctx) = 0;
  virtual void exitXtlFile(SolidityScriptParser::XtlFileContext *ctx) = 0;

  virtual void enterDirectivePath(SolidityScriptParser::DirectivePathContext *ctx) = 0;
  virtual void exitDirectivePath(SolidityScriptParser::DirectivePathContext *ctx) = 0;

  virtual void enterBoolLiteral(SolidityScriptParser::BoolLiteralContext *ctx) = 0;
  virtual void exitBoolLiteral(SolidityScriptParser::BoolLiteralContext *ctx) = 0;


};

