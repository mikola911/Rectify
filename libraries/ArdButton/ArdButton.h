#ifndef ArdButton_h
#define ArdButton_h

#include "Arduino.h"

class ArdButton
{
  private:
    int _pin;
	int _delay_ms;
	
	int _lastValue;

    void (*_callbackOnPressed)();
	void (*_callbackOnReleased)();

  public:
	ArdButton(int pin, int delay_ms = 170);
	
    bool isPressing();
	
	void setCallbackOnPressed(void (*callbackOnPressed)());
	void setCallbackOnReleased(void (*callbackOnReleased)());

    void check();
};

#endif