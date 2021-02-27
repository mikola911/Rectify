class Heat : public IRecipe1State {

public:
	Heat() : IRecipe1State() {};
    Heat(MoonshineMashine* moonshineMashine) : IRecipe1State(moonshineMashine) {};

	int  action() override{
		updateTemp();
		updateConstantTempTimeAction();
		int errorCode = checkError();
		if (errorCode < 0)
		{
			Serial.print("Error: ");
			Serial.println(errorCode);
			return errorCode;
		}
		if (moonshineMashine->t1_temp > heatMaxTem || millis() - constantTempTime > heatConstTempTime)
		{
			Serial.print("Normal exit. Temp: ");
			Serial.println(moonshineMashine->t1_temp);
			waitOperatorAction();
			return 1;
		}
		return 0;
	};
private:
    /**
     * ����� � ������� �������� ����������� �� ������.
     */
    int constantTempTime = 0;


    /**
     * ��������� ��������� �� ������� ������ � ������.
     * @return 0 - ��� ������ <0 ��� ������
     */
    int checkError() {
		if (moonshineMashine->t1_temp > heatTempErrorMax)
		{
			return TEMP_LARGE_ERROR;
		}
		else if (moonshineMashine->t1_temp < heatTempErrorMin)
		{
			return TEMP_SMALL_ERROR;
		}
		return 1;
	};

    /**
     * ������� ���������� ������� � ������� �������� ����������� �� ������.
     */
    void updateConstantTempTimeAction() {
		// #FIXME
		if (previousTemp > moonshineMashine->t1_temp + heatDeltaTemp) {
			constantTempTime = millis();
		}
	};
};

