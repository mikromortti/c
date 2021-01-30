#include <stdio.h>

void squeeze(char s1[], char s2[]);

int main(void) {
	char eka[] = "aamupala";
	char toka[] = "ää";

	printf("%s\n", eka);
	squeeze(eka, toka);
	printf("%s\n", eka);
}

void squeeze(char s1[], char s2[]) {
	for(int k = 0; s2[k] != '\0'; k++) {
		int j = 0;
		for(int i = 0; s1[i] != '\0'; i++) {
			if(s1[i] != s2[k]) {
				s1[j] = s1[i];
				j++;
			}
		}
		s1[j] = '\0';
	}
}