//var addon = require('./build/Release/addon.node');
var addon = require('bindings')('addon');

var objyAccess = new addon.ObjyAccess("/home/ibrahim/projects/blockparser/data/bitcoin.boot");
//console.log( obj.plusOne() ); // 11
//console.log( obj.plusOne() ); // 12
//console.log( obj.plusOne() ); // 13

console.log('querying FD: ', objyAccess.connection()); 

console.log('try query()')
objyAccess.query("From Block return count(*)", function(msg) {
  console.log(msg);
})

console.log('Done processing.');
