//
// Created by oem on 02.01.2021.
//
#include "production/technologist/recipe/recipe1/Constants.h"
#include "IRecipe1State.h"

void IRecipe1State::updateTemp()  {
    if(millis() - lastTempCheckTime> preheatingDeltaTimeForDeltaTemp)
    {
        lastTempCheckTime=millis();
        previousTemp = moonshineMashine->t1GetTemp();
    }
}

void IRecipe1State::waitOperatorAction() {
    moonshineMashine->buzzerOn();
    while (!moonshineMashine->isNextButtonPressed())
    {

    }
    moonshineMashine->buzzerOff();
}

