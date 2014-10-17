//Project 8
//Keyboard Instrument
int notes [] = {262, 294, 330, 349};

void setup(){
  Serial.begin(9600);
}

void loop(){
  //reads the analog input and prints it out in the serial monitor
  int keyVal = analogRead(A0);
  Serial.println(keyVal);

//uses else if function to determine which note is played for each button  
  if (keyVal == 1023){
    tone(8, notes[0]);
  }
  
  else if (keyVal >= 990 && keyVal <= 11010){
    tone(8, notes[1]);
  }
  else if (keyVal >= 505 && keyVal <= 515){
    tone(8, notes[2]);
  }
  else if (keyVal >= 5 && keyVal <= 10){
    tone(8, notes[3]);
  } 
  else {
    noTone(8);
  }
}
