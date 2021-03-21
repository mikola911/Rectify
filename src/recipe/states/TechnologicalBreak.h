class TechnologicalBreak : public IRecipe1State {

public:
	TechnologicalBreak() : IRecipe1State() {};
    TechnologicalBreak(MoonshineMachine* moonshineMachine) : IRecipe1State(moonshineMachine) {};

	int action() override {
		unsigned long ms = millis();
		if (firstAction) {
			firstAction = false;
			startMs = ms;
			moonshineMachine->s1Rotate(CLOSED_SERVO_ANGLE);
		}
		// FIXME - is it a function?
		String time = moonshineMachine->calculateTime(startMs, false)
			+ " from " + String(TECHNOLOGICAL_BREAK_TIME/60000)  + "min";
		moonshineMachine->d2Write(0,2, time);
		return ms - startMs > TECHNOLOGICAL_BREAK_TIME;
	};

private:
    bool firstAction = true;
	unsigned long startMs = 0;
};
