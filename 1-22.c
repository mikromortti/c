#include <stdio.h>
#include "myhead.h"


#define MAXLINE 1000
#define MAXLENGHT 10

int main(void) {
	char line[MAXLINE];
	int i;

	do {
		i = getOneLine(line, MAXLINE);
		fold(line, MAXLENGHT);		
	} while (i > 0);

}
