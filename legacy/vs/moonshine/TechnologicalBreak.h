#pragma once
#include "IRecipe1State.h"
class TechnologicalBreak : public IRecipe1State {

public:
    TechnologicalBreak(MoonshineMashine* moonshineMashine) : IRecipe1State(moonshineMashine) {};
    int  action() override;

private:
    bool firstAction = true;
    unsigned long startMiles = millis();

};

