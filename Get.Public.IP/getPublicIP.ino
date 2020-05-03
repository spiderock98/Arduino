#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

String getIp();

#ifndef STASSID
#define STASSID "VIETTEL"
#define STAPSK  "xxx"
#endif

const int led = 13;
const char* ssid = STASSID;
const char* password = STAPSK;

ESP8266WebServer server(80);

void handleRoot() {
  digitalWrite(led, 1);
  server.send(200, "text/plain", "public ip: " + getIp() + "\nLocalIP: " + WiFi.localIP().toString());
  digitalWrite(led, 0);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  digitalWrite(led, 0);
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);

  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  // put your main code here, to run repeatedly:
  server.handleClient();
}

String getIp()
{
  WiFiClient client;
  if (client.connect("api.ipify.org", 80))
  {
    Serial.println("connected");
    client.println("GET / HTTP/1.0");
    client.println("Host: api.ipify.org");
    client.println();
  } else {
    Serial.println("Connection to ipify.org failed");
    return String();
  }
  delay(5000);
  String line;
  while (client.available())
  {
    line = client.readStringUntil('\n');
    Serial.println(line);
  }
  return line;
}
