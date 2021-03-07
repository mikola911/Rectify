class AlcoholSelection : public IRecipe1State {

public:
	AlcoholSelection() : IRecipe1State() {};
    AlcoholSelection(MoonshineMachine* moonshineMachine) : IRecipe1State(moonshineMachine) {};

	int  action() override {
		if (firstAction) {
			firstAction = false;
			nodeSelectionTemp = moonshineMachine->t1_temp;
		}

		if (overheatTime > ALCOHOL_SELECTION_OVERHEAT_TIME) {
			//Serial.println("ladgeTempAfterClosingTimeMax ON");
			moonshineMachine->buzzerOn();
		} else {
			//Serial.println("ladgeTempAfterClosingTimeMax OFF");
			moonshineMachine->buzzerOff();
		}

		if (moonshineMachine->t1_temp > nodeSelectionTemp + ALCOHOL_SELECTION_DELTA_TEMP) {
			Serial.println("closeValve");
			closeValve();
		} else {
			Serial.println("openValve");
			openValve();
			overheatTime = millis();
		}
		return 0;
	};

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
    unsigned long overheatTime = 0;

};

