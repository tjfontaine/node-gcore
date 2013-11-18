var gcore = require('./index');

var i = 0;
var arr = [];
setInterval(function() {
  i++;
  gcore.gcore('gcore.' + i);
  var foo = 'dumped gcore.' + i;
  console.log(foo);
  arr.push(foo);
}, 1 * 1000);
