#include <stdio.h>

void draw (int a);

int main(void) {


  int c;
  int nl = 0;
  int tab = 0;
  int space = 0;

  int letter = 0;
  int number = 0;
  int special = 0;


	while((c = getchar()) != EOF) {
		if(c == '\n') {
			nl++;
		} else if (c == '\t') {
			tab++;
		} else if (c == ' ') {
			space++;
		} else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
			letter++;
		} else if (c >= '0' && c <= '9') {
			number++;
		} else {
			special++;
		}

	}

	printf("Letters:  ");
	draw(letter);
	printf("Numbers:  ");
	draw(number);
	printf("Specials: ");
	draw(special);
	printf("Newlines: ");
	draw(nl);
	printf("Tabs:     ");
	draw(tab);
	printf("Spaces:   ");
	draw(space);


	
}

void draw (int a) {
	for(int i = 0; i < a; i++) {
		printf("#");
	}
	printf("\n");
}