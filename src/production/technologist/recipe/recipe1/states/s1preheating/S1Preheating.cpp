//
// Created by oem on 02.01.2021.
//
#include "production/technologist/recipe/recipe1/Constants.h"
#include "production/technologist/recipe/recipe1/ErrorCodes.h"
#include "S1Preheating.h"


int S1Preheating::action() {
    updateTemp();
    int errorCode = checkError();
    if(errorCode<0)
        return errorCode;
    if(moonshineMashine->t1GetTemp() > preheatingTempJump)
    {
        waitOperatorAction();
        return 0;
    }
    //возможно будем передавать разные сообщения на дисплеи
    else if(moonshineMashine->t1GetTemp() - previousTemp> preheatingDeltaTempJump)
    {
        waitOperatorAction();
        return 0;
    }


    return 1;
}


int S1Preheating::checkError() {
    if(moonshineMashine->t1GetTemp()> preheatingTempErrorMax)
    {
        return TEMP_LARGE_ERROR;
    }
    else if(moonshineMashine->t1GetTemp()< preheatingTempErrorMin)
    {
        return TEMP_SMALL_ERROR;
    }
}


