#include "Recipe.h"

void Recipe::start() {
    for (currentState = 0; currentState < statesCount; currentState++)
    {
		this->moonshineMashine->d2Write(0, 1, this->statesLines[currentState]);
		Serial.print("Current state: ");
		Serial.println(this->statesLines[currentState]);


		if (currentState == 0)
		{
			Init init = Init(this->moonshineMashine);
			while (!init.action())
			{
				//printLog();
			}
		}
		else if (currentState == 1)
		{
			Preheating preheating = Preheating(this->moonshineMashine);
			while (!preheating.action())
			{
				//printLog();
			}
		}
		else if (currentState == 2) {
			Head head = Head(this->moonshineMashine);
			while (!head.action())
			{
				//printLog();
			}
		}
		else if (currentState == 3) {
			HeadSelection headSelection = HeadSelection(this->moonshineMashine);
			while (!headSelection.action())
			{
				//printLog();
			}
		}
		else if (currentState == 4) {
			TechnologicalBreak technologicalBreak = TechnologicalBreak(this->moonshineMashine);
			while (!technologicalBreak.action())
			{
				//printLog();
			}
		}
		else if (currentState == 5)
		{
			AlcoholSelection alcoholSelection = AlcoholSelection(this->moonshineMashine);
			while (!alcoholSelection.action())
			{
				//printLog();
			}
		}
		else{
			Serial.print("default: ");
			Serial.println(currentState);
		}

    }
}

void Recipe::printLog()
{
	this->moonshineMashine->d2Write(0, 1, this->statesLines[currentState]);
	Serial.print("Current state: ");
	Serial.println(this->statesLines[currentState]);
}

void Recipe::stop() {
    currentState = 0;

}

void Recipe::pause() {


}
