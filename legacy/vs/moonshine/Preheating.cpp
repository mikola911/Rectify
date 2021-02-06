#include "Preheating.h"
#include "Constants.h"
#include "ErrorCodes.h"

int Preheating::action() {
	//Serial.println("Preheating::action() ");
    updateTemp();
    int errorCode = checkError();
	if (errorCode < 0)
	{
		Serial.print("Error: ");
		Serial.println(errorCode);
		return errorCode;
	}
    if (moonshineMashine->t1GetTemp() > preheatingTempJump)
    {
		Serial.print("Exit by large temp: ");
		Serial.println(moonshineMashine->t1GetTemp());
        waitOperatorAction();
        return 1;
    }
    //�������� ����� ���������� ������ ��������� �� �������
    else if (moonshineMashine->t1GetTemp() - previousTemp > preheatingDeltaTempJump)
    {
		Serial.print("Exit by jumpe temp. Previous temp : ");
		Serial.println(previousTemp);
        waitOperatorAction();
        return 1;
    }


    return 0;
}


int Preheating::checkError() {
    if (moonshineMashine->t1GetTemp() > preheatingTempErrorMax)
    {
        return TEMP_LARGE_ERROR;
    }
    else if (moonshineMashine->t1GetTemp() < preheatingTempErrorMin)
    {
        return TEMP_SMALL_ERROR;
    }
	return 1;
}