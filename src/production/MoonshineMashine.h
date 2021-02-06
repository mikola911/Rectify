//
// Created by oem on 02.01.2021.
//
#include <Arduino.h>
#ifndef _MOONSHINE_MOONSHINEMASHINE_H
#define _MOONSHINE_MOONSHINEMASHINE_H

#include <Servo.h>
// #include "GyverEncoder.h"
#include <TM1637Display.h>
#include <OneWire.h>
#include <DS18B20.h>
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
#define I2C_ADR 0x27

/**
 * Рулит самогонным аппаратом.
 * t - термосенсоры
 * s - сервоприводы
 * e - энкодеры
 * d - дисплеи
 */
class  MoonshineMashine {

public:
    MoonshineMashine() {}

    /**
     * Выставить сервопривод в заданный угол.
     * @param angle угол в градусах
     */
    void s1Rotate(int angle);

    /**
     * Изменит угол сервопривода на deltaAngle
     * @param angle угол в градусах
     */
    void s1RotateOnDelta(int deltaAngle);

    /**
     * Получить температуру с термоменсора 1.
     * @return  температура с термосенсора 1 в градусах.
     */
    float t1GetTemp();

    /**
     * Вывести на дисплей информацию
     * @param index положение в строке (0-19)
     * @param rowNumber номер строки (0-3)
     * @param line строка
    */
    void d2Write(int index, int rowNumber, char line[]);

    /**
     *
     * @return нажата ли кнопка перехода к следующему технологическому состоянию.
     */
    bool isNextButtonPressed();
    /**
     * Включить бузер.
     * (надеюсь он висит на PWM)
     */
    void buzzerOn();
    /**
     * Выключить бузер.
     */
    void buzzerOff();

private: 
    /** 
     * последнее сохраненное значение
     */
    float t1_temp;

    OneWire oneWire = OneWire(ONE_WIRE_BUS);

    DS18B20 sensor = DS18B20(&oneWire);

    Servo servoValve;

    // Encoder enc(encCLK, encDT, btn);

    TM1637Display display = TM1637Display(ledCLK, ledDIO);

    LiquidCrystal_I2C lcd = LiquidCrystal_I2C(I2C_ADR, 20, 4);

    /**
     * Вывести на отдельный дисплей температуру с термосенсора 1
     */
    void showTemp();

    /**
     * Вывести на основной дисплей приветственное сообщение
     */
    void sayHello();
};


#endif //_MOONSHINE_MOONSHINEMASHINE_H
