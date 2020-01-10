"use strict";

var casper = require('casper').create({
    verbose: false,
    pageSettings: {
        loadImages: false
    }
});

var system = require('system');
casper.echo("{\"phantomjs_pid\":" + system.pid + "}");


if (!casper.cli.has('url')) {
    casper.echo("No url!");
    casper.exit();
}
var initUrl = casper.cli.get('url');

var cookie;
if(casper.cli.has('cookie')){
    cookie = casper.cli.get('cookie');
}

var getDomain = function(url) { 
        var host = url;
        var regex = /.*\:\/\/([^\/]*).*/;
        var match = url.match(regex);
        if(typeof match != "undefined" && null != match)
                host = match[1];
        return host;
}


if (cookie) {
    cookie.split(";").forEach(function(pair){
        pair = pair.split("=");
        phantom.addCookie({
        'name': pair[0],
        'value': pair[1],
        'domain': getDomain(initUrl),
        });
    });
}

var loadFinishedFlag = false;
var repeatCnt = 2000;

casper.on('resource.requested', function(req, networkRequest) {
    var url = req.url;
    this.echo(JSON.stringify(req));
    if (loadFinishedFlag) {
        networkRequest.abort();
    }
});

casper.on('remote.message', function(msg) {
    console.log(msg)
});
casper.on('page.initialized', function(){
    this.evaluate(function(){
        window.open = function(url,name,features,replace){
            var req = new Object;
            req.url = url;
            req.method = "GET";
            console.log(JSON.stringify(req))
        };
        window.showModalDialog = function () {
            var url = arguments[0];
            httpGet(url);
        };

    });
});

casper.start(initUrl);
casper.then(function() {
    loadFinishedFlag = true;
});
casper.repeat(repeatCnt, function() {
    repeatCnt--;
});


casper.run(function(){
    this.exit();
},1);
