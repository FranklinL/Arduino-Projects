int receiverpin = 11;
#include <IRremote.h>
IRrecv irrecv(receiverpin);
decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
  for (int z = 2 ; z < 8; z++)
  {
    pinMode(z, OUTPUT);
  }
}

void translateIR()
{
  switch(results.value)
  {
    case 0x80B92: pinOn(2); break;
    case 0x40B92: pinOn(3); break;
    case 0xC0B92: pinOn(4); break;
    case 0x20B92: pinOn(5); break;
    case 0xA0B92: pinOn(6); break;
    case 0x60B92: pinOn(7); break;
  }
}

void pinOn(int pin)
{
  digitalWrite(pin, HIGH);
  delay(1000);
  digitalWrite(pin, LOW);
}

void loop()
{
  if (irrecv.decode(&results))
  {
    Serial.print(results.value, HEX);
    Serial.print(" ");
    translateIR();
    for (int z = 0; z < 2; z++)
    {
      irrecv.resume();
    }
  }
}
