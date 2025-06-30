#pragma once

#include <evmc/evmc.hpp>
#include <evmone/evmone.h>
#include <vector>
#include <map>
#include <unordered_map>

// std::vector<uint8_t> hex2uint8(std::string& s);

namespace sol 
{
    class EVMHost;

    class EVMExecutionEngine
    {
        friend class EVMSimulator;
    public:
        EVMExecutionEngine():m_vm(evmc_create_evmone()){}
        evmc::result Deploy(EVMHost& host, const std::vector<uint8_t>& code, uint64_t address, std::vector<uint8_t>& input_data);
        evmc::result Run(EVMHost& host, const evmc_message& msg);
    private:
        evmc::VM m_vm;
        std::vector<uint8_t> Compile2ByteCode(std::string& solContractPath);
    };

}
