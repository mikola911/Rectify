

void setup() {
    MoonshineMashine* moonshineMashine = new MoonshineMashine;
    Recipe* recipe = new Recipe(moonshineMashine);

	while (true) { // Loop
		moonshineMashine->t1GetTemp();
		moonshineMashine->showTime();

		recipe->iteration();
	}
}
