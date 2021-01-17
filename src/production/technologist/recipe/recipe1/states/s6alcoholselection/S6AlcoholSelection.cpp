#include "production/technologist/recipe/recipe1/Constants.h"
#include "S6AlcoholSelection.h"


int S6AlcoholSelection::action()
{
    updateTemp();
    if(ladgeTempAfterClosingTime>ladgeTempAfterClosingTimeMax)
    {
        moonshineMashine->buzzerOn();
    }
    else
    {
        moonshineMashine->buzzerOff();
    }
    

    if(moonshineMashine->t1GetTemp()>nodeSelectionTemp+nodeSelectionDeltaTemp)
    {
        closeNodeSelection();

    }
    else
    {
        openNodeSelection();
        ladgeTempAfterClosingTime = millis();
    }
    
}

void S6AlcoholSelection::openNodeSelection()
{
    moonshineMashine->s1Rotate(nodeSelectionOpenAngle);
}

void S6AlcoholSelection::closeNodeSelection()
{
    moonshineMashine->s1Rotate(nodeSelectionCloseAngle);
}