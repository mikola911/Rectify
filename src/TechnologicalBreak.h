class TechnologicalBreak : public IRecipe1State {

public:
	TechnologicalBreak() : IRecipe1State() {};
    TechnologicalBreak(MoonshineMachine* moonshineMashine) : IRecipe1State(moonshineMashine) {};
    
	int action() override {
		unsigned long ms = millis();
		if (firstAction) {
			firstAction = false;
			startMs = ms;
			moonshineMashine->s1Rotate(CLOSED_SERVO_ANGLE);
		}
		return ms - startMs > TECHNOLOGICAL_BREAK_TIME;
	};

private:
    bool firstAction = true;
	unsigned long startMs = 0;
};

