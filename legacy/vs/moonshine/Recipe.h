#pragma once
#include "IRecipe1State.h"
#include "Init.h"
#include "Heat.h"
#include "Preheating.h"
#include "HeadSelection.h"
#include "TechnologicalBreak.h"
#include "TailCollection.h"
#include "AlcoholSelection.h"
class Recipe {

public:

    void pause();
    void stop();
    void start();

	Recipe(MoonshineMashine* moonshineMashine)
	{
		this->moonshineMashine = moonshineMashine;
		Init *init = new Init(moonshineMashine);
		statesCount = 6;
		states[0] = Init(moonshineMashine);
		states[1] = Preheating(moonshineMashine);
		states[2] = Heat(moonshineMashine);
		states[3] = HeadSelection(moonshineMashine);
		states[4] = TechnologicalBreak(moonshineMashine);
		states[5] = AlcoholSelection(moonshineMashine);
	}

private:
	MoonshineMashine* moonshineMashine;
    IRecipe1State states[6];
    int statesCount;
    int currentState = 0;
	String statesLines[7]={
		"    Stage:  init    ", 
		" Stage:  preheating ",
		"   Stage: Heating   ",
		"   Head Selection   ",
		" TechnologicalBreak ",
		"  AlcoholSelection  ",
		"77777777777777777777",
	};
};

