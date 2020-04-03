/* Arduino tutorial - Buzzer / Piezo Speaker
   More info and circuit: http://www.ardumotive.com/how-to-use-a-buzzer-en.html
   Dev: Michalis Vasilakis // Date: 9/6/2015 // www.ardumotive.com */


const int buzzer = 11; //buzzer to arduino pin 9


void setup() {

  pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output

}

void loop() {
  for (int i = 0; 5000 - i; ) {
    tone(buzzer, i);
    delay(5);
    ++i;
  }
  for (int i = 5000; i; ) {
    tone(buzzer, i);
    delay(5);
    --i;
  }
}
