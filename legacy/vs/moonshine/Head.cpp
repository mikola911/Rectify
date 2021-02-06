#include "Head.h"
#include "Constants.h"
#include "ErrorCodes.h"
int Head::action() {
    updateTemp();
    updateConstantTempTimeAction();
    int errorCode = checkError();
	if (errorCode < 0)
	{
		Serial.print("Error: ");
		Serial.println(errorCode);
		return errorCode;
	}
    if (moonshineMashine->t1GetTemp() > heatMaxTem || millis() - constantTempTime > heatConstTempTime)
    {
		Serial.print("Normal exit. Temp: ");
		Serial.println(moonshineMashine->t1GetTemp());
        waitOperatorAction();
        return 1;
    }


    return 0;
}

void Head::updateConstantTempTimeAction() {
    //!!!AHTUNG!!!!
    if (previousTemp > moonshineMashine->t1GetTemp() + heatDeltaTemp) {
        constantTempTime = millis();
    }
}

int Head::checkError() {
    if (moonshineMashine->t1GetTemp() > heatTempErrorMax)
    {
        return TEMP_LARGE_ERROR;
    }
    else if (moonshineMashine->t1GetTemp() < heatTempErrorMin)
    {
        return TEMP_SMALL_ERROR;
    }
	return 1;
}
