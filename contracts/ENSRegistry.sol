pragma solidity >=0.8.4;

contract ENSRegistry
{
    struct Record
    {
        address owner;
        address resolver;
        uint64 ttl;
    }
    address root_domain_owner;
    mapping(bytes32=>address) top_level_domain_owners;
    mapping (address => Record) record;
    /**
     * @dev Constructs a new ENS registry.
     */
    
    constructor() public
    {
    }
    
    function Config(address _scope) external
    {
        root_domain_owner = msg.sender;
        address rootnode_addr = address(uint160(bytes20(0x0)));
        address(666).call(
            abi.encodeWithSignature("_setOwner(address,address)", rootnode_addr, msg.sender)
        );
    }
    
    function setTopLevelDomain(address _scope, string memory name, address owner) external
    {
        require(root_domain_owner == msg.sender);
        bytes32 label = keccak256(bytes(name));
        bytes32 subnode = keccak256(abi.encodePacked(bytes32(0x0), label));
        address(888).call(
            abi.encodeWithSignature("_setTopLevelDomain(bytes32,address)", subnode, owner)
        );
        address node_addr = address(uint160(bytes20(subnode)));
        address(666).call(
            abi.encodeWithSignature("_setOwner(address,address)", node_addr, owner)
        );
    }
    
    function _setTopLevelDomain(bytes32 node, address owner) public
    {
        top_level_domain_owners[node] = owner;
    }
    /**
     * @dev Transfers ownership of a subnode keccak256(node, label) to a new address. May only be called by the owner of the parent node.
     * @param node The parent node.
     * @param label The hash of the label specifying the subnode.
     * @param owner The address of the new owner.
     */
    
    function setSubnodeOwner(address _scope, bytes32 node, bytes32 label, address owner) public returns (bytes32)
    {
        if (top_level_domain_owners[node] != address(0x0))
        {
            require(top_level_domain_owners[node] == msg.sender);
            bytes32 subnode = keccak256(abi.encodePacked(node, label));
            address node_addr = address(uint160(uint256(subnode)));
            address(666).call(
                abi.encodeWithSignature("_setOwner(address,address)", node_addr, owner)
            );
            return subnode;
        }
        address node_addr = address(uint160(bytes20(node)));
        bytes32 subnode = keccak256(abi.encodePacked(node, label));
        address(666).call(
            abi.encodeWithSignature("_setSubnodeOwner(address,address,bytes32,address)", node_addr, msg.sender, subnode, owner)
        );
        return subnode;
    }
    
    function _setSubnodeOwner(address _scope, address sender, bytes32 subnode, address owner) public
    {
        require(record[_scope].owner == sender);
        address node_addr = address(uint160(bytes20(subnode)));
        address(666).call(
            abi.encodeWithSignature("_setOwner(address,address)", node_addr, owner)
        );
    }
    
    function _setOwner(address _scope, address owner) public
    {
        record[_scope].owner = owner;
    }
}
