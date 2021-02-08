#include "TechnologicalBreak.h"
#include "Constants.h"
#include "ErrorCodes.h"
int TechnologicalBreak::action() {
    updateTemp();
	moonshineMashine->t1GetTemp();
    if (firstAction)
    {
		Serial.print("technologicalBreakTimeout: ");
		Serial.println(technologicalBreakTimeout);
        firstAction = false;
        moonshineMashine->s1Rotate(technologicalBreakServoPosition);
    }
	unsigned long delta = millis() - startMiles;
	Serial.print("delta: ");
	Serial.println(delta);
    return delta > technologicalBreakTimeout;

}
