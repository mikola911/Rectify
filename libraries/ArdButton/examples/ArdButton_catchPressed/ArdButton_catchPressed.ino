#include <ArdButton.h>

#define PIN_BUTTON A0

ArdButton *btn;

void setup() 
{
  Serial.begin(9600);

  btn = new ArdButton(PIN_BUTTON);

  btn->setCallbackOnPressed(btn_onPressed);
  btn->setCallbackOnReleased(btn_onReleased);
}

void loop() 
{
  btn->check();
  
  delay(500);
}

static void btn_onPressed()
{
  Serial.print("Pressed\n");
}

static void btn_onReleased()
{
  Serial.print("Released\n");
}

