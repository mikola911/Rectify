//
// Created by oem on 02.01.2021.
//
#include "production/technologist/recipe/recipe1/states/IRecipe1State.h"
#ifndef _MOONSHINE_S1PREHEATING_H
#define _MOONSHINE_S1PREHEATING_H


class S1Preheating : public IRecipe1State {

public:
    int  action() override;
    S1Preheating(MoonshineMashine *moonshineMashine) : IRecipe1State(moonshineMashine){};

private:

    /**
     * Проверяет находится ли текущая машина в ошибке.
     * @return 0 - нет ошибок <0 код ошибки
     */
    int checkError();

    /**
     * Ждем действия оператора.
     */
    void waitOperatorAction();

    /**
     * Обновляет температуру для поределения резкого скачка температуры.
     */
    void updateTemp();




};


#endif //_MOONSHINE_S1PREHEATING_H
