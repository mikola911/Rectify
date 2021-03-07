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
		return (ms - tempChangeTime);
	};
};

