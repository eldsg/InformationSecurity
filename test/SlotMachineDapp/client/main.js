import { Template } from 'meteor/templating';
import { ReactiveVar } from 'meteor/reactive-var';

import './main.html';

contractAddress = "0x0fC7c847E62DA63335628D13F0Af6265c68a7Cc7"
ABIArray = [{"constant":false,"inputs":[{"name":"amount","type":"uint256"}],"name":"withDraw","outputs":[],"payable":false,"type":"function"},{"constant":false,"inputs":[{"name":"t","type":"uint256"}],"name":"rand","outputs":[{"name":"","type":"uint256"}],"payable":false,"type":"function"},{"constant":true,"inputs":[{"name":"","type":"address"}],"name":"userBalances","outputs":[{"name":"","type":"uint256"}],"payable":false,"type":"function"},{"constant":true,"inputs":[],"name":"three","outputs":[{"name":"","type":"uint256"}],"payable":false,"type":"function"},{"constant":false,"inputs":[],"name":"doit","outputs":[{"name":"","type":"uint256"}],"payable":false,"type":"function"},{"constant":true,"inputs":[],"name":"two","outputs":[{"name":"","type":"uint256"}],"payable":false,"type":"function"},{"constant":true,"inputs":[],"name":"seven","outputs":[{"name":"","type":"uint256"}],"payable":false,"type":"function"},{"constant":true,"inputs":[],"name":"ownerAmount","outputs":[{"name":"","type":"uint256"}],"payable":false,"type":"function"},{"constant":true,"inputs":[],"name":"six","outputs":[{"name":"","type":"uint256"}],"payable":false,"type":"function"},{"constant":true,"inputs":[],"name":"one","outputs":[{"name":"","type":"uint256"}],"payable":false,"type":"function"},{"constant":true,"inputs":[],"name":"four","outputs":[{"name":"","type":"uint256"}],"payable":false,"type":"function"},{"constant":true,"inputs":[],"name":"five","outputs":[{"name":"","type":"uint256"}],"payable":false,"type":"function"},{"constant":false,"inputs":[{"name":"amount","type":"uint256"}],"name":"slot","outputs":[],"payable":false,"type":"function"},{"constant":false,"inputs":[{"name":"amount","type":"uint256"}],"name":"deposit","outputs":[],"payable":false,"type":"function"},{"constant":true,"inputs":[],"name":"zero","outputs":[{"name":"","type":"uint256"}],"payable":false,"type":"function"},{"constant":true,"inputs":[],"name":"eight","outputs":[{"name":"","type":"uint256"}],"payable":false,"type":"function"},{"constant":false,"inputs":[],"name":"init","outputs":[],"payable":false,"type":"function"}]
data = "606060405266038d7ea4c6800060005534610000575b610807806100236000396000f3606060405236156100e9576000357c01000000000000000000000000000000000000000000000000000000009004806314174f33146100ee5780632530c9051461010b57806326224c641461013c57806345caa1171461016d5780634d536fe3146101905780635fdf05d7146101b357806378710d37146101d65780637aefa817146101f95780638ae5f3151461021c578063901717d11461023f578063a1fca2b614610262578063af11c34c14610285578063b2025e4f146102a8578063b6b55f25146102c5578063bc1b392d146102e2578063cb94343e14610305578063e1c7392a14610328575b610000565b34610000576101096004808035906020019091905050610337565b005b346100005761012660048080359060200190919050506103ae565b6040518082815260200191505060405180910390f35b346100005761015760048080359060200190919050506103ea565b6040518082815260200191505060405180910390f35b346100005761017a610402565b6040518082815260200191505060405180910390f35b346100005761019d610408565b6040518082815260200191505060405180910390f35b34610000576101c0610634565b6040518082815260200191505060405180910390f35b34610000576101e361063a565b6040518082815260200191505060405180910390f35b3461000057610206610640565b6040518082815260200191505060405180910390f35b3461000057610229610646565b6040518082815260200191505060405180910390f35b346100005761024c61064c565b6040518082815260200191505060405180910390f35b346100005761026f610652565b6040518082815260200191505060405180910390f35b3461000057610292610658565b6040518082815260200191505060405180910390f35b34610000576102c3600480803590602001909190505061065e565b005b34610000576102e0600480803590602001909190505061076f565b005b34610000576102ef6107b0565b6040518082815260200191505060405180910390f35b34610000576103126107b6565b6040518082815260200191505060405180910390f35b34610000576103356107bc565b005b6000339050600160008273ffffffffffffffffffffffffffffffffffffffff1681526020019081526020016000205482111561037257610000565b81600160008373ffffffffffffffffffffffffffffffffffffffff168152602001908152602001600020600082825403925050819055505b5050565b600060006000600143039150428240600190040190508381016040518082815260200191505060405180910390206001900492505b5050919050565b60016020528060005260406000206000915090505481565b60055481565b600060006104146107bc565b6001600a61042260006103ae565b81156100005706016002819055506001600a61043e60016103ae565b81156100005706016003819055506001600a61045a60026103ae565b81156100005706016004819055506001600a61047660036103ae565b81156100005706016005819055506001600a61049260046103ae565b81156100005706016006819055506001600a6104ae60056103ae565b81156100005706016007819055506001600a6104ca60066103ae565b81156100005706016008819055506001600a6104e660076103ae565b81156100005706016009819055506001600a61050260086103ae565b8115610000570601600a819055506000905060035460025414801561052a5750600454600254145b1561053757600254810190505b60065460055414801561054d5750600754600554145b1561055a57600554810190505b6009546008541480156105705750600a54600854145b1561057d57600854810190505b6005546002541480156105935750600854600254145b156105a057600254810190505b6006546003541480156105b65750600954600354145b156105c357600354810190505b6007546004541480156105d95750600a54600454145b156105e657600454810190505b6006546002541480156105fc5750600a54600254145b1561060957600254810190505b60065460045414801561061f5750600854600454145b1561062c57600454810190505b8091505b5090565b60045481565b60095481565b60005481565b60085481565b60035481565b60065481565b60075481565b60006000339150669536c70891000083111561067957610000565b600054600a840210151561068c57610000565b82600160008473ffffffffffffffffffffffffffffffffffffffff1681526020019081526020016000205410156106c257610000565b8260006000828254019250508190555082600160008473ffffffffffffffffffffffffffffffffffffffff16815260200190815260200160002060008282540392505081905550610711610408565b905060008114151561076957808302600160008473ffffffffffffffffffffffffffffffffffffffff168152602001908152602001600020600082825401925050819055508083026000600082825403925050819055505b5b505050565b600033905081600160008373ffffffffffffffffffffffffffffffffffffffff168152602001908152602001600020600082825401925050819055505b5050565b60025481565b600a5481565b600060028190555060006003819055506000600481905550600060058190555060006006819055506000600781905550600060088190555060006009819055506000600a819055505b56"

