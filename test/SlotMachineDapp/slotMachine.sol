pragma solidity ^0.4.0;
contract slotMachine{
    uint256 public ownerAmount = 1000000000000000;
    mapping (address => uint) public userBalances;
    uint public zero;
    uint public one;
    uint public two;
    uint public three;
    uint public four;
    uint public five;
    uint public six;
    uint public seven;
    uint public eight;

    function init(){
        zero = 0;
        one = 0;
        two = 0;
        three = 0;
        four = 0;
        five = 0;
        six = 0;
        seven = 0;
        eight = 0;
    }

    function rand(uint256 t) public returns (uint){
        uint256 lastBlockNumber = block.number - 1;
        uint256 hashVal = uint256(block.blockhash(lastBlockNumber))+uint256(block.timestamp);
        return uint256(sha3(uint256(hashVal)+t));
    }
    function doit() public returns (uint256){
        init();
        zero = (rand(0) % 10) +1;
        one = (rand(1) % 10) +1;
        two = (rand(2) % 10) +1;
        three = (rand(3) % 10) +1;
        four = (rand(4) % 10) +1;
        five = (rand(5) % 10) +1;
        six = (rand(6) % 10) +1;
        seven = (rand(7) % 10) +1;
        eight = (rand(8) % 10) +1;
        uint256 ret = 0;
        if(zero == one && zero == two) ret+=zero;
        if(three == four && three == five) ret+=three;
        if(six == seven && six == eight) ret+=six;
        if(zero == three && zero == six) ret+=zero;
        if(one == four && one == seven) ret+=one;
        if(two == five && two == eight) ret+=two;
        if(zero == four && zero == eight) ret+=zero;
        if(two == four && two == six) ret+=two;
        return ret;
    }

    function slot(uint amount){
        address user = msg.sender;
        if(amount > 42000000000000000) throw;
        if(amount*10 >= ownerAmount) throw;
        if(userBalances[user] < amount) throw;
        ownerAmount += amount;
        userBalances[user] -= amount;
        uint256 ret = doit();
        if(ret != 0){
            userBalances[user] += amount*ret;
            ownerAmount -= amount*ret;
        }
    }

    function withDraw(uint256 amount){
        address user = msg.sender;
        if(amount > userBalances[user]) throw;
        userBalances[user] -= amount;
    }

    function deposit(uint256 amount){
        address user = msg.sender;
        userBalances[user] += amount;
    }
}