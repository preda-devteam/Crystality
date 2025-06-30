
// Generated from SolidityScript.g4 by ANTLR 4.12.0


#include "SolidityScriptListener.h"
#include "SolidityScriptVisitor.h"

#include "SolidityScriptParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct SolidityScriptParserStaticData final {
  SolidityScriptParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  SolidityScriptParserStaticData(const SolidityScriptParserStaticData&) = delete;
  SolidityScriptParserStaticData(SolidityScriptParserStaticData&&) = delete;
  SolidityScriptParserStaticData& operator=(const SolidityScriptParserStaticData&) = delete;
  SolidityScriptParserStaticData& operator=(SolidityScriptParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag solidityscriptParserOnceFlag;
SolidityScriptParserStaticData *solidityscriptParserStaticData = nullptr;

void solidityscriptParserInitialize() {
  assert(solidityscriptParserStaticData == nullptr);
  auto staticData = std::make_unique<SolidityScriptParserStaticData>(
    std::vector<std::string>{
      "source", "script", "variableDeclaration", "functionCall", "vizTrace", 
      "chainParams", "contractName", "deployAddress", "inputCSV", "count", 
      "scope", "arguments", "argument", "explicitTypeValue", "type", "identifier", 
      "expression", "randomCall", "stringArray", "structArray", "randomCallCount", 
      "randomCallArguments", "numberLiteral", "matchedParentheses", "solFile", 
      "xtlFile", "directivePath", "boolLiteral"
    },
    std::vector<std::string>{
      "", "'='", "'.'", "'('", "')'", "'<<'", "'viz'", "'trace'", "'['", 
      "']'", "'.csv'", "'*'", "'@'", "','", "'::'", "'{'", "'}'", "'.sol'", 
      "'.xtl'", "", "", "", "", "", "", "'chain'", "'stopwatch'", "'random'", 
      "'all'", "'intra'", "'cross'", "'uint16'", "'uint32'", "'uint256'", 
      "'address'", "'bool'", "'evmc::address'", "'bytes32'", "", "'true'", 
      "'false'", "'deploy'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "WINPATH", "WIN_ABSOLUTE_PATH", "WIN_REALATIVE_PATH", "UNIXPATH", 
      "UNIX_ABSOLUTE_PATH", "UNIX_REALATIVE_PATH", "CHAIN", "STOPWATCH", 
      "RANDOM", "ALL", "INTRA", "CROSS", "UINT16", "UINT32", "UINT256", 
      "ADDRESS", "BOOL", "EVMC_ADDRESS", "BYTES", "StringLiteral", "TRUE", 
      "FALSE", "DEPLOY", "Identifier", "DecimalNumber", "HexNumber", "WS", 
      "CommentSingleLine", "CommentMultiLine"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,47,309,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,1,0,5,
  	0,58,8,0,10,0,12,0,61,9,0,1,0,1,0,1,1,1,1,3,1,67,8,1,1,2,1,2,3,2,71,8,
  	2,1,2,1,2,1,2,1,3,1,3,1,3,1,3,3,3,80,8,3,1,3,1,3,3,3,84,8,3,1,3,1,3,3,
  	3,88,8,3,1,3,3,3,91,8,3,1,3,1,3,1,3,1,3,3,3,97,8,3,1,3,1,3,1,3,1,3,1,
  	3,1,3,1,3,3,3,106,8,3,1,3,1,3,3,3,110,8,3,1,3,3,3,113,8,3,1,3,1,3,3,3,
  	117,8,3,1,3,1,3,1,3,1,3,1,3,1,3,3,3,125,8,3,1,4,1,4,1,4,1,4,1,4,1,4,1,
  	4,1,4,3,4,135,8,4,1,5,1,5,3,5,139,8,5,1,6,1,6,1,7,1,7,1,8,1,8,1,8,1,9,
  	1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,3,9,157,8,9,1,10,1,10,1,10,1,10,1,10,
  	1,10,1,10,1,10,3,10,167,8,10,1,10,1,10,3,10,171,8,10,1,11,1,11,1,11,5,
  	11,176,8,11,10,11,12,11,179,9,11,1,12,1,12,3,12,183,8,12,1,13,1,13,3,
  	13,187,8,13,1,13,1,13,1,13,1,14,1,14,1,15,1,15,1,16,1,16,1,16,1,16,1,
  	16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,
  	16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,3,16,225,8,16,1,
  	16,1,16,3,16,229,8,16,1,16,1,16,1,16,1,16,1,16,5,16,236,8,16,10,16,12,
  	16,239,9,16,1,17,1,17,1,17,1,17,3,17,245,8,17,1,17,3,17,248,8,17,1,17,
  	1,17,1,17,1,17,3,17,254,8,17,3,17,256,8,17,1,18,1,18,1,18,1,18,5,18,262,
  	8,18,10,18,12,18,265,9,18,1,18,1,18,1,19,1,19,1,19,1,19,1,19,1,19,1,19,
  	3,19,276,8,19,1,20,1,20,1,20,1,20,1,21,1,21,3,21,284,8,21,1,21,1,21,1,
  	22,1,22,1,23,1,23,1,23,1,24,3,24,294,8,24,1,24,1,24,1,24,1,25,3,25,300,
  	8,25,1,25,1,25,1,25,1,26,1,26,1,27,1,27,1,27,0,1,32,28,0,2,4,6,8,10,12,
  	14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,0,6,1,
  	0,27,30,2,0,31,35,37,37,1,0,31,35,1,0,43,44,2,0,19,19,22,22,1,0,39,40,
  	325,0,59,1,0,0,0,2,66,1,0,0,0,4,68,1,0,0,0,6,124,1,0,0,0,8,126,1,0,0,
  	0,10,138,1,0,0,0,12,140,1,0,0,0,14,142,1,0,0,0,16,144,1,0,0,0,18,156,
  	1,0,0,0,20,170,1,0,0,0,22,172,1,0,0,0,24,182,1,0,0,0,26,186,1,0,0,0,28,
  	191,1,0,0,0,30,193,1,0,0,0,32,228,1,0,0,0,34,255,1,0,0,0,36,257,1,0,0,
  	0,38,268,1,0,0,0,40,277,1,0,0,0,42,281,1,0,0,0,44,287,1,0,0,0,46,289,
  	1,0,0,0,48,293,1,0,0,0,50,299,1,0,0,0,52,304,1,0,0,0,54,306,1,0,0,0,56,
  	58,3,2,1,0,57,56,1,0,0,0,58,61,1,0,0,0,59,57,1,0,0,0,59,60,1,0,0,0,60,
  	62,1,0,0,0,61,59,1,0,0,0,62,63,5,0,0,1,63,1,1,0,0,0,64,67,3,4,2,0,65,
  	67,3,6,3,0,66,64,1,0,0,0,66,65,1,0,0,0,67,3,1,0,0,0,68,70,3,30,15,0,69,
  	71,3,46,23,0,70,69,1,0,0,0,70,71,1,0,0,0,71,72,1,0,0,0,72,73,5,1,0,0,
  	73,74,3,32,16,0,74,5,1,0,0,0,75,76,5,25,0,0,76,77,5,2,0,0,77,79,5,41,
  	0,0,78,80,3,20,10,0,79,78,1,0,0,0,79,80,1,0,0,0,80,83,1,0,0,0,81,84,3,
  	48,24,0,82,84,3,50,25,0,83,81,1,0,0,0,83,82,1,0,0,0,84,90,1,0,0,0,85,
  	87,5,3,0,0,86,88,3,22,11,0,87,86,1,0,0,0,87,88,1,0,0,0,88,89,1,0,0,0,
  	89,91,5,4,0,0,90,85,1,0,0,0,90,91,1,0,0,0,91,125,1,0,0,0,92,93,5,25,0,
  	0,93,94,5,2,0,0,94,96,3,30,15,0,95,97,3,10,5,0,96,95,1,0,0,0,96,97,1,
  	0,0,0,97,125,1,0,0,0,98,99,5,26,0,0,99,100,5,2,0,0,100,125,3,30,15,0,
  	101,125,3,8,4,0,102,103,3,30,15,0,103,104,5,1,0,0,104,106,1,0,0,0,105,
  	102,1,0,0,0,105,106,1,0,0,0,106,107,1,0,0,0,107,109,3,32,16,0,108,110,
  	3,18,9,0,109,108,1,0,0,0,109,110,1,0,0,0,110,112,1,0,0,0,111,113,3,20,
  	10,0,112,111,1,0,0,0,112,113,1,0,0,0,113,114,1,0,0,0,114,116,5,3,0,0,
  	115,117,3,22,11,0,116,115,1,0,0,0,116,117,1,0,0,0,117,118,1,0,0,0,118,
  	119,5,4,0,0,119,125,1,0,0,0,120,121,3,30,15,0,121,122,5,5,0,0,122,123,
  	3,16,8,0,123,125,1,0,0,0,124,75,1,0,0,0,124,92,1,0,0,0,124,98,1,0,0,0,
  	124,101,1,0,0,0,124,105,1,0,0,0,124,120,1,0,0,0,125,7,1,0,0,0,126,127,
  	5,6,0,0,127,128,5,2,0,0,128,129,5,7,0,0,129,134,3,30,15,0,130,131,5,8,
  	0,0,131,132,3,44,22,0,132,133,5,9,0,0,133,135,1,0,0,0,134,130,1,0,0,0,
  	134,135,1,0,0,0,135,9,1,0,0,0,136,139,3,12,6,0,137,139,3,44,22,0,138,
  	136,1,0,0,0,138,137,1,0,0,0,139,11,1,0,0,0,140,141,3,30,15,0,141,13,1,
  	0,0,0,142,143,3,30,15,0,143,15,1,0,0,0,144,145,3,30,15,0,145,146,5,10,
  	0,0,146,17,1,0,0,0,147,148,5,11,0,0,148,157,3,44,22,0,149,150,5,11,0,
  	0,150,157,3,30,15,0,151,152,5,11,0,0,152,153,5,32,0,0,153,154,5,2,0,0,
  	154,155,5,27,0,0,155,157,3,42,21,0,156,147,1,0,0,0,156,149,1,0,0,0,156,
  	151,1,0,0,0,157,19,1,0,0,0,158,159,5,12,0,0,159,166,3,30,15,0,160,161,
  	5,2,0,0,161,167,7,0,0,0,162,163,5,8,0,0,163,164,3,44,22,0,164,165,5,9,
  	0,0,165,167,1,0,0,0,166,160,1,0,0,0,166,162,1,0,0,0,166,167,1,0,0,0,167,
  	171,1,0,0,0,168,169,5,12,0,0,169,171,3,44,22,0,170,158,1,0,0,0,170,168,
  	1,0,0,0,171,21,1,0,0,0,172,177,3,24,12,0,173,174,5,13,0,0,174,176,3,24,
  	12,0,175,173,1,0,0,0,176,179,1,0,0,0,177,175,1,0,0,0,177,178,1,0,0,0,
  	178,23,1,0,0,0,179,177,1,0,0,0,180,183,3,26,13,0,181,183,3,32,16,0,182,
  	180,1,0,0,0,182,181,1,0,0,0,183,25,1,0,0,0,184,187,3,44,22,0,185,187,
  	5,38,0,0,186,184,1,0,0,0,186,185,1,0,0,0,187,188,1,0,0,0,188,189,5,14,
  	0,0,189,190,3,28,14,0,190,27,1,0,0,0,191,192,7,1,0,0,192,29,1,0,0,0,193,
  	194,5,42,0,0,194,31,1,0,0,0,195,196,6,16,-1,0,196,197,5,36,0,0,197,198,
  	5,8,0,0,198,199,3,44,22,0,199,200,5,9,0,0,200,201,6,16,-1,0,201,229,1,
  	0,0,0,202,203,3,34,17,0,203,204,6,16,-1,0,204,229,1,0,0,0,205,206,3,44,
  	22,0,206,207,6,16,-1,0,207,229,1,0,0,0,208,209,3,54,27,0,209,210,6,16,
  	-1,0,210,229,1,0,0,0,211,212,5,38,0,0,212,229,6,16,-1,0,213,214,3,36,
  	18,0,214,215,6,16,-1,0,215,229,1,0,0,0,216,217,3,38,19,0,217,218,6,16,
  	-1,0,218,229,1,0,0,0,219,224,3,30,15,0,220,221,5,8,0,0,221,222,3,44,22,
  	0,222,223,5,9,0,0,223,225,1,0,0,0,224,220,1,0,0,0,224,225,1,0,0,0,225,
  	226,1,0,0,0,226,227,6,16,-1,0,227,229,1,0,0,0,228,195,1,0,0,0,228,202,
  	1,0,0,0,228,205,1,0,0,0,228,208,1,0,0,0,228,211,1,0,0,0,228,213,1,0,0,
  	0,228,216,1,0,0,0,228,219,1,0,0,0,229,237,1,0,0,0,230,231,10,7,0,0,231,
  	232,5,2,0,0,232,233,3,30,15,0,233,234,6,16,-1,0,234,236,1,0,0,0,235,230,
  	1,0,0,0,236,239,1,0,0,0,237,235,1,0,0,0,237,238,1,0,0,0,238,33,1,0,0,
  	0,239,237,1,0,0,0,240,241,7,2,0,0,241,242,5,2,0,0,242,244,5,27,0,0,243,
  	245,3,40,20,0,244,243,1,0,0,0,244,245,1,0,0,0,245,247,1,0,0,0,246,248,
  	3,42,21,0,247,246,1,0,0,0,247,248,1,0,0,0,248,256,1,0,0,0,249,250,3,30,
  	15,0,250,251,5,2,0,0,251,253,5,27,0,0,252,254,3,40,20,0,253,252,1,0,0,
  	0,253,254,1,0,0,0,254,256,1,0,0,0,255,240,1,0,0,0,255,249,1,0,0,0,256,
  	35,1,0,0,0,257,258,5,15,0,0,258,263,5,38,0,0,259,260,5,13,0,0,260,262,
  	5,38,0,0,261,259,1,0,0,0,262,265,1,0,0,0,263,261,1,0,0,0,263,264,1,0,
  	0,0,264,266,1,0,0,0,265,263,1,0,0,0,266,267,5,16,0,0,267,37,1,0,0,0,268,
  	269,5,15,0,0,269,270,3,22,11,0,270,275,5,16,0,0,271,272,5,8,0,0,272,273,
  	3,44,22,0,273,274,5,9,0,0,274,276,1,0,0,0,275,271,1,0,0,0,275,276,1,0,
  	0,0,276,39,1,0,0,0,277,278,5,8,0,0,278,279,3,44,22,0,279,280,5,9,0,0,
  	280,41,1,0,0,0,281,283,5,3,0,0,282,284,3,22,11,0,283,282,1,0,0,0,283,
  	284,1,0,0,0,284,285,1,0,0,0,285,286,5,4,0,0,286,43,1,0,0,0,287,288,7,
  	3,0,0,288,45,1,0,0,0,289,290,5,8,0,0,290,291,5,9,0,0,291,47,1,0,0,0,292,
  	294,3,52,26,0,293,292,1,0,0,0,293,294,1,0,0,0,294,295,1,0,0,0,295,296,
  	3,30,15,0,296,297,5,17,0,0,297,49,1,0,0,0,298,300,3,52,26,0,299,298,1,
  	0,0,0,299,300,1,0,0,0,300,301,1,0,0,0,301,302,3,30,15,0,302,303,5,18,
  	0,0,303,51,1,0,0,0,304,305,7,4,0,0,305,53,1,0,0,0,306,307,7,5,0,0,307,
  	55,1,0,0,0,33,59,66,70,79,83,87,90,96,105,109,112,116,124,134,138,156,
  	166,170,177,182,186,224,228,237,244,247,253,255,263,275,283,293,299
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  solidityscriptParserStaticData = staticData.release();
}

}

SolidityScriptParser::SolidityScriptParser(TokenStream *input) : SolidityScriptParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

SolidityScriptParser::SolidityScriptParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  SolidityScriptParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *solidityscriptParserStaticData->atn, solidityscriptParserStaticData->decisionToDFA, solidityscriptParserStaticData->sharedContextCache, options);
}

