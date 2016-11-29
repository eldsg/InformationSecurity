/**
 * Created by kim on 16. 11. 28.
 */
if (typeof web3 !== 'undefined') {
    web3 = new Web3(web3.currentProvider);
}
else{
    web = new Web3(new Web3.providers.HttpProvider("http://localhost:8545"));
}