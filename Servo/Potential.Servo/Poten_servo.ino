#include <Servo.h>

Servo ser;
void setup()
{
  ser.attach(3);
  ser.write(0);
}
void loop()
{
  while (ser.attached())
  {
    int val = analogRead(A0);
    val = map(val,0,1023,0,180);
    ser.write(val);
  }
}
