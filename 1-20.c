#include <stdio.h>

#define MAXLINE 1000
#define TABLENGTH 5

void detab(char s[], int n);
int getLine(char s[], int lim);

int main(void) {

char line[MAXLINE];

getLine(line, MAXLINE);



detab(line, TABLENGTH);


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


	
	s[i] = '\0';
	return i;
}

void detab(char s[], int n) {

int i = 0;
int k = 0;

while (s[i] != '\0') {
	if(k == n) {
		k = 0;
	}
	if(s[i] == '\t') {
		while(k < n) {
			printf(" ");
			k++;
		}
		i++;
		k = 0;
	} else {
		printf("%c", s[i]);
		i++;
		k++;	
	}


}

printf("\n");

}

