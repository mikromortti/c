#include <stdio.h>

unsigned int invert(unsigned int x, unsigned int p, unsigned int n);

const int koko = 8 * (int) sizeof(int); 

int main(void) {

	unsigned int x = 2213; // 100010100101


	printf("%u\n", invert(x, 4, 3));
}

unsigned int invert(unsigned int x, unsigned int p, unsigned int n) {

	if(p == 0 && n == 0) {
		return x;
	}

	unsigned int xLeft = x >> (p + n);
	xLeft = xLeft << (p + n);

	unsigned int xRight;

	if(p == 0) {
		xRight = xRight >> (((int)sizeof(int) * 8) - 1);
		xRight = xRight >> (((int)sizeof(int) * 8) - 1);
	} else {
		xRight = x << (koko - p);
		xRight = xRight >> (koko - p);	
	}

	unsigned int xMiddle = ~x;
	xMiddle = xMiddle >> p;
	xMiddle = xMiddle << p;

	xMiddle = xMiddle << (koko - (p + n));
	xMiddle = xMiddle >> (koko - (p + n));	




	return xLeft | xMiddle | xRight;
}