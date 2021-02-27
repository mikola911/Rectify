class TechnologicalBreak : public IRecipe1State {

public:
	TechnologicalBreak() : IRecipe1State() {};
    TechnologicalBreak(MoonshineMashine* moonshineMashine) : IRecipe1State(moonshineMashine) {};
    int action() override {
		if (firstAction) {
			firstAction = false;
			moonshineMashine->s1Rotate(technologicalBreakServoPosition);
		}
		unsigned long delta = millis() - startMiles;
		return delta > technologicalBreakTimeout;
	};

private:
    bool firstAction = true;
    unsigned long startMiles = millis();
};

