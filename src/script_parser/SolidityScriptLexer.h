
// Generated from SolidityScript.g4 by ANTLR 4.12.0

#pragma once


#include "antlr4-runtime.h"




class  SolidityScriptLexer : public antlr4::Lexer {
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

  explicit SolidityScriptLexer(antlr4::CharStream *input);

  ~SolidityScriptLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

