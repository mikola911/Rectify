/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
 */


// the setup function runs once when you press reset or power the board

#include <TM1637Display.h>
#include <LiquidCrystal_I2C.h>
#include <DS18B20.h>
#include <OneWire.h>
#include <Servo.h>
#include <Wire.h>
#include "MoonshineMashine.h"
#include "Recipe1.h"
void setup() {
    MoonshineMashine* moonshineMashine = new MoonshineMashine;
    Recipe1* recipe = new Recipe1(moonshineMashine);
    recipe->start();

}

void loop() {
    // put your main code here, to run repeatedly:
}
