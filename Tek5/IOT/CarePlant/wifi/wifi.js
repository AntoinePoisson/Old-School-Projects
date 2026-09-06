document.addEventListener("DOMContentLoaded", function (event) {
    var setEnabled;
    (setEnabled = function () {
        var res = false;
        for (const el of document.querySelectorAll("input")) {
            if (!el.value) {
                res = true;
                break;
            }
        }
        document.getElementById("submit").disabled = res;
    })();

    document.oninput = setEnabled;
    document.onchange = setEnabled;

})

function validateForm(event) {
    event.preventDefault();
    let ssid = event.target['wifi'].value;
    let password = event.target['mtp'].value;

    console.log("Info:", wifi, mtp);
    // // let httpRequest = new XMLHttpRequest();
    // // if (!httpRequest) {
    // //     alert('Abandon :( Impossible de créer une instance de XMLHTTP');
    // //     return false;
    // // }
    // // // httpRequest.onreadystatechange = function alertContents() {
    // // //     if (httpRequest.readyState === XMLHttpRequest.DONE) {
    // // //         if (httpRequest.status === 200) {
    // // //             alert(httpRequest.responseText);
    // // //         } else {
    // // //             alert('Il y a eu un problème avec la requête.');
    // // //         }
    // // //     }
    // // // }
    // // // 0.0.0.0/connect?ssid=&password=
    // // httpRequest.open('GET', '0.0.0.0/connect?ssid=' + ssid + '&password=' + password, true);
    // // httpRequest.send();
    ///////
    // fetch("'0.0.0.0/connect?ssid=' + ssid + '&password=' + password")
    // .then(function(res) {
    //     console.log(res)
    // })
    // .catch(function(err) {
    //     console.log(err)
    // })
}