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

#include "MoonshineMashine.h"
#include "Recipe.h"
void setup() {
    MoonshineMashine* moonshineMashine = new MoonshineMashine;
    Recipe* recipe = new Recipe(moonshineMashine);
    recipe->start();

}

void loop() {
	Serial.println('Loop');
}
