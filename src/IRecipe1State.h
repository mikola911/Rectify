#include "Constants.h"
#include "ErrorCodes.h"

class IRecipe1State
{
public:
	IRecipe1State() {}
    IRecipe1State(MoonshineMashine* moonshineMashine) {
        this->moonshineMashine = moonshineMashine;
    }
	/**
	 * Действи производимые агрегатом в момент времени dt
	 * вызывается в цикле.
	 * Кода ошибок
	 * (см ErrorCodes.h)
	 */
	virtual  int action() { return 0; };

protected:

    MoonshineMashine* moonshineMashine;

    /**
     * Температура, которая была во время предыдущего измерения температуры.
     */
    int previousTemp = 0XFF;// #FIXME

    /**
     * Ждем действия оператора.
     */
	void waitOperatorAction() { // #FIXME - remove while
	    while (!moonshineMashine->isNextButtonPressed()) {
			moonshineMashine->buzzerOn();
			moonshineMashine->t1GetTemp(); // температуру мы замеряем снаружи, избавимся от while - не будем делать доп замер
		}
		moonshineMashine->buzzerOff();
	};

    /**
     * Обновляет температуру для определения резкого скачка температуры.
     */
	void updateTemp() {
	    if (millis() - lastTempCheckTime > UPDATE_DELTA_TIME) {
			lastTempCheckTime = millis();
			previousTemp = moonshineMashine->t1_temp;
		}
	};

private:

    /**
     * Системное время последнего замера температуры.
     */
    int lastTempCheckTime = 0;
};

