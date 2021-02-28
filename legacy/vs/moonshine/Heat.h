class Heat : public IRecipe1State {

public:
	Heat() : IRecipe1State() {};
    Heat(MoonshineMashine* moonshineMashine) : IRecipe1State(moonshineMashine) {};

	int  action() override{
		updateTemp();

		if ((moonshineMashine->t1_temp > HEAT_MIN_TEMP) && (getConstantTempTime() > HEAT_BREAK_TIME)) {
			Serial.print("Normal exit. Temp: ");
			Serial.println(moonshineMashine->t1_temp);
			waitOperatorAction(); // #FIXME
			return 1;
		}
		return 0;
	};
private:
	/* системное время, когда менялась температура */
	unsigned long tempChangeTime = 0;

    /* Получаем время, в течение которого температура не растет */
	unsigned long getConstantTempTime() {  
		unsigned long ms = millis();
		if (abs(previousTemp - moonshineMashine->t1_temp) > HEAT_DELTA_TEMP) {
			tempChangeTime = ms;
		}
		return (ms - tempChangeTime);
	};
};

