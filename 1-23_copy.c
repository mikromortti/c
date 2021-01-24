#include <stdio.h>
#include <stdlib.h>

void removeComments(char fileName[]);

int main(int argc, char *argv[]) {
	removeComments(argv[1]);
}

void removeComments(char fileName[]) {
	FILE *ft;


	char const *name = fileName;
	int ch;
	ft = fopen(name, "r+");


	if(ft == NULL) {
		fprintf(stderr, "cannot open target file %s\n", name);
		exit (1);
	}

	while ((ch = fgetc(ft)) != EOF) {




		//kirjoitetaan "" sisällä olevat
		if(ch == '"') {
			while((ch = fgetc(ft)) != '"' && ch != EOF) {
				;
			}
		}

		///skipataan kommentit

		if(ch == '/') {
			fseek(ft, ftell(ft) - 1, SEEK_SET);
			fputc(' ', ft);
			ch = fgetc(ft);
			if(ch == '/') {
				fseek(ft, ftell(ft) - 1, SEEK_SET);
				fputc(' ', ft);
				while((ch = fgetc(ft)) != '\n' && ch != EOF) {
					fseek(ft, ftell(ft) - 1, SEEK_SET);
					fputc(' ', ft);
				}

			} 

			else if (ch == '*') {
				fseek(ft, ftell(ft) - 1, SEEK_SET);
				fputc(' ', ft);
				while((ch = fgetc(ft)) != '*' && ch != EOF) {
					if(ch != '\n') {
						fseek(ft, ftell(ft) - 1, SEEK_SET);
						fputc(' ', ft);
					}

				}
				fseek(ft, ftell(ft) - 1, SEEK_SET);
				fputc(' ', ft);
			} 

			else {
				ungetc(ch, ft);
			}
		} 



		

	}
	fclose(ft);

	
}