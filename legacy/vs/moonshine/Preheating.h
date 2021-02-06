#pragma once
#include "IRecipe1State.h"
class Preheating : public IRecipe1State
{

public:
    int  action() override;
    Preheating(MoonshineMashine* moonshineMashine) : IRecipe1State(moonshineMashine) {};

private:

    /**
     * ��������� ��������� �� ������� ������ � ������.
     * @return 0 - ��� ������ <0 ��� ������
     */
    int checkError();


};

