#include <stdio.h>

int bitcount(unsigned int x);

int main(void) {

	unsigned int x = 2214; // 100010100110

	int n = 0 & 1;

	printf("%u\n", n);

	printf("%u\n", bitcount(x));

}

int bitcount(unsigned int x) {

	int b = -1;

	for(b = 0; x != 0; x &= (x - 1)) {
		b++;
	}
 
	return b;
}