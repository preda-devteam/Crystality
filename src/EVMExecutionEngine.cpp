#include "EVMExecutionEngine.h"
#include "EVMHost.h"
#include "EVMScriptRunner.h"
#include <cassert>

namespace sol 
{
    evmc::result EVMExecutionEngine::Deploy(EVMHost& host, const std::vector<uint8_t>& code, uint64_t address, std::vector<uint8_t>& input_data)
    {
        struct evmc_message msg;
        msg.kind = EVMC_CREATE;
        msg.depth = 0;
        msg.gas = GAS_LIMIT;
        msg.destination = evmc::address(address);
        msg.sender = evmc::address(0);
        msg.input_data = input_data.data();
        msg.input_size = input_data.size();
        msg.value = { {0} };

        evmc::result ret = m_vm.execute(host, EVMC_LONDON, msg, &code[0], code.size());

        if (ret.status_code != EVMC_SUCCESS)
        {
            printf("  EVM execution failure: %d\n", ret.status_code);
        }
        else
        {
            evmc::address deployAddress(address);
	        host.m_accounts[deployAddress].code.resize(ret.output_size);
	        std::copy(ret.output_data, ret.output_data + ret.output_size, host.m_accounts[deployAddress].code.begin());
            // printf("Contract Deployed Successfully! %ld\n", ret.output_size);
        }
        return ret;
    }

    evmc::result EVMExecutionEngine::Run(EVMHost& host, const evmc_message& msg)
    {
        assert(msg.kind != EVMC_CREATE && msg.kind != EVMC_CREATE2);

        if (msg.kind == EVMC_CALL && msg.value != evmc::uint256be(0))
        {

            if (!host.transfer(msg.sender, msg.destination, msg.value))
            {
                return evmc::result(EVMC_INSUFFICIENT_BALANCE, msg.gas, nullptr, 0);
            }
        }

        if (host.m_accounts.find(msg.destination) == host.m_accounts.end())
        {
            return evmc::result(EVMC_FAILURE, msg.gas, nullptr, 0);
        }
        std::vector<uint8_t> code = host.m_accounts[msg.destination].code;
        if (code.empty())
        {
            return evmc::result(EVMC_FAILURE, msg.gas, nullptr, 0);
        }

#ifdef TIMER
	    sol::InTimer intimer;
	    intimer.ReStart();
	    evmc::result ret = m_vm.execute(host, EVMC_LONDON, msg, &code[0], code.size());
	    intimer.Stop();
        host._Shard->total_cost += intimer.Duration();
        host._Shard->max_cost = intimer.Duration() > host._Shard->max_cost ? intimer.Duration() : host._Shard->max_cost;
#else
	    evmc::result ret = m_vm.execute(host, EVMC_LONDON, msg, &code[0], code.size());
#endif 

        if (ret.status_code != EVMC_SUCCESS)
        {
            printf("  EVM execution failure: %d\n", ret.status_code);
        }

        return ret;
    }

    std::vector<uint8_t> EVMExecutionEngine::Compile2ByteCode(std::string& solContractPath)
    {
        /// solc.exe
#ifdef __linux__
        std::string cmd_exec = "./solc/solc-static-linux " + solContractPath + ".sol"
            " --bin --storage-layout --abi --hashes --output-dir ./solc/ --overwrite";
#endif
#ifdef _WIN32
        std::string cmd_exec = ".\\solc\\solc-windows " + solContractPath + ".sol"
        " --bin --storage-layout --abi --hashes --output-dir .\\solc\\ --overwrite";

#endif
#ifdef __APPLE__
        std::string cmd_exec = "./solc/solc-macos " + solContractPath + ".sol"
            " --bin --storage-layout --abi --hashes --output-dir ./solc/ --overwrite";
#endif
		// FILE* pipe = _popen(cmd_exec.c_str(), "r");
		// std::string result;
		// if(nullptr == pipe){
		// 	std::cout << "Failed to execute " << cmd_exec << std::endl;
		// 	return std::vector<uint8_t>();
		// }
		// else{
		// 	char buffer[128];
		// 	while (fgets(buffer, sizeof(buffer), pipe) != NULL)
		// 		result += buffer;
		// }

        int ret = system(cmd_exec.c_str());

        /// get binaray code
        std::ifstream ifs(solContractPath + ".bin");
        std::string strBinCode((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());

        ifs.close();
        return hex2uint8(strBinCode);
    }

}
