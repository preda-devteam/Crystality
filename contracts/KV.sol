
contract KV
{
    mapping (address => string) s;
    
    function set(address _scope, uint32 key, string memory value) public
    {
        address key_addr = address(uint160(key));
        address(666).call(
            abi.encodeWithSignature("_set(address,string)", key_addr, value)
        );
    }
    
    function _set(address _scope, string memory value) public
    {
        s[_scope] = value;
    }
}
