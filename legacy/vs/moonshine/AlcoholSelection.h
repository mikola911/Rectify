class AlcoholSelection : public IRecipe1State {

public:
	AlcoholSelection() : IRecipe1State() {};
    AlcoholSelection(MoonshineMashine* moonshineMashine) : IRecipe1State(moonshineMashine) {};

	int  action() override {
		if (firstAction) {
			firstAction = false;
			nodeSelectionTemp = moonshineMashine->t1_temp;
		}

		if (overheatTime > ALCOHOL_SELECTION_OVERHEAT_TIME) {
			//Serial.println("ladgeTempAfterClosingTimeMax ON");
			moonshineMashine->buzzerOn();
		} else {
			//Serial.println("ladgeTempAfterClosingTimeMax OFF");
			moonshineMashine->buzzerOff();
		}

		if (moonshineMashine->t1_temp > nodeSelectionTemp + ALCOHOL_SELECTION_DELTA_TEMP) {
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
		moonshineMashine->s1Rotate(ALCOHOL_SELECTION_SERVO_ANGLE);
	};
    void closeValve() {
		moonshineMashine->s1Rotate(CLOSED_SERVO_ANGLE);
	};

    /*  Температура которая должна поддерживатся при отборе спирта */
    float nodeSelectionTemp;

    /**
     * Время которое прошло закрытия клапана в течении которого температура не падает.
     */
    unsigned long overheatTime = 0;

};

