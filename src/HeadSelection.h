class HeadSelection : public IRecipe1State {

public:
	HeadSelection() : IRecipe1State() {};
    HeadSelection(MoonshineMachine* moonshineMachine) : IRecipe1State(moonshineMachine) {};
    int  action() override {
		if (firstAction) {
			moonshineMachine->s1Rotate(HEAD_SELECTION_SERVO_ANGLE);
			firstAction = false;
		}
		if (moonshineMachine->isNextButtonPressed())  return 1;
		return 0;
	};

private:
    bool firstAction = true;
};

