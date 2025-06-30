
// Generated from ExtendSolidity.g4 by ANTLR 4.12.0

#pragma once


#include "antlr4-runtime.h"
#include "ExtendSolidityVisitor.h"


/**
 * This class provides an empty implementation of ExtendSolidityVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  ExtendSolidityBaseVisitor : public ExtendSolidityVisitor {
public:

  virtual std::any visitSourceUnit(ExtendSolidityParser::SourceUnitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPragmaDirective(ExtendSolidityParser::PragmaDirectiveContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPragmaName(ExtendSolidityParser::PragmaNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPragmaValue(ExtendSolidityParser::PragmaValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVersion(ExtendSolidityParser::VersionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVersionOperator(ExtendSolidityParser::VersionOperatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVersionConstraint(ExtendSolidityParser::VersionConstraintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitImportDeclaration(ExtendSolidityParser::ImportDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitImportDirective(ExtendSolidityParser::ImportDirectiveContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNatSpec(ExtendSolidityParser::NatSpecContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitContractDefinition(ExtendSolidityParser::ContractDefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInheritanceSpecifier(ExtendSolidityParser::InheritanceSpecifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitContractPart(ExtendSolidityParser::ContractPartContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStateVariableDeclaration(ExtendSolidityParser::StateVariableDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUsingForDeclaration(ExtendSolidityParser::UsingForDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStructDefinition(ExtendSolidityParser::StructDefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstructorDefinition(ExtendSolidityParser::ConstructorDefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitModifierDefinition(ExtendSolidityParser::ModifierDefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitModifierInvocation(ExtendSolidityParser::ModifierInvocationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionDefinition(ExtendSolidityParser::FunctionDefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionDescriptor(ExtendSolidityParser::FunctionDescriptorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturnParameters(ExtendSolidityParser::ReturnParametersContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitModifierList(ExtendSolidityParser::ModifierListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOverrideSpecifier(ExtendSolidityParser::OverrideSpecifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAccessiblity(ExtendSolidityParser::AccessiblityContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEventDefinition(ExtendSolidityParser::EventDefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEnumValue(ExtendSolidityParser::EnumValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEnumDefinition(ExtendSolidityParser::EnumDefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParameterList(ExtendSolidityParser::ParameterListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParameter(ExtendSolidityParser::ParameterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEventParameterList(ExtendSolidityParser::EventParameterListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEventParameter(ExtendSolidityParser::EventParameterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionTypeParameterList(ExtendSolidityParser::FunctionTypeParameterListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionTypeParameter(ExtendSolidityParser::FunctionTypeParameterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVariableDeclaration(ExtendSolidityParser::VariableDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeName(ExtendSolidityParser::TypeNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUserDefinedTypeName(ExtendSolidityParser::UserDefinedTypeNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMapping(ExtendSolidityParser::MappingContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionTypeName(ExtendSolidityParser::FunctionTypeNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStorageLocation(ExtendSolidityParser::StorageLocationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStateMutability(ExtendSolidityParser::StateMutabilityContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlock(ExtendSolidityParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatement(ExtendSolidityParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpressionStatement(ExtendSolidityParser::ExpressionStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIfStatement(ExtendSolidityParser::IfStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIfWithBlock(ExtendSolidityParser::IfWithBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitElseWithBlock(ExtendSolidityParser::ElseWithBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitElseIfWithBlock(ExtendSolidityParser::ElseIfWithBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWhileStatement(ExtendSolidityParser::WhileStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitForStatement(ExtendSolidityParser::ForStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInlineAssemblyStatement(ExtendSolidityParser::InlineAssemblyStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDoWhileStatement(ExtendSolidityParser::DoWhileStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitContinueStatement(ExtendSolidityParser::ContinueStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBreakStatement(ExtendSolidityParser::BreakStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturnStatement(ExtendSolidityParser::ReturnStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitThrowStatement(ExtendSolidityParser::ThrowStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEmitStatement(ExtendSolidityParser::EmitStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRelayStatement(ExtendSolidityParser::RelayStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRelayLambdaDefinition(ExtendSolidityParser::RelayLambdaDefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRelayLambdaParameter(ExtendSolidityParser::RelayLambdaParameterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRelayScope(ExtendSolidityParser::RelayScopeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVariableDeclarationStatement(ExtendSolidityParser::VariableDeclarationStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLocalVariableDeclaration(ExtendSolidityParser::LocalVariableDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVariableDeclarationList(ExtendSolidityParser::VariableDeclarationListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMoreVariableDeclaration(ExtendSolidityParser::MoreVariableDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIdentifierList(ExtendSolidityParser::IdentifierListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMoreIdentifier(ExtendSolidityParser::MoreIdentifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitElementaryTypeName(ExtendSolidityParser::ElementaryTypeNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpression(ExtendSolidityParser::ExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPostOperator(ExtendSolidityParser::PostOperatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPreOperator(ExtendSolidityParser::PreOperatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMidOperator(ExtendSolidityParser::MidOperatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrimaryExpression(ExtendSolidityParser::PrimaryExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMatchedParentheses(ExtendSolidityParser::MatchedParenthesesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpressionList(ExtendSolidityParser::ExpressionListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNameValueList(ExtendSolidityParser::NameValueListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNameValue(ExtendSolidityParser::NameValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionCallArguments(ExtendSolidityParser::FunctionCallArgumentsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionCall(ExtendSolidityParser::FunctionCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssemblyBlock(ExtendSolidityParser::AssemblyBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssemblyItem(ExtendSolidityParser::AssemblyItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssemblyExpression(ExtendSolidityParser::AssemblyExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssemblyCall(ExtendSolidityParser::AssemblyCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssemblyLocalDefinition(ExtendSolidityParser::AssemblyLocalDefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssemblyAssignment(ExtendSolidityParser::AssemblyAssignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssemblyIdentifierOrList(ExtendSolidityParser::AssemblyIdentifierOrListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssemblyIdentifierList(ExtendSolidityParser::AssemblyIdentifierListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssemblyStackAssignment(ExtendSolidityParser::AssemblyStackAssignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLabelDefinition(ExtendSolidityParser::LabelDefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssemblySwitch(ExtendSolidityParser::AssemblySwitchContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssemblyCase(ExtendSolidityParser::AssemblyCaseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssemblyFunctionDefinition(ExtendSolidityParser::AssemblyFunctionDefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssemblyFunctionReturns(ExtendSolidityParser::AssemblyFunctionReturnsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssemblyFor(ExtendSolidityParser::AssemblyForContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssemblyIf(ExtendSolidityParser::AssemblyIfContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssemblyLiteral(ExtendSolidityParser::AssemblyLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSubAssembly(ExtendSolidityParser::SubAssemblyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTupleExpression(ExtendSolidityParser::TupleExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBracketTupleExpression(ExtendSolidityParser::BracketTupleExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMoreExpression(ExtendSolidityParser::MoreExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParanthesesTupleExpression(ExtendSolidityParser::ParanthesesTupleExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeNameExpression(ExtendSolidityParser::TypeNameExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNumberLiteral(ExtendSolidityParser::NumberLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIdentifier(ExtendSolidityParser::IdentifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitScope(ExtendSolidityParser::ScopeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAccessSpecifier(ExtendSolidityParser::AccessSpecifierContext *ctx) override {
    return visitChildren(ctx);
  }


};

