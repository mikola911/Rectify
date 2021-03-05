#pragma once
//#include <Arduino.h>

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

/**
 * Рулит самогонным аппаратом.
 * t - термосенсоры
 * s - сервоприводы
 * e - энкодеры
 * d - дисплеи
 */
    class  MoonshineMashine {

    public:
        MoonshineMashine();

        /**
         * Выставить сервопривод в заданный угол.
         * @param angle угол в градусах
         */
        void s1Rotate(int angle);

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
        void d2Write(int index, int rowNumber, String line);

        /**
         *
         * @return нажата ли кнопка перехода к следующему технологическому состоянию.
         */
        bool isNextButtonPressed();

        /**
         * Включить бузер.
         */
        void buzzerOn();
        /**
         * Выключить бузер.
         */
        void buzzerOff();

		/**
		 * Вывести на основной дисплей приветственное сообщение
		 */
		void sayHello();

		/**
		 * Вывести на основной дисплей время с начала запуска программы
		 */
		void showTime();
		/**
         * последнее сохраненное значение temp
         */
        float t1_temp;
    private:

        OneWire oneWire = OneWire(ONE_WIRE_BUS);

        DS18B20 sensor = DS18B20(&oneWire);

        Servo servoValve;

        // Encoder enc(encCLK, encDT, btn);

        TM1637Display display = TM1637Display(ledCLK, ledDIO);

        LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 20, 4);

        /**
         * Вывести на отдельный дисплей температуру с термосенсора 1
         */
        void showTemp();
};




