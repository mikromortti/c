#include <stdio.h>
#include "myhead.h"

#define MAXLINE 1000
#define TABLENGTH 5



int main(void) {

char line[MAXLINE];
int i;

for(;;) {
	i = getOneLine(line, MAXLINE);
	if(i == 0) {
		break;
	}
	entab(line, TABLENGTH);
}








}