SolidityScriptParser::~SolidityScriptParser() {
  delete _interpreter;
}

const atn::ATN& SolidityScriptParser::getATN() const {
  return *solidityscriptParserStaticData->atn;
}

std::string SolidityScriptParser::getGrammarFileName() const {
  return "SolidityScript.g4";
}

const std::vector<std::string>& SolidityScriptParser::getRuleNames() const {
  return solidityscriptParserStaticData->ruleNames;
}

const dfa::Vocabulary& SolidityScriptParser::getVocabulary() const {
  return solidityscriptParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView SolidityScriptParser::getSerializedATN() const {
  return solidityscriptParserStaticData->serializedATN;
}


//----------------- SourceContext ------------------------------------------------------------------

SolidityScriptParser::SourceContext::SourceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SolidityScriptParser::SourceContext::EOF() {
  return getToken(SolidityScriptParser::EOF, 0);
}

std::vector<SolidityScriptParser::ScriptContext *> SolidityScriptParser::SourceContext::script() {
  return getRuleContexts<SolidityScriptParser::ScriptContext>();
}

SolidityScriptParser::ScriptContext* SolidityScriptParser::SourceContext::script(size_t i) {
  return getRuleContext<SolidityScriptParser::ScriptContext>(i);
}


size_t SolidityScriptParser::SourceContext::getRuleIndex() const {
  return SolidityScriptParser::RuleSource;
}

void SolidityScriptParser::SourceContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolidityScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSource(this);
}

