class Preheating : public IRecipe1State
{

public:
    Preheating(MoonshineMashine* moonshineMashine) : IRecipe1State(moonshineMashine) {};

    int  action() override {
		//Serial.println("Preheating::action() ");
		updateTemp();
		int errorCode = checkError();
		if (errorCode < 0) {
			Serial.print("Error: ");
			Serial.println(errorCode);
			return errorCode;
		}
		if (moonshineMashine->t1_temp > preheatingTempJump) {
			Serial.print("Exit by large temp: ");
			Serial.println(moonshineMashine->t1_temp);
			waitOperatorAction();
			return 1;
		}
		//�������� ����� ���������� ������ ��������� �� �������
		else if (moonshineMashine->t1_temp - previousTemp > preheatingDeltaTempJump) {
			Serial.print("Exit by jump temp. Previous temp : ");
			Serial.println(previousTemp);
			waitOperatorAction();
			return 1;
		}
		return 0;
	};
private:

    /**
     * ��������� ��������� �� ������� ������ � ������.
     * @return 0 - ��� ������ <0 ��� ������
     */
	int checkError() {
		if (moonshineMashine->t1_temp > preheatingTempErrorMax) {
			return TEMP_LARGE_ERROR;
		} else if (moonshineMashine->t1_temp < preheatingTempErrorMin) {
			return TEMP_SMALL_ERROR;
		}
		return 1;
	};
};

