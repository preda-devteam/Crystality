#pragma once 
#include "EVMShard.h" 
#include <evmc/helpers.h> 
#include <evmc/loader.h> 
#include <evmc/evmc.hpp> 
#include <evmone/evmone.h> 
#include <iostream> 
#include <fstream> 
#include <sstream> 
#include <algorithm>
#include <map>
#include <vector>

using namespace evmc::literals;

void printBytes32(const evmc::bytes32&);

namespace evmc
{
    struct account
    {
        virtual ~account() = default;

        evmc::uint256be balance = {};
        std::vector<uint8_t> code;
        std::map<evmc::bytes32, evmc::bytes32> storage;
        //nonce

        virtual evmc::bytes32 code_hash() const
        {
            // Extremely dumb "hash" function.
            evmc::bytes32 ret{};
            for (const auto v : code)
                ret.bytes[v % sizeof(ret.bytes)] ^= v;
            return ret;
        }

        void PrintInfo()
        {
            for (auto& user : storage)
            {
                printBytes32(user.first); printf(": ");
                printBytes32(user.second); printf("\n");
            }
        }
    };

    using accounts = std::map<evmc::address, account>;

}  // namespace evmc

namespace sol
{
    class EVMExecutionEngine;
    class EVMShard;

    class EVMHost : public evmc::Host
    {
        friend class EVMShard;

    public:
        EVMShard* _Shard;
        EVMHost* _GlobalHost;
        evmc::accounts m_accounts;
        evmc_tx_context m_tx_context{};

    public:
        EVMHost() = default;

        bool account_exists(const evmc::address& addr) const noexcept;
        evmc::bytes32 get_storage(const evmc::address& addr, const evmc::bytes32& key) const noexcept;
        evmc_storage_status set_storage(const evmc::address& addr, const evmc::bytes32& key, const evmc::bytes32& value) noexcept;
        evmc::uint256be get_balance(const evmc::address& addr) const noexcept;
        size_t get_code_size(const evmc::address& addr) const noexcept;
        evmc::bytes32 get_code_hash(const evmc::address& addr) const noexcept;
        size_t copy_code(const evmc::address& addr, size_t code_offset, uint8_t* buffer_data, size_t buffer_size) const noexcept;
        void selfdestruct(const evmc::address& addr, const evmc::address& beneficiary) noexcept;
        evmc::result call(const evmc_message& msg) noexcept;
        evmc_tx_context get_tx_context() const noexcept;
        evmc::bytes32 get_block_hash(int64_t number) const noexcept;
        void emit_log(const evmc::address& addr, const uint8_t* data, size_t data_size, const evmc::bytes32 topics[], size_t topics_count) noexcept;
        evmc_access_status access_account(const evmc::address& addr) noexcept;
        evmc_access_status access_storage(const evmc::address& addr, const evmc::bytes32& key) noexcept;
        bool transfer(const evmc::address& from, const evmc::address& to, const evmc::uint256be& value_evm);

    private:
        void SetShard(EVMShard* shard) { _Shard = shard; }
        void SetGlobalHost(EVMHost* host) { _GlobalHost = host; }

    };
    
}