void SolidityScriptParser::SourceContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolidityScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSource(this);
}


std::any SolidityScriptParser::SourceContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SolidityScriptVisitor*>(visitor))
    return parserVisitor->visitSource(this);
  else
    return visitor->visitChildren(this);
}

SolidityScriptParser::SourceContext* SolidityScriptParser::source() {
  SourceContext *_localctx = _tracker.createInstance<SourceContext>(_ctx, getState());
  enterRule(_localctx, 0, SolidityScriptParser::RuleSource);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(59);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 32845863092288) != 0)) {
      setState(56);
      script();
      setState(61);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(62);
    match(SolidityScriptParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ScriptContext ------------------------------------------------------------------

SolidityScriptParser::ScriptContext::ScriptContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SolidityScriptParser::VariableDeclarationContext* SolidityScriptParser::ScriptContext::variableDeclaration() {
  return getRuleContext<SolidityScriptParser::VariableDeclarationContext>(0);
}

SolidityScriptParser::FunctionCallContext* SolidityScriptParser::ScriptContext::functionCall() {
  return getRuleContext<SolidityScriptParser::FunctionCallContext>(0);
}


size_t SolidityScriptParser::ScriptContext::getRuleIndex() const {
  return SolidityScriptParser::RuleScript;
}

void SolidityScriptParser::ScriptContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolidityScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterScript(this);
}

void SolidityScriptParser::ScriptContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolidityScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitScript(this);
}


std::any SolidityScriptParser::ScriptContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SolidityScriptVisitor*>(visitor))
    return parserVisitor->visitScript(this);
  else
    return visitor->visitChildren(this);
}

SolidityScriptParser::ScriptContext* SolidityScriptParser::script() {
  ScriptContext *_localctx = _tracker.createInstance<ScriptContext>(_ctx, getState());
  enterRule(_localctx, 2, SolidityScriptParser::RuleScript);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(66);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(64);
      variableDeclaration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(65);
      functionCall();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableDeclarationContext ------------------------------------------------------------------

SolidityScriptParser::VariableDeclarationContext::VariableDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SolidityScriptParser::ExpressionContext* SolidityScriptParser::VariableDeclarationContext::expression() {
  return getRuleContext<SolidityScriptParser::ExpressionContext>(0);
}

SolidityScriptParser::IdentifierContext* SolidityScriptParser::VariableDeclarationContext::identifier() {
  return getRuleContext<SolidityScriptParser::IdentifierContext>(0);
}

SolidityScriptParser::MatchedParenthesesContext* SolidityScriptParser::VariableDeclarationContext::matchedParentheses() {
  return getRuleContext<SolidityScriptParser::MatchedParenthesesContext>(0);
}


size_t SolidityScriptParser::VariableDeclarationContext::getRuleIndex() const {
  return SolidityScriptParser::RuleVariableDeclaration;
}

void SolidityScriptParser::VariableDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolidityScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariableDeclaration(this);
}

void SolidityScriptParser::VariableDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolidityScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariableDeclaration(this);
}


std::any SolidityScriptParser::VariableDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SolidityScriptVisitor*>(visitor))
    return parserVisitor->visitVariableDeclaration(this);
  else
    return visitor->visitChildren(this);
}

SolidityScriptParser::VariableDeclarationContext* SolidityScriptParser::variableDeclaration() {
  VariableDeclarationContext *_localctx = _tracker.createInstance<VariableDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 4, SolidityScriptParser::RuleVariableDeclaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(68);
    identifier();
    setState(70);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SolidityScriptParser::T__7) {
      setState(69);
      matchedParentheses();
    }
    setState(72);
    match(SolidityScriptParser::T__0);
    setState(73);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionCallContext ------------------------------------------------------------------

SolidityScriptParser::FunctionCallContext::FunctionCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SolidityScriptParser::FunctionCallContext::CHAIN() {
  return getToken(SolidityScriptParser::CHAIN, 0);
}

tree::TerminalNode* SolidityScriptParser::FunctionCallContext::DEPLOY() {
  return getToken(SolidityScriptParser::DEPLOY, 0);
}

SolidityScriptParser::SolFileContext* SolidityScriptParser::FunctionCallContext::solFile() {
  return getRuleContext<SolidityScriptParser::SolFileContext>(0);
}

SolidityScriptParser::XtlFileContext* SolidityScriptParser::FunctionCallContext::xtlFile() {
  return getRuleContext<SolidityScriptParser::XtlFileContext>(0);
}

SolidityScriptParser::ScopeContext* SolidityScriptParser::FunctionCallContext::scope() {
  return getRuleContext<SolidityScriptParser::ScopeContext>(0);
}

SolidityScriptParser::ArgumentsContext* SolidityScriptParser::FunctionCallContext::arguments() {
  return getRuleContext<SolidityScriptParser::ArgumentsContext>(0);
}

SolidityScriptParser::IdentifierContext* SolidityScriptParser::FunctionCallContext::identifier() {
  return getRuleContext<SolidityScriptParser::IdentifierContext>(0);
}

SolidityScriptParser::ChainParamsContext* SolidityScriptParser::FunctionCallContext::chainParams() {
  return getRuleContext<SolidityScriptParser::ChainParamsContext>(0);
}

tree::TerminalNode* SolidityScriptParser::FunctionCallContext::STOPWATCH() {
  return getToken(SolidityScriptParser::STOPWATCH, 0);
}

SolidityScriptParser::VizTraceContext* SolidityScriptParser::FunctionCallContext::vizTrace() {
  return getRuleContext<SolidityScriptParser::VizTraceContext>(0);
}

SolidityScriptParser::ExpressionContext* SolidityScriptParser::FunctionCallContext::expression() {
  return getRuleContext<SolidityScriptParser::ExpressionContext>(0);
}

SolidityScriptParser::CountContext* SolidityScriptParser::FunctionCallContext::count() {
  return getRuleContext<SolidityScriptParser::CountContext>(0);
}

SolidityScriptParser::InputCSVContext* SolidityScriptParser::FunctionCallContext::inputCSV() {
  return getRuleContext<SolidityScriptParser::InputCSVContext>(0);
}


size_t SolidityScriptParser::FunctionCallContext::getRuleIndex() const {
  return SolidityScriptParser::RuleFunctionCall;
}

void SolidityScriptParser::FunctionCallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolidityScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCall(this);
}

void SolidityScriptParser::FunctionCallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolidityScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCall(this);
}


std::any SolidityScriptParser::FunctionCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SolidityScriptVisitor*>(visitor))
    return parserVisitor->visitFunctionCall(this);
  else
    return visitor->visitChildren(this);
}

