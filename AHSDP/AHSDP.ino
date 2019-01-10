#include <Servo.h>
Servo myservo; 
int potpin = 0;  
int val,val1;
const int ledPin = 13;
const int ldrPin = A1;    
void setup() 
{
  myservo.attach(9);  
  pinMode(13, OUTPUT);
  pinMode(ldrPin, INPUT);
  Serial.begin(9600);
}
void loop() 
{
  val = analogRead(potpin);    
  int ldrStatus = analogRead(ldrPin);       
  Serial.println(ldrStatus);
  val1 = map(val, 0, 1023, 60, 120);    
  if(val>600||val<400)
  {
   if (ldrStatus <=300) 
     digitalWrite(13, HIGH);
  else 
  {
   digitalWrite(LED_BUILTIN, LOW);
  }
    myservo.write(val1);             
  }
} 
