class Init : public IRecipe1State {

public:
	virtual  int  action() override {
		int error = selfCheck();
		if (error == 1) {
			moonshineMashine->s1Rotate(startServoAngle);
		}
		return error;
	}
    Init(MoonshineMashine* moonshineMashine) : IRecipe1State(moonshineMashine) {};
private:
    /**
     * ��������� �������� ����� ������������.
     * @return 1 ������� <1 ��� ������
     */
	int selfCheck() {
		if (moonshineMashine->isNextButtonPressed())  return 1;
		return 0;
	};
};

