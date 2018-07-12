//char* str[]={"on","off"};
int compStr;
void setup()
{
  Serial.begin(9600);
  pinMode(13,OUTPUT);
}
void loop()
{
    compStr = Serial.read();

// so sánh
  
    if (compStr == '1')
    {
      digitalWrite(13,1);
      Serial.println("bat");
    }
    else if (compStr == '0')
    {
      digitalWrite(13,0);
      Serial.println("tat");
    }   
}

