#pragma once
#include "MoonshineMashine.h"

class Recipe
{
public:

    Recipe(MoonshineMashine* moonshineMashine)
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

    MoonshineMashine* moonshineMashine;
};