SolidityScriptParser::FunctionCallContext* SolidityScriptParser::functionCall() {
  FunctionCallContext *_localctx = _tracker.createInstance<FunctionCallContext>(_ctx, getState());
  enterRule(_localctx, 6, SolidityScriptParser::RuleFunctionCall);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(124);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(75);
      match(SolidityScriptParser::CHAIN);
      setState(76);
      match(SolidityScriptParser::T__1);
      setState(77);
      match(SolidityScriptParser::DEPLOY);
      setState(79);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SolidityScriptParser::T__11) {
        setState(78);
        scope();
      }
      setState(83);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
      case 1: {
        setState(81);
        solFile();
        break;
      }

      case 2: {
        setState(82);
        xtlFile();
        break;
      }

      default:
        break;
      }
      setState(90);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SolidityScriptParser::T__2) {
        setState(85);
        match(SolidityScriptParser::T__2);
        setState(87);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 32845762428928) != 0)) {
          setState(86);
          arguments();
        }
        setState(89);
        match(SolidityScriptParser::T__3);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(92);
      match(SolidityScriptParser::CHAIN);
      setState(93);
      match(SolidityScriptParser::T__1);
      setState(94);
      identifier();
      setState(96);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
      case 1: {
        setState(95);
        chainParams();
        break;
      }

      default:
        break;
      }
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(98);
      match(SolidityScriptParser::STOPWATCH);
      setState(99);
      match(SolidityScriptParser::T__1);
      setState(100);
      identifier();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(101);
      vizTrace();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(105);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
      case 1: {
        setState(102);
        identifier();
        setState(103);
        match(SolidityScriptParser::T__0);
        break;
      }

      default:
        break;
      }
      setState(107);
      expression(0);
      setState(109);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SolidityScriptParser::T__10) {
        setState(108);
        count();
      }
      setState(112);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SolidityScriptParser::T__11) {
        setState(111);
        scope();
      }
      setState(114);
      match(SolidityScriptParser::T__2);
      setState(116);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 32845762428928) != 0)) {
        setState(115);
        arguments();
      }
      setState(118);
      match(SolidityScriptParser::T__3);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(120);
      identifier();
      setState(121);
      match(SolidityScriptParser::T__4);
      setState(122);
      inputCSV();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VizTraceContext ------------------------------------------------------------------

SolidityScriptParser::VizTraceContext::VizTraceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SolidityScriptParser::IdentifierContext* SolidityScriptParser::VizTraceContext::identifier() {
  return getRuleContext<SolidityScriptParser::IdentifierContext>(0);
}

SolidityScriptParser::NumberLiteralContext* SolidityScriptParser::VizTraceContext::numberLiteral() {
  return getRuleContext<SolidityScriptParser::NumberLiteralContext>(0);
}


size_t SolidityScriptParser::VizTraceContext::getRuleIndex() const {
  return SolidityScriptParser::RuleVizTrace;
}

void SolidityScriptParser::VizTraceContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolidityScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVizTrace(this);
}

void SolidityScriptParser::VizTraceContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolidityScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVizTrace(this);
}


std::any SolidityScriptParser::VizTraceContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SolidityScriptVisitor*>(visitor))
    return parserVisitor->visitVizTrace(this);
  else
    return visitor->visitChildren(this);
}

SolidityScriptParser::VizTraceContext* SolidityScriptParser::vizTrace() {
  VizTraceContext *_localctx = _tracker.createInstance<VizTraceContext>(_ctx, getState());
  enterRule(_localctx, 8, SolidityScriptParser::RuleVizTrace);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(126);
    match(SolidityScriptParser::T__5);
    setState(127);
    match(SolidityScriptParser::T__1);
    setState(128);
    match(SolidityScriptParser::T__6);
    setState(129);
    identifier();
    setState(134);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SolidityScriptParser::T__7) {
      setState(130);
      match(SolidityScriptParser::T__7);
      setState(131);
      numberLiteral();
      setState(132);
      match(SolidityScriptParser::T__8);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ChainParamsContext ------------------------------------------------------------------

SolidityScriptParser::ChainParamsContext::ChainParamsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SolidityScriptParser::ContractNameContext* SolidityScriptParser::ChainParamsContext::contractName() {
  return getRuleContext<SolidityScriptParser::ContractNameContext>(0);
}

SolidityScriptParser::NumberLiteralContext* SolidityScriptParser::ChainParamsContext::numberLiteral() {
  return getRuleContext<SolidityScriptParser::NumberLiteralContext>(0);
}


size_t SolidityScriptParser::ChainParamsContext::getRuleIndex() const {
  return SolidityScriptParser::RuleChainParams;
}

void SolidityScriptParser::ChainParamsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolidityScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterChainParams(this);
}

void SolidityScriptParser::ChainParamsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolidityScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitChainParams(this);
}


std::any SolidityScriptParser::ChainParamsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SolidityScriptVisitor*>(visitor))
    return parserVisitor->visitChainParams(this);
  else
    return visitor->visitChildren(this);
}

SolidityScriptParser::ChainParamsContext* SolidityScriptParser::chainParams() {
  ChainParamsContext *_localctx = _tracker.createInstance<ChainParamsContext>(_ctx, getState());
  enterRule(_localctx, 10, SolidityScriptParser::RuleChainParams);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(138);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SolidityScriptParser::Identifier: {
        enterOuterAlt(_localctx, 1);
        setState(136);
        contractName();
        break;
      }

      case SolidityScriptParser::DecimalNumber:
      case SolidityScriptParser::HexNumber: {
        enterOuterAlt(_localctx, 2);
        setState(137);
        numberLiteral();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ContractNameContext ------------------------------------------------------------------

SolidityScriptParser::ContractNameContext::ContractNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SolidityScriptParser::IdentifierContext* SolidityScriptParser::ContractNameContext::identifier() {
  return getRuleContext<SolidityScriptParser::IdentifierContext>(0);
}


size_t SolidityScriptParser::ContractNameContext::getRuleIndex() const {
  return SolidityScriptParser::RuleContractName;
}

void SolidityScriptParser::ContractNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolidityScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterContractName(this);
}

void SolidityScriptParser::ContractNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolidityScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitContractName(this);
}


std::any SolidityScriptParser::ContractNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SolidityScriptVisitor*>(visitor))
    return parserVisitor->visitContractName(this);
  else
    return visitor->visitChildren(this);
}

SolidityScriptParser::ContractNameContext* SolidityScriptParser::contractName() {
  ContractNameContext *_localctx = _tracker.createInstance<ContractNameContext>(_ctx, getState());
  enterRule(_localctx, 12, SolidityScriptParser::RuleContractName);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(140);
    identifier();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeployAddressContext ------------------------------------------------------------------

SolidityScriptParser::DeployAddressContext::DeployAddressContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SolidityScriptParser::IdentifierContext* SolidityScriptParser::DeployAddressContext::identifier() {
  return getRuleContext<SolidityScriptParser::IdentifierContext>(0);
}


size_t SolidityScriptParser::DeployAddressContext::getRuleIndex() const {
  return SolidityScriptParser::RuleDeployAddress;
}

void SolidityScriptParser::DeployAddressContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolidityScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeployAddress(this);
}

void SolidityScriptParser::DeployAddressContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolidityScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeployAddress(this);
}


std::any SolidityScriptParser::DeployAddressContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SolidityScriptVisitor*>(visitor))
    return parserVisitor->visitDeployAddress(this);
  else
    return visitor->visitChildren(this);
}

SolidityScriptParser::DeployAddressContext* SolidityScriptParser::deployAddress() {
  DeployAddressContext *_localctx = _tracker.createInstance<DeployAddressContext>(_ctx, getState());
  enterRule(_localctx, 14, SolidityScriptParser::RuleDeployAddress);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(142);
    identifier();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InputCSVContext ------------------------------------------------------------------

SolidityScriptParser::InputCSVContext::InputCSVContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SolidityScriptParser::IdentifierContext* SolidityScriptParser::InputCSVContext::identifier() {
  return getRuleContext<SolidityScriptParser::IdentifierContext>(0);
}


size_t SolidityScriptParser::InputCSVContext::getRuleIndex() const {
  return SolidityScriptParser::RuleInputCSV;
}

void SolidityScriptParser::InputCSVContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolidityScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInputCSV(this);
}

void SolidityScriptParser::InputCSVContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolidityScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInputCSV(this);
}


std::any SolidityScriptParser::InputCSVContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SolidityScriptVisitor*>(visitor))
    return parserVisitor->visitInputCSV(this);
  else
    return visitor->visitChildren(this);
}

SolidityScriptParser::InputCSVContext* SolidityScriptParser::inputCSV() {
  InputCSVContext *_localctx = _tracker.createInstance<InputCSVContext>(_ctx, getState());
  enterRule(_localctx, 16, SolidityScriptParser::RuleInputCSV);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(144);
    identifier();
    setState(145);
    match(SolidityScriptParser::T__9);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CountContext ------------------------------------------------------------------

SolidityScriptParser::CountContext::CountContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SolidityScriptParser::NumberLiteralContext* SolidityScriptParser::CountContext::numberLiteral() {
  return getRuleContext<SolidityScriptParser::NumberLiteralContext>(0);
}

SolidityScriptParser::IdentifierContext* SolidityScriptParser::CountContext::identifier() {
  return getRuleContext<SolidityScriptParser::IdentifierContext>(0);
}

tree::TerminalNode* SolidityScriptParser::CountContext::UINT32() {
  return getToken(SolidityScriptParser::UINT32, 0);
}

tree::TerminalNode* SolidityScriptParser::CountContext::RANDOM() {
  return getToken(SolidityScriptParser::RANDOM, 0);
}

SolidityScriptParser::RandomCallArgumentsContext* SolidityScriptParser::CountContext::randomCallArguments() {
  return getRuleContext<SolidityScriptParser::RandomCallArgumentsContext>(0);
}


size_t SolidityScriptParser::CountContext::getRuleIndex() const {
  return SolidityScriptParser::RuleCount;
}

void SolidityScriptParser::CountContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolidityScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCount(this);
}

