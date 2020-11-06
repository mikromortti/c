#include <unistd.h>

int main(void) {

	write(1, "hello, world! \n", 36);
	return 0;
}
