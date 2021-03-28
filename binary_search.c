#include <stdio.h>
#include <time.h>

int binarySearch(int x, int v[], int n);

int main(void) {

	const int size = 89000;

	clock_t begin = clock();

	int numerot[size];

	for (int i = 0; i < size; i++) {
		numerot[i] = i * 2;
	}


	printf("%i\n", binarySearch(55422, numerot, size));

	clock_t end = clock();

	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

	printf("\nTime: %f seconds\n", time_spent);


}

int binarySearch(int x, int v[], int n) {
	int low, mid, high;

	low = 0;

	high = n - 1;

	while (low <= high) {
		mid = (low + high) / 2;
		if (x < v[mid]) {
			high = mid - 1;
		} else if (x > v[mid]) {
			low = mid + 1;
		} else {
			return mid;
		}
	}

	return -1;
}
