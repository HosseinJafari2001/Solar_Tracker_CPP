#include <Servo.h>
Servo sg90;

void setup()
{
  Serial.begin(9600);
}

void loop() 
{
  sg90.attach(9);
  sg90.write(90);
  int R1 = analogRead(A0);
  int R2 = analogRead(A1);  
  Serial.println(R1);
  Serial.println(R2);
  delay(3000);
}
