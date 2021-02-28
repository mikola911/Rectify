// Servo valve constants

/* Valve is closed */
#define CLOSED_SERVO_ANGLE  180

/* ���� �������� ����������� ��� ������ ����� */
#define HEAD_SELECTION_SERVO_ANGLE 170

/* ���� �������� ����������� ��� ������ ������ */
#define ALCOHOL_SELECTION_SERVO_ANGLE 160

/* ���� �������� ����������� ��� ������ ������� */
#define TAIL_SELECTION_SERVO_ANGLE 120 // #TODO

// Temperature constants 

/* system is too hot, end of preheat, need to switch on cooling */
#define PREHEAT_END_TEMP 45.0
/* heating too fast, end of preheat, need to switch on cooling */
#define PREHEAT_DELTA_TEMP 10.0

/* temperature seems enough for next step */
#define HEAT_MIN_TEMP 65.0

/* temperature seems too hot for heating */
#define HEAT_MAX_TEMP 85.0 // #TODO

/* allowed delta temperature for heating */
#define HEAT_DELTA_TEMP 0.5

/* ����� ����������� �� ������� ����� ��������� ��� ������ ����� */
#define ALCOHOL_SELECTION_DELTA_TEMP 0.2

/* maximum of temperature in normal conditions */
#define TEMP_MAX 102.0

/* minimum of temperature in normal conditions */
#define TEMP_MIN 16.0

// Time constants

/* Time interval for catching temp jump */
#define UPDATE_DELTA_TIME 1000

/* ����� � ������� �������� ����������� �������� ������ ���������� ����������.*/
#define HEAT_BREAK_TIME 60L*1000L*30L

/* tech break time - need for stable process */
#define TECHNOLOGICAL_BREAK_TIME 60L*1000L*30L

/* ������������ ����� ������� ������ �������� ������� � ������� �������� ����������� �� ������ */
#define ALCOHOL_SELECTION_OVERHEAT_TIME 1000L*20L

// Other constants
