#include "Constants.h"
#include "ErrorCodes.h"

class IRecipe1State
{
public:
	IRecipe1State() {}
    IRecipe1State(MoonshineMachine* moonshineMachine) {
        this->moonshineMachine = moonshineMachine;
    }
	/**
	 * ������� ������������ ��������� � ������ ������� dt
	 * ���������� � �����.
	 * ���� ������
	 * (�� ErrorCodes.h)
	 */
	virtual  int action() { return 0; };

protected:

    MoonshineMachine* moonshineMachine;

    /**
     * �����������, ������� ���� �� ����� ����������� ��������� �����������.
     */
    int previousTemp = 0XFF;// #FIXME

    /**
     * ���� �������� ���������.
     */
	void waitOperatorAction() { // #FIXME - remove while
	    while (!moonshineMachine->isNextButtonPressed()) {
			moonshineMachine->buzzerOn();
			moonshineMachine->t1GetTemp(); // ����������� �� �������� �������, ��������� �� while - �� ����� ������ ��� �����
		}
		moonshineMachine->buzzerOff();
	};

    /**
     * ��������� ����������� ��� ����������� ������� ������ �����������.
     */
	void updateTemp() {
	    if (millis() - lastTempCheckTime > UPDATE_DELTA_TIME) {
			lastTempCheckTime = millis();
			previousTemp = moonshineMachine->t1_temp;
		}
	};

private:

    /**
     * ��������� ����� ���������� ������ �����������.
     */
    int lastTempCheckTime = 0;
};

