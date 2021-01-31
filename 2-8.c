#include <stdio.h>

unsigned int rightrot(unsigned int x, unsigned int n);

const int koko = 8 * (int) sizeof(int); 

int main(void) {

	unsigned int x = 2213; // 100010100101


	printf("%u\n", rightrot(x, 3));

}

unsigned int rightrot(unsigned int x, unsigned int n) {

	if(n == 0) {
		return x;
	}

	return (x << (koko - n)) | (x >> n);
}