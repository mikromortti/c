#include <stdio.h>

#define MAXLINE 1000

int getLine(char s[], int lim);



char line[MAXLINE];
char longest[MAXLINE];

int toBePrinted = 10;


int main (void) {
	if(getLine(line, MAXLINE) > toBePrinted) {
		printf("%s", line);		
	}


}

int getLine(char s[], int lim) {

	int i, c;
	

	for(i = 0; i < lim - 1 && (c = getchar()) != EOF; i++) {
		s[i] = c;
		if(c == '\n') {
			i++;
			break;
		}
	}

	s[i] = '\0';
	return i;
}
