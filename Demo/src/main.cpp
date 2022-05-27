#include <Arduino.h>
#include <Servo.h>
void setup() {
 Servo_Init();
 pinMode(32,OUTPUT); // put your setup code here, to run once:
}

void loop() {
 int Angl;
 for(Angl=0;Angl<=100;Angl++)
 {
     Servo_SetAngle(1,Angl);
     delay(200);
     if(Angl>=100)
     {
         Angl = 0;
     }
 }
 
}