#include <unistd.h>

int main(void) {
	write(1, "hello, world\n", 20);
	return 0;
}