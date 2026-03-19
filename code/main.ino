#include <WiFi.h>
#include <WebServer.h>
#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

const char* ssid = "YOUR_WIFI";
const char* password = "YOUR_PASSWORD";

WebServer server(80);

// Sensor pins
int lm35Pin = 34;
int gasPin = 35;

// Data
float temp, hum, gas;

// System state
bool systemOn = false;

// CSV log
String csvData = "Temp,Humidity,Gas\n";

// ================= READ SENSORS =================
void readSensors() {
  hum = dht.readHumidity();
  temp = dht.readTemperature();
  gas = analogRead(gasPin);

  if (systemOn) {
    csvData += String(temp) + "," + String(hum) + "," + String(gas) + "\n";
  }
}

// ================= SEND JSON =================
void handleReadings() {
  readSensors();

  String json = "{";
  json += "\"temp\":" + String(temp) + ",";
  json += "\"hum\":" + String(hum) + ",";
  json += "\"gas\":" + String(gas);
  json += "}";

  server.send(200, "application/json", json);
}

// ================= DOWNLOAD CSV =================
void handleDownload() {
  server.sendHeader("Content-Disposition", "attachment; filename=data.csv");
  server.send(200, "text/csv", csvData);
}

// ================= SYSTEM ON/OFF =================
void handleUpdate() {
  if (server.hasArg("state")) {
    systemOn = server.arg("state") == "1";
  }
  server.send(200, "text/plain", "OK");
}

// ================= HTML PAGE =================
const char webpage[] PROGMEM = R"rawliteral(
PASTE_YOUR_HTML_CODE_HERE
)rawliteral";

// ================= ROOT =================
void handleRoot() {
  server.send(200, "text/html", webpage);
}

// ================= SETUP =================
void setup() {
  Serial.begin(115200);
  dht.begin();

  WiFi.begin(ssid, password);
  Serial.print("Connecting");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnected!");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.on("/readings", handleReadings);
  server.on("/download", handleDownload);
  server.on("/update", handleUpdate);

  server.begin();
}

// ================= LOOP =================
void loop() {
  server.handleClient();
}
