#pragma once
//#include <Arduino.h>

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

/**
 * ����� ���������� ���������.
 * t - ������������
 * s - ������������
 * e - ��������
 * d - �������
 */
class MoonshineMachine
{

public:
     MoonshineMachine();

     /**
         * ��������� ����������� � �������� ����.
         * @param angle ���� � ��������
         */
     void s1Rotate(int angle);

     /**
         * �������� ����������� � ������������ 1.
         * @return  ����������� � ������������ 1 � ��������.
         */
     float t1GetTemp();

     /**
         * ������� �� ������� ����������
         * @param index ��������� � ������ (0-19)
         * @param rowNumber ����� ������ (0-3)
         * @param line ������
        */
     void d2Write(int index, int rowNumber, String line);

     /**
         *
         * @return ������ �� ������ �������� � ���������� ���������������� ���������.
         */
     bool isNextButtonPressed();

     /**
         * �������� �����.
         */
     void buzzerOn();
     /**
         * ��������� �����.
         */
     void buzzerOff();

     /**
		 * ������� �� �������� ������� �������������� ���������
		 */
     void sayHello();

     /**
		 * ������� �� �������� ������� ����� � ������ ������� ���������
		 */
     void showTime();
     /**
         * ��������� ����������� �������� temp
         */
     float t1_temp;

private:
     OneWire oneWire = OneWire(ONE_WIRE_BUS);

     DallasTemperature sensor = DallasTemperature(&oneWire);

     Servo servoValve;

     // Encoder enc(encCLK, encDT, btn);

     TM1637Display display = TM1637Display(ledCLK, ledDIO);

     LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 20, 4);

     /**
         * ������� �� ��������� ������� ����������� � ������������ 1
         */
     void showTemp();
};
