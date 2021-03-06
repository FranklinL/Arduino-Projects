#include <LiquidCrystal.h>
int const potPin = A3;
int const controlPin1 = 8;
int const controlPin2 = 9;
int const enablePin = 10;
int const forwardSwitchPin = 11;
int const reverseSwitchPin = 12;
int const activeLEDPin = 13;
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

int potVal = 0;
int forwardSwitchState = 0;
int prevForwardSwitchState = 0;
int reverseSwitchState = 0;
int prevReverseSwitchState = 0;
int motorEnabled = 0;
int prevMotorSpeed = 0;
int motorSpeed = 0;
int motorDirection = 1;


void setup() {
  lcd.begin(16, 2);
  pinMode(controlPin1, OUTPUT);
  pinMode(controlPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);
  pinMode(forwardSwitchPin, INPUT);
  pinMode(reverseSwitchPin, INPUT);
  pinMode(activeLEDPin, OUTPUT);
  
  digitalWrite(enablePin, LOW);
  
  lcd.clear();
  lcd.print("Motor Speed Is:");
}

void loop() {
  
  
  delay(125);
  forwardSwitchState = digitalRead(forwardSwitchPin);
  reverseSwitchState = digitalRead(reverseSwitchPin);
  potVal = analogRead(potPin);
  
  motorSpeed = potVal / 4;
  
  /* motor Direction detection, checks for direction 
   * and sets a variable to fwd or bck. That variable
   * is passed to the printLCD function.
   */
  
  String motorDirectionText;
  if (motorDirection == 1) {
    motorDirectionText = "Fwd: ";
  }
  else if (motorDirection == 0) {
    motorDirectionText = "Bck: ";
  }
  
  if (forwardSwitchState != prevForwardSwitchState) {
    if (forwardSwitchState == HIGH) {
      motorDirection = 1;
      motorEnabled = 1;
      digitalWrite(activeLEDPin, HIGH);
      printLCD(motorSpeed, prevMotorSpeed, motorDirectionText);
    }
    else if (forwardSwitchState == LOW) {
      digitalWrite(activeLEDPin, LOW);
      motorEnabled = 0;
      motorSpeed = 0;
      printLCD(motorSpeed, prevMotorSpeed, motorDirectionText);
    }
  }  
  else if (reverseSwitchState != prevReverseSwitchState) {
    if (reverseSwitchState == HIGH) {
      motorDirection = 0;
      motorEnabled = 1;
      digitalWrite(activeLEDPin, HIGH);
      printLCD(motorSpeed, prevMotorSpeed, motorDirectionText);
    }
    else if (reverseSwitchState == LOW) {
      motorEnabled = 0;
      digitalWrite(activeLEDPin, LOW);      
      motorSpeed = 0;
      printLCD(motorSpeed, prevMotorSpeed, motorDirectionText);
    }
  }
  if (forwardSwitchState == prevForwardSwitchState) {
    if (forwardSwitchState == HIGH) {
      printLCD(motorSpeed, prevMotorSpeed, motorDirectionText);
    }
  }
  if (reverseSwitchState == prevReverseSwitchState) {
    if (reverseSwitchState == HIGH) {
      printLCD(motorSpeed, prevMotorSpeed, motorDirectionText);
    }
  }
  if (motorDirection == 1) {
    digitalWrite(controlPin1, HIGH);
    digitalWrite(controlPin2, LOW);
    motorDirectionText = "Fwd: ";
  }
  else if (motorDirection == 0) {
    digitalWrite(controlPin1, LOW);
    digitalWrite(controlPin2, HIGH);
    motorDirectionText = "Bck: ";
  }
  
  
  if (motorEnabled == 1) {
    analogWrite(enablePin, motorSpeed);
  }
  else {
    analogWrite(enablePin, 0); 
  }

  prevForwardSwitchState = forwardSwitchState;
  prevReverseSwitchState = reverseSwitchState;  
  prevMotorSpeed = motorSpeed;
}
void printLCD(int newMotorSpeed, int prevMotorSpeed, String motorText) {
    lcd.setCursor(0,1);
    lcd.print("                ");
    lcd.setCursor(0,1);
    lcd.print(motorText);
    lcd.print(newMotorSpeed);
}
