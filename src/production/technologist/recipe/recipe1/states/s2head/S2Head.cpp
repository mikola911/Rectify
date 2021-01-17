//
// Created by oem on 02.01.2021.
//
#include "production/technologist/recipe/recipe1/Constants.h"
#include "production/technologist/recipe/recipe1/ErrorCodes.h"
#include "S2Head.h"

int S2Head::action() {
    updateTemp();
    updateConstantTempTimeAction();
    int errorCode = checkError();
    if(errorCode<0)
        return errorCode;
    if(moonshineMashine->t1GetTemp() > heatMaxTem && millis() -constantTempTime>heatConstTempTime )
    {
        waitOperatorAction();
        return 0;
    }


    return 1;
}

void S2Head::updateConstantTempTimeAction() {
    //!!!AHTUNG!!!!
    if(previousTemp>moonshineMashine->t1GetTemp()+ heatDeltaTemp) {
        constantTempTime = millis();
    }
}

int S2Head::checkError() {
    if(moonshineMashine->t1GetTemp()> heatTempErrorMax)
    {
        return TEMP_LARGE_ERROR;
    }
    else if(moonshineMashine->t1GetTemp()< heatTempErrorMin)
    {
        return TEMP_SMALL_ERROR;
    }
}
