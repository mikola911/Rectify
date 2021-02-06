#pragma once
#include "IRecipe1State.h"
class TailCollection : public IRecipe1State {
public:
    TailCollection(MoonshineMashine* moonshineMashine) : IRecipe1State(moonshineMashine) {};
};

