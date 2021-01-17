//
// Created by oem on 02.01.2021.
//
#include "production/technologist/recipe/recipe1/Constants.h"
#include "S4TechnologicalBreak.h"


int S4TechnologicalBreak::action() {
    updateTemp();
    if(firstAction)
    {
        firstAction = false;
        moonshineMashine->s1Rotate(technologicalBreakServoPosition);
    }
    return millis() - startMiles < technologicalBreakTimeout;

}