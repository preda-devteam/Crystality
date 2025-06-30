pragma solidity ^0.8.17;

contract KittyBreeding
{
    struct KittyInfo
    {
        bool gender;
        uint birthTime;
        address owner;
    }
    struct Kitty
    {
        uint id;
        uint genes;
        uint matronId;
        uint sireId;
        uint lastBreed;
    }
    KittyInfo[] allKitties;
    KittyInfo[] newBorns;
    mapping (address => mapping(uint=>Kitty)) myKitties;
    
    function create(bool gender, address owner) internal returns (uint)
    {
        uint id = allKitties.length;
        KittyInfo memory n;
        n.gender = gender;
        n.birthTime = block.number;
        n.owner = owner;
        allKitties.push(n);
        return id;
    }
    
    function mint(address owner, uint genes, bool gender) public
    {
        address(888).call(
            abi.encodeWithSignature("_mint(address,uint256,bool)", owner, genes, gender)
        );
    }
    
    function _mint(address owner, uint genes, bool gender) public
    {
        uint id = create(gender, owner);
        address(666).call(
            abi.encodeWithSignature("_addNewKittyToAddr(address,uint256,uint256)", owner, genes, id)
        );
    }
    
    function _addNewKittyToAddr(address _scope, uint genes, uint id) public
    {
        _addNewKittyToAddr(_scope, genes, id, type(uint256).max, type(uint256).max);
    }
    
    function _addNewKittyToAddr(address _scope, uint genes, uint id, uint matronId, uint sireId) public
    {
        Kitty memory newKitty;
        newKitty.id = id;
        newKitty.genes = genes;
        newKitty.matronId = matronId;
        newKitty.sireId = sireId;
        newKitty.lastBreed = block.number;
        myKitties[_scope][id] = newKitty;
    }
    
    function sqrt(uint x) pure internal returns (uint)
    {
        uint z = (x + 1) / 2;
        uint y = x;
        while (z < y)
        {
            y = z;
            z = (x / z + z) / 2;
        }
        return y;
    }
    
    function genesMix(uint m_genes, uint s_gengs) pure internal returns (uint)
    {
        uint new_genes = sqrt(m_genes) * sqrt(s_gengs);
        new_genes = sqrt(m_genes) * sqrt(s_gengs);
        new_genes = sqrt(m_genes) * sqrt(s_gengs);
        new_genes = sqrt(m_genes) * sqrt(s_gengs);
        new_genes = sqrt(m_genes) * sqrt(s_gengs);
        new_genes = sqrt(m_genes) * sqrt(s_gengs);
        return new_genes;
    }
    
    function breed(address _scope, uint m, uint s, bool gender) public
    {
        require(m < allKitties.length);
        require(s < allKitties.length);
        require(allKitties[m].gender);
        require(!allKitties[s].gender);
        address(666).call(
            abi.encodeWithSignature("addMGenes(address,uint256,uint256,bool)", allKitties[m].owner, m, s, gender)
        );
    }
    
    function addMGenes(address _scope, uint m, uint s, bool gender) public
    {
        myKitties[_scope][m].lastBreed = block.number;
        address(666).call(
            abi.encodeWithSignature("addSGenes(address,uint256,uint256,uint256,bool)", allKitties[s].owner, myKitties[_scope][m].genes, m, s, gender)
        );
    }
    
    function addSGenes(address _scope, uint m_genes, uint m, uint s, bool gender) public
    {
        uint new_genes = genesMix(m_genes, myKitties[_scope][s].genes);
        address(666).call(
            abi.encodeWithSignature("addNewBorn(address,uint256,uint256,bool,uint256)", _scope, m, s, gender, new_genes)
        );
    }
    
    function addNewBorn(address _scope, uint m, uint s, bool gender, uint new_genes) public
    {
        uint birth_time = block.number;
        uint id_nb = newBorns.length | (1 << 255);
        _addNewKittyToAddr(_scope, new_genes, id_nb, m, s);
        KittyInfo memory n;
        n.gender = gender;
        n.birthTime = birth_time;
        n.owner = _scope;
        newBorns.push(n);
    }
    
    function finalize(address _scope) public
    {
        address(888).call(
            abi.encodeWithSignature("register()")
        );
    }
    
    function register() public
    {
        address(777).call(
            abi.encodeWithSignature("registerNewBorns()")
        );
    }
    
    function registerNewBorns() public
    {
        if (newBorns.length > 0)
        {
            address[] memory _addresses = new address[](newBorns.length);
            for (uint i = 0; i < newBorns.length; ++i)
            {
                _addresses[i] = newBorns[i].owner;
            }
            address(888).call(
                abi.encodeWithSignature("_registerNewBorns(address[])", _addresses)
            );
            delete newBorns;
        }
    }
    
    function _registerNewBorns(address[] memory new_borns) public
    {
        for (uint i = 0; i < new_borns.length; i++)
        {
            uint id = allKitties.length;
            address(666).call(
                abi.encodeWithSignature("_refreshKitty(address,uint256,uint256)", new_borns[i], i, id)
            );
        }
    }
    
    function _refreshKitty(address _scope, uint newBornIndex, uint id) public
    {
        uint id_nb = (1 << 255) | newBornIndex;
        myKitties[_scope][id] = myKitties[_scope][id_nb];
        delete myKitties[_scope][id_nb];
    }
}
