#include "MoonshineMachine.h"

MoonshineMachine::MoonshineMachine() {
    Serial.begin(115200);
    Serial.println("MoonshineMachine starting");
	sayHello();

    display.setBrightness(0x0f);
    lcd.init();
	lcd.backlight();

    sensor.begin();
	sensor.setResolution(11); //12bit, 1/16deg - max resolution
	sensor.requestTemperatures();

	enc.setTickMode(AUTO);
}

void MoonshineMachine::s1Rotate(int angle) {
    servoValve.attach(SERVO_PIN);
    servoValve.write(angle);
	Serial.print("s1Rotate: ");
	Serial.println(angle);
    delay(200);
    servoValve.detach();
}

float MoonshineMachine::t1GetTemp() {
	while (!sensor.isConversionComplete()) {}; //#FIXME - delay about 750ms if 12bit resolution
    // t1_temp = sensor.getTempC();
	t1_temp = sensor.getTempCByIndex(0);
	sensor.requestTemperatures();
	//Serial.print("Temp: ");
	//Serial.println(t1_temp);
	showTemp();
    return t1_temp;
}

void MoonshineMachine::showTemp() {
    display.showNumberDecEx(t1_temp * 100, 0b11100000, true, 4, 0);
}

void MoonshineMachine::sayHello() {
	buzzerOn();
	display.showNumberDec(0000);
	d2Write(0, 0, "Wunderwaffe starts");
}

void MoonshineMachine::d2Write(int index, int rowNumber, String line) {
    lcd.setCursor(index, rowNumber);
    lcd.print(line);
}

void MoonshineMachine::buzzerOff() {
	noTone(BUZZER_PIN);
}

void MoonshineMachine::buzzerOn() {
	tone(BUZZER_PIN, 200, 400);
	delay(400);
	tone(BUZZER_PIN, 600, 400);
	delay(200);
}

bool MoonshineMachine::isNextButtonPressed() {
	d2Write(4, 3, "Press button");
	bool state = false;
	if (enc.isPress()) state = true;
	while (enc.isHold()) { d2Write(3, 3, "Release button"); }
	if (state) d2Write(0, 3, "                    ");
	return state;
}

String MoonshineMachine::calculateTime(unsigned long start = 0, boolean withMillis = true) {
	unsigned long current = millis() - start;

	byte Seconds = current / 1000 % 60;
	byte Minutes = current / 1000 / 60 % 60;
	byte Hours = current / 1000 / 60 / 60;

	String Time;
	if (Hours > 9) Time = String(Hours) + ':';
	else Time = '0' + String(Hours) + ':';
	if (Minutes > 9) Time += String(Minutes) + ':';
	else Time += '0' + String(Minutes) + ':';
	if (Seconds > 9) Time += String(Seconds);
	else Time += '0' + String(Seconds);

	if (withMillis) {
		Time += '.';
		byte Millis = current % 100;
		if (Millis > 9) Time += String(Millis);
		else Time += '0' + String(Millis);
	}

	return Time;
}

void MoonshineMachine::showTime(unsigned long start = 0) {
	String TotalTime = calculateTime() + '/' + calculateTime(start, false);
	lcd.setCursor(0, 0);
	lcd.print(TotalTime);
}
