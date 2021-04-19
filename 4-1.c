#include <stdio.h>

int strindex(char s[], char t[]);

int main(void) {
	char s[] = "joojeejee";
	char t[] = "jee";

	printf("%d\n", strindex(s,t));


 }

int strindex(char s[], char t[]) {
	int v = -1;
	int i, j, k;

	for(i = 0; s[i] != '\0'; i++) {
		for(j = i, k = 0; s[j] == t[k]; j++, k++) {
			if(t[k] == '\0') {
				v = i;
				break;
			}
		}
	}

	return v;
}