myContract = web3.eth.contract(ABIArray).at(contractAddress);


Template.hello.onCreated(function helloOnCreated() {
    var template = Template.instance();
    myContract.ownerAmount(function(err,res){
        TemplateVar.set(template, "counter", res);
    })
    myContract.userBalances.call(web3.eth.coinbase, function(err, res){
        TemplateVar.set(template, "user", res);
    })
    myContract.zero(function(err, res){
        TemplateVar.set(template, "zero", res);
    })
    myContract.one(function(err, res){
        TemplateVar.set(template, "one", res);
    })
    myContract.two(function(err, res){
        TemplateVar.set(template, "two", res);
    })
    myContract.three(function(err,res){
        TemplateVar.set(template, "three", res);
    })
    myContract.four(function(err,res){
        TemplateVar.set(template, "four", res);
    })
    myContract.five(function(err,res){
        TemplateVar.set(template, "five", res);
    })
    myContract.six(function(err,res){
        TemplateVar.set(template, "six", res);
    })
    myContract.seven(function(err,res){
        TemplateVar.set(template, "seven", res);
    })
    myContract.eight(function(err,res){
        TemplateVar.set(template, "eight", res);
    })
});

Template.hello.helpers({
  counter() {
  },
});

Template.hello.events({
        'click #deposit'(event, instance) {
            myContract.deposit(100000, function (err, res) {
                if (!err) console.log(res);
                else console.log(err);
            })
        },
        'click #slots'(event, instance){
            myContract.slot(10000, function(err, res){
                if (!err) console.log(res);
                else console.log(err);
            })
        },
        'click #withdraw'(event, instance){
            myContract.withDraw(10000, function(err, res){
                if(!err)console.log(res);
                else console.log(err);
            })
        }
    }
);
