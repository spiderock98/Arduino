// Cathode chung

void setup()
{
  Serial.begin(9600);
  for(int i=7;i<=13;i++)
    pinMode(i,OUTPUT);
}
void loop()
{
  while(Serial.available())
  {
    char val = char(Serial.read());
    Seg(val);
    Serial.println(val);
  }
}
void Seg(char Number)
{
  switch (Number)
  {
    case '0': 
    {
      for(int i=7;i<=12;i++)
        digitalWrite(i,1);
      digitalWrite(13,0);
      break;
    }
    case '1':
    {
      digitalWrite(7,0);
      digitalWrite(8,1);
      digitalWrite(9,1);
      for(int i=10;i<=13;i++)
        digitalWrite(i,0);
      break;
    }
    case '2':
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
    case '3':
    {
      for(int i=7;i<=10;i++)
        digitalWrite(i,1);
      digitalWrite(13,1);
      digitalWrite(12,0);
      digitalWrite(11,0);
      break;
    }
    case '4':
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
    case '5':
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
    case '6':
    {
      for(int i=9;i<=12;i++)
        digitalWrite(i,1);
      digitalWrite(7,1);
      digitalWrite(13,1);
      digitalWrite(8,0);
      break;
    }
    case '7':
    {
      for(int i=7;i<=9;i++)
        digitalWrite(i,1);
      for(int i=10;i<=13;i++)
        digitalWrite(i,0);
      break;
    }
    case '8':
    {
      for(int i=7;i<=13;i++)
        digitalWrite(i,1);
      break;
    }
    case '9':
    {
      for(int i=7;i<=10;i++)
        digitalWrite(i,1);
      digitalWrite(12,1);
      digitalWrite(13,1);
      digitalWrite(11,0);
      break;
    }
  }
}

