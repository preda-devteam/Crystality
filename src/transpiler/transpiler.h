#include <iostream>
#include <fstream>
#include "antlr4-runtime.h"
#include "ExtendSolidityLexer.h"
#include "ExtendSolidityParser.h"
#include "ExtendSolidityTreeWalker.h"
#include "ExtendSolidityRealListener.h"
#include <filesystem>

inline std::string GetFileName(std::string filePath)
{
	for(auto& c : filePath){
		if( '\\' == c)
			c = '/';
	}
	auto lastSlashPos = filePath.find_last_of('/');
	std::string fileName = lastSlashPos == std::string::npos ? filePath : filePath.substr(lastSlashPos + 1);
	auto dotPos = fileName.find('.');
	return dotPos == std::string::npos ? fileName : fileName.substr(0, dotPos); 
}

inline int Transpile(std::string contractPath)
{
	/// fetch input code
	std::ifstream ifs(contractPath);
	if (!ifs.is_open())
	{
		std::cout << "Cannot find source file " << contractPath << std::endl;
		return -1;
	}
	std::string sourceCode = std::string(std::istreambuf_iterator<char>(ifs), std::istreambuf_iterator<char>());
	ifs.close();

	// delete caches 
	std::string contract_filename = GetFileName(contractPath);
	std::vector<std::string> files;
	files.push_back("./solc/" + contract_filename + ".sol");
	files.push_back("./solc/" + contract_filename + ".abi");
	files.push_back("./solc/" + contract_filename + ".bin");
	files.push_back("./solc/" + contract_filename + ".signatures");

	for (auto& file : files)
	{
		std::filesystem::path file_path = file;

		if (std::filesystem::exists(file_path))
		{
			std::filesystem::remove(file_path);
		}
	}

	antlr4::ANTLRInputStream input(sourceCode);

	/// get parsed tree
	CustomErrorListener errListener;
	errListener.err_file_path = contractPath;
	ExtendSolidityLexer lexer(&input);
	lexer.removeErrorListeners();
	lexer.addErrorListener(&errListener);
	antlr4::CommonTokenStream tokens(&lexer);
	ExtendSolidityParser parser(&tokens);
	parser.removeErrorListeners();
	parser.addErrorListener(&errListener);
	antlr4::tree::ParseTree* tree = parser.sourceUnit();

	if (!errListener.p_errors.empty()) {
		std::cout << "Compilation Failed!" << std::endl;
		for(auto& err : errListener.p_errors)
			std::cerr << err << std::endl;
		return -1;
	}

	/// walk through the tree and print corresponding codes
	ExtendSolidityRealListener listener;
	ExtendSolidityTreeWalker walker;
	listener.SetWalker(&walker);
	walker.walk(&listener, tree);
	
	/// write back to file
	// std::filesystem::create_directory("./solc/intermediate");
	std::string outFilePath = "./solc/" + contract_filename + ".sol";
	std::ofstream ofs(outFilePath, std::fstream::out);
	if (!ofs.is_open())
	{
		std::cout << "Cannot find source file " << outFilePath << std::endl;
		return false;
	}
	ofs << listener.GetStandardSolidityCode();
	ofs.close();
	std::cout << "Compilation Succeed!" << std::endl;
	std::cout << "Transpiled code has been written to " << outFilePath << std::endl;

	return 0;
}