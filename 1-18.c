#include <stdio.h>

#define MAXLINE 1000

int getLine(char s[], int lim);



char line[MAXLINE];
char longest[MAXLINE];

int toBePrinted = 10;


int main (void) {
	if(getLine(line, MAXLINE) > toBePrinted) {
		printf("%s\n", line);		
	}


}

int getLine(char s[], int lim) {

	int i, c;
	

	for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
		s[i] = c;
	}

	for (;i >= 0; i--) {
		if(s[i - 1] == '\t' || s[i - 1] == ' ') {
			s[i - 1] = '\0';
		} else {
			break;
		}
	}


	i++;
	s[i] = '\0';
	return i;
}
