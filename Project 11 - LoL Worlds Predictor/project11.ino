// League of Legends World Predictor 
// Season 4
// include the LCD library, initate LCD object(pin # in bracket)
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
//initate variable
const int switchPin = 6;
int switchState =0;
int prevSwitchState =0;
int reply;

void setup() {
  //initiate LCD electronically
  lcd.begin(16,2);
  pinMode(switchPin, INPUT);
  //print on first row
  lcd.print("Ask the");
  lcd.setCursor(0,1);
  //print on second row
  lcd.print("Prophet!");
  //generate pRNG using atmosphereic noise
  randomSeed(analogRead(0));
}

void loop() {
  switchState = digitalRead(switchPin);
  if(switchState != prevSwitchState) {
    if(switchState == LOW) {
      //get random numbers
      reply = random(10);
      //clear screen, set to print on column 0, row 1
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Crumbzz says:");
      //set to print on column 0, row 2
      lcd.setCursor(0, 1);
      
      //Print out according to RNG
      switch(reply) {
        case 0:
        lcd.print("SSW");
        break;
        
        case 1:
        lcd.print("SSW");
        break;
        
        case 2:
        lcd.print("NJW");
        break;
        
        case 3:
        lcd.print("SSB");
        break;
        
        case 4:
        lcd.print("SSB");
        break;
        
        case 5:
        lcd.print("TSM");
        break;
        
        case 6:
        lcd.print("C9");
        break;
        
        case 7:
        lcd.print("OMG");
        break;
      
        case 8:
        lcd.print("SRC");
        break;
        
        case 9:
        lcd.print("EDG");
        break;
      }
    }
  }
  prevSwitchState = switchState;
}
