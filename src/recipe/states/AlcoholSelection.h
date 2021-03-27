class AlcoholSelection : public IRecipe1State {

public:
	AlcoholSelection() : IRecipe1State() {};
    AlcoholSelection(MoonshineMachine* moonshineMachine) : IRecipe1State(moonshineMachine) {};

	int  action() override {
		unsigned long ms = millis();
		if (firstAction) {
			firstAction = false;
			overheatTime = ms;
			updateNodeSelectionTemp(moonshineMachine->t1_temp);
		}

		if (moonshineMachine->isNextButtonPressed()) { //#FIXME
			updateNodeSelectionTemp(moonshineMachine->t1_temp);
		}

		if (ms - overheatTime > ALCOHOL_SELECTION_OVERHEAT_TIME) {
			Serial.println("ladgeTempAfterClosingTimeMax ON");
			moonshineMachine->buzzerOn();
		} else {
			moonshineMachine->buzzerOff();
		}

		if (moonshineMachine->t1_temp > nodeSelectionTemp + ALCOHOL_SELECTION_DELTA_TEMP) {
			Serial.println("closeValve");
			closeValve();
			moonshineMachine->d2Write(10, 2, "too hot");
		} else {
			Serial.println("openValve");
			openValve();
			overheatTime = millis();
			moonshineMachine->d2Write(10, 2, "so good");
		}
		return 0;
	};
// TODO - store state of servo and do nothing is state is OK
private:
	bool firstAction = true;

    void openValve() {
		moonshineMachine->s1Rotate(ALCOHOL_SELECTION_SERVO_ANGLE);
	};
    void closeValve() {
		moonshineMachine->s1Rotate(CLOSED_SERVO_ANGLE);
	};

    /*  temperature of alcohol selection - fixed throw the stage */
    float nodeSelectionTemp;

    /* timestamp for overheat */
    unsigned long overheatTime;

	void updateNodeSelectionTemp(float temperature) {
			nodeSelectionTemp = temperature;
			Serial.print("SelectionTemp = ");
			Serial.println(nodeSelectionTemp);
			moonshineMachine->d2Write(0, 2, "t:");
			moonshineMachine->d2Write(3, 2, String(nodeSelectionTemp));
	}
};
