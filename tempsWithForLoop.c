#include <stdio.h>


// print Fahrenheit-Celsius table for fahr = 0, 20, ..., 300

int main() {

	#define LOWER 0
	#define UPPER 300
	#define STEP 20

	printf("\nFahrenheit to Celsius conversions\n\n");


	for(float fahr = UPPER; fahr >= LOWER; fahr -= STEP) {
		printf("%3.0f %6.1f \n", fahr, (5.0 / 9.0) * (fahr - 32.0));	
	}

	


}

