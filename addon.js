//var addon = require('./build/Release/addon.node');
var addon = require('bindings')('addon');

var objyAccess = new addon.ObjyAccess("MyTest.boot");
//console.log( obj.plusOne() ); // 11
//console.log( obj.plusOne() ); // 12
//console.log( obj.plusOne() ); // 13

console.log( objyAccess.connection() ); 

console.log('try query()')
objyAccess.query("From ooObj return *", function(msg) {
  console.log(msg);
})

console.log('try callback with query2...');

objyAccess.query2(function(msg) {
	console.log(msg);
})
