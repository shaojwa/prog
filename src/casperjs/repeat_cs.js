/*eslint strict:0*/
/*global CasperError, console, phantom, require*/

var casper = require("casper").create();

var links = [
    "http://www.baidu.com/",
];

casper.start();
var start = Date.now();
casper.repeat(1000, function() {
});

casper.run(function(){
    console.log(Date.now() - start);
    this.exit();
}, 10);
