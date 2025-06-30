// evmone: Fast Ethereum Virtual Machine implementation
// Copyright 2019-2020 The evmone Authors.
// SPDX-License-Identifier: Apache-2.0

#include "execution.hpp"
#include "analysis.hpp"
#include <memory>
//#define TIMER
#ifdef TIMER
#include <chrono>
#include <evmc/evmc.hpp>
#include <EVMHost.h>
extern uint64_t instr_count;
#endif

namespace evmone
{
evmc_result execute(AdvancedExecutionState& state, const AdvancedCodeAnalysis& analysis) noexcept
{
    state.analysis = &analysis;  // Allow accessing the analysis by instructions.

    const auto* instr = &state.analysis->instrs[0];  // Start with the first instruction.
    while (instr != nullptr){
        instr = instr->fn(instr, state);
		//++instr_count;
    }
                
    const auto gas_left =
        (state.status == EVMC_SUCCESS || state.status == EVMC_REVERT) ? state.gas_left : 0;

    return evmc::make_result(
        state.status, gas_left, state.memory.data() + state.output_offset, state.output_size);
}

evmc_result execute(evmc_vm* /*unused*/, const evmc_host_interface* host, evmc_host_context* ctx,
    evmc_revision rev, const evmc_message* msg, const uint8_t* code, size_t code_size) noexcept
{
#ifdef TIMER
    auto analyze_start = std::chrono::time_point_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now()).time_since_epoch().count();
    const auto analysis = analyze(rev, code, code_size);
    auto analyze_end = std::chrono::time_point_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now()).time_since_epoch().count();
    auto analyze_time = analyze_end - analyze_start;

    auto state = std::make_unique<AdvancedExecutionState>(*msg, rev, *host, ctx, code, code_size);
    evmc_result ret = execute(*state, analysis);
    auto execute_end = std::chrono::time_point_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now()).time_since_epoch().count();
    auto execute_time = execute_end - analyze_end;

	dynamic_cast<sol::EVMHost*>(evmc::Host::from_context(ctx))->_Shard->_Analyze += analyze_time;
	dynamic_cast<sol::EVMHost*>(evmc::Host::from_context(ctx))->_Shard->_Execute += execute_time;

    return ret;
#else
    const auto analysis = analyze(rev, code, code_size);
    auto state = std::make_unique<AdvancedExecutionState>(*msg, rev, *host, ctx, code, code_size);
    return execute(*state, analysis);

#endif

}
}  // namespace evmone
