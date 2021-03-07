#pragma once
#include "IRecipe1State.h"
#include "states/Init.h"
#include "states/Heat.h"
#include "states/Preheating.h"
#include "states/HeadSelection.h"
#include "states/TechnologicalBreak.h"
#include "states/TailCollection.h"
#include "states/AlcoholSelection.h"

class Recipe {
public:
	Recipe(MoonshineMachine* moonshineMachine) {
		this->moonshineMachine = moonshineMachine;

		init = Init(this->moonshineMachine);
		preheating = Preheating(this->moonshineMachine);
		heat = Heat(this->moonshineMachine);
		headSelection = HeadSelection(this->moonshineMachine);
		technologicalBreak = TechnologicalBreak(this->moonshineMachine);
		alcoholSelection = AlcoholSelection(this->moonshineMachine);
	}

	void pause() {};

	void stop() {currentState = 0;};

	void iteration() {
		// Serial.println(millis());
		this->moonshineMachine->d2Write(0, 1, this->statesLines[currentState]);
		// Serial.print("Before: currentState = ");
		// Serial.println(currentState);
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
		// #TODO - check common errors

		// Serial.print("After: currentState = ");
		// Serial.println(currentState);
	};

	

private:
	MoonshineMachine* moonshineMachine;

	int currentState = 0;

	Init				init;
	Preheating			preheating;
	Heat				heat;
	HeadSelection		headSelection;
	TechnologicalBreak	technologicalBreak;
	AlcoholSelection	alcoholSelection;

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
