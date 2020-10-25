#include <Servo.h>
#include "GyverEncoder.h"
#include <TM1637Display.h>
#include <OneWire.h>
#include <DS18B20.h>

#define buzzer 24

#define ONE_WIRE_BUS 25
OneWire oneWire(ONE_WIRE_BUS);
DS18B20 sensor(&oneWire);

#define servoPin 30
Servo servoValve;

#define encCLK 19
#define encDT 18
#define btn 20
Encoder enc(encCLK, encDT, btn);

#define ledCLK 52
#define ledDIO 10
TM1637Display display(ledCLK, ledDIO);

byte initialPos = 180;
byte workingPos = 90;
byte currentPos = 180;

void setup() {
  Serial.begin(115200);

  sensor.begin();
    
  servoValve.attach(servoPin);
  valveMoving(initialPos);

  attachInterrupt(5, isr, CHANGE);
  attachInterrupt(4, isr, CHANGE);

  display.setBrightness(0x0f);
  uint8_t data[] = { 0xff, 0xff, 0xff, 0xff };
  display.setSegments(data);
  delay(100);
  display.clear();
}

void isr() {
  enc.tick();  // отработка в прерывании
}

void loop() {
  encoder_routine();
  valveMoving(currentPos);
  display.showNumberDec(currentPos, false);

  sensor.requestTemperatures(); 
//  while (!sensor.isConversionComplete());  // wait until sensor is ready
  Serial.println(sensor.getTempC());
}

void encoder_routine(){
  if (enc.isRight() && (currentPos<180)) currentPos++;
  if (enc.isLeft()  && (currentPos>0))   currentPos--;

  if (enc.isRightH()) currentPos=initialPos; 
  if (enc.isLeftH())  currentPos=workingPos;
  
}

void valveMoving (byte pos) {
  servoValve.write(pos);
}
