//Temperature Sensor
//Project 3

//intialize variables
const int sensorPin = A0;
const float baselineTemp = 26.66;

void setup(){
  Serial.begin(9600);//opens a serial port
  
 
  for (int pinNumber = 2; pinNumber<5; pinNumber++){
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop(){
  int sensorVal = analogRead(sensorPin);
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);
  
  //convert the sensor reading to voltage
  float voltage = (sensorVal/1024.0) * 5.0;
  Serial.print (", Volts: ");
  Serial.print(voltage);
  Serial.print(", degrees C: ");
  
  //convert the voltage to temperature in degrees
  float temperature = (voltage - .5)*100;
  Serial.println(temperature);
  
  //Checks if the temperature that the sensor is above or below the base line temperature and turns LEDs on/off accordingly
  if (temperature < baselineTemp){
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if (temperature >= baselineTemp +2 && temperature < baselineTemp +4){
      digitalWrite(2, HIGH);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
  } else if (temperature >= baselineTemp +4 && temperature < baselineTemp +6){
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
  } else if (temperature >= baselineTemp +6){
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
  }
  delay(1);
}
      
