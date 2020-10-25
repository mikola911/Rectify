#include "ArdButton.h"

ArdButton::ArdButton(int pin, int delay_ms)
{
  _callbackOnPressed = NULL;
  _callbackOnReleased = NULL;
  
  //  save vars  //
  _pin = pin;
  _delay_ms = delay_ms;

  //  set pin to input  //
  pinMode(_pin, INPUT_PULLUP);
  
  //  flags  //
  _lastValue = 1;
}

void ArdButton::setCallbackOnPressed(void (*callbackOnPressed)())
{  
  //  save callback  //
  _callbackOnPressed = callbackOnPressed;
}

void ArdButton::setCallbackOnReleased(void (*callbackOnReleased)())
{  
  //  save callback  //
  _callbackOnReleased = callbackOnReleased;
}

bool ArdButton::isPressing()
{
  return (digitalRead(_pin) == 0);
}

void ArdButton::check()
{
  //  check pressing  //
  if(isPressing())
  {
    delay(_delay_ms);
	
	//  check pressed  //
	if(_lastValue == 1)
	{
		//  emit onPressed  //
		if(_callbackOnPressed != NULL)
		  _callbackOnPressed();
	}
	
	_lastValue = 0;
  }
  
  //  no pressing  //
  else
  {
	//delay(_delay_ms);
  
  	//  check released  //
	if(_lastValue == 0)
	{
		//  emit onPressed  //
		if(_callbackOnReleased != NULL)
		  _callbackOnReleased();
	}
	
	_lastValue = 1;
  }
}
