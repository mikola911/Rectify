//
// Created by oem on 02.01.2021.
//
#include "production/technologist/recipe/recipe1/states/IRecipe1State.h"
#ifndef _MOONSHINE_S0INIT_H
#define _MOONSHINE_S0INIT_H


class S0Init : public IRecipe1State {

public:
    int  action() override;
    S0Init(MoonshineMashine *moonshineMashine) : IRecipe1State(moonshineMashine){};
private:
    /**
     * Выполняет проверку всего оборудования.
     * @return 1 успешно <1 код ошибки
     */
    int selfCheck();




};


#endif //_MOONSHINE_S0INIT_H
