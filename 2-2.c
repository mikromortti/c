#include <stdio.h>


int lim = 5;
char s[5];
char c;


int main(void) {

	// for(int i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; i++) {
	// 	s[i] = c;
	// }


	int k = 0;
	while(k < lim - 1) {
		c = getchar();
		if(c == '\n') {
			break;
		} else if(c == EOF) {
			break;
		} else {
			s[k] = c;
		}
		k++;
	} 




	for(int j = 0; s[j] != '\0'; j++) {
		printf("%c", s[j]);
	}
	printf("\n");

}