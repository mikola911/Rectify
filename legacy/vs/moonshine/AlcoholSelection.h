#pragma once
#include "IRecipe1State.h"

class AlcoholSelection : public IRecipe1State {

public:
    int  action() override;
    AlcoholSelection(MoonshineMashine* moonshineMashine) : IRecipe1State(moonshineMashine) {
		nodeSelectionTemp = moonshineMashine->t1GetTemp();
		moonshineMashine->d2Write(0, 3, String(nodeSelectionTemp));
	};

private:
    void openNodeSelection();
    void closeNodeSelection();
    /**
     * Температура которая должна поддерживатся при отборе спирта.
    */
    float nodeSelectionTemp = 230;

    /**
     * Время которое прошло закрытия клапана в течении которого температура не падает.
     */
    int ladgeTempAfterClosingTime = 0;

};

