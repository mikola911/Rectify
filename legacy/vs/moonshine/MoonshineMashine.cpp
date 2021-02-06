#include "MoonshineMashine.h"




MoonshineMashine::MoonshineMashine() {
    
    Serial.begin(115200);
    //Serial.println(ìMoonshineMashine startingî);

    display.setBrightness(0x0f);
    display.showNumberDec(0000);

    lcd.init();
    lcd.backlight();
    sayHello();

    sensor.begin();
    t1GetTemp();
}

void MoonshineMashine::s1Rotate(int angle) {
    servoValve.attach(servoPin);
    servoValve.write(angle);
	Serial.print("s1Rotate: ");
	Serial.println(angle);
    delay(1000);
    servoValve.detach();
}

float MoonshineMashine::t1GetTemp() {
    sensor.requestTemperatures();
    t1_temp = sensor.getTempC();
	//Serial.print("Temp: ");
	//Serial.println(t1_temp);
	showTemp();
    return t1_temp;
}

void MoonshineMashine::showTemp() {
    display.showNumberDecEx(t1_temp * 100, 0b11100000, true, 4, 0);
}

void MoonshineMashine::sayHello() {
    lcd.setCursor(0, 0);
    lcd.print("Arduino i2c 20x4 LCD");
}

void MoonshineMashine::d2Write(int index, int rowNumber, String line) {
    lcd.setCursor(index, rowNumber);
    lcd.print(line);
}

void MoonshineMashine::buzzerOff()
{
	digitalWrite(buzzer, 0);
}
void MoonshineMashine::buzzerOn()
{
	digitalWrite(buzzer, 1);
}
bool MoonshineMashine::isNextButtonPressed()
{
    return true;// ŒÀﬂ, –≈¿À»«”… ›“Œ
}
