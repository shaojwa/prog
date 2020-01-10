
//
// goto special page
//
function goto(param) {
    //console.log("param = " + param);
    window.location.href = "http://localhost/" + param + ".html";
    return true;
}

function addNode() {
    var node;
    if (param == 'a') {
        node = document.createElement('P');
    } else if (param == 'b') {
        node = document.createElement('BR');
    } else {
        node = document.createElement('Div');
    }
    document.body.appendChild(node);
}


//
// jump
//
function jump() {
    var ans = prompt("Are you suer you want to do that ?", "looksgood");
    if (ans) {
        alert("you said " + ans);
    } else {
        alert("you refused to answer");
    }
}


//
// loops
//
function loop() {
    var counter = 0;
    var timer = setInerval(function () { alert('interval'); }, 1000)
        while(true) {
            counter++;
            if (counter == 10) {
                clearInterval(timer);
            }
            alert('loop');
        }
}


//
//test post
//
function post(url, params) {
    var temp = document.createElement("form");
    temp.action = url;
    //temp.target = "_blank";
    temp.method = "post";
    temp.style.display = "none";
    for (var x in params) {
        var opt = document.createElement("textarea");
        opt.name = x;
        opt.value = params[x];
        temp.appendChild(opt);
    }
    document.body.appendChild(temp);
    temp.submit();
}


//
// testAjax
//
function testAjax() {
    var xmlhttp;
    if (window.XMLHttpRequest) {
        xmlhttp = new XMLHttpRequest();
    }
    xmlhttp.onreadystatechange = function() {
        var state = xmlhttp.readyState;
        if (xmlhttp.readyState == 4 && xmlhttp.status == 200) {
            document.getElementById('myDiv').innerHTML =
                xmlhttp.responseText;
        }
    }
    xmlhttp.open("GET", "ajax", true);
    xmlhttp.send();
}


//
//show modal dialog
//
function showModal() {
    var obj = new Object();
    try {
        var retval = window.showModalDialog("showModalUrl",
                obj,"dialogWidth=100px;dialogHeight=100px");
        alert(retval);
    } catch (e) {
        alert(e.message);
    }
}
