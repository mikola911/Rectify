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
    while (!moonshineMashine->isNextButtonPressed())
    {
		moonshineMashine->buzzerOn();
		moonshineMashine->t1GetTemp(); // we can't idle without temp
    }
    moonshineMashine->buzzerOff();
}
