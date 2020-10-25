#include <ArdButton.h>

#define PIN_BUTTON A0

ArdButton *btn;

void setup() 
{
  Serial.begin(9600);

  btn = new ArdButton(PIN_BUTTON);
}

void loop() 
{
  if(btn->isPressing())
  {
    Serial.print("Pressing\n");
  }
  else
  {
    Serial.print("Not pressing\n");
  }

  delay(500);
}

