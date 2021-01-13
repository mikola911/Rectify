//
// Created by oem on 02.01.2021.
//
#include <Arduino.h>
#ifndef _MOONSHINE_MOONSHINEMASHINE_H
#define _MOONSHINE_MOONSHINEMASHINE_H

/**
 * Рулит самогонным аппаратом.
 * t - термосенсоры
 * s - сервоприводы
 * e - энкодеры
 * d - дисплеи
 */
class  MoonshineMashine {

public:
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
    int t1GetTemp();

    /**
     * Вывести на дисплей 1 информацию
     * @param rowNumber номер строки.
     * @param line строка
     */
    void d1Write(int rowNumber, char line[]);

    /**
     * Вывести на дисплей 1 информацию
     * @param rowNumber номер строки.
     * @param line строка
    */
    void d2Write(int rowNumber, char line[]);

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



};


#endif //_MOONSHINE_MOONSHINEMASHINE_H
