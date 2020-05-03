#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define LED 13 //D7
#define BUTTON 12 //D6

char auth[] = "5cb14295bb134f04a10863383df31ea0";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Phong may TTTV";
char pass[] = "";

WidgetLED led1(V1);

void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  
  pinMode(LED, OUTPUT); /* Cấu hình chân 13 ở chế độ OUTPUT */
  pinMode(BUTTON, INPUT_PULLUP); /* Cấu hình chân 12 ở chế độ INPUT */
  digitalWrite(LED, LOW);
}
void loop() {
  Blynk.run();
  
  if(digitalRead(BUTTON) == LOW) /* Nhấn nút, chân 12 ở mức cao, ngược lại ở mức thấp */
  {
    delay(20);  /* Trễ khoảng 20ms để trạng thái điện áp của nút nhấn ổn định */
    while(digitalRead(BUTTON) == LOW) /* Nếu vẫn còn nhấn nút*/
    {
      digitalWrite(LED, HIGH);
      led1.on();
    }
  }
  else
  {
    digitalWrite(LED, LOW);
    led1.off();
  }
}
