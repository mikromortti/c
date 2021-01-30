#include <stdio.h>

int any(char s1[], char s2[]);

int main(void) {
	char eka[] = "jeejee";
	char toka[] = "erkki";

	printf("%i\n", any(eka, toka));
}

int any(char s1[], char s2[]) {
	for(int i = 0; s1[i] != '\0'; i++) {
		for(int j = 0; s2[j] != '\0'; j++) {
			if(s1[i] == s2[j]) {
				return i;				
			}
		}
	}
	return -1;

}