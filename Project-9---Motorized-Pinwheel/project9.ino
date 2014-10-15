//Project 9
//Motorized Pinwheel

//intialize variables
const in switchPin = 2;
const int motorPin = 9;
int switchState = 0;

//declares pin directions
voidsetup(){
  pinMode(motorPin, OUTPUT);
  pinMode(switchPin, INPUT);
}

//reads the input and turns the motorPin to HIGH if switch is pressed.

void loop(){
  switchState = digitalread(switchPin);
  
  if (switchState = HIGH) {
    digitalWrite(motorPin, HIGH);
  }
  
  else {
    digitalWrite(mortorPin, LOW);
  }
}
