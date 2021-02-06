#pragma once
#include "IRecipe1State.h"
class Head : public IRecipe1State {

public:
    int  action() override;
    Head(MoonshineMashine* moonshineMashine) : IRecipe1State(moonshineMashine) {};

private:


    /**
     * Время в течении которого температура не растет.
     */
    int constantTempTime = 0;


    /**
     * Проверяет находится ли текущая машина в ошибке.
     * @return 0 - нет ошибок <0 код ошибки
     */
    int checkError();

    /**
     * Процесс обновления времени в течении которого температура не растет.
     */
    void updateConstantTempTimeAction();
};

