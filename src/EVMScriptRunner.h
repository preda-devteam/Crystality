#pragma once

#include "EVMSimulator.h"
#include <iostream>
#include <random>
#include <sstream>
#include <iomanip>
#include <chrono>
#include <mutex>

namespace sol
{
	class Randomizer
	{
		uint32_t random_seed;
		std::mt19937 generator;

	public:
		Randomizer(uint32_t _seed) : random_seed(_seed), generator(_seed) {}
		/// Generate a vector of random 20 bytes address in hexadecimal form, such as "0x0000000000000000000000000000000000000001"
		std::vector<std::string> GetRandomStringAddress(uint32_t count);
		/// Gneerate a vector of random 32 bytes uint256 data in hexadecimal form such as "0x0000000000000000000000000000000000000001000000000000000000000000"
		std::vector<std::string> GetRandomStringUint256(uint32_t count);
		/// Gneerate a vector of random 4 bytes uint32 data in a specific range in decimal form such as "10000"
		std::vector<std::string> GetRandomStringUint32(uint32_t count, uint32_t low = 0, uint32_t high = UINT32_MAX);
		std::vector<std::string> GetRandomStringUint16(uint32_t count, uint16_t low = 0, uint16_t high = UINT16_MAX);
    	std::vector<std::string> GetRandomStringBool(uint32_t count);
		/// Generate a vector of random subset of a vector string
		std::vector<std::string> GetRandomVectorString(const std::vector<std::string>& in, uint32_t count);
		/// Gneerate a vector of random 4 bytes uint32 data in a specific range in decimal form such as "10000"
		std::vector<uint32_t> GetRandomUint32(uint32_t count, uint32_t low = 0, uint32_t high = UINT32_MAX);
		/// Gneerate a vector of random 4 bytes uint32 data
		uint32_t RandomGetUint32(uint32_t low = 0, uint32_t high = UINT32_MAX);
		/// Gneerate a vector of random 4 bytes uint32 data
		std::string RandomGetUint32String(uint32_t low = 0, uint32_t high = UINT32_MAX);
		/// Convert a string of 20 bytes address which is in hexadecimal form to evmc_address
		evmc_address ConvertString2EVMAddress(std::string address);

	};

	class StopWatch
	{
	private:
		std::chrono::time_point<std::chrono::high_resolution_clock> start_time;
		std::chrono::duration<float> duration;

	public:
		StopWatch()
		{
			Restart();
		}

		void Restart()
		{
			start_time = std::chrono::high_resolution_clock::now();
		}

		void Stop()
		{
			auto end_time = std::chrono::high_resolution_clock::now();
			duration = end_time - start_time;
		}

		float GetElapsedSeconds()
		{
			auto end_time = std::chrono::high_resolution_clock::now();
			duration = end_time - start_time;
			return duration.count();
		}

		void Report()
		{
			std::cout << GetElapsedSeconds() << "s" << std::endl;
		}

		void Report(uint64_t txns)
		{
			std::cout << "total_txns: " << txns <<  " TPS: " << uint64_t((double)txns / GetElapsedSeconds()) << std::endl;
		}
	};

	class Timer {
	public:
		Timer(const std::string& identifier) : id(identifier) {
			start_time = std::chrono::high_resolution_clock::now();
		}

		~Timer() {
			auto end_time = std::chrono::high_resolution_clock::now();
			auto start = std::chrono::time_point_cast<std::chrono::microseconds>(start_time).time_since_epoch().count();
			auto end = std::chrono::time_point_cast<std::chrono::microseconds>(end_time).time_since_epoch().count();

			auto duration = end - start;
			total_durations[id] += duration;
		}

		static void PrintTotalDuration(const std::string& identifier) {
			if (total_durations.find(identifier) == total_durations.end()) {
				std::cout << "No time record for " << identifier << std::endl;
				return;
			}
			double ms = total_durations[identifier] * 0.001;
			std::cout << "Total time taken by " << identifier << ": " << ms << "ms" << std::endl;
		}

	private:
		std::chrono::time_point<std::chrono::high_resolution_clock> start_time;
		std::string id;
		static inline std::unordered_map<std::string, long long> total_durations;
	};

	class InTimer
	{
	public:
		void Start()
		{
			start_time = std::chrono::high_resolution_clock::now();
		}
		void ReStart()
		{
			start_time = std::chrono::high_resolution_clock::now();
			duration = 0;
		}
		void Stop()
		{
			auto end_time = std::chrono::high_resolution_clock::now();
			auto start = std::chrono::time_point_cast<std::chrono::microseconds>(start_time).time_since_epoch().count();
			auto end = std::chrono::time_point_cast<std::chrono::microseconds>(end_time).time_since_epoch().count();

			duration += (end - start);
		}
		void Reset()
		{
			duration = 0;
		}
		long long Duration()
		{
			return duration;
		}
	private:
		std::chrono::time_point<std::chrono::high_resolution_clock> start_time;
		long long duration;
	};
}

