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
     * ������ ������� ���������.
     */
    virtual void start();
    /**
     * ���������� ������� ���������
     */
    virtual void stop();
    /**
     * �����.
     */
    virtual void pause();

private:

    MoonshineMashine* moonshineMashine;
};

