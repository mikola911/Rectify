//
// Created by oem on 02.01.2021.
//
#include "production/technologist/recipe/Recipe.h"
#include "production/technologist/recipe/recipe1/states/IRecipe1State.h"
#include "production/technologist/recipe/recipe1/states/s0init/S0Init.h"
#include "production/technologist/recipe/recipe1/states/s1preheating/S1Preheating.h"
#include "production/technologist/recipe/recipe1/states/s2head/S2Head.h"
#include "production/technologist/recipe/recipe1/states/s3headselection/S3HeadSelection.h"
#include "production/technologist/recipe/recipe1/states/s4technologicalbreak/S4TechnologicalBreak.h"
#include "production/technologist/recipe/recipe1/states/s5tailcollection/S5TailCollection.h"
#include "production/technologist/recipe/recipe1/states/s6alcoholselection/S6AlcoholSelection.h"
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
                S2Head(moonshineMashine),
                S3HeadSelection(moonshineMashine),
                S4TechnologicalBreak(moonshineMashine),
                S5TailCollection(moonshineMashine),
                S6AlcoholSelection(moonshineMashine)};
        states = __states;
    }

private:
    IRecipe1State* states;
    int statesCount;
    int currentState = 0


};


#endif //_MOONSHINE_RECIPE1_H
