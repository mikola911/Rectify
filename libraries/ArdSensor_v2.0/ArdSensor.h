//
//  v1.1 - Added isWasPressed  //
//  v1.2 - delay replaced by request duration counter  //
//  v2.0 - used ArdPin_2.0  //
//

#ifndef ArdSensor_h
#define ArdSensor_h

#include "Arduino.h"

#include "../ArdPin_v2.0/ArdPin.h"

class ArdSensor : public ArdPin {
	
  private:		
	void onChanged(bool newState);
	
	bool _activateValue = LOW;

  public:
	ArdSensor(int pin, 
			  bool activateValue = LOW, 
			  unsigned long requestDuration_ms = 500);
	
    bool isActivating();

    void check();
	
	//
	//  Callbacks  //
	//
	
  private:
	void (*_callbackOnActivated)();
	void (*_callbackOnDeactivated)();
	
  public:
	void setCallbackOnActivated(void (*callbackOnActivated)());
	void setCallbackOnDeactivated(void (*callbackOnDeactivated)());
};

#endif