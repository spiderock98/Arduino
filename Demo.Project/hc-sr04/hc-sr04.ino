#include <Streaming.h>

const int trig = 11;
const int echo = 12;

unsigned long duration;
float distance;

void setup()
{
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop()
{
  digitalWrite(trig, 0);
  digitalWrite(trig, 1);
  delayMicroseconds(5);
  digitalWrite(trig, 0);

  //distance = int(duration / 2 / 29.412);
  distance = float(pulseIn(echo, HIGH)) * 34 / 1000 / 2;

  Serial << distance << " cm" << endl;

  delay(200);
}
