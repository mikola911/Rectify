#include "Recipe.h"

void Recipe::start() {
	Init init = Init(this->moonshineMashine);
	Preheating preheating = Preheating(this->moonshineMashine);
	Heat heat = Heat(this->moonshineMashine);
	HeadSelection headSelection = HeadSelection(this->moonshineMashine);
	TechnologicalBreak technologicalBreak = TechnologicalBreak(this->moonshineMashine);
	AlcoholSelection alcoholSelection = AlcoholSelection(this->moonshineMashine);

    while (true) {
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
}

void Recipe::stop() {
    currentState = 0;
}

void Recipe::pause() {}
