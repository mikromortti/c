#include <stdio.h>

#define MAXLINE 1000

int getLine(char s[], int lim);
void reverse(char s[]);



char line[MAXLINE];
char longest[MAXLINE];


/* Ei toimi oikein. Jos input 15 merkkiä tai yli, niin laittaa 0 tai ?
ensimmäiseksi merkiksi. Ei aavistustakaan, että miksi. Pitää selvittää */


int main (void) {


	getLine(line, MAXLINE);

	reverse(line);


	for(int i = 0; line[i] != '\0'; i++) {
		printf("%c", line[i]);
	}
	printf("\n");




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

void reverse(char s[]) {
	int i, j;
	int a = 0;

	for (i = 0; s[i] != '\0'; i++) {
		;
	}

	char tmp[i + 2];

	tmp[i + 1] = '\0';

	while(i > 0) {
		tmp[i] = s[a];
		i--;
		a++;
	}

	for(j = 0; tmp[j] != '\0'; j++) {
		s[j] = tmp[j];
	}
	j++;
	s[j] = '\0';



}
