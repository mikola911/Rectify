#include "ArdPin.h"

ArdPin::ArdPin(int pin, unsigned long requestDuration) {
  _callbackOnChanged = NULL;
  
  //  save vars  //
  _pin = pin;
  _requestDuration = requestDuration;

  //  set pin to input  //
  pinMode(_pin, INPUT_PULLUP);
  
  //  flags  //
  _lastValue = -1;
  
  isHighDetected = false;
  valueHigh_ts = 0;
  isLowDetected = false;
  valueLow_ts = 0;
}

void ArdPin::setCallbackOnChanged(void (*callbackOnChanged)(bool newState)) {  
  //  save callback  //
  _callbackOnChanged = callbackOnChanged;
}

bool ArdPin::getDirectValue() {
  return (digitalRead(_pin) == HIGH);
}

void ArdPin::check() {
	
  //  get value  //
  bool currentValue = getDirectValue();	
	
  //  check HIGH  //
  if(currentValue) {
	
	//  check new HIGH  //
	if(_lastValue == LOW) {
		
		//  save ts  //
		valueHigh_ts = millis();
	}
	
	//  check after delay (once)  //
	if(millis() - valueHigh_ts > _requestDuration
	&& isHighDetected == false) {
		
		//  set flag  //
		isHighDetected = true;
		
		onChanged(HIGH);
	}
	
	//  clear flag  //
	isLowDetected = false;
  }
  
  //  check LOW  //
  else {
  
  	//  check new LOW  //
	if(_lastValue == HIGH) {
		
		//  save ts  //
		valueLow_ts = millis();
	}
		
	//  check after delay (once)  //
	if(millis() - valueLow_ts > _requestDuration
	&& isLowDetected == false) {
		
		//  set flag  //
		isLowDetected = true;
		
		onChanged(LOW);
	}
	
	//  clear flag  //
	isHighDetected = false;
  }
  
  //  save value  //
  _lastValue = currentValue;
}

void ArdPin::onChanged(bool newState) {
	//  emit onChanged  //
	if(_callbackOnChanged != NULL) {
		_callbackOnChanged(newState);
	}
}

int ArdPin::getValue() {
	if(isHighDetected) {
		return 1;
	}
	else if(isLowDetected) {
		return 0;
	}
	else {
		return -1;
	}
}