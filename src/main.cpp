#include <Arduino.h>
#include "MoonshineMachine.h"
#include "Recipe.h"
MoonshineMachine *moonshineMashine;
Recipe *recipe;
void setup()
{
  moonshineMashine = new MoonshineMachine;
  recipe = new Recipe(moonshineMashine);

}

void loop()
{
		moonshineMashine->t1GetTemp();
		moonshineMashine->showTime();

		recipe->iteration();
}