class Heat : public IRecipe1State {

public:
	Heat() : IRecipe1State() {};
    Heat(MoonshineMachine* moonshineMachine) : IRecipe1State(moonshineMachine) {};

	int  action() override{
		updateTemp();

		if ((moonshineMachine->t1_temp > HEAT_MIN_TEMP) && (getConstantTempTime() > HEAT_BREAK_TIME)) {
			Serial.print("Normal exit. Temp: ");
			Serial.println(moonshineMachine->t1_temp);
			waitOperatorAction(); // #FIXME
			return 1;
		}
		if ((moonshineMachine->t1_temp > HEAT_MIN_TEMP) && moonshineMachine->isDoubleClicked()) { // #FIXME
			Serial.print("Exit by operator click");
			Serial.println(moonshineMachine->t1_temp);
			return 1;
		}
		return 0;
	};
private:
	/* timestamp for the last heat jump */
	unsigned long tempChangeTime = 0;

    /* get time interval with constant temperature */
	unsigned long getConstantTempTime() {
		unsigned long ms = millis();
		if (abs(previousTemp - moonshineMachine->t1_temp) > HEAT_DELTA_TEMP) {
			tempChangeTime = ms;
		}
		// FIXME - is it a function?
		String time = moonshineMachine->calculateTime(tempChangeTime, false)
			+ " from " + String(HEAT_BREAK_TIME/60000)  + "min";
		moonshineMachine->d2Write(0,2, time);
		return (ms - tempChangeTime);
	};
};
