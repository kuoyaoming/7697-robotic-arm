#include <Servo.h>

Servo myservo7;
Servo myservo8;
Servo myservo9;
Servo myservo10;

int a=0;

void setup()
{
  
  Serial.begin(9600);
  myservo7.attach(7);
  myservo8.attach(8);
  myservo9.attach(9);
  myservo10.attach(10);
     
  myservo7.writeMicroseconds(90);
  myservo8.writeMicroseconds(90);
  myservo9.writeMicroseconds(90);
  myservo10.writeMicroseconds(90);
}

void loop()
{
  while (Serial.available()>0)
  {
    a=Serial.read();
    Serial.println(a);
    myservo7.writeMicroseconds(a);
    myservo8.writeMicroseconds(a);
    myservo9.writeMicroseconds(a);
    myservo10.writeMicroseconds(a);
    delay(50);   
  }
  

}
