int receiverpin = 11;
#include <IRremote.h>
IRrecv irrecv(receiverpin);
decode_results results;

void setup()
{
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
    case 0x810: pinOn(2); break;
    case 0x410: pinOn(3); break;
    case 0xC10: pinOn(4); break;
    case 0x210: pinOn(5); break;
    case 0xA10: pinOn(6); break;
    case 0x610: pinOn(7); break;
  }
}

void pinOn(int pin)
{
  digitalWrite(pin, HIGH);
  delay(1000);
  digitalWrite(pin, LOW);
}

void loop(0
{
  if (irrecv.decode(&results))
  {
    translateIR();
    for (int z = 0; z < 2; z++)
    {
      irrecv.resume();
    }
  }
}
