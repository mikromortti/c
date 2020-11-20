#include <stdio.h>


// print Fahrenheit-Calsius table for fahr = 0, 20, ..., 300

int main() {
	int fahr, celsius;

	int lower = 0; /* lower limit of temperature table */
	int upper = 300; /*upper limit*/
	int step = 20; //step size



	fahr = lower;

	while (fahr <= upper) {
		celsius = 5 *  (fahr - 32) / 9;



		printf("%i\t%i\n", fahr, celsius);

		fahr += step;
	}

}

