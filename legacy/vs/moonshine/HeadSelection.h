class HeadSelection : public IRecipe1State {

public:
	HeadSelection() : IRecipe1State() {};
    HeadSelection(MoonshineMashine* moonshineMashine) : IRecipe1State(moonshineMashine) {};
    int  action() override {
		if (firstAction) {
			moonshineMashine->s1Rotate(HEAD_SELECTION_SERVO_ANGLE);
			firstAction = false;
		}
		if (moonshineMashine->isNextButtonPressed())  return 1;
		return 0;
	};

private:
    bool firstAction = true;
};

