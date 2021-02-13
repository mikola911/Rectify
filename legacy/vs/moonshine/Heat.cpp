#include "Heat.h"
#include "Constants.h"
#include "ErrorCodes.h"
int Heat::action() {
    updateTemp();
    updateConstantTempTimeAction();
    int errorCode = checkError();
	if (errorCode < 0)
	{
		Serial.print("Error: ");
		Serial.println(errorCode);
		return errorCode;
	}
    if (moonshineMashine->t1_temp > heatMaxTem || millis() - constantTempTime > heatConstTempTime)
    {
		Serial.print("Normal exit. Temp: ");
		Serial.println(moonshineMashine->t1_temp);
        waitOperatorAction();
        return 1;
    }


    return 0;
}

void Heat::updateConstantTempTimeAction() {
    // #FIXME
    if (previousTemp > moonshineMashine->t1_temp + heatDeltaTemp) {
        constantTempTime = millis();
    }
}

int Heat::checkError() {
    if (moonshineMashine->t1_temp > heatTempErrorMax)
    {
        return TEMP_LARGE_ERROR;
    }
    else if (moonshineMashine->t1_temp < heatTempErrorMin)
    {
        return TEMP_SMALL_ERROR;
    }
	return 1;
}
