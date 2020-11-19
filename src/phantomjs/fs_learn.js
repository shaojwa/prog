
var fs = require('fs');
console.log(fs.separator);
console.log(fs.workingDirectory);
console.log(fs.absolute("."));

var system = require('system');
var os = system.os;
console.log(os.architecture);
console.log(os.name);
console.log(os.version);

phantom.exit();

