#include "MoonshineMashine.h"

MoonshineMashine::MoonshineMashine() {
    Serial.begin(115200);
    Serial.println("MoonshineMashine starting");
	sayHello();

    display.setBrightness(0x0f);
    lcd.init();
	lcd.backlight();

    sensor.begin();
    t1GetTemp();
}

void MoonshineMashine::s1Rotate(int angle) {
    servoValve.attach(servoPin);
    servoValve.write(angle);
	Serial.print("s1Rotate: ");
	Serial.println(angle);
    delay(200);
    servoValve.detach();
}

float MoonshineMashine::t1GetTemp() {
	sensor.setResolution(11); //12bit, 1/16deg - max resolution
    sensor.requestTemperatures();
	while (!sensor.isConversionComplete()) {}; //#FIXME - delay about 750ms if 12bit resolution
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
	buzzerOn();
	display.showNumberDec(0000);
	d2Write(0, 0, "Wunderwaffe starts");
}

void MoonshineMashine::d2Write(int index, int rowNumber, String line) {
    lcd.setCursor(index, rowNumber);
    lcd.print(line);
}

void MoonshineMashine::buzzerOff() {
	noTone(buzzer);
}
void MoonshineMashine::buzzerOn() {
	tone(buzzer, 200, 400);
	delay(400);
	tone(buzzer, 600, 400);
	delay(200);
}
bool MoonshineMashine::isNextButtonPressed() {
	d2Write(4, 3, "Press button");
	bool state = false;
	if (digitalRead(btn) == 0) {
		state = true;
		for (int i = 0; i < 500; i++) {
			if (digitalRead(btn)) state = false;
		}
	}
	while (digitalRead(btn) == 0) { d2Write(3, 3, "Release button"); }
	if (state) d2Write(0, 3, "                    ");
	return state;
}

void MoonshineMashine::showTime() {
	unsigned long current = millis();
	byte Millis = current % 100;
	byte Seconds = current / 1000 % 60;
	byte Minutes = current / 1000 / 60 % 60;
	byte Hours = current / 1000 / 60 / 60;
	String Time;
	if (Hours > 9) Time = String(Hours) + ':';
	else Time = '0' + String(Hours) + ':';
	if (Minutes > 9) Time += String(Minutes) + ':';
	else Time += '0' + String(Minutes) + ':';
	if (Seconds > 9) Time += String(Seconds) + '.';
	else Time += '0' + String(Seconds) + '.';
	if (Millis > 9) Time += String(Millis);
	else Time += '0' + String(Millis);

	lcd.setCursor(9, 0);
	lcd.print(Time);
}
