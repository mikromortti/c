#include <stdio.h>

#define IN 1 // insde a word
#define OUT 0 // outside a world

// count lines, words, and character in input

int main() {


int state = OUT;
int c = 0;


while ((c = getchar()) != EOF) {
	if(c != '\n' && c != ' ' && c != '\t') {
		state = IN;
		printf("%c", c);
	} else {
		if(state == IN) {
			printf("\n");
		}
		state = OUT;
	}
}






}
