#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "b4237e6000db40108fb083d135f38de0";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "VIETTEL";
char pass[] = "Sherlock2211vtag";

WidgetLED led1(V1);//tạo led ảo trên app Blynk

BlynkTimer timer;

// V1 LED Widget is blinking
void blinkLedWidget()
{
  if (led1.getValue()) {
    led1.off();
    
  } else {
    led1.on();
    
  }
}

void setup()
{
  // Debug console
  Serial.begin(115200);
  pinMode(12,INPUT);
  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);

  timer.setInterval(1000L, blinkLedWidget);
}
void loop()
{
  Blynk.run();
  if (digitalRead(12) == 0){
    led1.off();
    Serial.println("LED on V1: off");
  }
  else{
    led1.on();
    Serial.println("LED on V1: on");
  }
  //timer.run();
}
