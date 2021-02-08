#pragma once
#include "IRecipe1State.h"

class AlcoholSelection : public IRecipe1State {

public:
    int  action() override;
    AlcoholSelection(MoonshineMashine* moonshineMashine) : IRecipe1State(moonshineMashine) {
		nodeSelectionTemp = moonshineMashine->t1GetTemp();
	};

private:
    void openNodeSelection();
    void closeNodeSelection();
    /**
     * ����������� ������� ������ ������������� ��� ������ ������.
    */
    float nodeSelectionTemp = 230;

    /**
     * ����� ������� ������ �������� ������� � ������� �������� ����������� �� ������.
     */
    int ladgeTempAfterClosingTime = 0;

};

