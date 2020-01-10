"use strict";

phantom.outputEncoding = 'utf-8'
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
var urls = initUrl.split(";");
var cookie;
if(casper.cli.has('cookie')){
    cookie = casper.cli.get('cookie');
}

var userAgent;
if (casper.cli.has('user-agent')) {
    userAgent = casper.cli.get('user-agent');
    casper.userAgent(userAgent);
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
    cookie.split("; ").forEach(function(pair){
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

        window.close = function() {};

        function httpGet(theUrl) {
            var xmlHttp = new XMLHttpRequest();
            xmlHttp.open("GET", theUrl, false);
            xmlHttp.send(null);
        }

        window.showModalDialog = function () {
            var url = arguments[0];
            httpGet(url);
        };
    });
});


casper.start().each(urls, function(self, url) {
    self.thenOpen(url, function() {
        loadFinishedFlag = true;
    });

    self.repeat(repeatCnt, function() {
        repeatCnt--;
        // do some work
    });

    self.then(function () {
        loadFinishedFlag = false;
        repeatCnt = 2000;
    });
});


casper.run(function onComplete() {
     this.exit();
},1);
