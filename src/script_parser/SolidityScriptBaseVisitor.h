
// Generated from SolidityScript.g4 by ANTLR 4.12.0

#pragma once


#include "antlr4-runtime.h"
#include "SolidityScriptVisitor.h"


/**
 * This class provides an empty implementation of SolidityScriptVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  SolidityScriptBaseVisitor : public SolidityScriptVisitor {
public:

  virtual std::any visitSource(SolidityScriptParser::SourceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitScript(SolidityScriptParser::ScriptContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVariableDeclaration(SolidityScriptParser::VariableDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionCall(SolidityScriptParser::FunctionCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVizTrace(SolidityScriptParser::VizTraceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitChainParams(SolidityScriptParser::ChainParamsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitContractName(SolidityScriptParser::ContractNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDeployAddress(SolidityScriptParser::DeployAddressContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInputCSV(SolidityScriptParser::InputCSVContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCount(SolidityScriptParser::CountContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitScope(SolidityScriptParser::ScopeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArguments(SolidityScriptParser::ArgumentsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArgument(SolidityScriptParser::ArgumentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExplicitTypeValue(SolidityScriptParser::ExplicitTypeValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType(SolidityScriptParser::TypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIdentifier(SolidityScriptParser::IdentifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpression(SolidityScriptParser::ExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRandomCall(SolidityScriptParser::RandomCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStringArray(SolidityScriptParser::StringArrayContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStructArray(SolidityScriptParser::StructArrayContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRandomCallCount(SolidityScriptParser::RandomCallCountContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRandomCallArguments(SolidityScriptParser::RandomCallArgumentsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNumberLiteral(SolidityScriptParser::NumberLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMatchedParentheses(SolidityScriptParser::MatchedParenthesesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSolFile(SolidityScriptParser::SolFileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitXtlFile(SolidityScriptParser::XtlFileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDirectivePath(SolidityScriptParser::DirectivePathContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBoolLiteral(SolidityScriptParser::BoolLiteralContext *ctx) override {
    return visitChildren(ctx);
  }


};

