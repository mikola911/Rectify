#ifndef ArdPin_h
#define ArdPin_h

#include "Arduino.h"

class ArdPin {

  private:
    int _pin;

	unsigned long _requestDuration;

	int _lastValue;
	
	bool isHighDetected;
	unsigned long valueHigh_ts;
	
	bool isLowDetected;
	unsigned long valueLow_ts;

  public:
	ArdPin(int pin, unsigned long requestDuration = 500);

    bool getDirectValue();
	int getValue();

    void check();
	
protected:
	virtual void onChanged(bool newState);

	//
	//  Callbacks  //
	//
	
  private:
	void (*_callbackOnChanged)(bool newState);
	
  public:
	void setCallbackOnChanged(void (*callbackOnChanged)(bool newState));
};

#endif