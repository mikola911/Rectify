#include "IRecipe1State.h"
#include "Constants.h"

void IRecipe1State::updateTemp() {
    if (millis() - lastTempCheckTime > preheatingDeltaTimeForDeltaTemp) {
        lastTempCheckTime = millis();
        previousTemp = moonshineMashine->t1GetTemp();
    }
}

void IRecipe1State::waitOperatorAction() { //FIXME - нельзя зависать в функции! должен быть выход и повторный вход
    while (!moonshineMashine->isNextButtonPressed())
    {
		moonshineMashine->buzzerOn();
		moonshineMashine->t1GetTemp(); // температуру мы замеряем снаружи, избавимся от while - не будем делать доп замер
    }
    moonshineMashine->buzzerOff();
}
