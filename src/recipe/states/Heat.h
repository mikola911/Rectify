class Heat : public IRecipe1State {

public:
	Heat() : IRecipe1State() {};
    Heat(MoonshineMachine* moonshineMachine) : IRecipe1State(moonshineMachine) {};

	int  action() override{
		getConstantTempTime();

		if ((moonshineMachine->t1_temp > HEAT_MIN_TEMP) && (constTempTime > HEAT_BREAK_TIME)) {
			Serial.print("Normal exit. Temp: ");
			Serial.println(moonshineMachine->t1_temp);
			waitOperatorAction(); // #FIXME
			return 1;
		}
		if ((moonshineMachine->t1_temp > HEAT_MIN_TEMP) && moonshineMachine->isNextButtonPressed(true)) {
			Serial.print("Exit by operator click");
			Serial.println(moonshineMachine->t1_temp);
			return 1;
		}
		updateTemp();
		return 0;
	};
private:
	/* timestamp for the last heat jump */
	unsigned long tempChangeTimestamp = 0;

	/* internal with constant temperature */
	unsigned long constTempTime = 0;

    /* get time interval with constant temperature */
	unsigned long getConstantTempTime() {
		unsigned long ms = millis();

		if ( abs(moonshineMachine->t1_temp - previousTemp) > HEAT_DELTA_TEMP) {
			tempChangeTimestamp = ms;
			constTempTime = 0;

			String time = "00:00:00 from " + String(HEAT_BREAK_TIME/60000)  + "min";
			moonshineMachine->d2Write(0,2, time);

			return;
		}

		String time = moonshineMachine->calculateTime(tempChangeTimestamp, false)
			+ " from " + String(HEAT_BREAK_TIME/60000)  + "min";
		moonshineMachine->d2Write(0,2, time);

		constTempTime = ms - tempChangeTimestamp;
	};
};
