#include <iostream>
#include <fstream>
#include "antlr4-runtime.h"
#include "SolidityScriptLexer.h"
#include "SolidityScriptParser.h"
#include "SolidityScriptTreeWalker.h"
#include "SolidityScriptRealListener.h"
#include "ExtendSolidityRealListener.h"
#include <filesystem>


inline int RunScript(std::string scriptPath, uint32_t order, std::string templatePath, std::string outputPath)
{
	std::ifstream ifs(scriptPath);
	if (!ifs.is_open())
	{
		std::cout << "Cannot find source file " << scriptPath << std::endl;
		return -1;
	}
	std::string sourceCode = std::string(std::istreambuf_iterator<char>(ifs), std::istreambuf_iterator<char>());
	ifs.close();

	antlr4::ANTLRInputStream input(sourceCode);

	/// get parsed tree
	CustomErrorListener errListener;
	errListener.err_file_path = scriptPath;
	SolidityScriptLexer lexer(&input);
	lexer.removeErrorListeners();
	lexer.addErrorListener(&errListener);
	antlr4::CommonTokenStream tokens(&lexer);
	SolidityScriptParser parser(&tokens);
	parser.removeErrorListeners();
	parser.addErrorListener(&errListener);
	antlr4::tree::ParseTree* tree = parser.source();

	if (!errListener.p_errors.empty()) {
		for(auto& err : errListener.p_errors)
			std::cerr << err << std::endl;
		return -1;
	}

	/// walk through the tree and print corresponding codes
	sol::SolidityScriptRealListener listener(order);
	std::string slashScriptDir = "";
	for (auto c : scriptPath) {
		if ('\\' == c && !slashScriptDir.empty() && slashScriptDir.back() != '/')
			slashScriptDir.push_back('/');
		else
			slashScriptDir.push_back(c);
	}
	auto lastSlashPos = slashScriptDir.find_last_of('/');
	listener.SetScriptDir(lastSlashPos == std::string::npos ? slashScriptDir : slashScriptDir.substr(0, lastSlashPos + 1));
	SolidityScriptTreeWalker walker;
	listener.SetWalker(&walker);
	walker.walk(&listener, tree);
	std::string json = listener.GetVizJson();
	if (templatePath.length() && outputPath.length() && json.length())
	{
		listener.GetSimulator()->ExportViz(json, templatePath, outputPath);
	}
	std::string contractName;
	std::string varName;
	if (scriptPath.find("Ballot") != std::string::npos)
	{
		contractName = "Ballot";
		varName = "last_result";
	}
	else if (scriptPath.find("ERC20") != std::string::npos)
	{
		contractName = "ERC20";
		varName = "balance";
	}
	//std::string contractName = "ERC20";
	//std::string varName = "balance";
	// if(contractName.size() > 0 && varName.size() > 0)
	// 	listener.VizualizeStateVar(contractName, varName, nullptr);
	return 0;
}
