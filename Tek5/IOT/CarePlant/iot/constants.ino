#define AP_PORT 90

#define mc_ssid "ESP8266-Access-Point"
#define mc_password "123456789"

#define DB_URL "https://careplant-api.herokuapp.com/api/data/device"
#define DB_URL_LOCAL "http://localhost:8080/api/data/device"
#define ARDCODE "B1234"

const char info_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML>
<html>
  <head>
    <script>
      function switchStatus() {
        fetch('/switch-status', {method: "POST"});
        location.reload();
      }

      function scanWifi() {
        fetch('/scan', {method: "POST"});
        location.reload();
      }
    </script>
  </head>
  <body>
    <h1> Code: %ARDCODE% </h1>
    <h3> WiFi SSID: %WIFINAME% </h3>
    <h3> Status: %STATUS% </h3>
    <h3> %USERSTATUS% </h3>
    <button onclick="switchStatus()">Switch</button>
    <span></span>
    <!-- <button onclick="scanWifi()">Scan Wifi</button> -->
  </body>
</html>)rawliteral";

const char success_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML>
<html>
  <head></head>
  <body>
    <h1> Your device is now connected to the internet and will send data about your plant !</h1>
  </body>
</html>)rawliteral";

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML>
<html>

<head>
    <title>Super Thermo humidité</title>
    <meta charset="utf-8" />
    <meta name="theme-color" content="#000000" />
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <style>
      body {
        margin: 0px;
        height: 100vh;
        width: 100vw;
        display: flex;
      }

      #root {
          color: #333;
          height: 100vh;
          width: 100vw;
          position: relative;
          display: flex;
      }

      #modal {
          margin: auto;
          width: 100vw;
      }

      #modal-inline {
          padding: 6px;
          display: block;
          background-color: rgba(255, 255, 255, 0.836);
          border-radius: 15px;
          margin: auto;
          width: 460px;
      }

      .info {
          display: flex;
          position: relative;
          flex-direction: column;
      }

      .item {
          display: flex;
          position: relative;
          flex-direction: column;
          margin: 0 auto 0 auto;
          width: 370px;
      }

      .list {
          font-family: 'Muli', sans-serif;
          font-size: 18px;
          margin-left: 32%;
      }

      button {
          margin: 15px auto 10px auto;
          width: 230px;
          height: 35px;
          font-size: 19px;
          cursor: pointer;
          border: 0;
          border-radius: 4px;
          font-weight: 700;
          box-shadow: 0 0 20px rgba(4, 3, 9, 0.2);
          transition: 0.4s;
      }

      button:hover:enabled {
          color: white;
          box-shadow: 0 0 20px rgba(43, 101, 28, 0.6);
          background-color: rgb(71, 145, 53);
      }

      h2 {
          padding-bottom: 15px;
          text-align: center;
          font-size: 31px;
          font-family: 'Poppins-Bold';
      }
    </style>
    <script>
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

        fetch('/connect?ssid=' + ssid + '&password=' + password, {method: "POST",
                                                                        body: JSON.stringify({'ssid': parseInt(ssid), 'password': password}),
                                                                        headers: {'Content-Type': 'application/json'}})
        .then(function(res) {
            console.log(res)
        })
        .catch(function(err) {
            console.log(err)
        })
      }
    </script>
</head>

<body>
    <noscript>You need to enable JavaScript to run this app.</noscript>
    <div id="root">
        <div id="modal">
            <div id="modal-inline">
                <h2>Choisir une WIFI</h2>
                <ol class="list">
                  %WIFILIST%
                </ol>
                <form class="info" onsubmit="validateForm(event)">
                    <div class="item">
                        <label>Renseignez le numéro de la WIFI:</label>
                        <input id="wifi" type="number">
                    </div>
                    <div class="item">
                        <label>Renseignez le mot de passe:</label>
                        <input id="mtp" type="password">
                    </div>
                    <button type="submit" id="submit">
                        Valider
                    </button>
                </form>
            </div>
        </div>
    </div>
</body>)rawliteral";