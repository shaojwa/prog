

var casper = require('casper').create({
    verbose: false,
    pageSettings: {
        loadImages: true
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

casper.start(initUrl);
casper.then(function() {
    this.wait(2000,function(){
        var obj=this.getElementBounds('.logo-box span');
        this.echo("top:" + obj.top + ", left:" + obj.left + 
            ", width:" + obj.width + ", height:" + obj.height);

        this.capture('cap0.png');
        this.capture('cap1.png', {
            top: obj.top,
            left:  obj.left,
            width:  obj.width,
            height:  obj.height
        });

        this.captureSelector('cap2.png','.logo-box span');
        this.colse();
    });
});


casper.run();
