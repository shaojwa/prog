phantom.outputEncoding = "gbk";//解决乱码问题
//phantom.timeout = 120000;
var casper = require('casper').create({
  clientScripts: ["jquery-1.7.2.min.js"],
  verbose: false,
  logLevel: 'debug',
  pageSettings: {
    //loadImages: false, // The WebPage instance used by Casper will
    loadPlugins: false // use these settings
  }
});
var args2 = casper.cli.args;
//var url2 = "http://flights.ctrip.com/booking/"+args2[0]+"-"+args2[1]+"-day-"+args2[2]+".html";
var url2 = "http://flights.ctrip.com/booking/sha-kmg-day-1.html";
console.log(url2);
casper.start(url2, function() {
	this.capture('post.png');
});

// 3. 开始搜索价格  
/*casper.then(function getPrice() {
	  
	if(this.exists("#J_flightlist2")){
		this.echo('true');
		this.captureSelector('capture1.png', '#J_searchError');
	    product = casper.evaluate(function getPriceFromPage() { 
	        return $("#J_searchError").html();
	    });
	    console.log(product);
	 }
});*/

/*casper.start(url2, function() {
    this.echo('ctrip...');
});    
casper.then(function() {
	//this.click(".btn_book");
	//this.click(".btn_book");
});
   
casper.then(function() {
    this.wait(3000,function() {
    	//this.capture('post.png');
        if(this.exists("#J_flightlist2")){
        	//this.captureSelector('capture2.png', '#J_flightlist2');
			product = casper.evaluate(function getProductFromPage() {
		    	return $("#J_flightlist2").html();
		  	});
		  	console.log(product);
		}
    });
});
*/

casper.then(function() {
    this.wait(3000,function() {
    	this.capture('post1.png');
        if(this.exists("#J_flightlist2")){
        	//this.captureSelector('capture2.png', '#J_flightlist2');
			product = casper.evaluate(function getProductFromPage() {
		    	return $("#J_flightlist2").html();
		  	});
		  	console.log(product);
		}
    });
});


casper.run();
