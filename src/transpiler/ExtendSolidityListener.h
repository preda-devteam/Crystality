
// Generated from ExtendSolidity.g4 by ANTLR 4.12.0

#pragma once


#include "antlr4-runtime.h"
#include "ExtendSolidityParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by ExtendSolidityParser.
 */
class  ExtendSolidityListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterSourceUnit(ExtendSolidityParser::SourceUnitContext *ctx) = 0;
  virtual void exitSourceUnit(ExtendSolidityParser::SourceUnitContext *ctx) = 0;

  virtual void enterPragmaDirective(ExtendSolidityParser::PragmaDirectiveContext *ctx) = 0;
  virtual void exitPragmaDirective(ExtendSolidityParser::PragmaDirectiveContext *ctx) = 0;

  virtual void enterPragmaName(ExtendSolidityParser::PragmaNameContext *ctx) = 0;
  virtual void exitPragmaName(ExtendSolidityParser::PragmaNameContext *ctx) = 0;

  virtual void enterPragmaValue(ExtendSolidityParser::PragmaValueContext *ctx) = 0;
  virtual void exitPragmaValue(ExtendSolidityParser::PragmaValueContext *ctx) = 0;

  virtual void enterVersion(ExtendSolidityParser::VersionContext *ctx) = 0;
  virtual void exitVersion(ExtendSolidityParser::VersionContext *ctx) = 0;

  virtual void enterVersionOperator(ExtendSolidityParser::VersionOperatorContext *ctx) = 0;
  virtual void exitVersionOperator(ExtendSolidityParser::VersionOperatorContext *ctx) = 0;

  virtual void enterVersionConstraint(ExtendSolidityParser::VersionConstraintContext *ctx) = 0;
  virtual void exitVersionConstraint(ExtendSolidityParser::VersionConstraintContext *ctx) = 0;

  virtual void enterImportDeclaration(ExtendSolidityParser::ImportDeclarationContext *ctx) = 0;
  virtual void exitImportDeclaration(ExtendSolidityParser::ImportDeclarationContext *ctx) = 0;

  virtual void enterImportDirective(ExtendSolidityParser::ImportDirectiveContext *ctx) = 0;
  virtual void exitImportDirective(ExtendSolidityParser::ImportDirectiveContext *ctx) = 0;

  virtual void enterNatSpec(ExtendSolidityParser::NatSpecContext *ctx) = 0;
  virtual void exitNatSpec(ExtendSolidityParser::NatSpecContext *ctx) = 0;

  virtual void enterContractDefinition(ExtendSolidityParser::ContractDefinitionContext *ctx) = 0;
  virtual void exitContractDefinition(ExtendSolidityParser::ContractDefinitionContext *ctx) = 0;

  virtual void enterInheritanceSpecifier(ExtendSolidityParser::InheritanceSpecifierContext *ctx) = 0;
  virtual void exitInheritanceSpecifier(ExtendSolidityParser::InheritanceSpecifierContext *ctx) = 0;

  virtual void enterContractPart(ExtendSolidityParser::ContractPartContext *ctx) = 0;
  virtual void exitContractPart(ExtendSolidityParser::ContractPartContext *ctx) = 0;

  virtual void enterStateVariableDeclaration(ExtendSolidityParser::StateVariableDeclarationContext *ctx) = 0;
  virtual void exitStateVariableDeclaration(ExtendSolidityParser::StateVariableDeclarationContext *ctx) = 0;

  virtual void enterUsingForDeclaration(ExtendSolidityParser::UsingForDeclarationContext *ctx) = 0;
  virtual void exitUsingForDeclaration(ExtendSolidityParser::UsingForDeclarationContext *ctx) = 0;

  virtual void enterStructDefinition(ExtendSolidityParser::StructDefinitionContext *ctx) = 0;
  virtual void exitStructDefinition(ExtendSolidityParser::StructDefinitionContext *ctx) = 0;

  virtual void enterConstructorDefinition(ExtendSolidityParser::ConstructorDefinitionContext *ctx) = 0;
  virtual void exitConstructorDefinition(ExtendSolidityParser::ConstructorDefinitionContext *ctx) = 0;

  virtual void enterModifierDefinition(ExtendSolidityParser::ModifierDefinitionContext *ctx) = 0;
  virtual void exitModifierDefinition(ExtendSolidityParser::ModifierDefinitionContext *ctx) = 0;

  virtual void enterModifierInvocation(ExtendSolidityParser::ModifierInvocationContext *ctx) = 0;
  virtual void exitModifierInvocation(ExtendSolidityParser::ModifierInvocationContext *ctx) = 0;

  virtual void enterFunctionDefinition(ExtendSolidityParser::FunctionDefinitionContext *ctx) = 0;
  virtual void exitFunctionDefinition(ExtendSolidityParser::FunctionDefinitionContext *ctx) = 0;

  virtual void enterFunctionDescriptor(ExtendSolidityParser::FunctionDescriptorContext *ctx) = 0;
  virtual void exitFunctionDescriptor(ExtendSolidityParser::FunctionDescriptorContext *ctx) = 0;

  virtual void enterReturnParameters(ExtendSolidityParser::ReturnParametersContext *ctx) = 0;
  virtual void exitReturnParameters(ExtendSolidityParser::ReturnParametersContext *ctx) = 0;

  virtual void enterModifierList(ExtendSolidityParser::ModifierListContext *ctx) = 0;
  virtual void exitModifierList(ExtendSolidityParser::ModifierListContext *ctx) = 0;

  virtual void enterOverrideSpecifier(ExtendSolidityParser::OverrideSpecifierContext *ctx) = 0;
  virtual void exitOverrideSpecifier(ExtendSolidityParser::OverrideSpecifierContext *ctx) = 0;

  virtual void enterAccessiblity(ExtendSolidityParser::AccessiblityContext *ctx) = 0;
  virtual void exitAccessiblity(ExtendSolidityParser::AccessiblityContext *ctx) = 0;

  virtual void enterEventDefinition(ExtendSolidityParser::EventDefinitionContext *ctx) = 0;
  virtual void exitEventDefinition(ExtendSolidityParser::EventDefinitionContext *ctx) = 0;

  virtual void enterEnumValue(ExtendSolidityParser::EnumValueContext *ctx) = 0;
  virtual void exitEnumValue(ExtendSolidityParser::EnumValueContext *ctx) = 0;

  virtual void enterEnumDefinition(ExtendSolidityParser::EnumDefinitionContext *ctx) = 0;
  virtual void exitEnumDefinition(ExtendSolidityParser::EnumDefinitionContext *ctx) = 0;

  virtual void enterParameterList(ExtendSolidityParser::ParameterListContext *ctx) = 0;
  virtual void exitParameterList(ExtendSolidityParser::ParameterListContext *ctx) = 0;

  virtual void enterParameter(ExtendSolidityParser::ParameterContext *ctx) = 0;
  virtual void exitParameter(ExtendSolidityParser::ParameterContext *ctx) = 0;

  virtual void enterEventParameterList(ExtendSolidityParser::EventParameterListContext *ctx) = 0;
  virtual void exitEventParameterList(ExtendSolidityParser::EventParameterListContext *ctx) = 0;

  virtual void enterEventParameter(ExtendSolidityParser::EventParameterContext *ctx) = 0;
  virtual void exitEventParameter(ExtendSolidityParser::EventParameterContext *ctx) = 0;

  virtual void enterFunctionTypeParameterList(ExtendSolidityParser::FunctionTypeParameterListContext *ctx) = 0;
  virtual void exitFunctionTypeParameterList(ExtendSolidityParser::FunctionTypeParameterListContext *ctx) = 0;

  virtual void enterFunctionTypeParameter(ExtendSolidityParser::FunctionTypeParameterContext *ctx) = 0;
  virtual void exitFunctionTypeParameter(ExtendSolidityParser::FunctionTypeParameterContext *ctx) = 0;

  virtual void enterVariableDeclaration(ExtendSolidityParser::VariableDeclarationContext *ctx) = 0;
  virtual void exitVariableDeclaration(ExtendSolidityParser::VariableDeclarationContext *ctx) = 0;

  virtual void enterTypeName(ExtendSolidityParser::TypeNameContext *ctx) = 0;
  virtual void exitTypeName(ExtendSolidityParser::TypeNameContext *ctx) = 0;

  virtual void enterUserDefinedTypeName(ExtendSolidityParser::UserDefinedTypeNameContext *ctx) = 0;
  virtual void exitUserDefinedTypeName(ExtendSolidityParser::UserDefinedTypeNameContext *ctx) = 0;

  virtual void enterMapping(ExtendSolidityParser::MappingContext *ctx) = 0;
  virtual void exitMapping(ExtendSolidityParser::MappingContext *ctx) = 0;

  virtual void enterFunctionTypeName(ExtendSolidityParser::FunctionTypeNameContext *ctx) = 0;
  virtual void exitFunctionTypeName(ExtendSolidityParser::FunctionTypeNameContext *ctx) = 0;

  virtual void enterStorageLocation(ExtendSolidityParser::StorageLocationContext *ctx) = 0;
  virtual void exitStorageLocation(ExtendSolidityParser::StorageLocationContext *ctx) = 0;

  virtual void enterStateMutability(ExtendSolidityParser::StateMutabilityContext *ctx) = 0;
  virtual void exitStateMutability(ExtendSolidityParser::StateMutabilityContext *ctx) = 0;

  virtual void enterBlock(ExtendSolidityParser::BlockContext *ctx) = 0;
  virtual void exitBlock(ExtendSolidityParser::BlockContext *ctx) = 0;

  virtual void enterStatement(ExtendSolidityParser::StatementContext *ctx) = 0;
  virtual void exitStatement(ExtendSolidityParser::StatementContext *ctx) = 0;

  virtual void enterExpressionStatement(ExtendSolidityParser::ExpressionStatementContext *ctx) = 0;
  virtual void exitExpressionStatement(ExtendSolidityParser::ExpressionStatementContext *ctx) = 0;

  virtual void enterIfStatement(ExtendSolidityParser::IfStatementContext *ctx) = 0;
  virtual void exitIfStatement(ExtendSolidityParser::IfStatementContext *ctx) = 0;

  virtual void enterIfWithBlock(ExtendSolidityParser::IfWithBlockContext *ctx) = 0;
  virtual void exitIfWithBlock(ExtendSolidityParser::IfWithBlockContext *ctx) = 0;

  virtual void enterElseWithBlock(ExtendSolidityParser::ElseWithBlockContext *ctx) = 0;
  virtual void exitElseWithBlock(ExtendSolidityParser::ElseWithBlockContext *ctx) = 0;

  virtual void enterElseIfWithBlock(ExtendSolidityParser::ElseIfWithBlockContext *ctx) = 0;
  virtual void exitElseIfWithBlock(ExtendSolidityParser::ElseIfWithBlockContext *ctx) = 0;

  virtual void enterWhileStatement(ExtendSolidityParser::WhileStatementContext *ctx) = 0;
  virtual void exitWhileStatement(ExtendSolidityParser::WhileStatementContext *ctx) = 0;

  virtual void enterForStatement(ExtendSolidityParser::ForStatementContext *ctx) = 0;
  virtual void exitForStatement(ExtendSolidityParser::ForStatementContext *ctx) = 0;

  virtual void enterInlineAssemblyStatement(ExtendSolidityParser::InlineAssemblyStatementContext *ctx) = 0;
  virtual void exitInlineAssemblyStatement(ExtendSolidityParser::InlineAssemblyStatementContext *ctx) = 0;

  virtual void enterDoWhileStatement(ExtendSolidityParser::DoWhileStatementContext *ctx) = 0;
  virtual void exitDoWhileStatement(ExtendSolidityParser::DoWhileStatementContext *ctx) = 0;

  virtual void enterContinueStatement(ExtendSolidityParser::ContinueStatementContext *ctx) = 0;
  virtual void exitContinueStatement(ExtendSolidityParser::ContinueStatementContext *ctx) = 0;

  virtual void enterBreakStatement(ExtendSolidityParser::BreakStatementContext *ctx) = 0;
  virtual void exitBreakStatement(ExtendSolidityParser::BreakStatementContext *ctx) = 0;

  virtual void enterReturnStatement(ExtendSolidityParser::ReturnStatementContext *ctx) = 0;
  virtual void exitReturnStatement(ExtendSolidityParser::ReturnStatementContext *ctx) = 0;

  virtual void enterThrowStatement(ExtendSolidityParser::ThrowStatementContext *ctx) = 0;
  virtual void exitThrowStatement(ExtendSolidityParser::ThrowStatementContext *ctx) = 0;

  virtual void enterEmitStatement(ExtendSolidityParser::EmitStatementContext *ctx) = 0;
  virtual void exitEmitStatement(ExtendSolidityParser::EmitStatementContext *ctx) = 0;

  virtual void enterRelayStatement(ExtendSolidityParser::RelayStatementContext *ctx) = 0;
  virtual void exitRelayStatement(ExtendSolidityParser::RelayStatementContext *ctx) = 0;

  virtual void enterRelayLambdaDefinition(ExtendSolidityParser::RelayLambdaDefinitionContext *ctx) = 0;
  virtual void exitRelayLambdaDefinition(ExtendSolidityParser::RelayLambdaDefinitionContext *ctx) = 0;

  virtual void enterRelayLambdaParameter(ExtendSolidityParser::RelayLambdaParameterContext *ctx) = 0;
  virtual void exitRelayLambdaParameter(ExtendSolidityParser::RelayLambdaParameterContext *ctx) = 0;

  virtual void enterRelayScope(ExtendSolidityParser::RelayScopeContext *ctx) = 0;
  virtual void exitRelayScope(ExtendSolidityParser::RelayScopeContext *ctx) = 0;

  virtual void enterVariableDeclarationStatement(ExtendSolidityParser::VariableDeclarationStatementContext *ctx) = 0;
  virtual void exitVariableDeclarationStatement(ExtendSolidityParser::VariableDeclarationStatementContext *ctx) = 0;

  virtual void enterLocalVariableDeclaration(ExtendSolidityParser::LocalVariableDeclarationContext *ctx) = 0;
  virtual void exitLocalVariableDeclaration(ExtendSolidityParser::LocalVariableDeclarationContext *ctx) = 0;

  virtual void enterVariableDeclarationList(ExtendSolidityParser::VariableDeclarationListContext *ctx) = 0;
  virtual void exitVariableDeclarationList(ExtendSolidityParser::VariableDeclarationListContext *ctx) = 0;

  virtual void enterMoreVariableDeclaration(ExtendSolidityParser::MoreVariableDeclarationContext *ctx) = 0;
  virtual void exitMoreVariableDeclaration(ExtendSolidityParser::MoreVariableDeclarationContext *ctx) = 0;

  virtual void enterIdentifierList(ExtendSolidityParser::IdentifierListContext *ctx) = 0;
  virtual void exitIdentifierList(ExtendSolidityParser::IdentifierListContext *ctx) = 0;

  virtual void enterMoreIdentifier(ExtendSolidityParser::MoreIdentifierContext *ctx) = 0;
  virtual void exitMoreIdentifier(ExtendSolidityParser::MoreIdentifierContext *ctx) = 0;

  virtual void enterElementaryTypeName(ExtendSolidityParser::ElementaryTypeNameContext *ctx) = 0;
  virtual void exitElementaryTypeName(ExtendSolidityParser::ElementaryTypeNameContext *ctx) = 0;

  virtual void enterExpression(ExtendSolidityParser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(ExtendSolidityParser::ExpressionContext *ctx) = 0;

  virtual void enterPostOperator(ExtendSolidityParser::PostOperatorContext *ctx) = 0;
  virtual void exitPostOperator(ExtendSolidityParser::PostOperatorContext *ctx) = 0;

  virtual void enterPreOperator(ExtendSolidityParser::PreOperatorContext *ctx) = 0;
  virtual void exitPreOperator(ExtendSolidityParser::PreOperatorContext *ctx) = 0;

  virtual void enterMidOperator(ExtendSolidityParser::MidOperatorContext *ctx) = 0;
  virtual void exitMidOperator(ExtendSolidityParser::MidOperatorContext *ctx) = 0;

  virtual void enterPrimaryExpression(ExtendSolidityParser::PrimaryExpressionContext *ctx) = 0;
  virtual void exitPrimaryExpression(ExtendSolidityParser::PrimaryExpressionContext *ctx) = 0;

  virtual void enterMatchedParentheses(ExtendSolidityParser::MatchedParenthesesContext *ctx) = 0;
  virtual void exitMatchedParentheses(ExtendSolidityParser::MatchedParenthesesContext *ctx) = 0;

  virtual void enterExpressionList(ExtendSolidityParser::ExpressionListContext *ctx) = 0;
  virtual void exitExpressionList(ExtendSolidityParser::ExpressionListContext *ctx) = 0;

  virtual void enterNameValueList(ExtendSolidityParser::NameValueListContext *ctx) = 0;
  virtual void exitNameValueList(ExtendSolidityParser::NameValueListContext *ctx) = 0;

  virtual void enterNameValue(ExtendSolidityParser::NameValueContext *ctx) = 0;
  virtual void exitNameValue(ExtendSolidityParser::NameValueContext *ctx) = 0;

  virtual void enterFunctionCallArguments(ExtendSolidityParser::FunctionCallArgumentsContext *ctx) = 0;
  virtual void exitFunctionCallArguments(ExtendSolidityParser::FunctionCallArgumentsContext *ctx) = 0;

  virtual void enterFunctionCall(ExtendSolidityParser::FunctionCallContext *ctx) = 0;
  virtual void exitFunctionCall(ExtendSolidityParser::FunctionCallContext *ctx) = 0;

  virtual void enterAssemblyBlock(ExtendSolidityParser::AssemblyBlockContext *ctx) = 0;
  virtual void exitAssemblyBlock(ExtendSolidityParser::AssemblyBlockContext *ctx) = 0;

  virtual void enterAssemblyItem(ExtendSolidityParser::AssemblyItemContext *ctx) = 0;
  virtual void exitAssemblyItem(ExtendSolidityParser::AssemblyItemContext *ctx) = 0;

  virtual void enterAssemblyExpression(ExtendSolidityParser::AssemblyExpressionContext *ctx) = 0;
  virtual void exitAssemblyExpression(ExtendSolidityParser::AssemblyExpressionContext *ctx) = 0;

  virtual void enterAssemblyCall(ExtendSolidityParser::AssemblyCallContext *ctx) = 0;
  virtual void exitAssemblyCall(ExtendSolidityParser::AssemblyCallContext *ctx) = 0;

  virtual void enterAssemblyLocalDefinition(ExtendSolidityParser::AssemblyLocalDefinitionContext *ctx) = 0;
  virtual void exitAssemblyLocalDefinition(ExtendSolidityParser::AssemblyLocalDefinitionContext *ctx) = 0;

  virtual void enterAssemblyAssignment(ExtendSolidityParser::AssemblyAssignmentContext *ctx) = 0;
  virtual void exitAssemblyAssignment(ExtendSolidityParser::AssemblyAssignmentContext *ctx) = 0;

  virtual void enterAssemblyIdentifierOrList(ExtendSolidityParser::AssemblyIdentifierOrListContext *ctx) = 0;
  virtual void exitAssemblyIdentifierOrList(ExtendSolidityParser::AssemblyIdentifierOrListContext *ctx) = 0;

  virtual void enterAssemblyIdentifierList(ExtendSolidityParser::AssemblyIdentifierListContext *ctx) = 0;
  virtual void exitAssemblyIdentifierList(ExtendSolidityParser::AssemblyIdentifierListContext *ctx) = 0;

  virtual void enterAssemblyStackAssignment(ExtendSolidityParser::AssemblyStackAssignmentContext *ctx) = 0;
  virtual void exitAssemblyStackAssignment(ExtendSolidityParser::AssemblyStackAssignmentContext *ctx) = 0;

  virtual void enterLabelDefinition(ExtendSolidityParser::LabelDefinitionContext *ctx) = 0;
  virtual void exitLabelDefinition(ExtendSolidityParser::LabelDefinitionContext *ctx) = 0;

  virtual void enterAssemblySwitch(ExtendSolidityParser::AssemblySwitchContext *ctx) = 0;
  virtual void exitAssemblySwitch(ExtendSolidityParser::AssemblySwitchContext *ctx) = 0;

  virtual void enterAssemblyCase(ExtendSolidityParser::AssemblyCaseContext *ctx) = 0;
  virtual void exitAssemblyCase(ExtendSolidityParser::AssemblyCaseContext *ctx) = 0;

  virtual void enterAssemblyFunctionDefinition(ExtendSolidityParser::AssemblyFunctionDefinitionContext *ctx) = 0;
  virtual void exitAssemblyFunctionDefinition(ExtendSolidityParser::AssemblyFunctionDefinitionContext *ctx) = 0;

  virtual void enterAssemblyFunctionReturns(ExtendSolidityParser::AssemblyFunctionReturnsContext *ctx) = 0;
  virtual void exitAssemblyFunctionReturns(ExtendSolidityParser::AssemblyFunctionReturnsContext *ctx) = 0;

  virtual void enterAssemblyFor(ExtendSolidityParser::AssemblyForContext *ctx) = 0;
  virtual void exitAssemblyFor(ExtendSolidityParser::AssemblyForContext *ctx) = 0;

  virtual void enterAssemblyIf(ExtendSolidityParser::AssemblyIfContext *ctx) = 0;
  virtual void exitAssemblyIf(ExtendSolidityParser::AssemblyIfContext *ctx) = 0;

  virtual void enterAssemblyLiteral(ExtendSolidityParser::AssemblyLiteralContext *ctx) = 0;
  virtual void exitAssemblyLiteral(ExtendSolidityParser::AssemblyLiteralContext *ctx) = 0;

  virtual void enterSubAssembly(ExtendSolidityParser::SubAssemblyContext *ctx) = 0;
  virtual void exitSubAssembly(ExtendSolidityParser::SubAssemblyContext *ctx) = 0;

  virtual void enterTupleExpression(ExtendSolidityParser::TupleExpressionContext *ctx) = 0;
  virtual void exitTupleExpression(ExtendSolidityParser::TupleExpressionContext *ctx) = 0;

  virtual void enterBracketTupleExpression(ExtendSolidityParser::BracketTupleExpressionContext *ctx) = 0;
  virtual void exitBracketTupleExpression(ExtendSolidityParser::BracketTupleExpressionContext *ctx) = 0;

  virtual void enterMoreExpression(ExtendSolidityParser::MoreExpressionContext *ctx) = 0;
  virtual void exitMoreExpression(ExtendSolidityParser::MoreExpressionContext *ctx) = 0;

  virtual void enterParanthesesTupleExpression(ExtendSolidityParser::ParanthesesTupleExpressionContext *ctx) = 0;
  virtual void exitParanthesesTupleExpression(ExtendSolidityParser::ParanthesesTupleExpressionContext *ctx) = 0;

  virtual void enterTypeNameExpression(ExtendSolidityParser::TypeNameExpressionContext *ctx) = 0;
  virtual void exitTypeNameExpression(ExtendSolidityParser::TypeNameExpressionContext *ctx) = 0;

  virtual void enterNumberLiteral(ExtendSolidityParser::NumberLiteralContext *ctx) = 0;
  virtual void exitNumberLiteral(ExtendSolidityParser::NumberLiteralContext *ctx) = 0;

  virtual void enterIdentifier(ExtendSolidityParser::IdentifierContext *ctx) = 0;
  virtual void exitIdentifier(ExtendSolidityParser::IdentifierContext *ctx) = 0;

  virtual void enterScope(ExtendSolidityParser::ScopeContext *ctx) = 0;
  virtual void exitScope(ExtendSolidityParser::ScopeContext *ctx) = 0;

  virtual void enterAccessSpecifier(ExtendSolidityParser::AccessSpecifierContext *ctx) = 0;
  virtual void exitAccessSpecifier(ExtendSolidityParser::AccessSpecifierContext *ctx) = 0;


};

