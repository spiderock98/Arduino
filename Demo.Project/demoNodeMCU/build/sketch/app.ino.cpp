#line 1 "/Users/spiderock/Desktop/demoNodeMCU/app.ino"
#include <ESP8266WiFi.h>
#include <Arduino.h>

#line 4 "/Users/spiderock/Desktop/demoNodeMCU/app.ino"
void setup();
#line 10 "/Users/spiderock/Desktop/demoNodeMCU/app.ino"
void loop();
#line 4 "/Users/spiderock/Desktop/demoNodeMCU/app.ino"
void setup()
{
    Serial.begin(115200);
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
    digitalWrite(LED_BUILTIN, 1);
    delay(500);
    digitalWrite(LED_BUILTIN, 0);
    delay(500);
}

