#include <stdio.h>

#define MAXLINE 1000 //max input line size

/* Huom! External variables ei välttämättä hyvä juttu!
Selitys sivulla 33! */







int max; //max length seen
char line[MAXLINE]; //current input line
char longest[MAXLINE]; //longest line saved here

int getLine(void);
void copy(void);

// print longest input line. Version with external variables

int main(void) {
	int len;


	max = 0;

	while ((len = getLine()) > 0) {
		if (len > max) {
			max = len;
			copy();
		}
	if (max > 0) /*There was a line*/ {
		printf("%s\n", longest);
	}	
	}
	return 0;
}

//getLine: version with external variables

int getLine (void) {
	int c, i;


	for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
		line[i] = c;

		if (c == '\n') {
			line[i] = c;
			i++;
		}


	}

	line[i] = '\0';
	return i;


}

//copy: version with external variables

void copy(void) {
	int i;


	i = 0;

	while ((longest[i] = line[i])
	 != '\0') {
		i++;
	}
}


