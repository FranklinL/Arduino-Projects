//Project 5
//Mood Cue

//imports Servo library
#include <Servo.h>

//intiate variables
Servo myServo;
int const potPin = A0;
int potVal;
int angle;

//setup function runs once
void setup() {
  myServo.attach(8); //Servo pin is attached to 8
  Serial.begin (9600); //Begin serial output
}

void loop(){
  
  potVal = analogRead(potPin); //read servo values and then stores it in potVal
  
  Serial.print("potVal: ");
  Serial.print(potVal);
  
  angle = map(potVal, 0, 1023, 0, 179); //map function changes values between 0-1023 to between 0-179

  Serial.print(", angle: ");
  Serial.println(angle);
  
  myServo.write(angle); //moves the servo
  delay(15);
}
