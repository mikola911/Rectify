class AlcoholSelection : public IRecipe1State {

public:
    AlcoholSelection(MoonshineMashine* moonshineMashine) : IRecipe1State(moonshineMashine) {
		nodeSelectionTemp = moonshineMashine->t1GetTemp();
	};

	int  action() override {
		updateTemp();
		if (ladgeTempAfterClosingTime > ladgeTempAfterClosingTimeMax) {
			//Serial.println("ladgeTempAfterClosingTimeMax ON");
			moonshineMashine->buzzerOn();
		} else {
			//Serial.println("ladgeTempAfterClosingTimeMax OFF");
			moonshineMashine->buzzerOff();
		}

		if (moonshineMashine->t1_temp > nodeSelectionTemp + nodeSelectionDeltaTemp) {
			Serial.println("closeNodeSelection");
			closeNodeSelection();
		} else {
			Serial.println("openNodeSelection");
			openNodeSelection();
			ladgeTempAfterClosingTime = millis();
		}
		return 0;
	};

private:
    void openNodeSelection() {
		moonshineMashine->s1Rotate(nodeSelectionOpenAngle);
	};
    void closeNodeSelection() {
		moonshineMashine->s1Rotate(nodeSelectionCloseAngle);
	};
    /**
     * Температура которая должна поддерживатся при отборе спирта.
    */
    float nodeSelectionTemp = 230;

    /**
     * Время которое прошло закрытия клапана в течении которого температура не падает.
     */
    int ladgeTempAfterClosingTime = 0;

};

