//
// Created by oem on 02.01.2021.
//
#include "production/technologist/recipe/recipe1/states/IRecipe1State.h"
#ifndef _MOONSHINE_TECHNOLOGICALPAUSE_H
#define _MOONSHINE_TECHNOLOGICALPAUSE_H


class S3HeadSelection : public IRecipe1State {

public:
    S3HeadSelection(MoonshineMashine *moonshineMashine) : IRecipe1State(moonshineMashine){};
    int  action() override;

private:
    /**
     * Флаг означает что метод actionв данном экземпляре еще не запускался.
     */
    bool firstAction = true;



};


#endif //_MOONSHINE_TECHNOLOGICALPAUSE_H
