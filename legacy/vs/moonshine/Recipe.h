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
	void pause() {};

	void stop() {currentState = 0;};

	void start() {
		Init init = Init(this->moonshineMashine);
		Preheating preheating = Preheating(this->moonshineMashine);
		Heat heat = Heat(this->moonshineMashine);
		HeadSelection headSelection = HeadSelection(this->moonshineMashine);
		TechnologicalBreak technologicalBreak = TechnologicalBreak(this->moonshineMashine);
		AlcoholSelection alcoholSelection = AlcoholSelection(this->moonshineMashine);

		while (true) { // Loop
			this->moonshineMashine->d2Write(0, 1, this->statesLines[currentState]);
			this->moonshineMashine->t1GetTemp();
			this->moonshineMashine->showTime();

			if (currentState == 0) {
				if (init.action()) currentState++;
			} else if (currentState == 1) {
				if (preheating.action()) currentState++;
			} else if (currentState == 2) {
				if (heat.action()) currentState++;
			} else if (currentState == 3) {
				if (headSelection.action()) currentState++;
			} else if (currentState == 4) {
				if (technologicalBreak.action()) currentState++;
			} else if (currentState == 5) {
				if (alcoholSelection.action()) currentState++;
			} else {
				Serial.print("default: ");
				Serial.println(currentState);
				Serial.println("Program ends, restarting...");
				currentState = 0;
			}
		}
	};

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

