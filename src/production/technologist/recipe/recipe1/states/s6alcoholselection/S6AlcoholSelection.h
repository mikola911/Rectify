//
// Created by oem on 02.01.2021.
//
#include "production/technologist/recipe/recipe1/states/IRecipe1State.h"

#ifndef _MOONSHINE_TAILCOLLECTION_H
#define _MOONSHINE_TAILCOLLECTION_H


class S6AlcoholSelection : public IRecipe1State {

public:
    int  action() override;
    S6AlcoholSelection(MoonshineMashine *moonshineMashine) : IRecipe1State(moonshineMashine){};

private:
    void openNodeSelection();
    void closeNodeSelection();
    /**
     * Температура которая должна поддерживатся при отборе спирта.
    */
    float nodeSelectionTemp = 230;

    /**
     * Время которое прошло закрытия клапана в течении которого температура не падает.
     */
    int ladgeTempAfterClosingTime = 0;

    
};


#endif //_MOONSHINE_TAILCOLLECTION_H