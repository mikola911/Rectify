//
// Created by oem on 02.01.2021.
//
#include "production/MoonshineMashine.h"

#ifndef _MOONSHINE_RECIPE_H
#define _MOONSHINE_RECIPE_H


class Recipe {

public:

    Recipe(MoonshineMashine *moonshineMashine)
    {
        this->moonshineMashine = moonshineMashine;
    }

    /**
     * Начать процесс перегонки.
     */
    virtual void start();
    /**
     * Остановить процесс перегонки
     */
    virtual void stop();
    /**
     * Пауза.
     */
    virtual void pause();

private:

    MoonshineMashine *moonshineMashine;

};


#endif //_MOONSHINE_RECIPE_H
