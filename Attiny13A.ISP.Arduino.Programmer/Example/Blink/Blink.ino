// The Green Led Builtin is connect to pin PB0

void setup()
{
  DDRB = B00000001;
  PRR |= (1 << 1) | (1 << 0); //shut down Timer/Counter0 module and ADC module
  while (1) {
    PORTB = ~PORTB;
    delay(50);
  }
}


void loop()
{}
