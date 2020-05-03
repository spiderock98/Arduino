#include <BlynkSimpleEsp8266.h>
#include <Servo.h>
#include <SPI.h>
#include <ESP8266WiFi.h>

char ssid[]= "VIETTEL";
char pass[] = "Sherlock2211vtag";
char auth[] = "b4237e6000db40108fb083d135f38de0";
int retVal;
Servo servo;
BLYNK_WRITE(V1) //Button Widget is writing to pin V1
  {
    int val = param.asInt();
    Serial.print("V1 Slider value is: ");
    Serial.println(val);
    retVal = val;
  }

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Blynk.begin(auth,ssid,pass);
  servo.attach(2);
}

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();
  //BLYNK_WRITE(V1);
  servo.write(retVal);
}
