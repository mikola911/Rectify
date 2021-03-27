class Preheating : public IRecipe1State {

public:
	Preheating() : IRecipe1State() {};
    Preheating(MoonshineMachine* moonshineMachine) : IRecipe1State(moonshineMachine) {};

    int  action() override {
		if (moonshineMachine->t1_temp > PREHEAT_END_TEMP) {
			Serial.print("Exit by large temp: ");
			Serial.println(moonshineMachine->t1_temp);
			waitOperatorAction();
			return 1;
		}
		else if (moonshineMachine->t1_temp - previousTemp > PREHEAT_DELTA_TEMP) {
			Serial.print("Exit by jump temp. Previous temp : ");
			Serial.println(previousTemp);
			waitOperatorAction();
			return 1;
		}
		updateTemp();
		return 0;
	};
};
