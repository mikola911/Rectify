#include "Init.h"
#include "Constants.h"

/*
int Init::action() {
	Serial.println("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
    int error = selfCheck();
    if (error == 1) {
		Serial.println("1");
        moonshineMashine->s1Rotate(startServoAngle);
        return 1;
    }
	else
	{
		Serial.println("2");
		return error;
	}
}
*/

int Init::selfCheck() {
    return 1;
}

