/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>

int RECV_PIN = A0;
IRrecv irrecv(RECV_PIN);
decode_results result;

void setup()
{
  irrecv.enableIRIn(); // Start the receiver
  for(int i=7;i<=13;i++)
    pinMode(i,OUTPUT);
}

void loop() {
  if (irrecv.decode(&result)) {

    switch (result.value)
  {
    case 0xF377C5B7: //0
    {
      for(int i=7;i<=12;i++)
        digitalWrite(i,1);
      digitalWrite(13,0);
      break;
    }
    case 0x305D6FF://1
    {
      digitalWrite(7,0);
      digitalWrite(8,1);
      digitalWrite(9,1);
      for(int i=10;i<=13;i++)
        digitalWrite(i,0);
      break;
    }
    case 0x8AB3679B://2
    {
      digitalWrite(7,1);
      digitalWrite(8,1);
      digitalWrite(13,1);
      digitalWrite(11,1);
      digitalWrite(10,1);
      digitalWrite(9,0);
      digitalWrite(12,0);
      break;
    }
    case 0xFF9186B7: //3
    {
      for(int i=7;i<=10;i++)
        digitalWrite(i,1);
      digitalWrite(13,1);
      digitalWrite(12,0);
      digitalWrite(11,0);
      break;
    }
    case 0xA23C94BF: //4
    {
      digitalWrite(8,1);
      digitalWrite(9,1);
      digitalWrite(12,1);
      digitalWrite(13,1);
      digitalWrite(7,0);
      digitalWrite(10,0);
      digitalWrite(11,0);
      break;
    }
    case 0xE721C0DB: //5
    {
      digitalWrite(7,1);
      digitalWrite(9,1);
      digitalWrite(10,1);
      digitalWrite(12,1);
      digitalWrite(13,1);
      digitalWrite(8,0);
      digitalWrite(11,0);
      break;
    }
    case 0xF0C41643: //6
    {
      for(int i=9;i<=12;i++)
        digitalWrite(i,1);
      digitalWrite(7,1);
      digitalWrite(13,1);
      digitalWrite(8,0);
      break;
    }
    case 0x86B0E697: //7
    {
      for(int i=7;i<=9;i++)
        digitalWrite(i,1);
      for(int i=10;i<=13;i++)
        digitalWrite(i,0);
      break;
    }
    case 0x9EF4941F://8
    {
      for(int i=7;i<=13;i++)
        digitalWrite(i,1);
      break;
    }
    case 0xA3C8EDDB://9
    {
      for(int i=7;i<=10;i++)
        digitalWrite(i,1);
      digitalWrite(12,1);
      digitalWrite(13,1);
      digitalWrite(11,0);
      break;
    }
  }
    
    irrecv.resume(); // Receive the next value
  }
  //delay(100);
}