void SolidityScriptParser::CountContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolidityScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCount(this);
}


std::any SolidityScriptParser::CountContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SolidityScriptVisitor*>(visitor))
    return parserVisitor->visitCount(this);
  else
    return visitor->visitChildren(this);
}

SolidityScriptParser::CountContext* SolidityScriptParser::count() {
  CountContext *_localctx = _tracker.createInstance<CountContext>(_ctx, getState());
  enterRule(_localctx, 18, SolidityScriptParser::RuleCount);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(156);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(147);
      match(SolidityScriptParser::T__10);
      setState(148);
      numberLiteral();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(149);
      match(SolidityScriptParser::T__10);
      setState(150);
      identifier();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(151);
      match(SolidityScriptParser::T__10);
      setState(152);
      match(SolidityScriptParser::UINT32);
      setState(153);
      match(SolidityScriptParser::T__1);
      setState(154);
      match(SolidityScriptParser::RANDOM);
      setState(155);
      randomCallArguments();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ScopeContext ------------------------------------------------------------------

SolidityScriptParser::ScopeContext::ScopeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SolidityScriptParser::IdentifierContext* SolidityScriptParser::ScopeContext::identifier() {
  return getRuleContext<SolidityScriptParser::IdentifierContext>(0);
}

SolidityScriptParser::NumberLiteralContext* SolidityScriptParser::ScopeContext::numberLiteral() {
  return getRuleContext<SolidityScriptParser::NumberLiteralContext>(0);
}

tree::TerminalNode* SolidityScriptParser::ScopeContext::ALL() {
  return getToken(SolidityScriptParser::ALL, 0);
}

tree::TerminalNode* SolidityScriptParser::ScopeContext::RANDOM() {
  return getToken(SolidityScriptParser::RANDOM, 0);
}

tree::TerminalNode* SolidityScriptParser::ScopeContext::INTRA() {
  return getToken(SolidityScriptParser::INTRA, 0);
}

tree::TerminalNode* SolidityScriptParser::ScopeContext::CROSS() {
  return getToken(SolidityScriptParser::CROSS, 0);
}


size_t SolidityScriptParser::ScopeContext::getRuleIndex() const {
  return SolidityScriptParser::RuleScope;
}

void SolidityScriptParser::ScopeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolidityScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterScope(this);
}

void SolidityScriptParser::ScopeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolidityScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitScope(this);
}


std::any SolidityScriptParser::ScopeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SolidityScriptVisitor*>(visitor))
    return parserVisitor->visitScope(this);
  else
    return visitor->visitChildren(this);
}

SolidityScriptParser::ScopeContext* SolidityScriptParser::scope() {
  ScopeContext *_localctx = _tracker.createInstance<ScopeContext>(_ctx, getState());
  enterRule(_localctx, 20, SolidityScriptParser::RuleScope);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(170);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(158);
      match(SolidityScriptParser::T__11);
      setState(159);
      identifier();
      setState(166);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case SolidityScriptParser::T__1: {
          setState(160);
          match(SolidityScriptParser::T__1);
          setState(161);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 2013265920) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          break;
        }

        case SolidityScriptParser::T__7: {
          setState(162);
          match(SolidityScriptParser::T__7);
          setState(163);
          numberLiteral();
          setState(164);
          match(SolidityScriptParser::T__8);
          break;
        }

        case SolidityScriptParser::T__2:
        case SolidityScriptParser::WINPATH:
        case SolidityScriptParser::UNIXPATH:
        case SolidityScriptParser::Identifier: {
          break;
        }

      default:
        break;
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(168);
      match(SolidityScriptParser::T__11);
      setState(169);
      numberLiteral();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentsContext ------------------------------------------------------------------

SolidityScriptParser::ArgumentsContext::ArgumentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SolidityScriptParser::ArgumentContext *> SolidityScriptParser::ArgumentsContext::argument() {
  return getRuleContexts<SolidityScriptParser::ArgumentContext>();
}

SolidityScriptParser::ArgumentContext* SolidityScriptParser::ArgumentsContext::argument(size_t i) {
  return getRuleContext<SolidityScriptParser::ArgumentContext>(i);
}


size_t SolidityScriptParser::ArgumentsContext::getRuleIndex() const {
  return SolidityScriptParser::RuleArguments;
}

void SolidityScriptParser::ArgumentsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolidityScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArguments(this);
}

void SolidityScriptParser::ArgumentsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolidityScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArguments(this);
}


std::any SolidityScriptParser::ArgumentsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SolidityScriptVisitor*>(visitor))
    return parserVisitor->visitArguments(this);
  else
    return visitor->visitChildren(this);
}

SolidityScriptParser::ArgumentsContext* SolidityScriptParser::arguments() {
  ArgumentsContext *_localctx = _tracker.createInstance<ArgumentsContext>(_ctx, getState());
  enterRule(_localctx, 22, SolidityScriptParser::RuleArguments);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(172);
    argument();
    setState(177);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SolidityScriptParser::T__12) {
      setState(173);
      match(SolidityScriptParser::T__12);
      setState(174);
      argument();
      setState(179);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentContext ------------------------------------------------------------------

SolidityScriptParser::ArgumentContext::ArgumentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SolidityScriptParser::ExplicitTypeValueContext* SolidityScriptParser::ArgumentContext::explicitTypeValue() {
  return getRuleContext<SolidityScriptParser::ExplicitTypeValueContext>(0);
}

SolidityScriptParser::ExpressionContext* SolidityScriptParser::ArgumentContext::expression() {
  return getRuleContext<SolidityScriptParser::ExpressionContext>(0);
}


size_t SolidityScriptParser::ArgumentContext::getRuleIndex() const {
  return SolidityScriptParser::RuleArgument;
}

void SolidityScriptParser::ArgumentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolidityScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArgument(this);
}

void SolidityScriptParser::ArgumentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolidityScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArgument(this);
}


std::any SolidityScriptParser::ArgumentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SolidityScriptVisitor*>(visitor))
    return parserVisitor->visitArgument(this);
  else
    return visitor->visitChildren(this);
}

SolidityScriptParser::ArgumentContext* SolidityScriptParser::argument() {
  ArgumentContext *_localctx = _tracker.createInstance<ArgumentContext>(_ctx, getState());
  enterRule(_localctx, 24, SolidityScriptParser::RuleArgument);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(182);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(180);
      explicitTypeValue();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(181);
      expression(0);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExplicitTypeValueContext ------------------------------------------------------------------

SolidityScriptParser::ExplicitTypeValueContext::ExplicitTypeValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SolidityScriptParser::TypeContext* SolidityScriptParser::ExplicitTypeValueContext::type() {
  return getRuleContext<SolidityScriptParser::TypeContext>(0);
}

SolidityScriptParser::NumberLiteralContext* SolidityScriptParser::ExplicitTypeValueContext::numberLiteral() {
  return getRuleContext<SolidityScriptParser::NumberLiteralContext>(0);
}

tree::TerminalNode* SolidityScriptParser::ExplicitTypeValueContext::StringLiteral() {
  return getToken(SolidityScriptParser::StringLiteral, 0);
}


size_t SolidityScriptParser::ExplicitTypeValueContext::getRuleIndex() const {
  return SolidityScriptParser::RuleExplicitTypeValue;
}

void SolidityScriptParser::ExplicitTypeValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolidityScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExplicitTypeValue(this);
}

void SolidityScriptParser::ExplicitTypeValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolidityScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExplicitTypeValue(this);
}


std::any SolidityScriptParser::ExplicitTypeValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SolidityScriptVisitor*>(visitor))
    return parserVisitor->visitExplicitTypeValue(this);
  else
    return visitor->visitChildren(this);
}

