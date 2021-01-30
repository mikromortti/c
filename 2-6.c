#include <stdio.h>

unsigned int setbits(unsigned int x, unsigned int p, unsigned int n, unsigned int y);

int main(void) {
	unsigned int x = 2213; // 100010100101
	unsigned int y = 1324; // 010100101100 => 100000100101 = 2085







	printf("%u\n", setbits(x, 8, 8, y));



}

unsigned int setbits(unsigned int x, unsigned int p, unsigned int n, unsigned int y) {

	unsigned int xLeft = x >> p;
	xLeft = xLeft << p;

	unsigned int xRight;
	if(p == n) {
		xRight = xRight >> (((int)sizeof(int) * 8) - 1);
		xRight = xRight >> (((int)sizeof(int) * 8) - 1);
	} else {
		xRight = x << (((int)sizeof(int) * 8) - (p - n));
		xRight = xRight >> (((int)sizeof(int) * 8) - (p - n));	 
	}

	unsigned int yMiddle = y >> (p - n);
	yMiddle = yMiddle << (p - n);
	yMiddle = yMiddle << (((int)sizeof(int) * 8) - p);	
	yMiddle = yMiddle >> (((int)sizeof(int) * 8) - p);		

	printf("%u\n", xLeft);
	printf("%u\n", yMiddle);
	printf("%u\n", xRight);		


	x = xLeft | xRight | yMiddle;

	return x;
}