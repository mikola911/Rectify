#include "Preheating.h"
#include "Constants.h"
#include "ErrorCodes.h"

int Preheating::action() {
	//Serial.println("Preheating::action() ");
    updateTemp();
    int errorCode = checkError();
	if (errorCode < 0) {
		Serial.print("Error: ");
		Serial.println(errorCode);
		return errorCode;
	}
    if (moonshineMashine->t1_temp > preheatingTempJump) {
		Serial.print("Exit by large temp: ");
		Serial.println(moonshineMashine->t1_temp);
        waitOperatorAction();
        return 1;
    }
    //возможно будем передавать разные сообщения на дисплеи
    else if (moonshineMashine->t1_temp - previousTemp > preheatingDeltaTempJump) {
		Serial.print("Exit by jumpe temp. Previous temp : ");
		Serial.println(previousTemp);
        waitOperatorAction();
        return 1;
    }
    return 0;
}


int Preheating::checkError() {
    if (moonshineMashine->t1_temp > preheatingTempErrorMax) {
        return TEMP_LARGE_ERROR;
    } else if (moonshineMashine->t1_temp < preheatingTempErrorMin) {
        return TEMP_SMALL_ERROR;
    }
	return 1;
}