SolidityScriptParser::ExplicitTypeValueContext* SolidityScriptParser::explicitTypeValue() {
  ExplicitTypeValueContext *_localctx = _tracker.createInstance<ExplicitTypeValueContext>(_ctx, getState());
  enterRule(_localctx, 26, SolidityScriptParser::RuleExplicitTypeValue);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(186);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SolidityScriptParser::DecimalNumber:
      case SolidityScriptParser::HexNumber: {
        setState(184);
        numberLiteral();
        break;
      }

      case SolidityScriptParser::StringLiteral: {
        setState(185);
        match(SolidityScriptParser::StringLiteral);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(188);
    match(SolidityScriptParser::T__13);
    setState(189);
    type();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

SolidityScriptParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SolidityScriptParser::TypeContext::UINT16() {
  return getToken(SolidityScriptParser::UINT16, 0);
}

tree::TerminalNode* SolidityScriptParser::TypeContext::UINT32() {
  return getToken(SolidityScriptParser::UINT32, 0);
}

tree::TerminalNode* SolidityScriptParser::TypeContext::UINT256() {
  return getToken(SolidityScriptParser::UINT256, 0);
}

tree::TerminalNode* SolidityScriptParser::TypeContext::ADDRESS() {
  return getToken(SolidityScriptParser::ADDRESS, 0);
}

tree::TerminalNode* SolidityScriptParser::TypeContext::BOOL() {
  return getToken(SolidityScriptParser::BOOL, 0);
}

tree::TerminalNode* SolidityScriptParser::TypeContext::BYTES() {
  return getToken(SolidityScriptParser::BYTES, 0);
}


size_t SolidityScriptParser::TypeContext::getRuleIndex() const {
  return SolidityScriptParser::RuleType;
}

void SolidityScriptParser::TypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolidityScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType(this);
}

void SolidityScriptParser::TypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolidityScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType(this);
}


std::any SolidityScriptParser::TypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SolidityScriptVisitor*>(visitor))
    return parserVisitor->visitType(this);
  else
    return visitor->visitChildren(this);
}

SolidityScriptParser::TypeContext* SolidityScriptParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 28, SolidityScriptParser::RuleType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(191);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 204010946560) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdentifierContext ------------------------------------------------------------------

SolidityScriptParser::IdentifierContext::IdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SolidityScriptParser::IdentifierContext::Identifier() {
  return getToken(SolidityScriptParser::Identifier, 0);
}


size_t SolidityScriptParser::IdentifierContext::getRuleIndex() const {
  return SolidityScriptParser::RuleIdentifier;
}

void SolidityScriptParser::IdentifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolidityScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdentifier(this);
}

void SolidityScriptParser::IdentifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolidityScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdentifier(this);
}


std::any SolidityScriptParser::IdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SolidityScriptVisitor*>(visitor))
    return parserVisitor->visitIdentifier(this);
  else
    return visitor->visitChildren(this);
}

SolidityScriptParser::IdentifierContext* SolidityScriptParser::identifier() {
  IdentifierContext *_localctx = _tracker.createInstance<IdentifierContext>(_ctx, getState());
  enterRule(_localctx, 30, SolidityScriptParser::RuleIdentifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(193);
    match(SolidityScriptParser::Identifier);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

SolidityScriptParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SolidityScriptParser::ExpressionContext::EVMC_ADDRESS() {
  return getToken(SolidityScriptParser::EVMC_ADDRESS, 0);
}

SolidityScriptParser::NumberLiteralContext* SolidityScriptParser::ExpressionContext::numberLiteral() {
  return getRuleContext<SolidityScriptParser::NumberLiteralContext>(0);
}

SolidityScriptParser::RandomCallContext* SolidityScriptParser::ExpressionContext::randomCall() {
  return getRuleContext<SolidityScriptParser::RandomCallContext>(0);
}

SolidityScriptParser::BoolLiteralContext* SolidityScriptParser::ExpressionContext::boolLiteral() {
  return getRuleContext<SolidityScriptParser::BoolLiteralContext>(0);
}

tree::TerminalNode* SolidityScriptParser::ExpressionContext::StringLiteral() {
  return getToken(SolidityScriptParser::StringLiteral, 0);
}

SolidityScriptParser::StringArrayContext* SolidityScriptParser::ExpressionContext::stringArray() {
  return getRuleContext<SolidityScriptParser::StringArrayContext>(0);
}

SolidityScriptParser::StructArrayContext* SolidityScriptParser::ExpressionContext::structArray() {
  return getRuleContext<SolidityScriptParser::StructArrayContext>(0);
}

SolidityScriptParser::IdentifierContext* SolidityScriptParser::ExpressionContext::identifier() {
  return getRuleContext<SolidityScriptParser::IdentifierContext>(0);
}

SolidityScriptParser::ExpressionContext* SolidityScriptParser::ExpressionContext::expression() {
  return getRuleContext<SolidityScriptParser::ExpressionContext>(0);
}


size_t SolidityScriptParser::ExpressionContext::getRuleIndex() const {
  return SolidityScriptParser::RuleExpression;
}

void SolidityScriptParser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolidityScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void SolidityScriptParser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolidityScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}


std::any SolidityScriptParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SolidityScriptVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}


SolidityScriptParser::ExpressionContext* SolidityScriptParser::expression() {
   return expression(0);
}

SolidityScriptParser::ExpressionContext* SolidityScriptParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SolidityScriptParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  SolidityScriptParser::ExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 32;
  enterRecursionRule(_localctx, 32, SolidityScriptParser::RuleExpression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(228);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
    case 1: {
      setState(196);
      match(SolidityScriptParser::EVMC_ADDRESS);
      setState(197);
      match(SolidityScriptParser::T__7);
      setState(198);
      numberLiteral();
      setState(199);
      match(SolidityScriptParser::T__8);
      antlrcpp::downCast<ExpressionContext *>(_localctx)->expressionType =  0;
      break;
    }

    case 2: {
      setState(202);
      randomCall();
      antlrcpp::downCast<ExpressionContext *>(_localctx)->expressionType =  1;
      break;
    }

    case 3: {
      setState(205);
      numberLiteral();
      antlrcpp::downCast<ExpressionContext *>(_localctx)->expressionType =  3;
      break;
    }

    case 4: {
      setState(208);
      boolLiteral();
      antlrcpp::downCast<ExpressionContext *>(_localctx)->expressionType =  4;
      break;
    }

    case 5: {
      setState(211);
      match(SolidityScriptParser::StringLiteral);
      antlrcpp::downCast<ExpressionContext *>(_localctx)->expressionType =  5;
      break;
    }

    case 6: {
      setState(213);
      stringArray();
      antlrcpp::downCast<ExpressionContext *>(_localctx)->expressionType =  6;
      break;
    }

    case 7: {
      setState(216);
      structArray();
      antlrcpp::downCast<ExpressionContext *>(_localctx)->expressionType =  7;
      break;
    }

    case 8: {
      setState(219);
      identifier();
      setState(224);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
      case 1: {
        setState(220);
        match(SolidityScriptParser::T__7);
        setState(221);
        numberLiteral();
        setState(222);
        match(SolidityScriptParser::T__8);
        break;
      }

      default:
        break;
      }
      antlrcpp::downCast<ExpressionContext *>(_localctx)->expressionType =  8;
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(237);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleExpression);
        setState(230);

        if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
        setState(231);
        match(SolidityScriptParser::T__1);
        setState(232);
        identifier();
        antlrcpp::downCast<ExpressionContext *>(_localctx)->expressionType =  2; 
      }
      setState(239);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- RandomCallContext ------------------------------------------------------------------

SolidityScriptParser::RandomCallContext::RandomCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SolidityScriptParser::RandomCallContext::RANDOM() {
  return getToken(SolidityScriptParser::RANDOM, 0);
}

tree::TerminalNode* SolidityScriptParser::RandomCallContext::UINT16() {
  return getToken(SolidityScriptParser::UINT16, 0);
}

tree::TerminalNode* SolidityScriptParser::RandomCallContext::UINT32() {
  return getToken(SolidityScriptParser::UINT32, 0);
}

tree::TerminalNode* SolidityScriptParser::RandomCallContext::UINT256() {
  return getToken(SolidityScriptParser::UINT256, 0);
}

tree::TerminalNode* SolidityScriptParser::RandomCallContext::ADDRESS() {
  return getToken(SolidityScriptParser::ADDRESS, 0);
}

tree::TerminalNode* SolidityScriptParser::RandomCallContext::BOOL() {
  return getToken(SolidityScriptParser::BOOL, 0);
}

SolidityScriptParser::RandomCallCountContext* SolidityScriptParser::RandomCallContext::randomCallCount() {
  return getRuleContext<SolidityScriptParser::RandomCallCountContext>(0);
}

