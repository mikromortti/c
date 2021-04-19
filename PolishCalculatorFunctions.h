#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXVAL 100
#define BUFSIZE 100
#define MAXOP 100
#define NUMBER '0'

char buf[BUFSIZE];
int bufp = 0;

int sp = 0;
double val[MAXVAL];

void push(double f) {
	if (sp < MAXVAL) {
		val[sp++] = f;
	} else {
		printf("error: stack full, can't push nothing (%g\n)", f);
	}
}



double pop(void) {
	if (sp > 0) {
		return val[--sp];
	} else {
		printf("error: stack empty\n");
		return 0.0;
	}

}

int getch(void) {
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
	if (bufp >= BUFSIZE) {
		printf("ungetch: too many characters\n");
	} else {
		buf[bufp++] = c;
	}
}





int getop(char s[]) {
	int i, c;

	int neg = 0;

	while ((s[0] = c = getch()) == ' ' || c == '\t') {
		;
	}

	s[1] = '\0';
	if (!isdigit(c) && c != '.') {
		if(c == '-') {
			c = getch();
			if(isdigit(c)) {
				neg = 1;
			}
			ungetch(c);
		}
		if(neg == 0) {
			return c;			
		}

	}

	i = 0;



	if (isdigit(c)) {

		while (isdigit(s[++i] = c = getch())) {
			;
		}
	}

	if (c == '.') {
		while (isdigit(s[++i] = c = getch())) {
			;
		}
	}
	s[i] = '\0';

	if (c != EOF) {
		ungetch(c);
	}

		return NUMBER;		
	


}













