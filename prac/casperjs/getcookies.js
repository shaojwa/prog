

var casper = require('casper').create({
    verbose: false,
    pageSettings: {
        loadImages: false
    }
});


if (!casper.cli.has('url')) {
    casper.echo("No url!");
    casper.exit();
}


var initUrl = casper.cli.get('url');


casper.on('remote.message', function(msg) {
    console.log(msg)
});

casper.page.setCookies({'name':'login', 'value':'tshirtman'});

casper.start(initUrl);
casper.then(function() {
    var cookies = phantom.cookies;
    this.echo("cookie.length = " + cookies.length);
    for (var i in cookies) {
        this.echo(cookies[i].name + "=" +  cookies[i].value);
    }
 

});


casper.run();