SolidityScriptParser::RandomCallArgumentsContext* SolidityScriptParser::RandomCallContext::randomCallArguments() {
  return getRuleContext<SolidityScriptParser::RandomCallArgumentsContext>(0);
}

SolidityScriptParser::IdentifierContext* SolidityScriptParser::RandomCallContext::identifier() {
  return getRuleContext<SolidityScriptParser::IdentifierContext>(0);
}


size_t SolidityScriptParser::RandomCallContext::getRuleIndex() const {
  return SolidityScriptParser::RuleRandomCall;
}

void SolidityScriptParser::RandomCallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolidityScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRandomCall(this);
}

void SolidityScriptParser::RandomCallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolidityScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRandomCall(this);
}


std::any SolidityScriptParser::RandomCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SolidityScriptVisitor*>(visitor))
    return parserVisitor->visitRandomCall(this);
  else
    return visitor->visitChildren(this);
}

SolidityScriptParser::RandomCallContext* SolidityScriptParser::randomCall() {
  RandomCallContext *_localctx = _tracker.createInstance<RandomCallContext>(_ctx, getState());
  enterRule(_localctx, 34, SolidityScriptParser::RuleRandomCall);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(255);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SolidityScriptParser::UINT16:
      case SolidityScriptParser::UINT32:
      case SolidityScriptParser::UINT256:
      case SolidityScriptParser::ADDRESS:
      case SolidityScriptParser::BOOL: {
        enterOuterAlt(_localctx, 1);
        setState(240);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 66571993088) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(241);
        match(SolidityScriptParser::T__1);
        setState(242);
        match(SolidityScriptParser::RANDOM);
        setState(244);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
        case 1: {
          setState(243);
          randomCallCount();
          break;
        }

        default:
          break;
        }
        setState(247);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
        case 1: {
          setState(246);
          randomCallArguments();
          break;
        }

        default:
          break;
        }
        break;
      }

      case SolidityScriptParser::Identifier: {
        enterOuterAlt(_localctx, 2);
        setState(249);
        identifier();
        setState(250);
        match(SolidityScriptParser::T__1);
        setState(251);
        match(SolidityScriptParser::RANDOM);
        setState(253);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx)) {
        case 1: {
          setState(252);
          randomCallCount();
          break;
        }

        default:
          break;
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StringArrayContext ------------------------------------------------------------------

SolidityScriptParser::StringArrayContext::StringArrayContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> SolidityScriptParser::StringArrayContext::StringLiteral() {
  return getTokens(SolidityScriptParser::StringLiteral);
}

tree::TerminalNode* SolidityScriptParser::StringArrayContext::StringLiteral(size_t i) {
  return getToken(SolidityScriptParser::StringLiteral, i);
}


size_t SolidityScriptParser::StringArrayContext::getRuleIndex() const {
  return SolidityScriptParser::RuleStringArray;
}

void SolidityScriptParser::StringArrayContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolidityScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStringArray(this);
}

void SolidityScriptParser::StringArrayContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolidityScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStringArray(this);
}


std::any SolidityScriptParser::StringArrayContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SolidityScriptVisitor*>(visitor))
    return parserVisitor->visitStringArray(this);
  else
    return visitor->visitChildren(this);
}

SolidityScriptParser::StringArrayContext* SolidityScriptParser::stringArray() {
  StringArrayContext *_localctx = _tracker.createInstance<StringArrayContext>(_ctx, getState());
  enterRule(_localctx, 36, SolidityScriptParser::RuleStringArray);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(257);
    match(SolidityScriptParser::T__14);
    setState(258);
    match(SolidityScriptParser::StringLiteral);
    setState(263);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SolidityScriptParser::T__12) {
      setState(259);
      match(SolidityScriptParser::T__12);
      setState(260);
      match(SolidityScriptParser::StringLiteral);
      setState(265);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(266);
    match(SolidityScriptParser::T__15);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StructArrayContext ------------------------------------------------------------------

SolidityScriptParser::StructArrayContext::StructArrayContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SolidityScriptParser::ArgumentsContext* SolidityScriptParser::StructArrayContext::arguments() {
  return getRuleContext<SolidityScriptParser::ArgumentsContext>(0);
}

SolidityScriptParser::NumberLiteralContext* SolidityScriptParser::StructArrayContext::numberLiteral() {
  return getRuleContext<SolidityScriptParser::NumberLiteralContext>(0);
}


size_t SolidityScriptParser::StructArrayContext::getRuleIndex() const {
  return SolidityScriptParser::RuleStructArray;
}

void SolidityScriptParser::StructArrayContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolidityScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStructArray(this);
}

void SolidityScriptParser::StructArrayContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolidityScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStructArray(this);
}


std::any SolidityScriptParser::StructArrayContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SolidityScriptVisitor*>(visitor))
    return parserVisitor->visitStructArray(this);
  else
    return visitor->visitChildren(this);
}

SolidityScriptParser::StructArrayContext* SolidityScriptParser::structArray() {
  StructArrayContext *_localctx = _tracker.createInstance<StructArrayContext>(_ctx, getState());
  enterRule(_localctx, 38, SolidityScriptParser::RuleStructArray);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(268);
    match(SolidityScriptParser::T__14);
    setState(269);
    arguments();
    setState(270);
    match(SolidityScriptParser::T__15);
    setState(275);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx)) {
    case 1: {
      setState(271);
      match(SolidityScriptParser::T__7);
      setState(272);
      numberLiteral();
      setState(273);
      match(SolidityScriptParser::T__8);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RandomCallCountContext ------------------------------------------------------------------

SolidityScriptParser::RandomCallCountContext::RandomCallCountContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SolidityScriptParser::NumberLiteralContext* SolidityScriptParser::RandomCallCountContext::numberLiteral() {
  return getRuleContext<SolidityScriptParser::NumberLiteralContext>(0);
}


size_t SolidityScriptParser::RandomCallCountContext::getRuleIndex() const {
  return SolidityScriptParser::RuleRandomCallCount;
}

void SolidityScriptParser::RandomCallCountContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolidityScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRandomCallCount(this);
}

void SolidityScriptParser::RandomCallCountContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolidityScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRandomCallCount(this);
}


std::any SolidityScriptParser::RandomCallCountContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SolidityScriptVisitor*>(visitor))
    return parserVisitor->visitRandomCallCount(this);
  else
    return visitor->visitChildren(this);
}

SolidityScriptParser::RandomCallCountContext* SolidityScriptParser::randomCallCount() {
  RandomCallCountContext *_localctx = _tracker.createInstance<RandomCallCountContext>(_ctx, getState());
  enterRule(_localctx, 40, SolidityScriptParser::RuleRandomCallCount);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(277);
    match(SolidityScriptParser::T__7);
    setState(278);
    numberLiteral();
    setState(279);
    match(SolidityScriptParser::T__8);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RandomCallArgumentsContext ------------------------------------------------------------------

SolidityScriptParser::RandomCallArgumentsContext::RandomCallArgumentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SolidityScriptParser::ArgumentsContext* SolidityScriptParser::RandomCallArgumentsContext::arguments() {
  return getRuleContext<SolidityScriptParser::ArgumentsContext>(0);
}


size_t SolidityScriptParser::RandomCallArgumentsContext::getRuleIndex() const {
  return SolidityScriptParser::RuleRandomCallArguments;
}

void SolidityScriptParser::RandomCallArgumentsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolidityScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRandomCallArguments(this);
}

void SolidityScriptParser::RandomCallArgumentsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolidityScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRandomCallArguments(this);
}


std::any SolidityScriptParser::RandomCallArgumentsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SolidityScriptVisitor*>(visitor))
    return parserVisitor->visitRandomCallArguments(this);
  else
    return visitor->visitChildren(this);
}

SolidityScriptParser::RandomCallArgumentsContext* SolidityScriptParser::randomCallArguments() {
  RandomCallArgumentsContext *_localctx = _tracker.createInstance<RandomCallArgumentsContext>(_ctx, getState());
  enterRule(_localctx, 42, SolidityScriptParser::RuleRandomCallArguments);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(281);
    match(SolidityScriptParser::T__2);
    setState(283);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 32845762428928) != 0)) {
      setState(282);
      arguments();
    }
    setState(285);
    match(SolidityScriptParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumberLiteralContext ------------------------------------------------------------------

SolidityScriptParser::NumberLiteralContext::NumberLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SolidityScriptParser::NumberLiteralContext::DecimalNumber() {
  return getToken(SolidityScriptParser::DecimalNumber, 0);
}

tree::TerminalNode* SolidityScriptParser::NumberLiteralContext::HexNumber() {
  return getToken(SolidityScriptParser::HexNumber, 0);
}


size_t SolidityScriptParser::NumberLiteralContext::getRuleIndex() const {
  return SolidityScriptParser::RuleNumberLiteral;
}

void SolidityScriptParser::NumberLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolidityScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumberLiteral(this);
}

