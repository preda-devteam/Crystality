#include "EVMHost.h"
#include "EVMScriptRunner.h"
#include <mutex>

std::mutex mtx_print;

void printBytes32(const evmc::bytes32& bytes)
{
    const uint8_t* data = bytes.bytes;
    for (size_t i = 0; i < sizeof(bytes.bytes); ++i)
    {
        printf("%02x", static_cast<unsigned int>(data[i]));
    }
}

namespace sol
{
    bool EVMHost::account_exists(const evmc::address& addr) const noexcept
    {
        return m_accounts.find(addr) != m_accounts.end();
    }

    evmc::bytes32 EVMHost::get_storage(const evmc::address& addr, const evmc::bytes32& key) const noexcept
    {
        const auto account_iter = m_accounts.find(addr);
        if (account_iter == m_accounts.end())
        {
            printf("(contract doesn't exist)\n");
            return {};
        }


        const auto storage_iter = account_iter->second.storage.find(key);
	    evmc::bytes32 value{};
        if (storage_iter != account_iter->second.storage.end())
		    value = storage_iter->second;
        else if(_GlobalHost != nullptr)
            value = _GlobalHost->get_storage(addr, key);

        //printf("get_storage => ");
        //printf("key: ");
        //printBytes32(key);
        //printf(" value: ");
        //printBytes32(value);
        //printf("\n");

	    return value;
    }

    evmc_storage_status EVMHost::set_storage(const evmc::address& addr, const evmc::bytes32& key, const evmc::bytes32& value) noexcept
    {
        auto& account = m_accounts[addr];
        auto prev_value = account.storage[key];
        account.storage[key] = value;
        //printf("set_storage => ");
        //printf("key: ");
        //printBytes32(key);
        //printf(" value: ");
        //printBytes32(value);
        //printf("\n");
        return (prev_value == value) ? EVMC_STORAGE_UNCHANGED : EVMC_STORAGE_MODIFIED;
    }

    evmc::uint256be EVMHost::get_balance(const evmc::address& addr) const noexcept
    {
        auto it = m_accounts.find(addr);
        if (it != m_accounts.end())
            return it->second.balance;
        return {};
    }

    size_t EVMHost::get_code_size(const evmc::address& addr) const noexcept
    {
        auto it = m_accounts.find(addr);
        if (it != m_accounts.end())
            return it->second.code.size();
        return 0;
    }

    evmc::bytes32 EVMHost::get_code_hash(const evmc::address& addr) const noexcept
    {
        auto it = m_accounts.find(addr);
        if (it != m_accounts.end())
            return it->second.code_hash();
        return {};
    }

    size_t EVMHost::copy_code(const evmc::address& addr, size_t code_offset, uint8_t* buffer_data, size_t buffer_size) const noexcept
    {
        const auto it = m_accounts.find(addr);
        if (it == m_accounts.end())
            return 0;

        const auto& code = it->second.code;

        if (code_offset >= code.size())
            return 0;

        const auto n = std::min(buffer_size, code.size() - code_offset);

        if (n > 0)
            std::copy_n(&code[code_offset], n, buffer_data);
        return n;
    }

    void EVMHost::selfdestruct(const evmc::address& addr, const evmc::address& beneficiary) noexcept
    {
        (void)addr;
        (void)beneficiary;
    }

    evmc::result EVMHost::call(const evmc_message& msg) noexcept
    {
        evmc::result ret(EVMC_SUCCESS, msg.gas, nullptr, 0);
        ret.status_code = EVMC_SUCCESS;
        ret.gas_left = msg.gas;
        if (evmc::address(555) == evmc::address(msg.destination)) {
            ret.output_data = _Shard->GetShardOrder();
            ret.output_size = 32;
        }
		else if(evmc::address(666) == evmc::address(msg.destination)
        || evmc::address(777) == evmc::address(msg.destination)
		|| evmc::address(888) == evmc::address(msg.destination)
        || evmc::address(32) == evmc::address(msg.destination)){
            _Shard->Relay(msg);
		}
        else if(msg.input_size){
			return _Shard->Execute(msg);
        }
        else
        {
            printf("relay call no input data");
        }
        return ret;
    }

    evmc_tx_context EVMHost::get_tx_context() const noexcept 
    { 
        return m_tx_context; 
    }

    evmc::bytes32 EVMHost::get_block_hash(int64_t number) const noexcept
    {
        const int64_t current_block_number = get_tx_context().block_number;

        return (number < current_block_number && number >= current_block_number - 256) ?
            0xb10c8a5fb10c8a5fb10c8a5fb10c8a5fb10c8a5fb10c8a5fb10c8a5fb10c8a5f_bytes32 :
            0x0000000000000000000000000000000000000000000000000000000000000000_bytes32;
    }

    void EVMHost::emit_log(const evmc::address& addr, const uint8_t* data, size_t data_size, const evmc::bytes32 topics[], size_t topics_count) noexcept
    {
        // std::cout << _Shard->GetSimulator()->GetDecodedString(topics[0], data, data_size) << std::endl;
    }

    evmc_access_status EVMHost::access_account(const evmc::address& addr) noexcept
    {
        (void)addr;
        return EVMC_ACCESS_COLD;
    }

    evmc_access_status EVMHost::access_storage(const evmc::address& addr, const evmc::bytes32& key) noexcept
    {
        (void)addr;
        (void)key;
        return EVMC_ACCESS_COLD;
    }

    bool EVMHost::transfer(const evmc::address& from, const evmc::address& to, const evmc::uint256be& value_evm)
    {
        evmc::uint256be from_balance = get_balance(from);
        evmc::uint256be value = value_evm;
        if (from_balance < value)
        {
            return false;
        }
        return true;
    }

}
