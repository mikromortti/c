#include <stdio.h>


// print Fahrenheit-Celsius table for fahr = 0, 20, ..., 300

float convertFahrToC(float fahr);

int main() {
	float fahr, celsius;

	int lower = 0; /* lower limit of temperature table */
	int upper = 300; /*upper limit*/
	int step = 20; //step size



	fahr = lower;

	printf("\nFahrenheit to Celsius conversions\n\n");


	while (fahr <= upper) {

		printf("%3.0f %6.1f \n", fahr, convertFahrToC(fahr));

		fahr += step;
	}

}

float convertFahrToC(float fahr) {
	return (5.0 / 9.0) * (fahr - 32.0);
}

