#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHTesp.h> // including the library of DHT11 temperature and humidity sensor
//#include <SimpleTimer.h>   //including the library of SimpleTimer
//#define DHTTYPE DHT11      // DHT 11
//#define DHTTYPE DHT22   // DHT 22, AM2302, AM2321
//#define DHTTYPE DHT21   // DHT 21, AM2301

#define dht_dpin D5        // ngõ vào cảm biến DHT là chân D5
DHTesp dht;
//SimpleTimer timer;
BlynkTimer timer;
char auth[] = "5cb14295bb134f04a10863383df31ea0"; // Get Auth Token in the Blynk App.
                               // Go to the Project Settings (nut icon).

char ssid[] = "Phong may TTTV";    // Your WiFi credentials.
char pass[] = "";  // Set password to "" for open networks.
float t;                                   // Declare the variables 
float h;

void setup()
{
    Serial.begin(115200);// Debug console
    Blynk.begin(auth, ssid, pass);
    dht.setup(13, DHTesp::DHT11); // Connect DHT sensor to GPIO 17
    timer.setInterval(2000, sendUptime);
}

void sendUptime()
{
  
  float h = dht.getHumidity();   //đọc giá trị nhiệt độ 
  float t = dht.getTemperature();//đọc giá trị độ ẩm
  Serial.println("Humidity and temperature\n\n");
  Serial.print("Current humidity = ");
  Serial.print(h);
  Serial.print("%  ");
  Serial.print("temperature = ");
  Serial.print(t); 
  Blynk.virtualWrite(V0, t); //gửi giá trị nhiệt độ đến biến ảo V0
  Blynk.virtualWrite(V1, h); //gửi giá trị độ ẩm đến biến ảo V1
  
}

void loop()
{
  Blynk.run();
  timer.run();
}
