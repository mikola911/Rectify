//
// Created by oem on 02.01.2021.
//
#include "production/technologist/recipe/Recipe.h"
#include "production/technologist/recipe/recipe1/states/IRecipe1State.h"
#include "production/technologist/recipe/recipe1/states/s0init/S0Init.h"
#include "production/technologist/recipe/recipe1/states/s1preheating/S1Preheating.h"
#include "production/technologist/recipe/recipe1/states/s2headselection/S2HeadSelection.h"
#include "production/technologist/recipe/recipe1/states/s3technologicalpause/S3HeadSelection.h"
#include "production/technologist/recipe/recipe1/states/s4alcoholselection/S4TechnologicalBreak.h"
#include "production/technologist/recipe/recipe1/states/s5tailcollection/S5TailCollection.h"
#ifndef _MOONSHINE_RECIPE1_H
#define _MOONSHINE_RECIPE1_H

/**
 * Рецепт 1.
 * Самый простой рецепт неведомой фигни которую мы будем гнать на MVP.
 */
class Recipe1 : public Recipe {

public:
    void pause() override;
    void stop() override;
    void start() override;

    Recipe1(MoonshineMashine *moonshineMashine) : Recipe(moonshineMashine)
    {
        statesCount =6;
        IRecipe1State __states[6] = {
                S0Init(moonshineMashine),
                S1Preheating(moonshineMashine),
                S2HeadSelection(moonshineMashine),
                S3TechnologicalPause(moonshineMashine),
                S4AlcoholSelection(moonshineMashine),
                S5TailCollection(moonshineMashine)};
        states = __states;
    }

private:
    IRecipe1State* states;
    int statesCount;
    int currentState = 0


};


#endif //_MOONSHINE_RECIPE1_H
