#include <Servo.h>
#include "GyverEncoder.h"
#include <TM1637Display.h>
#include <OneWire.h>
#include <DS18B20.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#define buzzer 24

#define ONE_WIRE_BUS 25
OneWire oneWire(ONE_WIRE_BUS);
DS18B20 sensor(&oneWire);

#define servoPin 30
Servo servoValve;

#define encCLK 19
#define encDT 18
#define btn 27
Encoder enc(encCLK, encDT, btn);

#define ledCLK 52
#define ledDIO 10
TM1637Display display(ledCLK, ledDIO);
LiquidCrystal_I2C lcd(0x27,20,4);

byte initialPos = 180;
byte workingPos = 90;
byte currentPos = 180;

void setup() {
  Serial.begin(115200);
  
  lcd.init(); 
  sensor.begin();
  valveMoving(initialPos);

  attachInterrupt(5, isr, CHANGE);
  attachInterrupt(4, isr, CHANGE);

  display.setBrightness(0x0f);
  uint8_t data[] = { 0xff, 0xff, 0xff, 0xff };
  display.setSegments(data);
  delay(100);
  display.clear();
  showHello();
}

void isr() {
  enc.tick();  // отработка в прерывании
}

void loop() {
  encoder_routine();
  valveMoving(currentPos);
  showServoPos(currentPos);

  sensor.requestTemperatures(); 
//  while (!sensor.isConversionComplete());  // wait until sensor is ready
  float temp = sensor.getTempC();
  showTemp(temp);
  showTime();
}

void encoder_routine(){
  if (enc.isRight() && (currentPos<180)) currentPos++;
  if (enc.isLeft()  && (currentPos>0))   currentPos--;

  if (enc.isRightH()) currentPos=initialPos; 
  if (enc.isLeftH())  currentPos=workingPos;
  
}

void valveMoving (byte pos) {
  
  servoValve.attach(servoPin);
  servoValve.write(pos);
  delay(100);
  servoValve.detach();
}

void showHello () {
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Wunderwaffe");
  lcd.setCursor(0,1);
  lcd.print("Arduino i2c 20x4 LCD");
}

void showTemp(float temp) {
  Serial.println(temp);
  lcd.setCursor(3,3);
  lcd.print("Temp = "+ String(temp) + " C");
  display.showNumberDecEx(temp*100,0b11100000, true, 4,0);
}

void showServoPos(byte pos) {
  lcd.setCursor(2,2);
  lcd.print("valve in pos "+ String(pos) + "  ");
}

void showTime() {
  unsigned long current = millis();
  byte Seconds = current / 1000 % 60;
  byte Minutes = current / 1000 / 60 % 60;
  byte Hours = current / 1000 / 60 / 60;
  String Time;
  if (Hours > 9) Time = String(Hours) + ':';
  else Time ='0' + String(Hours) + ':';
  if (Minutes > 9) Time += String(Minutes) + ':';
  else Time +='0' + String(Minutes) + ':';
  if (Seconds > 9) Time += String(Seconds);
  else Time +='0' + String(Seconds);
  
  lcd.setCursor(12,0);
  lcd.print(Time);
}
