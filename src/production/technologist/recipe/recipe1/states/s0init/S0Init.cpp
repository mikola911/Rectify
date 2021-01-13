//
// Created by oem on 02.01.2021.
//

#include "S0Init.h"
#include "production/technologist/recipe/recipe1/Constants.h"


int S0Init::action() {
    int error = selfCheck();
    if(error==1) {
        moonshineMashine->s1Rotate(startServoAngle);
        return 1;
    }
    else
        return error;
}

int S0Init::selfCheck() {
    return 1;
}


