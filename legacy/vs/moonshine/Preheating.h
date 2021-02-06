#pragma once
#include "IRecipe1State.h"
class Preheating : public IRecipe1State
{

public:
    int  action() override;
    Preheating(MoonshineMashine* moonshineMashine) : IRecipe1State(moonshineMashine) {};

private:

    /**
     * Проверяет находится ли текущая машина в ошибке.
     * @return 0 - нет ошибок <0 код ошибки
     */
    int checkError();


};

