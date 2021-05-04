class AlcoholSelection : public IRecipe1State {

public:
	AlcoholSelection() : IRecipe1State() {};
    AlcoholSelection(MoonshineMachine* moonshineMachine) : IRecipe1State(moonshineMachine) {};

	int  action() override {
		unsigned long ms = millis();

		if (firstAction) {
			moonshineMachine->t1SetResolution(12);
			firstAction = false;
			overheatTime = ms;
			updateNodeSelectionTemp(moonshineMachine->t1_temp);
		}

		if (moonshineMachine->isNextButtonPressed()) { //#FIXME - temporary ability
			updateNodeSelectionTemp(moonshineMachine->t1_temp);
		}

		if (ms - overheatTime > ALCOHOL_SELECTION_OVERHEAT_TIME) {
			moonshineMachine->buzzerOn();
		} else {
			moonshineMachine->buzzerOff();
		}

		if (moonshineMachine->t1_temp > nodeSelectionTemp + ALCOHOL_SELECTION_DELTA_TEMP) {
			if (isValveOpen == true) {
				closeValve();
				isValveOpen = false;
			// #TODO - if too hot, some time do not open again (trottle for edge temperature)
			}
			moonshineMachine->d2Write(10, 2, "too hot");
		} else {
			if (isValveOpen == false) {
				openValve();
				isValveOpen = true;
			}
			overheatTime = millis();
			moonshineMachine->d2Write(10, 2, "so good");
		}
		return 0;
	};

private:
	bool firstAction = true;
	bool isValveOpen = false;

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
