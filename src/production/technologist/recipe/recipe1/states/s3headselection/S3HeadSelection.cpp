//
// Created by oem on 02.01.2021.
//

#include "S3HeadSelection.h"
#include "production/technologist/recipe/recipe1/Constants.h"
#include "production/technologist/recipe/recipe1/ErrorCodes.h"


int S3HeadSelection::action() {
    if(firstAction)
    {
        moonshineMashine->s1Rotate(headSelectionServoAngle);
        firstAction =false;
    }
    updateTemp();
    if(moonshineMashine->isNextButtonPressed())
    {
        return 0;
    }

    return 1;
}
