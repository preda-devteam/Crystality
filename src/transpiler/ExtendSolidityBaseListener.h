
// Generated from ExtendSolidity.g4 by ANTLR 4.12.0

#pragma once


#include "antlr4-runtime.h"
#include "ExtendSolidityListener.h"


/**
 * This class provides an empty implementation of ExtendSolidityListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  ExtendSolidityBaseListener : public ExtendSolidityListener {
public:

  virtual void enterSourceUnit(ExtendSolidityParser::SourceUnitContext * /*ctx*/) override { }
  virtual void exitSourceUnit(ExtendSolidityParser::SourceUnitContext * /*ctx*/) override { }

  virtual void enterPragmaDirective(ExtendSolidityParser::PragmaDirectiveContext * /*ctx*/) override { }
  virtual void exitPragmaDirective(ExtendSolidityParser::PragmaDirectiveContext * /*ctx*/) override { }

  virtual void enterPragmaName(ExtendSolidityParser::PragmaNameContext * /*ctx*/) override { }
  virtual void exitPragmaName(ExtendSolidityParser::PragmaNameContext * /*ctx*/) override { }

  virtual void enterPragmaValue(ExtendSolidityParser::PragmaValueContext * /*ctx*/) override { }
  virtual void exitPragmaValue(ExtendSolidityParser::PragmaValueContext * /*ctx*/) override { }

  virtual void enterVersion(ExtendSolidityParser::VersionContext * /*ctx*/) override { }
  virtual void exitVersion(ExtendSolidityParser::VersionContext * /*ctx*/) override { }

  virtual void enterVersionOperator(ExtendSolidityParser::VersionOperatorContext * /*ctx*/) override { }
  virtual void exitVersionOperator(ExtendSolidityParser::VersionOperatorContext * /*ctx*/) override { }

  virtual void enterVersionConstraint(ExtendSolidityParser::VersionConstraintContext * /*ctx*/) override { }
  virtual void exitVersionConstraint(ExtendSolidityParser::VersionConstraintContext * /*ctx*/) override { }

  virtual void enterImportDeclaration(ExtendSolidityParser::ImportDeclarationContext * /*ctx*/) override { }
  virtual void exitImportDeclaration(ExtendSolidityParser::ImportDeclarationContext * /*ctx*/) override { }

  virtual void enterImportDirective(ExtendSolidityParser::ImportDirectiveContext * /*ctx*/) override { }
  virtual void exitImportDirective(ExtendSolidityParser::ImportDirectiveContext * /*ctx*/) override { }

  virtual void enterNatSpec(ExtendSolidityParser::NatSpecContext * /*ctx*/) override { }
  virtual void exitNatSpec(ExtendSolidityParser::NatSpecContext * /*ctx*/) override { }

  virtual void enterContractDefinition(ExtendSolidityParser::ContractDefinitionContext * /*ctx*/) override { }
  virtual void exitContractDefinition(ExtendSolidityParser::ContractDefinitionContext * /*ctx*/) override { }

  virtual void enterInheritanceSpecifier(ExtendSolidityParser::InheritanceSpecifierContext * /*ctx*/) override { }
  virtual void exitInheritanceSpecifier(ExtendSolidityParser::InheritanceSpecifierContext * /*ctx*/) override { }

  virtual void enterContractPart(ExtendSolidityParser::ContractPartContext * /*ctx*/) override { }
  virtual void exitContractPart(ExtendSolidityParser::ContractPartContext * /*ctx*/) override { }

  virtual void enterStateVariableDeclaration(ExtendSolidityParser::StateVariableDeclarationContext * /*ctx*/) override { }
  virtual void exitStateVariableDeclaration(ExtendSolidityParser::StateVariableDeclarationContext * /*ctx*/) override { }

  virtual void enterUsingForDeclaration(ExtendSolidityParser::UsingForDeclarationContext * /*ctx*/) override { }
  virtual void exitUsingForDeclaration(ExtendSolidityParser::UsingForDeclarationContext * /*ctx*/) override { }

  virtual void enterStructDefinition(ExtendSolidityParser::StructDefinitionContext * /*ctx*/) override { }
  virtual void exitStructDefinition(ExtendSolidityParser::StructDefinitionContext * /*ctx*/) override { }

  virtual void enterConstructorDefinition(ExtendSolidityParser::ConstructorDefinitionContext * /*ctx*/) override { }
  virtual void exitConstructorDefinition(ExtendSolidityParser::ConstructorDefinitionContext * /*ctx*/) override { }

  virtual void enterModifierDefinition(ExtendSolidityParser::ModifierDefinitionContext * /*ctx*/) override { }
  virtual void exitModifierDefinition(ExtendSolidityParser::ModifierDefinitionContext * /*ctx*/) override { }

  virtual void enterModifierInvocation(ExtendSolidityParser::ModifierInvocationContext * /*ctx*/) override { }
  virtual void exitModifierInvocation(ExtendSolidityParser::ModifierInvocationContext * /*ctx*/) override { }

  virtual void enterFunctionDefinition(ExtendSolidityParser::FunctionDefinitionContext * /*ctx*/) override { }
  virtual void exitFunctionDefinition(ExtendSolidityParser::FunctionDefinitionContext * /*ctx*/) override { }

  virtual void enterFunctionDescriptor(ExtendSolidityParser::FunctionDescriptorContext * /*ctx*/) override { }
  virtual void exitFunctionDescriptor(ExtendSolidityParser::FunctionDescriptorContext * /*ctx*/) override { }

  virtual void enterReturnParameters(ExtendSolidityParser::ReturnParametersContext * /*ctx*/) override { }
  virtual void exitReturnParameters(ExtendSolidityParser::ReturnParametersContext * /*ctx*/) override { }

  virtual void enterModifierList(ExtendSolidityParser::ModifierListContext * /*ctx*/) override { }
  virtual void exitModifierList(ExtendSolidityParser::ModifierListContext * /*ctx*/) override { }

  virtual void enterOverrideSpecifier(ExtendSolidityParser::OverrideSpecifierContext * /*ctx*/) override { }
  virtual void exitOverrideSpecifier(ExtendSolidityParser::OverrideSpecifierContext * /*ctx*/) override { }

  virtual void enterAccessiblity(ExtendSolidityParser::AccessiblityContext * /*ctx*/) override { }
  virtual void exitAccessiblity(ExtendSolidityParser::AccessiblityContext * /*ctx*/) override { }

  virtual void enterEventDefinition(ExtendSolidityParser::EventDefinitionContext * /*ctx*/) override { }
  virtual void exitEventDefinition(ExtendSolidityParser::EventDefinitionContext * /*ctx*/) override { }

  virtual void enterEnumValue(ExtendSolidityParser::EnumValueContext * /*ctx*/) override { }
  virtual void exitEnumValue(ExtendSolidityParser::EnumValueContext * /*ctx*/) override { }

  virtual void enterEnumDefinition(ExtendSolidityParser::EnumDefinitionContext * /*ctx*/) override { }
  virtual void exitEnumDefinition(ExtendSolidityParser::EnumDefinitionContext * /*ctx*/) override { }

  virtual void enterParameterList(ExtendSolidityParser::ParameterListContext * /*ctx*/) override { }
  virtual void exitParameterList(ExtendSolidityParser::ParameterListContext * /*ctx*/) override { }

  virtual void enterParameter(ExtendSolidityParser::ParameterContext * /*ctx*/) override { }
  virtual void exitParameter(ExtendSolidityParser::ParameterContext * /*ctx*/) override { }

  virtual void enterEventParameterList(ExtendSolidityParser::EventParameterListContext * /*ctx*/) override { }
  virtual void exitEventParameterList(ExtendSolidityParser::EventParameterListContext * /*ctx*/) override { }

  virtual void enterEventParameter(ExtendSolidityParser::EventParameterContext * /*ctx*/) override { }
  virtual void exitEventParameter(ExtendSolidityParser::EventParameterContext * /*ctx*/) override { }

  virtual void enterFunctionTypeParameterList(ExtendSolidityParser::FunctionTypeParameterListContext * /*ctx*/) override { }
  virtual void exitFunctionTypeParameterList(ExtendSolidityParser::FunctionTypeParameterListContext * /*ctx*/) override { }

  virtual void enterFunctionTypeParameter(ExtendSolidityParser::FunctionTypeParameterContext * /*ctx*/) override { }
  virtual void exitFunctionTypeParameter(ExtendSolidityParser::FunctionTypeParameterContext * /*ctx*/) override { }

  virtual void enterVariableDeclaration(ExtendSolidityParser::VariableDeclarationContext * /*ctx*/) override { }
  virtual void exitVariableDeclaration(ExtendSolidityParser::VariableDeclarationContext * /*ctx*/) override { }

  virtual void enterTypeName(ExtendSolidityParser::TypeNameContext * /*ctx*/) override { }
  virtual void exitTypeName(ExtendSolidityParser::TypeNameContext * /*ctx*/) override { }

  virtual void enterUserDefinedTypeName(ExtendSolidityParser::UserDefinedTypeNameContext * /*ctx*/) override { }
  virtual void exitUserDefinedTypeName(ExtendSolidityParser::UserDefinedTypeNameContext * /*ctx*/) override { }

  virtual void enterMapping(ExtendSolidityParser::MappingContext * /*ctx*/) override { }
  virtual void exitMapping(ExtendSolidityParser::MappingContext * /*ctx*/) override { }

  virtual void enterFunctionTypeName(ExtendSolidityParser::FunctionTypeNameContext * /*ctx*/) override { }
  virtual void exitFunctionTypeName(ExtendSolidityParser::FunctionTypeNameContext * /*ctx*/) override { }

  virtual void enterStorageLocation(ExtendSolidityParser::StorageLocationContext * /*ctx*/) override { }
  virtual void exitStorageLocation(ExtendSolidityParser::StorageLocationContext * /*ctx*/) override { }

  virtual void enterStateMutability(ExtendSolidityParser::StateMutabilityContext * /*ctx*/) override { }
  virtual void exitStateMutability(ExtendSolidityParser::StateMutabilityContext * /*ctx*/) override { }

  virtual void enterBlock(ExtendSolidityParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(ExtendSolidityParser::BlockContext * /*ctx*/) override { }

  virtual void enterStatement(ExtendSolidityParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(ExtendSolidityParser::StatementContext * /*ctx*/) override { }

  virtual void enterExpressionStatement(ExtendSolidityParser::ExpressionStatementContext * /*ctx*/) override { }
  virtual void exitExpressionStatement(ExtendSolidityParser::ExpressionStatementContext * /*ctx*/) override { }

  virtual void enterIfStatement(ExtendSolidityParser::IfStatementContext * /*ctx*/) override { }
  virtual void exitIfStatement(ExtendSolidityParser::IfStatementContext * /*ctx*/) override { }

  virtual void enterIfWithBlock(ExtendSolidityParser::IfWithBlockContext * /*ctx*/) override { }
  virtual void exitIfWithBlock(ExtendSolidityParser::IfWithBlockContext * /*ctx*/) override { }

  virtual void enterElseWithBlock(ExtendSolidityParser::ElseWithBlockContext * /*ctx*/) override { }
  virtual void exitElseWithBlock(ExtendSolidityParser::ElseWithBlockContext * /*ctx*/) override { }

  virtual void enterElseIfWithBlock(ExtendSolidityParser::ElseIfWithBlockContext * /*ctx*/) override { }
  virtual void exitElseIfWithBlock(ExtendSolidityParser::ElseIfWithBlockContext * /*ctx*/) override { }

  virtual void enterWhileStatement(ExtendSolidityParser::WhileStatementContext * /*ctx*/) override { }
  virtual void exitWhileStatement(ExtendSolidityParser::WhileStatementContext * /*ctx*/) override { }

  virtual void enterForStatement(ExtendSolidityParser::ForStatementContext * /*ctx*/) override { }
  virtual void exitForStatement(ExtendSolidityParser::ForStatementContext * /*ctx*/) override { }

  virtual void enterInlineAssemblyStatement(ExtendSolidityParser::InlineAssemblyStatementContext * /*ctx*/) override { }
  virtual void exitInlineAssemblyStatement(ExtendSolidityParser::InlineAssemblyStatementContext * /*ctx*/) override { }

  virtual void enterDoWhileStatement(ExtendSolidityParser::DoWhileStatementContext * /*ctx*/) override { }
  virtual void exitDoWhileStatement(ExtendSolidityParser::DoWhileStatementContext * /*ctx*/) override { }

  virtual void enterContinueStatement(ExtendSolidityParser::ContinueStatementContext * /*ctx*/) override { }
  virtual void exitContinueStatement(ExtendSolidityParser::ContinueStatementContext * /*ctx*/) override { }

  virtual void enterBreakStatement(ExtendSolidityParser::BreakStatementContext * /*ctx*/) override { }
  virtual void exitBreakStatement(ExtendSolidityParser::BreakStatementContext * /*ctx*/) override { }

  virtual void enterReturnStatement(ExtendSolidityParser::ReturnStatementContext * /*ctx*/) override { }
  virtual void exitReturnStatement(ExtendSolidityParser::ReturnStatementContext * /*ctx*/) override { }

  virtual void enterThrowStatement(ExtendSolidityParser::ThrowStatementContext * /*ctx*/) override { }
  virtual void exitThrowStatement(ExtendSolidityParser::ThrowStatementContext * /*ctx*/) override { }

  virtual void enterEmitStatement(ExtendSolidityParser::EmitStatementContext * /*ctx*/) override { }
  virtual void exitEmitStatement(ExtendSolidityParser::EmitStatementContext * /*ctx*/) override { }

  virtual void enterRelayStatement(ExtendSolidityParser::RelayStatementContext * /*ctx*/) override { }
  virtual void exitRelayStatement(ExtendSolidityParser::RelayStatementContext * /*ctx*/) override { }

  virtual void enterRelayLambdaDefinition(ExtendSolidityParser::RelayLambdaDefinitionContext * /*ctx*/) override { }
  virtual void exitRelayLambdaDefinition(ExtendSolidityParser::RelayLambdaDefinitionContext * /*ctx*/) override { }

  virtual void enterRelayLambdaParameter(ExtendSolidityParser::RelayLambdaParameterContext * /*ctx*/) override { }
  virtual void exitRelayLambdaParameter(ExtendSolidityParser::RelayLambdaParameterContext * /*ctx*/) override { }

  virtual void enterRelayScope(ExtendSolidityParser::RelayScopeContext * /*ctx*/) override { }
  virtual void exitRelayScope(ExtendSolidityParser::RelayScopeContext * /*ctx*/) override { }

  virtual void enterVariableDeclarationStatement(ExtendSolidityParser::VariableDeclarationStatementContext * /*ctx*/) override { }
  virtual void exitVariableDeclarationStatement(ExtendSolidityParser::VariableDeclarationStatementContext * /*ctx*/) override { }

  virtual void enterLocalVariableDeclaration(ExtendSolidityParser::LocalVariableDeclarationContext * /*ctx*/) override { }
  virtual void exitLocalVariableDeclaration(ExtendSolidityParser::LocalVariableDeclarationContext * /*ctx*/) override { }

  virtual void enterVariableDeclarationList(ExtendSolidityParser::VariableDeclarationListContext * /*ctx*/) override { }
  virtual void exitVariableDeclarationList(ExtendSolidityParser::VariableDeclarationListContext * /*ctx*/) override { }

  virtual void enterMoreVariableDeclaration(ExtendSolidityParser::MoreVariableDeclarationContext * /*ctx*/) override { }
  virtual void exitMoreVariableDeclaration(ExtendSolidityParser::MoreVariableDeclarationContext * /*ctx*/) override { }

  virtual void enterIdentifierList(ExtendSolidityParser::IdentifierListContext * /*ctx*/) override { }
  virtual void exitIdentifierList(ExtendSolidityParser::IdentifierListContext * /*ctx*/) override { }

  virtual void enterMoreIdentifier(ExtendSolidityParser::MoreIdentifierContext * /*ctx*/) override { }
  virtual void exitMoreIdentifier(ExtendSolidityParser::MoreIdentifierContext * /*ctx*/) override { }

  virtual void enterElementaryTypeName(ExtendSolidityParser::ElementaryTypeNameContext * /*ctx*/) override { }
  virtual void exitElementaryTypeName(ExtendSolidityParser::ElementaryTypeNameContext * /*ctx*/) override { }

  virtual void enterExpression(ExtendSolidityParser::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(ExtendSolidityParser::ExpressionContext * /*ctx*/) override { }

  virtual void enterPostOperator(ExtendSolidityParser::PostOperatorContext * /*ctx*/) override { }
  virtual void exitPostOperator(ExtendSolidityParser::PostOperatorContext * /*ctx*/) override { }

  virtual void enterPreOperator(ExtendSolidityParser::PreOperatorContext * /*ctx*/) override { }
  virtual void exitPreOperator(ExtendSolidityParser::PreOperatorContext * /*ctx*/) override { }

  virtual void enterMidOperator(ExtendSolidityParser::MidOperatorContext * /*ctx*/) override { }
  virtual void exitMidOperator(ExtendSolidityParser::MidOperatorContext * /*ctx*/) override { }

  virtual void enterPrimaryExpression(ExtendSolidityParser::PrimaryExpressionContext * /*ctx*/) override { }
  virtual void exitPrimaryExpression(ExtendSolidityParser::PrimaryExpressionContext * /*ctx*/) override { }

  virtual void enterMatchedParentheses(ExtendSolidityParser::MatchedParenthesesContext * /*ctx*/) override { }
  virtual void exitMatchedParentheses(ExtendSolidityParser::MatchedParenthesesContext * /*ctx*/) override { }

  virtual void enterExpressionList(ExtendSolidityParser::ExpressionListContext * /*ctx*/) override { }
  virtual void exitExpressionList(ExtendSolidityParser::ExpressionListContext * /*ctx*/) override { }

  virtual void enterNameValueList(ExtendSolidityParser::NameValueListContext * /*ctx*/) override { }
  virtual void exitNameValueList(ExtendSolidityParser::NameValueListContext * /*ctx*/) override { }

  virtual void enterNameValue(ExtendSolidityParser::NameValueContext * /*ctx*/) override { }
  virtual void exitNameValue(ExtendSolidityParser::NameValueContext * /*ctx*/) override { }

  virtual void enterFunctionCallArguments(ExtendSolidityParser::FunctionCallArgumentsContext * /*ctx*/) override { }
  virtual void exitFunctionCallArguments(ExtendSolidityParser::FunctionCallArgumentsContext * /*ctx*/) override { }

  virtual void enterFunctionCall(ExtendSolidityParser::FunctionCallContext * /*ctx*/) override { }
  virtual void exitFunctionCall(ExtendSolidityParser::FunctionCallContext * /*ctx*/) override { }

  virtual void enterAssemblyBlock(ExtendSolidityParser::AssemblyBlockContext * /*ctx*/) override { }
  virtual void exitAssemblyBlock(ExtendSolidityParser::AssemblyBlockContext * /*ctx*/) override { }

  virtual void enterAssemblyItem(ExtendSolidityParser::AssemblyItemContext * /*ctx*/) override { }
  virtual void exitAssemblyItem(ExtendSolidityParser::AssemblyItemContext * /*ctx*/) override { }

  virtual void enterAssemblyExpression(ExtendSolidityParser::AssemblyExpressionContext * /*ctx*/) override { }
  virtual void exitAssemblyExpression(ExtendSolidityParser::AssemblyExpressionContext * /*ctx*/) override { }

  virtual void enterAssemblyCall(ExtendSolidityParser::AssemblyCallContext * /*ctx*/) override { }
  virtual void exitAssemblyCall(ExtendSolidityParser::AssemblyCallContext * /*ctx*/) override { }

  virtual void enterAssemblyLocalDefinition(ExtendSolidityParser::AssemblyLocalDefinitionContext * /*ctx*/) override { }
  virtual void exitAssemblyLocalDefinition(ExtendSolidityParser::AssemblyLocalDefinitionContext * /*ctx*/) override { }

  virtual void enterAssemblyAssignment(ExtendSolidityParser::AssemblyAssignmentContext * /*ctx*/) override { }
  virtual void exitAssemblyAssignment(ExtendSolidityParser::AssemblyAssignmentContext * /*ctx*/) override { }

  virtual void enterAssemblyIdentifierOrList(ExtendSolidityParser::AssemblyIdentifierOrListContext * /*ctx*/) override { }
  virtual void exitAssemblyIdentifierOrList(ExtendSolidityParser::AssemblyIdentifierOrListContext * /*ctx*/) override { }

  virtual void enterAssemblyIdentifierList(ExtendSolidityParser::AssemblyIdentifierListContext * /*ctx*/) override { }
  virtual void exitAssemblyIdentifierList(ExtendSolidityParser::AssemblyIdentifierListContext * /*ctx*/) override { }

  virtual void enterAssemblyStackAssignment(ExtendSolidityParser::AssemblyStackAssignmentContext * /*ctx*/) override { }
  virtual void exitAssemblyStackAssignment(ExtendSolidityParser::AssemblyStackAssignmentContext * /*ctx*/) override { }

  virtual void enterLabelDefinition(ExtendSolidityParser::LabelDefinitionContext * /*ctx*/) override { }
  virtual void exitLabelDefinition(ExtendSolidityParser::LabelDefinitionContext * /*ctx*/) override { }

  virtual void enterAssemblySwitch(ExtendSolidityParser::AssemblySwitchContext * /*ctx*/) override { }
  virtual void exitAssemblySwitch(ExtendSolidityParser::AssemblySwitchContext * /*ctx*/) override { }

  virtual void enterAssemblyCase(ExtendSolidityParser::AssemblyCaseContext * /*ctx*/) override { }
  virtual void exitAssemblyCase(ExtendSolidityParser::AssemblyCaseContext * /*ctx*/) override { }

  virtual void enterAssemblyFunctionDefinition(ExtendSolidityParser::AssemblyFunctionDefinitionContext * /*ctx*/) override { }
  virtual void exitAssemblyFunctionDefinition(ExtendSolidityParser::AssemblyFunctionDefinitionContext * /*ctx*/) override { }

  virtual void enterAssemblyFunctionReturns(ExtendSolidityParser::AssemblyFunctionReturnsContext * /*ctx*/) override { }
  virtual void exitAssemblyFunctionReturns(ExtendSolidityParser::AssemblyFunctionReturnsContext * /*ctx*/) override { }

  virtual void enterAssemblyFor(ExtendSolidityParser::AssemblyForContext * /*ctx*/) override { }
  virtual void exitAssemblyFor(ExtendSolidityParser::AssemblyForContext * /*ctx*/) override { }

  virtual void enterAssemblyIf(ExtendSolidityParser::AssemblyIfContext * /*ctx*/) override { }
  virtual void exitAssemblyIf(ExtendSolidityParser::AssemblyIfContext * /*ctx*/) override { }

  virtual void enterAssemblyLiteral(ExtendSolidityParser::AssemblyLiteralContext * /*ctx*/) override { }
  virtual void exitAssemblyLiteral(ExtendSolidityParser::AssemblyLiteralContext * /*ctx*/) override { }

  virtual void enterSubAssembly(ExtendSolidityParser::SubAssemblyContext * /*ctx*/) override { }
  virtual void exitSubAssembly(ExtendSolidityParser::SubAssemblyContext * /*ctx*/) override { }

  virtual void enterTupleExpression(ExtendSolidityParser::TupleExpressionContext * /*ctx*/) override { }
  virtual void exitTupleExpression(ExtendSolidityParser::TupleExpressionContext * /*ctx*/) override { }

  virtual void enterBracketTupleExpression(ExtendSolidityParser::BracketTupleExpressionContext * /*ctx*/) override { }
  virtual void exitBracketTupleExpression(ExtendSolidityParser::BracketTupleExpressionContext * /*ctx*/) override { }

  virtual void enterMoreExpression(ExtendSolidityParser::MoreExpressionContext * /*ctx*/) override { }
  virtual void exitMoreExpression(ExtendSolidityParser::MoreExpressionContext * /*ctx*/) override { }

  virtual void enterParanthesesTupleExpression(ExtendSolidityParser::ParanthesesTupleExpressionContext * /*ctx*/) override { }
  virtual void exitParanthesesTupleExpression(ExtendSolidityParser::ParanthesesTupleExpressionContext * /*ctx*/) override { }

  virtual void enterTypeNameExpression(ExtendSolidityParser::TypeNameExpressionContext * /*ctx*/) override { }
  virtual void exitTypeNameExpression(ExtendSolidityParser::TypeNameExpressionContext * /*ctx*/) override { }

  virtual void enterNumberLiteral(ExtendSolidityParser::NumberLiteralContext * /*ctx*/) override { }
  virtual void exitNumberLiteral(ExtendSolidityParser::NumberLiteralContext * /*ctx*/) override { }

  virtual void enterIdentifier(ExtendSolidityParser::IdentifierContext * /*ctx*/) override { }
  virtual void exitIdentifier(ExtendSolidityParser::IdentifierContext * /*ctx*/) override { }

  virtual void enterScope(ExtendSolidityParser::ScopeContext * /*ctx*/) override { }
  virtual void exitScope(ExtendSolidityParser::ScopeContext * /*ctx*/) override { }

  virtual void enterAccessSpecifier(ExtendSolidityParser::AccessSpecifierContext * /*ctx*/) override { }
  virtual void exitAccessSpecifier(ExtendSolidityParser::AccessSpecifierContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

