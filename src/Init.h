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
	 * ��������� ������. 
	 * 0 - ��� ��, �� ���� ���������. 
	 * 1 - ��� ��, ������ � ������ ����
	 * ��� ��� ������ ���� - ������ (���� �� �������)
	 * ���� �� ��������� - ������� ��� � ������
	 */
	int checkStatus = -1;

	void selfCheck() {
		if (checkStatus < 1) {
			// #TODO
			checkStatus = 1;
		}
	};
};

