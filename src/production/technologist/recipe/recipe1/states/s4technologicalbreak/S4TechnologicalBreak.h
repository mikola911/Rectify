//
// Created by oem on 02.01.2021.
//
#include "production/technologist/recipe/recipe1/states/IRecipe1State.h"
#ifndef _MOONSHINE_ALCOHOLSELECTION_H
#define _MOONSHINE_ALCOHOLSELECTION_H


class S4TechnologicalBreak : public IRecipe1State {

public:
    S4TechnologicalBreak(MoonshineMashine *moonshineMashine) : IRecipe1State(moonshineMashine){};
    int  action() override;

private:
    bool firstAction = true;
    int startMiles = millis();



};


#endif //_MOONSHINE_ALCOHOLSELECTION_H
