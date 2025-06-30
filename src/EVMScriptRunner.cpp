#include "EVMScriptRunner.h"


namespace sol
{

    std::vector<std::string> Randomizer::GetRandomStringAddress(uint32_t count) {
        std::vector<std::string> addresses;
        std::uniform_int_distribution<int> distribution(0, 255);
        for (uint32_t i = 0; i < count; i++) {
            std::stringstream ss;
            ss << "0x";
            for (int j = 0; j < 20; j++) {
                ss << std::setw(2) << std::setfill('0') << std::hex << distribution(generator);
            }
            addresses.push_back(ss.str());
        }
        return addresses;
    }

    std::vector<std::string> Randomizer::GetRandomStringUint256(uint32_t count) {
        std::vector<std::string> uint256s;
        std::uniform_int_distribution<int> distribution(0, 255);
        for (uint32_t i = 0; i < count; i++) {
            std::stringstream ss;
            ss << "0x";
            for (int j = 0; j < 32; j++) {
                ss << std::setw(2) << std::setfill('0') << std::hex << distribution(generator);
            }
            uint256s.push_back(ss.str());
        }
        return uint256s;
    }

    std::vector<std::string> Randomizer::GetRandomStringUint32(uint32_t count, uint32_t low, uint32_t high) {
        std::vector<std::string> uint32s;
        std::uniform_int_distribution<uint32_t> distribution(low, high);
        for (uint32_t i = 0; i < count; i++) {
            uint32s.push_back(std::to_string(distribution(generator)));
        }
        return uint32s;
    }
    std::vector<std::string> Randomizer::GetRandomStringUint16(uint32_t count, uint16_t low, uint16_t high)
    {
        std::vector<std::string> uint16s;
        std::uniform_int_distribution<uint16_t> distribution(low, high);
        for (uint32_t i = 0; i < count; i++) {
            uint16s.push_back(std::to_string(distribution(generator)));
        }
        return uint16s;
    }

    std::vector<std::string> Randomizer::GetRandomStringBool(uint32_t count) {
		std::vector<std::string> bools;
        std::uniform_int_distribution<uint32_t> distribution(0, 1);
        for (uint32_t i = 0; i < count; i++) {
            bools.push_back(distribution(generator) == 1 ? "false" : "true");
        }
        return bools;
	}
    std::vector<std::string> Randomizer::GetRandomVectorString(const std::vector<std::string>& in, uint32_t count)
    {
        std::vector<std::string> ret;
        std::vector<uint32_t> rands = GetRandomUint32(count, 0, in.size() - 1);
        for (uint32_t i = 0; i < count; ++i)
        {
            ret.push_back(in[rands[i]]);
        }
        return ret;
    }

    std::vector<uint32_t> Randomizer::GetRandomUint32(uint32_t count, uint32_t low, uint32_t high)
    {
        std::vector<uint32_t> uint32s;
        std::uniform_int_distribution<uint32_t> distribution(low, high);
        for (uint32_t i = 0; i < count; i++) {
            uint32s.push_back(distribution(generator));
        }
        return uint32s;
    }

    uint32_t Randomizer::RandomGetUint32(uint32_t low, uint32_t high)
    {
        std::uniform_int_distribution<uint32_t> distribution(low, high);
        return distribution(generator);
    }

    std::string Randomizer::RandomGetUint32String(uint32_t low, uint32_t high)
    {
        std::uniform_int_distribution<uint32_t> distribution(low, high);
        return std::to_string(distribution(generator));
    }

    evmc_address Randomizer::ConvertString2EVMAddress(std::string address) {
        evmc_address evm_address = {};
        if (address.size() != 42) {
            throw std::runtime_error("Invalid address string length");
        }

        for (size_t i = 0; i < 20; i++) {
            evm_address.bytes[i] = std::stoul(address.substr(i * 2 + 2, 2), nullptr, 16);
        }

        return evm_address;
    }
}
