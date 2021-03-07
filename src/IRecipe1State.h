#include "Constants.h"
#include "ErrorCodes.h"

/* this class is a pattern for the single state of state machine */
class IRecipe1State {
public:
	IRecipe1State() {}
    IRecipe1State(MoonshineMachine* moonshineMachine) {
        this->moonshineMachine = moonshineMachine;
    }

	/**
	 * single action for one temp measure
	 * @return 
	 * 0 if everything is ok, and we will run this action again next time. 
	 * 1 if everything is ok, but this action finished. next time we will run next action. 
	 * <0 if we have an error and should handle it. 
	 * (#TODO ErrorCodes.h)
	 */
	virtual int action() { return 0; };

protected:

    MoonshineMachine* moonshineMachine;

	/* temperature at last updateTemp */
    int previousTemp = 0XFF;// #FIXME - may be possible move to moonshineMachine

    /* idle while operator confirm step */
	void waitOperatorAction() { // #FIXME - remove while
		while (!moonshineMachine->isNextButtonPressed()) {
			moonshineMachine->buzzerOn();
			moonshineMachine->t1GetTemp(); // #FIXME - remove after while vanishes
		}
		moonshineMachine->buzzerOff();
	};

    /* update temperature every UPDATE_DELTA_TIME for trending */
	void updateTemp() {
		if (millis() - lastTempCheckTime > UPDATE_DELTA_TIME) {
			lastTempCheckTime = millis();
			previousTemp = moonshineMachine->t1_temp;
		}
	};

private:

    /* timestamp of the last update temperature */
    int lastTempCheckTime = 0;
};

