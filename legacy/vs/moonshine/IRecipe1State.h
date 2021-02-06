#pragma once
#include "MoonshineMashine.h"
class IRecipe1State
{



public:
	IRecipe1State()
	{
	}
    IRecipe1State(MoonshineMashine* moonshineMashine)
    {
        this->moonshineMashine = moonshineMashine;
    }
	/**
	 * Действи производимые агрегатом в момент времени dt
	 * вызывается в цикле.
	 * Кода ошибок
	 * (см ErrorCodes.h)
	 * @return 1 находимсся все еще в текущем состоянии 0 выходим из состояния <0 ошибка
	 */
	virtual  int action() { return 0; };




protected:



    MoonshineMashine* moonshineMashine;

    /**
     * Температура которая была во время предидущего измерения температуры.
     */
    int previousTemp = 0XFF;// #FIXME

    /**
     * Ждем действия оператора.
     */
    void waitOperatorAction();

    /**
     * Обновляет температуру для поределения резкого скачка температуры.
     */
    void updateTemp();



private:


    /**
     * Системное время последнего замера температуры.
     */
    int lastTempCheckTime = 0;
};

