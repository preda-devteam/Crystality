# crystality
Crystality is a smart contract programming language for parallel EVMs. By slightly extending the Solidity language, it is able to expose the data access structure of a smart contract to the underlying execution layer without requiring explicit specifying the data dependency by developers.

Crystality achieves deterministic parallelization which allows a developer fully utilizing the throughtput of all available instances of EVMs on the smart contract layer because it completely avoids execution rollback due to reading and writing conflict. What's more, deterministic parallelization in Crystality naturally exhibits linear scalibilty that gains greater acceleration on transaction processing with increasing number of parallel EVMs. Our performance evaluation demonstrates 36.67⨉ ~ 53.36⨉ speed boost using 64 parallel EVMs.

Crystality dev team is focus on designing a parallel programming language and building the corresponding toolchain (compiler, testbed and IDE) for intergation on the next generation parallel blockchain systems.
## Build
### Platform win
```
// build
cd /path_to_crystality
cmake -S . -B build
# build in vs (note: release type)

// run contract
./crystality ../contracts/test_cases/ERC20.xtlts -order:<shard_num>
```
### Paltform linux

```
// build
cd /path_to_evmhost
cmake -S . -B build
cd build && make -j8

// run contract
cd ../bin
./crystality ../contracts/test_cases/ERC20.xtlts -order:<shard_num>
```

### Debug in windows
1. cd to /path_to_crystality/proj.win
2. open crystality.sln
3. build the project
4. copy the corresponding dll to working directory
```
# copy 3rdParty/antlr4/lib/win/release/antlr4-runtime.dll bin/Release
or 
# copy 3rdParty/antlr4/lib/win/debug/antlr4-runtime.dll bin/Debug
```
5. start debug

## Statistic Graphs in Notion
https://cold-centaur-95a.notion.site/MultiShard-EVM-Model-Experiment-2250f12474e14291ae631e301b59ccee?pvs=4
