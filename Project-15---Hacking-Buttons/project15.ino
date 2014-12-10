const int optoPin = 2;

//configures the pin direction
void setup(){
  pinMode(optoPin, OUTPUT);
}
//this loops turns the optoPin on for a few milleseconds
//and closes the switch on the device and then turns the optoPin off
void loop(){
  digitalWrite(optoPin, HIGH);
  delay(15);
  digitalWrite(optoPin, LOW);
  
  //waits for 21 seconds, allowing the message to play back before looping again.
  delay(21000);
}

