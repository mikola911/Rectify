#include <Arduino.h>
#include "production/MoonshineMashine.h"
#include "production/technologist/recipe/recipe1/Recipe1.h"
void setup() {
    MoonshineMashine *moonshineMashine = new MoonshineMashine;
    Recipe1 *recipe = new Recipe1(moonshineMashine);
    recipe->start();

}

void loop() {
  // put your main code here, to run repeatedly:
}