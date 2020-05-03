# 1 "/Users/spiderock/Desktop/demoNodeMCU/app.ino"
# 2 "/Users/spiderock/Desktop/demoNodeMCU/app.ino" 2
# 3 "/Users/spiderock/Desktop/demoNodeMCU/app.ino" 2

void setup()
{
    Serial.begin(115200);
    pinMode(2, 0x01);
}

void loop()
{
    digitalWrite(2, 1);
    delay(500);
    digitalWrite(2, 0);
    delay(500);
}
