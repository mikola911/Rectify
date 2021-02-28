class Init : public IRecipe1State {

public:
	Init() : IRecipe1State() {};
    Init(MoonshineMashine* moonshineMashine) : IRecipe1State(moonshineMashine) {};

	int action() override {
		selfCheck();

		if (checkStatus > 0) {
			if (moonshineMashine->isNextButtonPressed()) {
				moonshineMashine->s1Rotate(CLOSED_SERVO_ANGLE);
				return 1;
			}
			return 0;
		}
		return checkStatus;
	}
private:
	/*
	 * состояние машины. 
	 * 0 - все ок, но ждем оператора. 
	 * 1 - все ок, уходим в другой этап
	 * все что меньше нуля - ошибки (пока не сделаны)
	 * пока не проверили - считаем что в ошибке
	 */
	int checkStatus = -1;

	void selfCheck() {
		if (checkStatus < 1) {
			// #TODO
			checkStatus = 1;
		}
	};
};

