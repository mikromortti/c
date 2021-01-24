#include <stdio.h>
#include <stdlib.h>

void checkErrors(char fileName[]);

int main(int argc, char *argv[]) {
	checkErrors(argv[1]);
}

void checkErrors(char fileName[]) {
	FILE *ft;

	char const *name = fileName;
	int ch;
	ft = fopen(name, "r");

	int singleQuotes = 0;
	int doubleQuotes = 0;
	int bracketsL = 0;
	int bracketsR = 0;
	int parenthesesL = 0;	
	int parenthesesR = 0;
	int bracesL = 0;
	int bracesR = 0;
	int errors = 0;


	if(ft == NULL) {
		fprintf(stderr, "cannot open target file %s\n", name);
		exit (1);
	}


	while ((ch = fgetc(ft)) != EOF) {

		//Ei välitetä kommenteista
        if(ch == '/') {
            ch = fgetc(ft);
            if(ch == '/') {
                while((ch = fgetc(ft)) != '\n' && ch != EOF) {
                	;
                }

            } 

            else if (ch == '*') {
                while((ch = fgetc(ft)) != '*' && ch != EOF) {
                    if(ch != '\n') {
						;
                    }

                }
            } 

            else {
                ungetc(ch, ft);
            }
        } 

        // Jos 'sisällä'
        else if(ch == '\'') {
        	singleQuotes++;
        	ch = fgetc(ft);
        	if(ch == '\\') {
        		ch = fgetc(ft);
        	}
        	ch = fgetc(ft);
        	if(ch == '\'') {
        		singleQuotes++;
        	}  	
        	     	
        }



        // Jos "sisällä"
        else if(ch == '\"') {
        	doubleQuotes++;
			for(;;) {
				ch = fgetc(ft);
				if (ch == EOF) {
					break;
				}
				if(ch == '\\') {
					ch = fgetc(ft);
					if(ch == '"') {
						ch = fgetc(ft);
					}	
				}
				if(ch == '"') {
					doubleQuotes++;
					break;
				}
			}
   	
        }


		else if (ch == '(') {
			parenthesesL++;
		} 

		else if (ch == ')') {
			parenthesesR++;
		}

		else if (ch == '[') {
			bracketsL++;
		}

		else if (ch == ']') {
			bracketsR++;
		}

		else if (ch == '{') {
			bracesL++;
		}

		else if (ch == '}') {
			bracesR++;
		}





        

	}

	// printf("SingleQuotes: %i\n", singleQuotes);
	// printf("DoubleQuotes: %i\n", doubleQuotes);
	// printf("Left parentheses: %i\n", parenthesesL);
	// printf("Right parentheses: %i\n", parenthesesR);
	// printf("Left brackets: %i\n", bracketsL);
	// printf("Right brackets: %i\n", bracketsR);
	// printf("Left braces: %i\n", bracesL);
	// printf("Right braces: %i\n", bracesR);

	if(singleQuotes % 2 != 0) {
		printf("Unbalanced single quotes\n");
		errors++;
	} 

	if(doubleQuotes % 2 != 0) {
		printf("Unbalanced double quotes\n");
		errors++;
	}


	if(parenthesesL != parenthesesR) {
		printf("Unbalanced parentheses\n");
		errors++;		
	}

	if(bracketsL != bracketsR) {
		printf("Unbalanced brackets\n");
		errors++;		
	}

	if(bracesL != bracesR) {
		printf("Unbalanced braces\n");
		errors++;		
	}


	if(errors == 0) {
		printf("All Good!\n");
	}


	fclose(ft);

}