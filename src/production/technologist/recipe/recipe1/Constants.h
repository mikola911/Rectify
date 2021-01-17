//
// Created by oem on 09.01.2021.
//


//Инициализация

/**
 * Начальный угол сервопривода.
 */
#define startServoAngle  0

//Преднагрев

/**
 * Температура при которой мы считаем, что преднагрев закончен
 */
#define preheatingTempJump 20

/**
 * Температура при которой мы считаем, что вошли в ошибку.
 */
#define preheatingTempErrorMax 220
/**
 * Температура при которой мы считаем, что вошли в ошибку.
 */
#define preheatingTempErrorMin -20
/**
 * скачек температуры который мы воспринимаем как сигнал перехода к следующему состоянию.
 */
#define preheatingDeltaTempJump 120

/**
 * Интервал времени закоторый должен происходить скачек температуры.
 */
#define preheatingDeltaTimeForDeltaTemp 10000

//Нагрев
/**
 * Температура при которой процесс нагрева можно считать оконченным.
 */
#define heatMaxTem 77

/**
 * Скачек температуры допустимый при выходи в стабильный режим данного этапа.
 * !!!ВНИМАНИЕ ПОКА СТАВЛЮ В INT!!!!
 */
#define heatDeltaTemp 1

/**
 * Время в течении которого температура жидкости должна оставаться постоянной.
 */
#define heatConstTempTime 60*1000*300
/**
 * Температура при которой мы считаем, что вошли в ошибку.
 */
#define heatTempErrorMax 220
/**
 * Температура при которой мы считаем, что вошли в ошибку.
 */
#define heatTempErrorMin -20

//Отбор голов

/**
 * Угол поворота сервомашины при отборе голов.
 */
#define headSelectionServoAngle 10


//Технологическая пауза

/**
 * Технологическя пауза [мс.]
 */
#define technologicalBreakTimeout 60*1000*15
/**
 * Угол поворота сервомотора во время технологической паузы.
 */
#define technologicalBreakServoPosition 15


//Отбор спирта

/**
 * Уголо поворота сервопривода при котором отбор спирта прекращен
 */
#define nodeSelectionCloseAngle 0

/**
 * Уголо поворота сервопривода при котором отбор спирта идет.
 */
#define nodeSelectionOpenAngle 230
/**
 * Дельа температуры на которую можно превышать при отборе голов.
 */
#define nodeSelectionDeltaTemp 0.5
/**
* Максимальное время которое прошло закрытия клапана в течении которого температура не падает.
*/
#define ladgeTempAfterClosingTimeMax 1000*20


#ifndef _MOONSHINE_CONSTANTS_H
#define _MOONSHINE_CONSTANTS_H

#endif //_MOONSHINE_CONSTANTS_H
