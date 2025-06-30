pragma solidity ^0.8.17;

contract NewKittyBreeding
{
    struct Kitty
    {
        uint id;
        address owner;
        uint genes;
        uint matronId;
        uint sireId;
        uint birthTime;
        uint lastBreed;
    }
    Kitty[] allKitties;
    Kitty[] newBorns;
    
    function breed(address _scope, uint m, uint s) public
    {
        require(m < allKitties.length);
        require(s < allKitties.length);
        uint new_genes = genesMix(allKitties[m].genes, allKitties[s].genes);
        create(msg.sender, new_genes, m, s);
    }
    
    function create(address owner, uint genes, uint matronId, uint sireId) internal returns (uint)
    {
        uint id_nb = newBorns.length;
        Kitty memory newKitty;
        newKitty.birthTime = block.number;
        newKitty.owner = owner;
        newKitty.id = id_nb;
        newKitty.genes = genes;
        newKitty.matronId = matronId;
        newKitty.sireId = sireId;
        newKitty.lastBreed = block.number;
        newBorns.push(newKitty);
        return id_nb;
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
    
    function mint(address owner, uint genes) public returns (uint)
    {
        uint id = allKitties.length;
        Kitty memory newKitty;
        newKitty.birthTime = block.number;
        newKitty.owner = owner;
        newKitty.id = id;
        newKitty.genes = genes;
        newKitty.matronId = 0;
        newKitty.sireId = 0;
        newKitty.lastBreed = block.number;
        allKitties.push(newKitty);
        return id;
    }
    
    function registerNewBorns() public
    {
        if (newBorns.length > 0)
        {
            uint256[] memory ids = new uint256[](newBorns.length);
            address[] memory owners = new address[](newBorns.length);
            uint256[] memory geneses = new uint256[](newBorns.length);
            uint256[] memory matronIds = new uint256[](newBorns.length);
            uint256[] memory sireIds = new uint256[](newBorns.length);
            uint256[] memory birthTimes = new uint256[](newBorns.length);
            uint256[] memory lastBreeds = new uint256[](newBorns.length);
            for (uint256 i = 0; i < newBorns.length; i++)
            {
                ids[i] = newBorns[i].id;
                owners[i] = newBorns[i].owner;
                geneses[i] = newBorns[i].genes;
                matronIds[i] = newBorns[i].matronId;
                sireIds[i] = newBorns[i].sireId;
                birthTimes[i] = newBorns[i].birthTime;
                lastBreeds[i] = newBorns[i].lastBreed;
            }
            address(888).call(
                abi.encodeWithSignature("_registerNewBorns(uint256[],address[],uint256[],uint256[],uint256[],uint256[],uint256[])", ids, owners, geneses, matronIds, sireIds, birthTimes, lastBreeds)
            );
            delete newBorns;
        }
    }
    
    function _registerNewBorns(uint256[] memory ids, address[] memory owners, uint256[] memory geneses, uint256[] memory matronIds, uint256[] memory sireIds, uint256[] memory birthTimes, uint256[] memory lastBreeds) public
    {
        for (uint256 i = 0; i < ids.length; i++)
        {
            Kitty memory kitty;
            uint256 id = allKitties.length;
            kitty.id = id;
            kitty.owner = owners[i];
            kitty.genes = geneses[i];
            kitty.matronId = matronIds[i];
            kitty.sireId = sireIds[i];
            kitty.birthTime = birthTimes[i];
            kitty.lastBreed = lastBreeds[i];
            allKitties.push(kitty);
        }
    }
    
    function register() public
    {
        address(777).call(
            abi.encodeWithSignature("registerNewBorns()")
        );
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
}
