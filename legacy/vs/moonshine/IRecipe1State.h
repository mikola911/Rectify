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
	void waitOperatorAction() {
	    while (!moonshineMashine->isNextButtonPressed())
		{
			moonshineMashine->buzzerOn();
			moonshineMashine->t1GetTemp(); // ����������� �� �������� �������, ��������� �� while - �� ����� ������ ��� �����
		}
		moonshineMashine->buzzerOff();
	};

    /**
     * ��������� ����������� ��� ����������� ������� ������ �����������.
     */
	void updateTemp() {
	    if (millis() - lastTempCheckTime > preheatingDeltaTimeForDeltaTemp) {
			lastTempCheckTime = millis();
			previousTemp = moonshineMashine->t1GetTemp();
		}
	};

private:

    /**
     * ��������� ����� ���������� ������ �����������.
     */
    int lastTempCheckTime = 0;
};

