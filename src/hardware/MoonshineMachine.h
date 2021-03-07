#pragma once

#include <Servo.h>
// #include "GyverEncoder.h"
#include <TM1637Display.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define buzzer 24
#define ONE_WIRE_BUS 25
#define servoPin 30
// #define encCLK 19
// #define encDT 18
#define btn 27
#define ledCLK 52
#define ledDIO 10

/* hardware managment */
class MoonshineMachine {

public:
    MoonshineMachine();

    /**
     * set servo valve angle
     * @param angle - target angle in deg
     */
    void s1Rotate(int angle);

    /**
     * get temperature from t1 and make some side actions //#FIXME
     * @return {float} temperature in degrees
     */
    float t1GetTemp();

    /**
     * show something at 4x20 display
     * @param index index in row (0-19)
     * @param rowNumber (0-3)
     * @param line string to show
    */
    void d2Write(int index, int rowNumber, String line);

    /* @return did operator confirmed action */
    bool isNextButtonPressed();

    void buzzerOn();

    void buzzerOff();

    /* print initial message in 4x20 display*/
    void sayHello();

    /* print current time on 4x20 display */
    void showTime();

    /* last measure of temperature */
    float t1_temp;

private:
    OneWire oneWire = OneWire(ONE_WIRE_BUS);

    DallasTemperature sensor = DallasTemperature(&oneWire);

    Servo servoValve;

    // Encoder enc(encCLK, encDT, btn);

    TM1637Display display = TM1637Display(ledCLK, ledDIO);

    LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 20, 4);

    /* show temperature on 4-digit display */
    void showTemp();
};
