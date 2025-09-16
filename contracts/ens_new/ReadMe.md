## Deploy ENS Contracts

### Deploy ENSRegistry

After successful deployment, the owner of the root node will be the address of the transaction sender.

### Deploy BaseRegistrarImplementation

Deployment parameters:

- `_ens`: ENSRegistry contract address
- `_baseNode`: `0x93cdeb708b7545dc668eb9280176169d1c33cfd8ed6f04690a0bcc88a93fc4ae`

## Initialization

### Set the owner of the `.eth` domain

Call the `setSubnodeOwner` function of the ENSRegistry contract with the following parameters:

- `node`: `0x0000000000000000000000000000000000000000000000000000000000000000`
- `label`: `0x4f5b812789fc606be1b3b16908db13fc7a9adf7ca72641f84d75b47069d3d7f0`
- `owner`: BaseRegistrarImplementation contract address

## Execute Transaction

Call the `registerWithConfig` function of the BaseRegistrarImplementation contract.
 Parameters: Use the values provided in the transaction data.
