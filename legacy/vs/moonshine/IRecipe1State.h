#pragma once
#include "MoonshineMashine.h"
class IRecipe1State
{



public:
	IRecipe1State()
	{
	}
    IRecipe1State(MoonshineMashine* moonshineMashine)
    {
        this->moonshineMashine = moonshineMashine;
    }
	/**
	 * ������� ������������ ��������� � ������ ������� dt
	 * ���������� � �����.
	 * ���� ������
	 * (�� ErrorCodes.h)
	 * @return 1 ���������� ��� ��� � ������� ��������� 0 ������� �� ��������� <0 ������
	 */
	virtual  int action() { return 0; };




protected:



    MoonshineMashine* moonshineMashine;

    /**
     * ����������� ������� ���� �� ����� ����������� ��������� �����������.
     */
    int previousTemp = 0XFF;// #FIXME

    /**
     * ���� �������� ���������.
     */
    void waitOperatorAction();

    /**
     * ��������� ����������� ��� ����������� ������� ������ �����������.
     */
    void updateTemp();



private:


    /**
     * ��������� ����� ���������� ������ �����������.
     */
    int lastTempCheckTime = 0;
};

