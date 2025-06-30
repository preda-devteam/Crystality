#include "SolidityScript.h"
#include "transpiler.h"
#include <string>
#include <iostream>

int main(int argc, char* argv[])
{
	if(argc < 2) {
		std::cout << "crystality input_file.(xtl|xtlts) [-order:n] [-viz:output_filename] [-viz_templ:webui_template_path]" << std::endl;
		return 1;
	}
	
	std::string contract = argv[1];
	uint32_t order = 2;
	std::string templatePath;
	std::string outputPath;
	for (uint32_t i = 2; i < argc; i++)
	{
		std::string str(argv[i]);
		std::string arg(str.substr(str.find(":") + 1));
		if (str.find("-order:") != std::string::npos)
		{
			order = std::stoi(arg);
		}
		else if (str.find("-viz_templ:") != std::string::npos)
		{
			templatePath = arg;
		}
		else if (str.find("-viz:") != std::string::npos)
		{
			outputPath = arg;
		}
	}
	auto dotPos = contract.find_last_of(".");
	if(dotPos == std::string::npos){
		std::cout << "error input file format, expecting .xtl or .xtlts extension" << std::endl;
		return 1;
	}

	std::string extend_name = contract.substr(dotPos + 1);
	if(extend_name == "xtlts")
		RunScript(contract, order, templatePath, outputPath);
	else if(extend_name == "xtl")
		Transpile(contract);
	else{
		std::cout << "error input file format, expecting .xtl or .xtlts extension" << std::endl;
		return 1;
	}

    return 0;
}
