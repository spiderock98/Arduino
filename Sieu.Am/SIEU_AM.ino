const int trig = 8;     // chân trig của HC-SR04
const int echo = 7;     // chân echo của HC-SR04
 
void setup()
{
    Serial.begin(9600);     // giao tiếp Serial với baudrate 9600
    pinMode(trig,OUTPUT);   // chân trig sẽ phát tín hiệu
    pinMode(echo,INPUT);    // chân echo sẽ nhận tín hiệu
}
 
void loop()
{
    unsigned long duration; // biến đo thời gian
    float distance;           // biến lưu khoảng cách
    
    /* Phát xung từ chân trig */
    digitalWrite(trig,1);   // tắt chân trig
    delayMicroseconds(2);
    digitalWrite(trig,0);   // phát xung từ chân trig
    delayMicroseconds(5);   // xung có độ dài 5 microSeconds
    digitalWrite(trig,1);   // tắt chân trig
    
    /* Tính toán thời gian */
    // Đo độ rộng xung HIGH ở chân echo. 
    duration = pulseIn(echo,HIGH02198f);  
    // Tính khoảng cách đến vật.
    distance = int((duration*0.034)/2);
    
    /* In kết quả ra Serial Monitor */
    Serial.print(distance);
    Serial.println(" cm");
    delay(200);
}
