#pragma once
#include "Recipe.h"
#include "IRecipe1State.h"
#include "Init.h"
#include "Head.h"
#include "Preheating.h"
#include "HeadSelection.h"
#include "TechnologicalBreak.h"
#include "TailCollection.h"
#include "AlcoholSelection.h"
class Recipe1 : public Recipe{

public:
    void pause() override;
    void stop() override;
    void start() override;

	Recipe1(MoonshineMashine* moonshineMashine) : Recipe(moonshineMashine)
	{
		this->moonshineMashine = moonshineMashine;
		Init *init = new Init(moonshineMashine);
		statesCount = 6;
		states[0] = Init(moonshineMashine);
		states[1] = Preheating(moonshineMashine);
		states[2] = Head(moonshineMashine);
		states[3] = HeadSelection(moonshineMashine);
		states[4] = TechnologicalBreak(moonshineMashine);
		states[5] = AlcoholSelection(moonshineMashine);
	}

private:
	MoonshineMashine* moonshineMashine;
    IRecipe1State states[6];
    int statesCount;
    int currentState = 0;
	String statesLines[6]={"init", "Preheating","Head", "HeadSelection", "TechnologicalBreak", "AlcoholSelection"};
	void printLog();
};

