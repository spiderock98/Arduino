// The Green Led Builtin is connect to pin PB0

void setup()
{
    DDRB = B00000001;
}
void loop()
{
    PORTB = B00000001;
    delay(1000);
    PORTB = B00000000;
    delay(1000);
}