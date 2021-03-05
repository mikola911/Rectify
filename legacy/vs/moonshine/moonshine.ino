

void setup() {


	while (true) { // Loop
		moonshineMashine->t1GetTemp();
		moonshineMashine->showTime();

		recipe->iteration();
	}
}
