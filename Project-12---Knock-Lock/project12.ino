//import Servo library
#include <Servo.h>
//creats servo instance
Servo myServo;

//Intialize constants to hold input and outputs
const int piezo = A0;
const int switchPin = 2;
const int yellowLED = 3;
const int greenLED = 4;
const int redLED = 5;

//intialize variables to hold values from the switch and piezo
int knockVal;
int switchVal;

//set up constans to use as thresholds for max. and min.
const int quietKnock = 10;
const int loudKnock = 100;
boolean locked =false;
int numberOfKnocks = 0;

//attach servo to pin 9 and sets the LED pins as outputs and switch as input
void setup(){
  myServo.attach(9);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(switchPin, INPUT);
  Serial.begin(9600);
}
//checks to see if box is locked. If locked reads switch value.
void loop(){
  if (locked == false){
    switchVal = digitalRead(switchPin);
    
    //if switch is pressed changes the lock variable to true (locking the box)
    //turns off the green LED and turns on the red LED and writes to the serial monitor
    if (switchVal == HIGH){
      locked = true;
      digitalWrite(greenLED, LOW);
      digitalWrite(redLED, HIGH);
      myServo.write(90);
      Serial.println("The box is locked!");
      delay (1000);
    }
  }
  // if locked variable is true, it reads the value of the vibration of the piezo and stores it in knock val.
  if (locked == true){
    knockVal = analogRead(piezo);
    
    if(numberOfKnocks < 3 && knockVal > 0){
      if (checkForKnocks(knockVal) == true){
        numberOfKnocks++;
      }
      Serial.print(3 - numberOfKnocks);
      Serial.println(" mores knocks to go");
    }
    if(numberOfKnocks >= 3){
      locked = false;
      myServo.write(0);
      delay(20);
      digitalWrite(greenLED, HIGH);
      digitalWrite(redLED, LOW);
      Serial.println("The box is unlocked!");
    }
  }
}

boolean checkForKnocks(int value){
  if (value > quietKnock && value < loudKnock){
    digitalWrite(yellowLED, HIGH);
    delay(50);
    digitalWrite(yellowLED, LOW);
    Serial.print("Valid knock of value ");
    Serial.println(value);
    return true;
  }
  else {
    Serial.print ("Bad knock value ");
    Serial.println(value);
    return false;
  }
}
  
