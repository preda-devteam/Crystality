
// Generated from ExtendSolidity.g4 by ANTLR 4.12.0

#pragma once


#include "antlr4-runtime.h"
#include "ExtendSolidityParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by ExtendSolidityParser.
 */
class  ExtendSolidityVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by ExtendSolidityParser.
   */
    virtual std::any visitSourceUnit(ExtendSolidityParser::SourceUnitContext *context) = 0;

    virtual std::any visitPragmaDirective(ExtendSolidityParser::PragmaDirectiveContext *context) = 0;

    virtual std::any visitPragmaName(ExtendSolidityParser::PragmaNameContext *context) = 0;

    virtual std::any visitPragmaValue(ExtendSolidityParser::PragmaValueContext *context) = 0;

    virtual std::any visitVersion(ExtendSolidityParser::VersionContext *context) = 0;

    virtual std::any visitVersionOperator(ExtendSolidityParser::VersionOperatorContext *context) = 0;

    virtual std::any visitVersionConstraint(ExtendSolidityParser::VersionConstraintContext *context) = 0;

    virtual std::any visitImportDeclaration(ExtendSolidityParser::ImportDeclarationContext *context) = 0;

    virtual std::any visitImportDirective(ExtendSolidityParser::ImportDirectiveContext *context) = 0;

    virtual std::any visitNatSpec(ExtendSolidityParser::NatSpecContext *context) = 0;

    virtual std::any visitContractDefinition(ExtendSolidityParser::ContractDefinitionContext *context) = 0;

    virtual std::any visitInheritanceSpecifier(ExtendSolidityParser::InheritanceSpecifierContext *context) = 0;

    virtual std::any visitContractPart(ExtendSolidityParser::ContractPartContext *context) = 0;

    virtual std::any visitStateVariableDeclaration(ExtendSolidityParser::StateVariableDeclarationContext *context) = 0;

    virtual std::any visitUsingForDeclaration(ExtendSolidityParser::UsingForDeclarationContext *context) = 0;

    virtual std::any visitStructDefinition(ExtendSolidityParser::StructDefinitionContext *context) = 0;

    virtual std::any visitConstructorDefinition(ExtendSolidityParser::ConstructorDefinitionContext *context) = 0;

    virtual std::any visitModifierDefinition(ExtendSolidityParser::ModifierDefinitionContext *context) = 0;

    virtual std::any visitModifierInvocation(ExtendSolidityParser::ModifierInvocationContext *context) = 0;

    virtual std::any visitFunctionDefinition(ExtendSolidityParser::FunctionDefinitionContext *context) = 0;

    virtual std::any visitFunctionDescriptor(ExtendSolidityParser::FunctionDescriptorContext *context) = 0;

    virtual std::any visitReturnParameters(ExtendSolidityParser::ReturnParametersContext *context) = 0;

    virtual std::any visitModifierList(ExtendSolidityParser::ModifierListContext *context) = 0;

    virtual std::any visitOverrideSpecifier(ExtendSolidityParser::OverrideSpecifierContext *context) = 0;

    virtual std::any visitAccessiblity(ExtendSolidityParser::AccessiblityContext *context) = 0;

    virtual std::any visitEventDefinition(ExtendSolidityParser::EventDefinitionContext *context) = 0;

    virtual std::any visitEnumValue(ExtendSolidityParser::EnumValueContext *context) = 0;

    virtual std::any visitEnumDefinition(ExtendSolidityParser::EnumDefinitionContext *context) = 0;

    virtual std::any visitParameterList(ExtendSolidityParser::ParameterListContext *context) = 0;

    virtual std::any visitParameter(ExtendSolidityParser::ParameterContext *context) = 0;

    virtual std::any visitEventParameterList(ExtendSolidityParser::EventParameterListContext *context) = 0;

    virtual std::any visitEventParameter(ExtendSolidityParser::EventParameterContext *context) = 0;

    virtual std::any visitFunctionTypeParameterList(ExtendSolidityParser::FunctionTypeParameterListContext *context) = 0;

    virtual std::any visitFunctionTypeParameter(ExtendSolidityParser::FunctionTypeParameterContext *context) = 0;

    virtual std::any visitVariableDeclaration(ExtendSolidityParser::VariableDeclarationContext *context) = 0;

    virtual std::any visitTypeName(ExtendSolidityParser::TypeNameContext *context) = 0;

    virtual std::any visitUserDefinedTypeName(ExtendSolidityParser::UserDefinedTypeNameContext *context) = 0;

    virtual std::any visitMapping(ExtendSolidityParser::MappingContext *context) = 0;

    virtual std::any visitFunctionTypeName(ExtendSolidityParser::FunctionTypeNameContext *context) = 0;

    virtual std::any visitStorageLocation(ExtendSolidityParser::StorageLocationContext *context) = 0;

    virtual std::any visitStateMutability(ExtendSolidityParser::StateMutabilityContext *context) = 0;

    virtual std::any visitBlock(ExtendSolidityParser::BlockContext *context) = 0;

    virtual std::any visitStatement(ExtendSolidityParser::StatementContext *context) = 0;

    virtual std::any visitExpressionStatement(ExtendSolidityParser::ExpressionStatementContext *context) = 0;

    virtual std::any visitIfStatement(ExtendSolidityParser::IfStatementContext *context) = 0;

    virtual std::any visitIfWithBlock(ExtendSolidityParser::IfWithBlockContext *context) = 0;

    virtual std::any visitElseWithBlock(ExtendSolidityParser::ElseWithBlockContext *context) = 0;

    virtual std::any visitElseIfWithBlock(ExtendSolidityParser::ElseIfWithBlockContext *context) = 0;

    virtual std::any visitWhileStatement(ExtendSolidityParser::WhileStatementContext *context) = 0;

    virtual std::any visitForStatement(ExtendSolidityParser::ForStatementContext *context) = 0;

    virtual std::any visitInlineAssemblyStatement(ExtendSolidityParser::InlineAssemblyStatementContext *context) = 0;

    virtual std::any visitDoWhileStatement(ExtendSolidityParser::DoWhileStatementContext *context) = 0;

    virtual std::any visitContinueStatement(ExtendSolidityParser::ContinueStatementContext *context) = 0;

    virtual std::any visitBreakStatement(ExtendSolidityParser::BreakStatementContext *context) = 0;

    virtual std::any visitReturnStatement(ExtendSolidityParser::ReturnStatementContext *context) = 0;

    virtual std::any visitThrowStatement(ExtendSolidityParser::ThrowStatementContext *context) = 0;

    virtual std::any visitEmitStatement(ExtendSolidityParser::EmitStatementContext *context) = 0;

    virtual std::any visitRelayStatement(ExtendSolidityParser::RelayStatementContext *context) = 0;

    virtual std::any visitRelayLambdaDefinition(ExtendSolidityParser::RelayLambdaDefinitionContext *context) = 0;

    virtual std::any visitRelayLambdaParameter(ExtendSolidityParser::RelayLambdaParameterContext *context) = 0;

    virtual std::any visitRelayScope(ExtendSolidityParser::RelayScopeContext *context) = 0;

    virtual std::any visitVariableDeclarationStatement(ExtendSolidityParser::VariableDeclarationStatementContext *context) = 0;

    virtual std::any visitLocalVariableDeclaration(ExtendSolidityParser::LocalVariableDeclarationContext *context) = 0;

    virtual std::any visitVariableDeclarationList(ExtendSolidityParser::VariableDeclarationListContext *context) = 0;

    virtual std::any visitMoreVariableDeclaration(ExtendSolidityParser::MoreVariableDeclarationContext *context) = 0;

    virtual std::any visitIdentifierList(ExtendSolidityParser::IdentifierListContext *context) = 0;

    virtual std::any visitMoreIdentifier(ExtendSolidityParser::MoreIdentifierContext *context) = 0;

    virtual std::any visitElementaryTypeName(ExtendSolidityParser::ElementaryTypeNameContext *context) = 0;

    virtual std::any visitExpression(ExtendSolidityParser::ExpressionContext *context) = 0;

    virtual std::any visitPostOperator(ExtendSolidityParser::PostOperatorContext *context) = 0;

    virtual std::any visitPreOperator(ExtendSolidityParser::PreOperatorContext *context) = 0;

    virtual std::any visitMidOperator(ExtendSolidityParser::MidOperatorContext *context) = 0;

    virtual std::any visitPrimaryExpression(ExtendSolidityParser::PrimaryExpressionContext *context) = 0;

    virtual std::any visitMatchedParentheses(ExtendSolidityParser::MatchedParenthesesContext *context) = 0;

    virtual std::any visitExpressionList(ExtendSolidityParser::ExpressionListContext *context) = 0;

    virtual std::any visitNameValueList(ExtendSolidityParser::NameValueListContext *context) = 0;

    virtual std::any visitNameValue(ExtendSolidityParser::NameValueContext *context) = 0;

    virtual std::any visitFunctionCallArguments(ExtendSolidityParser::FunctionCallArgumentsContext *context) = 0;

    virtual std::any visitFunctionCall(ExtendSolidityParser::FunctionCallContext *context) = 0;

    virtual std::any visitAssemblyBlock(ExtendSolidityParser::AssemblyBlockContext *context) = 0;

    virtual std::any visitAssemblyItem(ExtendSolidityParser::AssemblyItemContext *context) = 0;

    virtual std::any visitAssemblyExpression(ExtendSolidityParser::AssemblyExpressionContext *context) = 0;

    virtual std::any visitAssemblyCall(ExtendSolidityParser::AssemblyCallContext *context) = 0;

    virtual std::any visitAssemblyLocalDefinition(ExtendSolidityParser::AssemblyLocalDefinitionContext *context) = 0;

    virtual std::any visitAssemblyAssignment(ExtendSolidityParser::AssemblyAssignmentContext *context) = 0;

    virtual std::any visitAssemblyIdentifierOrList(ExtendSolidityParser::AssemblyIdentifierOrListContext *context) = 0;

    virtual std::any visitAssemblyIdentifierList(ExtendSolidityParser::AssemblyIdentifierListContext *context) = 0;

    virtual std::any visitAssemblyStackAssignment(ExtendSolidityParser::AssemblyStackAssignmentContext *context) = 0;

    virtual std::any visitLabelDefinition(ExtendSolidityParser::LabelDefinitionContext *context) = 0;

    virtual std::any visitAssemblySwitch(ExtendSolidityParser::AssemblySwitchContext *context) = 0;

    virtual std::any visitAssemblyCase(ExtendSolidityParser::AssemblyCaseContext *context) = 0;

    virtual std::any visitAssemblyFunctionDefinition(ExtendSolidityParser::AssemblyFunctionDefinitionContext *context) = 0;

    virtual std::any visitAssemblyFunctionReturns(ExtendSolidityParser::AssemblyFunctionReturnsContext *context) = 0;

    virtual std::any visitAssemblyFor(ExtendSolidityParser::AssemblyForContext *context) = 0;

    virtual std::any visitAssemblyIf(ExtendSolidityParser::AssemblyIfContext *context) = 0;

    virtual std::any visitAssemblyLiteral(ExtendSolidityParser::AssemblyLiteralContext *context) = 0;

    virtual std::any visitSubAssembly(ExtendSolidityParser::SubAssemblyContext *context) = 0;

    virtual std::any visitTupleExpression(ExtendSolidityParser::TupleExpressionContext *context) = 0;

    virtual std::any visitBracketTupleExpression(ExtendSolidityParser::BracketTupleExpressionContext *context) = 0;

    virtual std::any visitMoreExpression(ExtendSolidityParser::MoreExpressionContext *context) = 0;

    virtual std::any visitParanthesesTupleExpression(ExtendSolidityParser::ParanthesesTupleExpressionContext *context) = 0;

    virtual std::any visitTypeNameExpression(ExtendSolidityParser::TypeNameExpressionContext *context) = 0;

    virtual std::any visitNumberLiteral(ExtendSolidityParser::NumberLiteralContext *context) = 0;

    virtual std::any visitIdentifier(ExtendSolidityParser::IdentifierContext *context) = 0;

    virtual std::any visitScope(ExtendSolidityParser::ScopeContext *context) = 0;

    virtual std::any visitAccessSpecifier(ExtendSolidityParser::AccessSpecifierContext *context) = 0;


};

