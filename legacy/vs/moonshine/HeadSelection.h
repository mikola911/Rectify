#pragma once
#include "IRecipe1State.h"
class HeadSelection : public IRecipe1State {

public:
    HeadSelection(MoonshineMashine* moonshineMashine) : IRecipe1State(moonshineMashine) {};
    int  action() override;

private:
    /**
     * Флаг означает что метод actionв данном экземпляре еще не запускался.
     */
    bool firstAction = true;
};

