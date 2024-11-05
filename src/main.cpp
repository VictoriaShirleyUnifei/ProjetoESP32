#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "ESP32-Victoria";
const char* password = "03122001";

WebServer server(80);

void handleRoot() {
  server.send(200, "text/html", "<html><body><h1>ESP32 da Victoria</h1><p>Teste do ESP32 na aula de ECOP11A</p></body></html>");
  Serial.println("Pagina enviada ao cliente.");
}

void setup() {
  Serial.begin(115200);
  WiFi.softAP(ssid, password);

  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);

  server.on("/", handleRoot);
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}