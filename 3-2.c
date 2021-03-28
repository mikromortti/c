#include <stdio.h>

void escape(char s[], char t[]);
void unescape(char s[], char t[]);


int main(void) {

	char s[] = "jee\tjee\nniin, että jeejee";
	char t[(int)sizeof(s) * 2];
	char k[(int) sizeof(s)];

	escape(s, t);

	printf("%s\n", t);

	unescape(t, k);

	printf("%s\n", k);




}

void escape(char s[], char t[]) {
	int i, j;
	for(i = j = 0; s[i] != EOF; i++, j++) {
		switch (s[i]) {
			case '\t':
				t[j] = '\\';
				j++;
				t[j] = 't';
				break;
			case '\n':
				t[j] = '\\';
				j++;
				t[j] = 'n';
				break;
			default:
				t[j] = s[i];
				break;						
		}

	}

}

void unescape(char s[], char t[]) {
	int i, j;
	for(i = j = 0; s[j] != EOF; i++, j++) {
		switch (s[j]) {
			case '\\':
				switch (s[j + 1]) {
					case 't':
						t[i] = '\t';
						j++;
						break;
					case 'n':
						t[i] = '\n';
						j++;
						break;
				}
				break;
			default:
				t[i] = s[j];
				break;	
		}

	}
}





