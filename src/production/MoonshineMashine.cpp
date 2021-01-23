//
// Created by oem on 02.01.2021.
//

#include "MoonshineMashine.h"

MoonshineMashine::MoonshineMashine() {
    Serial.begin(115200);
    Serial.println(F(“MoonshineMashine starting”))

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
    delay(100);
    servoValve.detach();
}

float MoonshineMashine::t1GetTemp() {
    sensor.requestTemperatures();
    t1_temp = sensor.getTempC();
    return t1_temp;
}

void MoonshineMashine::showTemp() {
    display.showNumberDecEx(t1_temp * 100, 0b11100000, true, 4, 0);
}

void MoonshineMashine::sayHello() {
    lcd.setCursor(0,0);
    lcd.print("Arduino i2c 20x4 LCD");
}

void d2Write(int index, int rowNumber, char line[]) {
    lcd.setCursor(index,rowNumber);
    lcd.print(line);
}