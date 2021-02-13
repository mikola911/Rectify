#include "AlcoholSelection.h"
#include "Constants.h"
#include "ErrorCodes.h"
int AlcoholSelection::action()
{
    updateTemp();
    if (ladgeTempAfterClosingTime > ladgeTempAfterClosingTimeMax)
    {
		//Serial.println("ladgeTempAfterClosingTimeMax ON");
        moonshineMashine->buzzerOn();
    }
    else
    {
		//Serial.println("ladgeTempAfterClosingTimeMax OFF");
        moonshineMashine->buzzerOff();
    }


    if (moonshineMashine->t1_temp > nodeSelectionTemp + nodeSelectionDeltaTemp)
    {
		Serial.println("closeNodeSelection");
        closeNodeSelection();

    }
    else
    {
		Serial.println("openNodeSelection");
        openNodeSelection();
        ladgeTempAfterClosingTime = millis();
    }
	return 0;
}

void AlcoholSelection::openNodeSelection()
{
    moonshineMashine->s1Rotate(nodeSelectionOpenAngle);
}

void AlcoholSelection::closeNodeSelection()
{
    moonshineMashine->s1Rotate(nodeSelectionCloseAngle);
}
