//
// Created by oem on 02.01.2021.
//
#include "production/MoonshineMashine.h"
#ifndef _MOONSHINE_IRECIPE1STATE_H
#define _MOONSHINE_IRECIPE1STATE_H


class IRecipe1State {



public:

    IRecipe1State(MoonshineMashine *moonshineMashine)
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
    virtual int action();

protected:
    MoonshineMashine *moonshineMashine;

    /**
     * Температура которая была во время предидущего измерения температуры.
     */
    int previousTemp = 0XFFFF;

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


#endif //_MOONSHINE_IRECIPE1STATE_H
