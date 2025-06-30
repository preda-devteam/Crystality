## 部署ENS合约
### 部署ENSRegistry
部署成功后，根地址的owner为部署交易发起者地址
### 部署BaseRegistrarImplementation
部署参数：
_ens：ENSRegistry合约地址
_baseNode：0x93cdeb708b7545dc668eb9280176169d1c33cfd8ed6f04690a0bcc88a93fc4ae

## 初始化
### 设置.eth域名的owner
调用ENSRegistry合约的setSubnodeOwner函数
参数：
node："0x0000000000000000000000000000000000000000000000000000000000000000"
label:"0x4f5b812789fc606be1b3b16908db13fc7a9adf7ca72641f84d75b47069d3d7f0"
owner:BaseRegistrarImplementation合约地址

## 发起交易
调用BaseRegistrarImplementation合约的registerWithConfig函数
参数：
使用交易数据中参数即可