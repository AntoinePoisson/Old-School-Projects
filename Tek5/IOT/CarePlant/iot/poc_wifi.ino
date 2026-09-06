#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <Arduino_JSON.h>
//#define home_password "XXXXXXXX_WIFI_PASSWORD_REDACTED_XXXXXXXX"
//#define home_ssid "XXXXXXXX_WIFI_SSID_REDACTED_XXXXXXXX"
#define i_ssid "XXXXXXXX_HOTSPOT_SSID_REDACTED_XXXXXXXX"
#define i_password "XXXXXXXX_HOTSPOT_PASSWORD_REDACTED_XXXXXXXX"
#define DB_URL_LOCAL "http://localhost:8080/api/data/device"
#define DB_URL "http://careplant-api.herokuapp.com/api/data/device"
#define DATE_API_URL "https://www.timeapi.io/api/Time/current/zone?timeZone=Europe/Paris"

extern String home_ssid;
extern String home_password;

enum CONNECTION_STATUS {
  NONE = 0,
  CREDENTIALS = 1,
  CONNECTED = 2,
  FAILED = 3
};

enum USER_STATUS {
  PAUSE = 0,
  SEND = 1
};

enum CONNECTION_STATUS status = NONE;
enum USER_STATUS user_status = SEND;

String input;

HTTPClient http;
WiFiClient client;

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_AP);
  scanAndFormatWifi();
  setupAccessPoint();
}

void loop() {
  delay(2000);
  checkConnection(home_ssid, home_password);
  if (status == FAILED) {
    Serial.println("Connection failed."); // Client will have to go to /connect again
  }
  if (status == CREDENTIALS) {
    setupWifi(home_ssid, home_password);
  }
  else if (status == CONNECTED && user_status == SEND) {
    readInputAndMakeRequest();
  }
}

void readInputAndMakeRequest() {
  int avg = 0;
  Serial.println();
  Serial.println("Reading value and sending to api...");
  for (int i = 0; i < 10; i++) {
    delay(100);
    int res = getSensorValue();
    if (res > 1000)
      res = 1000;
    avg = (avg + (res / 10)) / 2; // Moyenne des valeurs
  }
  http.begin(client, DB_URL);
  http.addHeader("Content-Type", "application/json");
  Serial.println("{\"code\": \"B1234\",\"data\": " + String(avg) + "}");
  int httpCode = http.POST("{\"code\": \"B1234\",\"data\": " + String(avg) + "}");
  Serial.print("============ Response Code: ");
  Serial.println(httpCode);
  if (httpCode != 200) {
    Serial.println("Error while posting values");
  }
  http.end();
  delay(9000);
}

void setupWifi(String ssid, String password) {
  Serial.println("============================================================================================================");
  Serial.println("====== Wifi SSid: |" + home_ssid + "| ======= Wifi Password: |" + home_password + "|=======");
  Serial.println("============================================================================================================");
  WiFi.begin(ssid, password);
  int counter = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    if (counter > 80) {  // If counter > 120, the connection is considered as failed.
      status = FAILED;
      scanAndFormatWifi();
      WiFi.disconnect();
      home_ssid = "";
      home_password = "";
      return;
    }
    counter++;
    Serial.print(".");
  }
  status = CONNECTED;  // Loop out, we're connected;
}

void printConnectionInfo() {
  Serial.println("");
  Serial.println("WiFi connecté");
  Serial.print("MAC : ");
  Serial.println(WiFi.macAddress());
  Serial.print("Adresse IP : ");
  Serial.println(WiFi.localIP());
}

void checkConnection(String ssid, String password) {
  if (!ssid || ssid == "" || !password || password == "") {
    status = NONE;
    return;
  } else if (WiFi.status() == WL_CONNECTED) {
    status = CONNECTED;
    return;
  } else if (ssid != "" && password != "")
    status = CREDENTIALS;
  else
    status = FAILED;
}