#include <ESP8266WiFi.h>
const char* ssid = "VIETTEL";
const char* password = "Sherlock2211vtag";
// Create an instance of the server
// specify the port to listen on as an argument
WiFiServer  server(80);
void setup() {
  // prepare GPIO2
  pinMode(2, OUTPUT);
  pinMode(15, OUTPUT);
  digitalWrite(2, 0);
  digitalWrite(15,0);
  // bật baudrate
  Serial.begin(115200);
  delay(10);
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
 while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
    // Start the server
  server.begin();
  Serial.println("Server started");
  // Print the IP address
  Serial.println(WiFi.localIP());
}
void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  
  // Wait until the client sends some data
  Serial.println("new client");
  //ping check kết nối
  while(!client.available()){
    delay(1);
  }
  
  // Read the first line of the request
  String req = client.readStringUntil('\r');
  Serial.println(req);
  client.flush();
  
  // Match the request
  int val;
  int led;
  int k =0;
  if (req.indexOf("/led1/off") != -1)
    {
      val = 0;
      k = 1;
    }
  else if (req.indexOf("/led1/on") != -1)
    {
      val = 1;
      k = 1;
    }
  else if (req.indexOf("/led2/on") != -1)
    {
      led = 1;
      k = 2;
    }
  else if (req.indexOf("/led2/off") != -1)
    {
      led = 0;
      k = 2;
    }
    else if (req.indexOf("/off") != -1)
    {
      led = 0;
      val = 0;
      k=3;
    }
    else if (req.indexOf("/on") != -1)
    {
      led = 1;
      val = 1;
      k=3;
    }
  else {
    Serial.println("invalid request");
    client.stop(); // release để ko bị chồng dữ liệu
    return;
  }

  // Set GPIO2 according to the request
  digitalWrite(2, val);
  digitalWrite(15,led);
  client.flush(); // xoá giá trị biến client

  // Prepare the response
  String chain;
  if (k == 1)
  {
  String s = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>\r\nLed1 is now ";
  s += (val)?"high":"low";
  s += "</html>\n";
  chain = s;
  }
  if(k == 2)
  {
  String s = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>\r\nLed2 is now ";
  s += (val)?"high":"low";
  s += "</html>\n";
  chain = s;
  }
  if(k == 3)
  {
  String s = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>\r\nAll led is now ";
  s += (val)?"high":"low";
  s += "</html>\n";
  chain = s;
  }

  // Send the response to the client
  client.print(chain);
  delay(1);
  Serial.println("Client disonnected");
  

  // The client will actually be disconnected 
  // when the function returns and 'client' object is detroyed

 }
