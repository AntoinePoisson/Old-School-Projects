#include <ESPAsyncWebServer.h>
#include <ArduinoJson.h>

AsyncWebServer server(AP_PORT);

String availableSsids[30];
String htmlWifiList = "";

String home_ssid = "";
String home_password = "";

extern const char index_html[];
extern const char info_html[];
extern enum CONNECTION_STATUS status;
extern enum USER_STATUS user_status;

String processor(const String& var) {
  if(var == "WIFILIST") {
    String wifiList;
    wifiList += htmlWifiList;
    return wifiList;
  }
  return String();
}

String status_processor(const String& var) {
  if(var == "STATUS") {
    switch (status) {
      case FAILED:
        return "Failed to connect, please try again";
      case CONNECTED:
        return "Device is connected to internet and sending data";
      case CREDENTIALS:
        return "Device is trying to connect to your wifi";
      default:
        return "Try to connect by going to /connect";
    }
  }
  if (var == "USERSTATUS") {
    if (user_status == SEND) {
      return "Device is working and sending data. Press button to pause it.";
    } else {
      return "Device is on pause. Press button to start it.";
    }
  }
  return String();
}

void setupAccessPoint() {
  WiFi.softAP(mc_ssid, mc_password);
  IPAddress IP = WiFi.softAPIP();
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *req) {
    req->send_P(200, "text/html", index_html, processor);
  });
  server.on("/info", HTTP_GET, [](AsyncWebServerRequest *req) {
    req->send_P(200, "text/html", info_html, status_processor);
  });
  server.on("/switch-status", HTTP_POST, [](AsyncWebServerRequest *req) {
    if (user_status == SEND)
      user_status = PAUSE;
    else
      user_status = SEND;
  });
  server.on("/scan", HTTP_POST, [](AsyncWebServerRequest *req) {
    scanAndFormatWifi();
  });
  server.on("/connect", HTTP_POST, 
    [](AsyncWebServerRequest * request) {
      Serial.print("Content type::");
      Serial.println(request->contentType());
  }, nullptr, [](AsyncWebServerRequest* req, uint8_t* data, size_t len, size_t index, size_t total) {
    status = NONE;
    WiFi.disconnect();
    DynamicJsonDocument bodyJSON(1024);
    deserializeJson(bodyJSON, data, len);
    String ssid_index = bodyJSON["ssid"];
    String pw = bodyJSON["password"];
    int chosen_ssid_index = atoi(ssid_index.c_str()) - 1;
    if (chosen_ssid_index < 0 || chosen_ssid_index > 30 || !availableSsids[chosen_ssid_index] || availableSsids[chosen_ssid_index] == "") {
      Serial.println("Error, SSID must be between 1 and MAX_SSID.");
      req->redirect("/error");
      return;
    }
    home_ssid = availableSsids[chosen_ssid_index];
    home_password = pw;
    Serial.print("Chosen SSID: ");
    Serial.print(home_ssid);
    Serial.println(" | Chosen PW: " + home_password);
    status = CREDENTIALS;
  });
  server.begin();
  Serial.print("AP Exposed on: ");
  Serial.println(IP);
  Serial.println("HTTP server started");
}

void scanAndFormatWifi() {
  String ssid;
  int32_t rssi;
  uint8_t encryptionType;
  uint8_t* bssid;
  int32_t channel;
  bool hidden;
  int scanResult;
  int total = 0;

  htmlWifiList = "";
  for (int i = 0; i < 30; i++) {
    availableSsids[i] = "";
  }
  Serial.println("Starting scan");
  scanResult = WiFi.scanNetworks(false, true);
  if (scanResult == 0) {
    return; // TODO
  }
  for (int8_t i = 0; i < scanResult; i++) {
    WiFi.getNetworkInfo(i, ssid, encryptionType, rssi, bssid, channel, hidden);
    if (!ssid || ssid == "")
      continue;
    htmlWifiList += "<li>" + ssid + "</li>";
    availableSsids[total++] = String(ssid);
  }
  for (int i = 0; i < total; i++) {
    Serial.println("Ssid: " + availableSsids[i]);
  }
  Serial.println("Scanning Done");
}
