#include "Constants.h"
#include "ErrorCodes.h"

class IRecipe1State
{
public:
	IRecipe1State() {}
    IRecipe1State(MoonshineMashine* moonshineMashine) {
        this->moonshineMashine = moonshineMashine;
    }
	/**
	 * ������� ������������ ��������� � ������ ������� dt
	 * ���������� � �����.
	 * ���� ������
	 * (�� ErrorCodes.h)
	 */
	virtual  int action() { return 0; };

protected:

    MoonshineMashine* moonshineMashine;

    /**
     * �����������, ������� ���� �� ����� ����������� ��������� �����������.
     */
    int previousTemp = 0XFF;// #FIXME

    /**
     * ���� �������� ���������.
     */
	void waitOperatorAction() { // #FIXME - remove while
	    while (!moonshineMashine->isNextButtonPressed()) {
			moonshineMashine->buzzerOn();
			moonshineMashine->t1GetTemp(); // ����������� �� �������� �������, ��������� �� while - �� ����� ������ ��� �����
		}
		moonshineMashine->buzzerOff();
	};

    /**
     * ��������� ����������� ��� ����������� ������� ������ �����������.
     */
	void updateTemp() {
	    if (millis() - lastTempCheckTime > UPDATE_DELTA_TIME) {
			lastTempCheckTime = millis();
			previousTemp = moonshineMashine->t1_temp;
		}
	};

private:

    /**
     * ��������� ����� ���������� ������ �����������.
     */
    int lastTempCheckTime = 0;
};

