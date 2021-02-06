#include "IRecipe1State.h"
#include "Constants.h"

void IRecipe1State::updateTemp() {
    if (millis() - lastTempCheckTime > preheatingDeltaTimeForDeltaTemp)
    {
        lastTempCheckTime = millis();
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
