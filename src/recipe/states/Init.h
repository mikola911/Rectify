class Init : public IRecipe1State {

public:
	Init() : IRecipe1State() {};
    Init(MoonshineMachine* moonshineMachine) : IRecipe1State(moonshineMachine) {};

	int action() override {
		selfCheck();

		if (checkStatus > 0) {
			if (moonshineMachine->isNextButtonPressed()) {
				moonshineMachine->s1Rotate(CLOSED_SERVO_ANGLE);
				return 1;
			}
			return 0;
		}
		return checkStatus;
	}
private:
	/*
	 * machine state 
	 * 0 - everything is OK, but wait operator confirmation
	 * 1 - everything is OK, operator confirmed next step
	 * if status < 0, status is Error (#TODO - error codes)
	 * status is error before checked up
	 */
	int checkStatus = -1;

	void selfCheck() {
		if (checkStatus < 1) {
			// #TODO
			checkStatus = 1;
		}
	};
};

