int green = 8;
int red = 9;
int yellow = 10;

void setup()
{
  pinMode(green,OUTPUT);
  pinMode(red,OUTPUT);
  pinMode(yellow,OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  while(Serial.available())
  {
    int val = Serial.read();
    switch (val){
    case '1':
    {
      digitalWrite(green,1);
      break;
    }
    case '2':
    {
      digitalWrite(green,0);
      break;
    }
    case '3':
    {
      digitalWrite(red,1);
      break;
    }
    case '4':
    {
      digitalWrite(red,0);
      break;
    }
    case '5':
    {
      digitalWrite(yellow,1);
      break;
    }
    case '6':
    {
      digitalWrite(yellow,0);
      break;
    }
    case '7':
    {
      digitalWrite(green,1);
      digitalWrite(yellow,1);
      digitalWrite(red,1);
      break;
    }
    case '8':
    {
      digitalWrite(green,0);
      digitalWrite(yellow,0);
      digitalWrite(red,0);
      break;
    }
    }
  }
}

