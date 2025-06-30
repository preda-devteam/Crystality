
// Generated from SolidityScript.g4 by ANTLR 4.12.0

#pragma once


#include "antlr4-runtime.h"




class  SolidityScriptParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, WINPATH = 19, WIN_ABSOLUTE_PATH = 20, 
    WIN_REALATIVE_PATH = 21, UNIXPATH = 22, UNIX_ABSOLUTE_PATH = 23, UNIX_REALATIVE_PATH = 24, 
    CHAIN = 25, STOPWATCH = 26, RANDOM = 27, ALL = 28, INTRA = 29, CROSS = 30, 
    UINT16 = 31, UINT32 = 32, UINT256 = 33, ADDRESS = 34, BOOL = 35, EVMC_ADDRESS = 36, 
    BYTES = 37, StringLiteral = 38, TRUE = 39, FALSE = 40, DEPLOY = 41, 
    Identifier = 42, DecimalNumber = 43, HexNumber = 44, WS = 45, CommentSingleLine = 46, 
    CommentMultiLine = 47
  };

  enum {
    RuleSource = 0, RuleScript = 1, RuleVariableDeclaration = 2, RuleFunctionCall = 3, 
    RuleVizTrace = 4, RuleChainParams = 5, RuleContractName = 6, RuleDeployAddress = 7, 
    RuleInputCSV = 8, RuleCount = 9, RuleScope = 10, RuleArguments = 11, 
    RuleArgument = 12, RuleExplicitTypeValue = 13, RuleType = 14, RuleIdentifier = 15, 
    RuleExpression = 16, RuleRandomCall = 17, RuleStringArray = 18, RuleStructArray = 19, 
    RuleRandomCallCount = 20, RuleRandomCallArguments = 21, RuleNumberLiteral = 22, 
    RuleMatchedParentheses = 23, RuleSolFile = 24, RuleXtlFile = 25, RuleDirectivePath = 26, 
    RuleBoolLiteral = 27
  };

  explicit SolidityScriptParser(antlr4::TokenStream *input);

  SolidityScriptParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~SolidityScriptParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class SourceContext;
  class ScriptContext;
  class VariableDeclarationContext;
  class FunctionCallContext;
  class VizTraceContext;
  class ChainParamsContext;
  class ContractNameContext;
  class DeployAddressContext;
  class InputCSVContext;
  class CountContext;
  class ScopeContext;
  class ArgumentsContext;
  class ArgumentContext;
  class ExplicitTypeValueContext;
  class TypeContext;
  class IdentifierContext;
  class ExpressionContext;
  class RandomCallContext;
  class StringArrayContext;
  class StructArrayContext;
  class RandomCallCountContext;
  class RandomCallArgumentsContext;
  class NumberLiteralContext;
  class MatchedParenthesesContext;
  class SolFileContext;
  class XtlFileContext;
  class DirectivePathContext;
  class BoolLiteralContext; 

  class  SourceContext : public antlr4::ParserRuleContext {
  public:
    SourceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<ScriptContext *> script();
    ScriptContext* script(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SourceContext* source();

  class  ScriptContext : public antlr4::ParserRuleContext {
  public:
    ScriptContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VariableDeclarationContext *variableDeclaration();
    FunctionCallContext *functionCall();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ScriptContext* script();

  class  VariableDeclarationContext : public antlr4::ParserRuleContext {
  public:
    VariableDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    IdentifierContext *identifier();
    MatchedParenthesesContext *matchedParentheses();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VariableDeclarationContext* variableDeclaration();

  class  FunctionCallContext : public antlr4::ParserRuleContext {
  public:
    FunctionCallContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CHAIN();
    antlr4::tree::TerminalNode *DEPLOY();
    SolFileContext *solFile();
    XtlFileContext *xtlFile();
    ScopeContext *scope();
    ArgumentsContext *arguments();
    IdentifierContext *identifier();
    ChainParamsContext *chainParams();
    antlr4::tree::TerminalNode *STOPWATCH();
    VizTraceContext *vizTrace();
    ExpressionContext *expression();
    CountContext *count();
    InputCSVContext *inputCSV();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionCallContext* functionCall();

  class  VizTraceContext : public antlr4::ParserRuleContext {
  public:
    VizTraceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();
    NumberLiteralContext *numberLiteral();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VizTraceContext* vizTrace();

  class  ChainParamsContext : public antlr4::ParserRuleContext {
  public:
    ChainParamsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ContractNameContext *contractName();
    NumberLiteralContext *numberLiteral();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ChainParamsContext* chainParams();

  class  ContractNameContext : public antlr4::ParserRuleContext {
  public:
    ContractNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ContractNameContext* contractName();

  class  DeployAddressContext : public antlr4::ParserRuleContext {
  public:
    DeployAddressContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DeployAddressContext* deployAddress();

  class  InputCSVContext : public antlr4::ParserRuleContext {
  public:
    InputCSVContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InputCSVContext* inputCSV();

  class  CountContext : public antlr4::ParserRuleContext {
  public:
    CountContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NumberLiteralContext *numberLiteral();
    IdentifierContext *identifier();
    antlr4::tree::TerminalNode *UINT32();
    antlr4::tree::TerminalNode *RANDOM();
    RandomCallArgumentsContext *randomCallArguments();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CountContext* count();

  class  ScopeContext : public antlr4::ParserRuleContext {
  public:
    ScopeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();
    NumberLiteralContext *numberLiteral();
    antlr4::tree::TerminalNode *ALL();
    antlr4::tree::TerminalNode *RANDOM();
    antlr4::tree::TerminalNode *INTRA();
    antlr4::tree::TerminalNode *CROSS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ScopeContext* scope();

  class  ArgumentsContext : public antlr4::ParserRuleContext {
  public:
    ArgumentsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ArgumentContext *> argument();
    ArgumentContext* argument(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArgumentsContext* arguments();

  class  ArgumentContext : public antlr4::ParserRuleContext {
  public:
    ArgumentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExplicitTypeValueContext *explicitTypeValue();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArgumentContext* argument();

  class  ExplicitTypeValueContext : public antlr4::ParserRuleContext {
  public:
    ExplicitTypeValueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeContext *type();
    NumberLiteralContext *numberLiteral();
    antlr4::tree::TerminalNode *StringLiteral();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExplicitTypeValueContext* explicitTypeValue();

  class  TypeContext : public antlr4::ParserRuleContext {
  public:
    TypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *UINT16();
    antlr4::tree::TerminalNode *UINT32();
    antlr4::tree::TerminalNode *UINT256();
    antlr4::tree::TerminalNode *ADDRESS();
    antlr4::tree::TerminalNode *BOOL();
    antlr4::tree::TerminalNode *BYTES();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeContext* type();

  class  IdentifierContext : public antlr4::ParserRuleContext {
  public:
    IdentifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IdentifierContext* identifier();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    int expressionType = -1;
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EVMC_ADDRESS();
    NumberLiteralContext *numberLiteral();
    RandomCallContext *randomCall();
    BoolLiteralContext *boolLiteral();
    antlr4::tree::TerminalNode *StringLiteral();
    StringArrayContext *stringArray();
    StructArrayContext *structArray();
    IdentifierContext *identifier();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExpressionContext* expression();
  ExpressionContext* expression(int precedence);
  class  RandomCallContext : public antlr4::ParserRuleContext {
  public:
    RandomCallContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RANDOM();
    antlr4::tree::TerminalNode *UINT16();
    antlr4::tree::TerminalNode *UINT32();
    antlr4::tree::TerminalNode *UINT256();
    antlr4::tree::TerminalNode *ADDRESS();
    antlr4::tree::TerminalNode *BOOL();
    RandomCallCountContext *randomCallCount();
    RandomCallArgumentsContext *randomCallArguments();
    IdentifierContext *identifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RandomCallContext* randomCall();

  class  StringArrayContext : public antlr4::ParserRuleContext {
  public:
    StringArrayContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> StringLiteral();
    antlr4::tree::TerminalNode* StringLiteral(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StringArrayContext* stringArray();

  class  StructArrayContext : public antlr4::ParserRuleContext {
  public:
    StructArrayContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ArgumentsContext *arguments();
    NumberLiteralContext *numberLiteral();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StructArrayContext* structArray();

  class  RandomCallCountContext : public antlr4::ParserRuleContext {
  public:
    RandomCallCountContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NumberLiteralContext *numberLiteral();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RandomCallCountContext* randomCallCount();

  class  RandomCallArgumentsContext : public antlr4::ParserRuleContext {
  public:
    RandomCallArgumentsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ArgumentsContext *arguments();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RandomCallArgumentsContext* randomCallArguments();

  class  NumberLiteralContext : public antlr4::ParserRuleContext {
  public:
    NumberLiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DecimalNumber();
    antlr4::tree::TerminalNode *HexNumber();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NumberLiteralContext* numberLiteral();

  class  MatchedParenthesesContext : public antlr4::ParserRuleContext {
  public:
    MatchedParenthesesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MatchedParenthesesContext* matchedParentheses();

  class  SolFileContext : public antlr4::ParserRuleContext {
  public:
    SolFileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();
    DirectivePathContext *directivePath();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SolFileContext* solFile();

  class  XtlFileContext : public antlr4::ParserRuleContext {
  public:
    XtlFileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();
    DirectivePathContext *directivePath();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  XtlFileContext* xtlFile();

  class  DirectivePathContext : public antlr4::ParserRuleContext {
  public:
    DirectivePathContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WINPATH();
    antlr4::tree::TerminalNode *UNIXPATH();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DirectivePathContext* directivePath();

  class  BoolLiteralContext : public antlr4::ParserRuleContext {
  public:
    BoolLiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TRUE();
    antlr4::tree::TerminalNode *FALSE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BoolLiteralContext* boolLiteral();


  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool expressionSempred(ExpressionContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

