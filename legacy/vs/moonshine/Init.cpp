#include "Init.h"
#include "Constants.h"

int Init::selfCheck() {
	if (moonshineMashine->isNextButtonPressed())  return 1;
	return 0;
}

