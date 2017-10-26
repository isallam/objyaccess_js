//var addon = require('./build/Release/addon.node');
var addon = require('bindings')('addon');

var objyAccess = new addon.ObjyAccess("/home/ibrahim/projects/blockparser/data/bitcoin.boot");

console.log('querying FD: ', objyAccess.connection()); 

console.log('try query()')
objyAccess.query("From Block return count(*)", function(msg) {
  console.log(msg);
})

var q2 = 'match p = (:Address {m_Hash == "1HB5XMLmzFVj8ALj6mfBsbifRoD4miY36v"})' +
              '-->()-->(:Transaction)-->(:Input)-->(:Transaction) return p;';
      
objyAccess.query(q2, function(msg) {
    console.log("Q2 Results: ", msg)
})
console.log('Done processing.');