void SolidityScriptParser::NumberLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolidityScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumberLiteral(this);
}


std::any SolidityScriptParser::NumberLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SolidityScriptVisitor*>(visitor))
    return parserVisitor->visitNumberLiteral(this);
  else
    return visitor->visitChildren(this);
}

SolidityScriptParser::NumberLiteralContext* SolidityScriptParser::numberLiteral() {
  NumberLiteralContext *_localctx = _tracker.createInstance<NumberLiteralContext>(_ctx, getState());
  enterRule(_localctx, 44, SolidityScriptParser::RuleNumberLiteral);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(287);
    _la = _input->LA(1);
    if (!(_la == SolidityScriptParser::DecimalNumber

    || _la == SolidityScriptParser::HexNumber)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MatchedParenthesesContext ------------------------------------------------------------------

SolidityScriptParser::MatchedParenthesesContext::MatchedParenthesesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SolidityScriptParser::MatchedParenthesesContext::getRuleIndex() const {
  return SolidityScriptParser::RuleMatchedParentheses;
}

void SolidityScriptParser::MatchedParenthesesContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolidityScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMatchedParentheses(this);
}

void SolidityScriptParser::MatchedParenthesesContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolidityScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMatchedParentheses(this);
}


std::any SolidityScriptParser::MatchedParenthesesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SolidityScriptVisitor*>(visitor))
    return parserVisitor->visitMatchedParentheses(this);
  else
    return visitor->visitChildren(this);
}

SolidityScriptParser::MatchedParenthesesContext* SolidityScriptParser::matchedParentheses() {
  MatchedParenthesesContext *_localctx = _tracker.createInstance<MatchedParenthesesContext>(_ctx, getState());
  enterRule(_localctx, 46, SolidityScriptParser::RuleMatchedParentheses);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(289);
    match(SolidityScriptParser::T__7);
    setState(290);
    match(SolidityScriptParser::T__8);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SolFileContext ------------------------------------------------------------------

SolidityScriptParser::SolFileContext::SolFileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SolidityScriptParser::IdentifierContext* SolidityScriptParser::SolFileContext::identifier() {
  return getRuleContext<SolidityScriptParser::IdentifierContext>(0);
}

SolidityScriptParser::DirectivePathContext* SolidityScriptParser::SolFileContext::directivePath() {
  return getRuleContext<SolidityScriptParser::DirectivePathContext>(0);
}


size_t SolidityScriptParser::SolFileContext::getRuleIndex() const {
  return SolidityScriptParser::RuleSolFile;
}

void SolidityScriptParser::SolFileContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolidityScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSolFile(this);
}

void SolidityScriptParser::SolFileContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolidityScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSolFile(this);
}


std::any SolidityScriptParser::SolFileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SolidityScriptVisitor*>(visitor))
    return parserVisitor->visitSolFile(this);
  else
    return visitor->visitChildren(this);
}

SolidityScriptParser::SolFileContext* SolidityScriptParser::solFile() {
  SolFileContext *_localctx = _tracker.createInstance<SolFileContext>(_ctx, getState());
  enterRule(_localctx, 48, SolidityScriptParser::RuleSolFile);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(293);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SolidityScriptParser::WINPATH

    || _la == SolidityScriptParser::UNIXPATH) {
      setState(292);
      directivePath();
    }
    setState(295);
    identifier();
    setState(296);
    match(SolidityScriptParser::T__16);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- XtlFileContext ------------------------------------------------------------------

SolidityScriptParser::XtlFileContext::XtlFileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SolidityScriptParser::IdentifierContext* SolidityScriptParser::XtlFileContext::identifier() {
  return getRuleContext<SolidityScriptParser::IdentifierContext>(0);
}

SolidityScriptParser::DirectivePathContext* SolidityScriptParser::XtlFileContext::directivePath() {
  return getRuleContext<SolidityScriptParser::DirectivePathContext>(0);
}


size_t SolidityScriptParser::XtlFileContext::getRuleIndex() const {
  return SolidityScriptParser::RuleXtlFile;
}

void SolidityScriptParser::XtlFileContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolidityScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterXtlFile(this);
}

void SolidityScriptParser::XtlFileContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolidityScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitXtlFile(this);
}


std::any SolidityScriptParser::XtlFileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SolidityScriptVisitor*>(visitor))
    return parserVisitor->visitXtlFile(this);
  else
    return visitor->visitChildren(this);
}

SolidityScriptParser::XtlFileContext* SolidityScriptParser::xtlFile() {
  XtlFileContext *_localctx = _tracker.createInstance<XtlFileContext>(_ctx, getState());
  enterRule(_localctx, 50, SolidityScriptParser::RuleXtlFile);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(299);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SolidityScriptParser::WINPATH

    || _la == SolidityScriptParser::UNIXPATH) {
      setState(298);
      directivePath();
    }
    setState(301);
    identifier();
    setState(302);
    match(SolidityScriptParser::T__17);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DirectivePathContext ------------------------------------------------------------------

SolidityScriptParser::DirectivePathContext::DirectivePathContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SolidityScriptParser::DirectivePathContext::WINPATH() {
  return getToken(SolidityScriptParser::WINPATH, 0);
}

tree::TerminalNode* SolidityScriptParser::DirectivePathContext::UNIXPATH() {
  return getToken(SolidityScriptParser::UNIXPATH, 0);
}


size_t SolidityScriptParser::DirectivePathContext::getRuleIndex() const {
  return SolidityScriptParser::RuleDirectivePath;
}

void SolidityScriptParser::DirectivePathContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolidityScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDirectivePath(this);
}

void SolidityScriptParser::DirectivePathContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolidityScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDirectivePath(this);
}


std::any SolidityScriptParser::DirectivePathContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SolidityScriptVisitor*>(visitor))
    return parserVisitor->visitDirectivePath(this);
  else
    return visitor->visitChildren(this);
}

SolidityScriptParser::DirectivePathContext* SolidityScriptParser::directivePath() {
  DirectivePathContext *_localctx = _tracker.createInstance<DirectivePathContext>(_ctx, getState());
  enterRule(_localctx, 52, SolidityScriptParser::RuleDirectivePath);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(304);
    _la = _input->LA(1);
    if (!(_la == SolidityScriptParser::WINPATH

    || _la == SolidityScriptParser::UNIXPATH)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BoolLiteralContext ------------------------------------------------------------------

SolidityScriptParser::BoolLiteralContext::BoolLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SolidityScriptParser::BoolLiteralContext::TRUE() {
  return getToken(SolidityScriptParser::TRUE, 0);
}

tree::TerminalNode* SolidityScriptParser::BoolLiteralContext::FALSE() {
  return getToken(SolidityScriptParser::FALSE, 0);
}


size_t SolidityScriptParser::BoolLiteralContext::getRuleIndex() const {
  return SolidityScriptParser::RuleBoolLiteral;
}

void SolidityScriptParser::BoolLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolidityScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBoolLiteral(this);
}

void SolidityScriptParser::BoolLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SolidityScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBoolLiteral(this);
}


std::any SolidityScriptParser::BoolLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SolidityScriptVisitor*>(visitor))
    return parserVisitor->visitBoolLiteral(this);
  else
    return visitor->visitChildren(this);
}

SolidityScriptParser::BoolLiteralContext* SolidityScriptParser::boolLiteral() {
  BoolLiteralContext *_localctx = _tracker.createInstance<BoolLiteralContext>(_ctx, getState());
  enterRule(_localctx, 54, SolidityScriptParser::RuleBoolLiteral);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(306);
    _la = _input->LA(1);
    if (!(_la == SolidityScriptParser::TRUE

    || _la == SolidityScriptParser::FALSE)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool SolidityScriptParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 16: return expressionSempred(antlrcpp::downCast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool SolidityScriptParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 7);

  default:
    break;
  }
  return true;
}

void SolidityScriptParser::initialize() {
  ::antlr4::internal::call_once(solidityscriptParserOnceFlag, solidityscriptParserInitialize);
}
