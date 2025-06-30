pragma solidity >=0.8.4;
import"./ENSRegistry.sol";

contract BaseRegistrarImplementation
{
    ENSRegistry public ens;
    bytes32 public baseNode;
    
    function Config(ENSRegistry _ens, bytes32 _baseNode) external
    {
        ens = _ens;
        baseNode = _baseNode;
    }
    
    function registerWithConfig(address _scope, string memory name, address owner, uint duration, bytes32 secret, address resolver, address addr) external returns (bytes32)
    {
        bytes32 label = keccak256(bytes(name));
        return ens.setSubnodeOwner(_scope, baseNode, label, owner);
    }
}
