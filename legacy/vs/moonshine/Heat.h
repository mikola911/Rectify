#pragma once
#include "IRecipe1State.h"
class Heat : public IRecipe1State {

public:
    int  action() override;
    Heat(MoonshineMashine* moonshineMashine) : IRecipe1State(moonshineMashine) {};

private:


    /**
     * ����� � ������� �������� ����������� �� ������.
     */
    int constantTempTime = 0;


    /**
     * ��������� ��������� �� ������� ������ � ������.
     * @return 0 - ��� ������ <0 ��� ������
     */
    int checkError();

    /**
     * ������� ���������� ������� � ������� �������� ����������� �� ������.
     */
    void updateConstantTempTimeAction();
};

