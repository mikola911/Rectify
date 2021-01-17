//
// Created by oem on 02.01.2021.
//
#include "production/technologist/recipe/recipe1/states/IRecipe1State.h"
#ifndef _MOONSHINE_S3HEADSELECTION_H
#define _MOONSHINE_S3HEADSELECTION_H


class S2Head : public IRecipe1State {

public:
    int  action() override;
    S2Head(MoonshineMashine *moonshineMashine) : IRecipe1State(moonshineMashine){};

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


#endif //_MOONSHINE_S3HEADSELECTION_H
