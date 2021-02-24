#include "MoonshineMashine.h"
#include "Recipe.h"
void setup() {
    MoonshineMashine* moonshineMashine = new MoonshineMashine;
    Recipe* recipe = new Recipe(moonshineMashine);
    recipe->start(); // only init should be here
}

void loop() {
	// mesure loop should be here
	// recipe loop should be here
}
