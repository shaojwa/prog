
//
//对指定的网址进行页面抓取并显示抓取到的链接
//20151024
//

console.log('**** begin ****');
phantom.outputEncoding="gbk";

var page = require('webpage').create();
var sys = require('system');
var fs = require('fs');
var target_url;
var links_count = 0;
var scripts_count = 0;
var block_req = 0;

if (sys.args.length != 2) {
    console.log('Usage: parse.js <some URL>');
    phantom.exit();
}


page.onConsoleMessage = function(msg, lineNum, sourceId) {
  console.log(msg);
};


page.onResourceRequested = function(requestData, networkRequest) {
    var req_url = requestData.url;
    console.log('request: url = ' + req_url);
    if (block_req === 0) {
        block_req = 1;
        return;
    }
    networkRequest.abort();
};


target_url = "http://" + sys.args[1];;
console.log('target = ' + target_url);
page.open(target_url, function (status) {

    if (status === 'success') {
        scripts_count = page.evaluate(function() {
            return document.getElementsByTagName('script').length;
        });
    }
    else {
        console.log('request failed');
        phantom.exit();
    }

    //抓取静态链接
    console.log('**** capture label-a links ****');
    page.evaluate(function() {
        var static_links = document.getElementsByTagName('a');
        for(var i = 0; i < static_links.length; i++) {
            console.log("a-href: " + static_links[i].href);
        }
    });


    //抓取动态链接
    console.log('**** capture button links ****');
    page.evaluate(function() {
        var url = document.url;
        var btns = document.getElementsByTagName('button');
        for(var i = 0; i < btns.length; i++) {
            console.log('before click ' +  btns[i].id);
            btns[i].click();
            console.log('after click ' +  btns[i].id);
        }
    });
});


    //正则表达式匹
    // console.log('**** capture http links ****');
    // fs.write('content.txt', page.content, 'w');
    // steps = page.content.match(/http:\/\/[\/\w\.]+/ig);
    // if (steps != null) {
    //     steps.forEach(function(ins) {
    //         links_count++;
    //         console.log("http-links: " + ins);
    //     });
    // }


//console.log('*** end ****');
// var now = new Date();
// var exitTime = now.getTime() + 10000;
// while (true) {
//     now = new Date();
//     if (now.getTime() > exitTime) {
//         break;
//     }
// }
// phantom.exit();


    // var btns = document.getElementsByTagName("button");
    // for(var i=0; i<btns.length; i++) {
    //     btns[i].click();
    //     var now = new Date();
    //     var exitTime = now.getTime() + 1000;
    //     while (true) {
    //         now = new Date();
    //         if (now.getTime() > exitTime) {
    //             return;
    //         }
    //     }
    // }
