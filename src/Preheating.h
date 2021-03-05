class Preheating : public IRecipe1State
{

public:
	Preheating() : IRecipe1State() {};
    Preheating(MoonshineMashine* moonshineMashine) : IRecipe1State(moonshineMashine) {};

    int  action() override {
		updateTemp();

		if (moonshineMashine->t1_temp > PREHEAT_END_TEMP) {
			Serial.print("Exit by large temp: ");
			Serial.println(moonshineMashine->t1_temp);
			waitOperatorAction();
			return 1;
		}
		else if (moonshineMashine->t1_temp - previousTemp > PREHEAT_DELTA_TEMP) {
			Serial.print("Exit by jump temp. Previous temp : ");
			Serial.println(previousTemp);
			waitOperatorAction();
			return 1;
		}
		return 0;
	};
};

