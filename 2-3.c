#include <stdio.h>
#include <math.h>

int htoi(char s[]);

int main(void) {
	char s[] = "0x10f2c";

	printf("%i\n", htoi(s));
}

int htoi(char s[]) {
	int length;
	int decimal = 0;

	for(length = 0; s[length] != '\0'; length++) {
		;
	}

	for(int i = length - 1, pos = 0; i > 0; i--, pos++) {

		if(s[i] == 'x' || s[i] == 'X') {
			break;
		}


		if (s[i] >= 'a' && s[i] <= 'f') {
			decimal += (s[i] - 'a' + 10) * pow(16, pos);
		} else if (s[i] >= 'A' && s[i] <= 'F') {
			decimal += (s[i] - 'A' + 10) * pow(16, pos);			
		} else {
			decimal += (s[i] - '0') * pow(16, pos);
		}
		

	}

	return decimal;


}