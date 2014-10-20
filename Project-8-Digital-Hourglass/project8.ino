//Project 8
//Digital Hourglass

//intialize variables
const int switchPin = 8;
unsigned long previousTime = 0;
int switchState = 0;
int prevSwitchState = 0;
int led = 2;

//delay between each LED turning on (10mins)
long interval = 600000;

void setup() {
  //sets the LED pins as outputs
  for (int x = 2; x < 8; x++){
    pinMode (x, OUTPUT);
  }
  //sets the tilt switch as an input
  pinMode(switchPin, INPUT);
}

//checks the time since the program started running
void loop(){
  unsigned long currentTime = millis();
  
  // compare the current time to the previous time an LED turned on
  // if it is greater than your interval, run the if statement
  if (currentTime - previousTime > interval){
    // save the current time as the last time you changed an LED 
    previousTime = currentTime;
    //turns on an LED
    digitalWrite(led, HIGH);
    //increments the LED variable to turn on the next one on the next loop
    led++;
    //checks to see if all lights are on
    if(led == 7){
    }
  }
  //reads the value of the switch
  switchState = digitalRead(switchPin);
  //resets the variables to the defaults 
  if (switchState != prevSwitchState){
    for(int x = 2; x < 8; x++){
      digitalWrite(x, LOW);
    }
    led = 2;
    //resets the timer
    previousTime = currentTime;
  }
  prevSwitchState = switchState;
}
