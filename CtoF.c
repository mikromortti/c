#include <stdio.h>


// print Celsius-Fahrenheit table for fahr = 0, 20, ..., 300

int main() {
	float fahr, celsius;

	int lower = 0; /* lower limit of temperature table */
	int upper = 300; /*upper limit*/
	int step = 20; //step size



	celsius = lower;

	printf("\nCelsius to Fahrenheit conversions\n\n");


	while (celsius <= upper) {
		

		fahr = celsius / (5.0 / 9.0) + 32;


		printf("%3.0f %6.0f \n", celsius, fahr);

		celsius += step;
	}

}