#include <Arduino.h>
#include "hardware/MoonshineMachine.h"
#include "recipe/Recipe.h"

MoonshineMachine *moonshineMachine;
Recipe *recipe;

void setup() {
  moonshineMachine = new MoonshineMachine();
  recipe = new Recipe(moonshineMachine);
}

void loop() {
  moonshineMachine->t1GetTemp();
  moonshineMachine->showTime();

  recipe->iteration();
}
