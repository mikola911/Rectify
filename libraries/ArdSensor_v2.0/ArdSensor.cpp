#include "ArdSensor.h"

ArdSensor::ArdSensor(int pin, 
					 bool activateValue, 
					 unsigned long requestDuration_ms) 
					 : ArdPin(pin, 
							  requestDuration_ms) {
	
	//  save values  //
	_activateValue = activateValue;
	
	_callbackOnActivated = NULL;
	_callbackOnDeactivated = NULL;
}

void ArdSensor::check() {
	ArdPin::check();
}

void ArdSensor::onChanged(bool newState) {
	ArdPin::onChanged(newState);
	
	//  check on pressed  //
	if(newState == _activateValue) {
		//  emit onPressed  //
		if(_callbackOnActivated != NULL) {
			_callbackOnActivated();
		}
	} 
	
	//  check on released  //
	else {
		//  emit onReleased  //
		if(_callbackOnDeactivated != NULL) {
			_callbackOnDeactivated();
		}
	}
}

bool ArdSensor::isActivating() {
	return getValue() == _activateValue;
}

void ArdSensor::setCallbackOnActivated(void (*callbackOnActivated)()) {  
	_callbackOnActivated = callbackOnActivated;
}

void ArdSensor::setCallbackOnDeactivated(void (*callbackOnDeactivated)()) {  
	_callbackOnDeactivated = callbackOnDeactivated;
}






