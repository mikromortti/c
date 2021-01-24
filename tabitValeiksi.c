#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	FILE *ft;
	FILE *tmp;

	char const *name = argv[1];
	int ch;
	ft = fopen(name, "r+");
	tmp = fopen("tmp.c", "w");


	if(ft == NULL) {
		fprintf(stderr, "cannot open target file %s\n", name);
		exit (1);
	}

	if(tmp == NULL) {
		fprintf(stderr, "cannot open target file tmp.c");
		exit (1);
	}

	while ((ch = fgetc(ft)) != EOF) {

		if(ch == '\t') {
			for (int i = 0; i < 4; i++) {
				fputc(' ', tmp);	
			}
		} else {
			fputc(ch, tmp);
		}
	}

	fclose(ft);
	fclose(tmp);

	remove(name);
	rename("tmp.c", name);

}