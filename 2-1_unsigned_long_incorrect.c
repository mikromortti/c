#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <math.h>

unsigned long long maxUnsigned(unsigned long long size);

int main(void) {

	// printf("Sizes:\n");
	// printf("char size: %lu\n", sizeof(char));
	// printf("short size: %lu\n", sizeof(short));
	// printf("int size: %lu\n", sizeof(int));
	// printf("long size: %lu\n", sizeof(long));
	// printf("float size: %lu\n", sizeof(float));
	// printf("double size: %lu\n", sizeof(double));
	// printf("\n\n");

	printf("Ranges from header:\n\n");
	printf("min char: %i\n", CHAR_MIN);	
	printf("max char: %i\n", CHAR_MAX);
	printf("max unsigned char: %i\n\n", UCHAR_MAX);

	printf("min short: %i\n", SHRT_MIN);	
	printf("max short: %i\n", SHRT_MAX);
	printf("max unsigned short: %i\n\n", USHRT_MAX);

	printf("min int: %i\n", INT_MIN);	
	printf("max int: %i\n", INT_MAX);
	printf("max unsigned int: %u\n\n", UINT_MAX);
		
	printf("min long: %lli\n", LLONG_MIN);	
	printf("max long: %lli\n", LLONG_MAX);
	printf("max unsigned long: %llu\n\n", ULLONG_MAX);


	



	printf("\n\n");



	printf("Computed ranges:\n\n");
	printf("min char: %lli\n", (maxUnsigned(sizeof(char)) / 2) * (-1) - 1);
	printf("max char: %lli\n", maxUnsigned(sizeof(char)) / 2);
	printf("max unsigned char: %lli\n\n", maxUnsigned(sizeof(char)));
	
	printf("min short: %lli\n", (maxUnsigned(sizeof(short)) / 2) * (-1) - 1);
	printf("max short: %lli\n", maxUnsigned(sizeof(short)) / 2);
	printf("max unsigned short: %lli\n\n", maxUnsigned(sizeof(short)));

	
	printf("min int: %lli\n", (maxUnsigned(sizeof(int)) / 2) * (-1) - 1);
	printf("max int: %lli\n", maxUnsigned(sizeof(int)) / 2);
	printf("max unsigned int: %lli\n\n", maxUnsigned(sizeof(int)));


	printf("min long: %lli\n", (maxUnsigned(sizeof(long)) / 2) * (-1) - 1);
	printf("max long: %lli\n", maxUnsigned(sizeof(long)) / 2);
	printf("max unsigned long: %llu\n\n", maxUnsigned(sizeof(long)));




	printf("Floating-point types:\n\n");
	printf("min float: %g\n", FLT_MIN);	
	printf("max float: %g\n", FLT_MAX);

		
	printf("min double: %g\n", DBL_MIN);	
	printf("max double: %g\n", DBL_MAX);



}

unsigned long long maxUnsigned(unsigned long long size) {
	unsigned long long maxUnsigned = 0;
	int newSize = size * 8;
	for(int i = 0; i < newSize; i++) {
		maxUnsigned += pow(2, i);
	}
	return maxUnsigned;
}