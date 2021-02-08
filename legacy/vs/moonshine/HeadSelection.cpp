#include "HeadSelection.h"
#include "Constants.h"
#include "ErrorCodes.h"

int HeadSelection::action() {
    if (firstAction)
    {
        moonshineMashine->s1Rotate(headSelectionServoAngle);
        firstAction = false;
    }
    updateTemp();
	moonshineMashine->t1GetTemp();
    if (moonshineMashine->isNextButtonPressed())
    {
        return 1;
    }

    return 0;
}
