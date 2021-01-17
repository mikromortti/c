#include <stdio.h>
#include <stdlib.h>

void checkErrors(char fileName[]);

int main(int argc, char *argv[]) {

}

void checkErrors(char fileName[]) {
	FILE *ft;

	char const *name = fileName;
	int ch;
	ft = fopen(name, "r");

	if(ft == NULL) {
		fprintf(stderr, "cannot open target file %s\n", name);
		exit (1);
	}

	//toiminnallisuus
	while ((ch = fgetc(ft)) != EOF) {
		fputc(ch, stderr);
	}



	fclose(ft);
}