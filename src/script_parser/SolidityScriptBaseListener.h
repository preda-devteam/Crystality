
// Generated from SolidityScript.g4 by ANTLR 4.12.0

#pragma once


#include "antlr4-runtime.h"
#include "SolidityScriptListener.h"


/**
 * This class provides an empty implementation of SolidityScriptListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  SolidityScriptBaseListener : public SolidityScriptListener {
public:

  virtual void enterSource(SolidityScriptParser::SourceContext * /*ctx*/) override { }
  virtual void exitSource(SolidityScriptParser::SourceContext * /*ctx*/) override { }

  virtual void enterScript(SolidityScriptParser::ScriptContext * /*ctx*/) override { }
  virtual void exitScript(SolidityScriptParser::ScriptContext * /*ctx*/) override { }

  virtual void enterVariableDeclaration(SolidityScriptParser::VariableDeclarationContext * /*ctx*/) override { }
  virtual void exitVariableDeclaration(SolidityScriptParser::VariableDeclarationContext * /*ctx*/) override { }

  virtual void enterFunctionCall(SolidityScriptParser::FunctionCallContext * /*ctx*/) override { }
  virtual void exitFunctionCall(SolidityScriptParser::FunctionCallContext * /*ctx*/) override { }

  virtual void enterVizTrace(SolidityScriptParser::VizTraceContext * /*ctx*/) override { }
  virtual void exitVizTrace(SolidityScriptParser::VizTraceContext * /*ctx*/) override { }

  virtual void enterChainParams(SolidityScriptParser::ChainParamsContext * /*ctx*/) override { }
  virtual void exitChainParams(SolidityScriptParser::ChainParamsContext * /*ctx*/) override { }

  virtual void enterContractName(SolidityScriptParser::ContractNameContext * /*ctx*/) override { }
  virtual void exitContractName(SolidityScriptParser::ContractNameContext * /*ctx*/) override { }

  virtual void enterDeployAddress(SolidityScriptParser::DeployAddressContext * /*ctx*/) override { }
  virtual void exitDeployAddress(SolidityScriptParser::DeployAddressContext * /*ctx*/) override { }

  virtual void enterInputCSV(SolidityScriptParser::InputCSVContext * /*ctx*/) override { }
  virtual void exitInputCSV(SolidityScriptParser::InputCSVContext * /*ctx*/) override { }

  virtual void enterCount(SolidityScriptParser::CountContext * /*ctx*/) override { }
  virtual void exitCount(SolidityScriptParser::CountContext * /*ctx*/) override { }

  virtual void enterScope(SolidityScriptParser::ScopeContext * /*ctx*/) override { }
  virtual void exitScope(SolidityScriptParser::ScopeContext * /*ctx*/) override { }

  virtual void enterArguments(SolidityScriptParser::ArgumentsContext * /*ctx*/) override { }
  virtual void exitArguments(SolidityScriptParser::ArgumentsContext * /*ctx*/) override { }

  virtual void enterArgument(SolidityScriptParser::ArgumentContext * /*ctx*/) override { }
  virtual void exitArgument(SolidityScriptParser::ArgumentContext * /*ctx*/) override { }

  virtual void enterExplicitTypeValue(SolidityScriptParser::ExplicitTypeValueContext * /*ctx*/) override { }
  virtual void exitExplicitTypeValue(SolidityScriptParser::ExplicitTypeValueContext * /*ctx*/) override { }

  virtual void enterType(SolidityScriptParser::TypeContext * /*ctx*/) override { }
  virtual void exitType(SolidityScriptParser::TypeContext * /*ctx*/) override { }

  virtual void enterIdentifier(SolidityScriptParser::IdentifierContext * /*ctx*/) override { }
  virtual void exitIdentifier(SolidityScriptParser::IdentifierContext * /*ctx*/) override { }

  virtual void enterExpression(SolidityScriptParser::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(SolidityScriptParser::ExpressionContext * /*ctx*/) override { }

  virtual void enterRandomCall(SolidityScriptParser::RandomCallContext * /*ctx*/) override { }
  virtual void exitRandomCall(SolidityScriptParser::RandomCallContext * /*ctx*/) override { }

  virtual void enterStringArray(SolidityScriptParser::StringArrayContext * /*ctx*/) override { }
  virtual void exitStringArray(SolidityScriptParser::StringArrayContext * /*ctx*/) override { }

  virtual void enterStructArray(SolidityScriptParser::StructArrayContext * /*ctx*/) override { }
  virtual void exitStructArray(SolidityScriptParser::StructArrayContext * /*ctx*/) override { }

  virtual void enterRandomCallCount(SolidityScriptParser::RandomCallCountContext * /*ctx*/) override { }
  virtual void exitRandomCallCount(SolidityScriptParser::RandomCallCountContext * /*ctx*/) override { }

  virtual void enterRandomCallArguments(SolidityScriptParser::RandomCallArgumentsContext * /*ctx*/) override { }
  virtual void exitRandomCallArguments(SolidityScriptParser::RandomCallArgumentsContext * /*ctx*/) override { }

  virtual void enterNumberLiteral(SolidityScriptParser::NumberLiteralContext * /*ctx*/) override { }
  virtual void exitNumberLiteral(SolidityScriptParser::NumberLiteralContext * /*ctx*/) override { }

  virtual void enterMatchedParentheses(SolidityScriptParser::MatchedParenthesesContext * /*ctx*/) override { }
  virtual void exitMatchedParentheses(SolidityScriptParser::MatchedParenthesesContext * /*ctx*/) override { }

  virtual void enterSolFile(SolidityScriptParser::SolFileContext * /*ctx*/) override { }
  virtual void exitSolFile(SolidityScriptParser::SolFileContext * /*ctx*/) override { }

  virtual void enterXtlFile(SolidityScriptParser::XtlFileContext * /*ctx*/) override { }
  virtual void exitXtlFile(SolidityScriptParser::XtlFileContext * /*ctx*/) override { }

  virtual void enterDirectivePath(SolidityScriptParser::DirectivePathContext * /*ctx*/) override { }
  virtual void exitDirectivePath(SolidityScriptParser::DirectivePathContext * /*ctx*/) override { }

  virtual void enterBoolLiteral(SolidityScriptParser::BoolLiteralContext * /*ctx*/) override { }
  virtual void exitBoolLiteral(SolidityScriptParser::BoolLiteralContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

