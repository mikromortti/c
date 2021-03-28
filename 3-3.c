#include <stdio.h>
#include <stdbool.h>

void expand(char s1[], char s2[]);

int main(void) {
	char s1[] = "-A-z0-9-";
	char s2[100];

	printf("%s\n", s1);
	expand(s1, s2);
	printf("%s\n", s2);

}

void expand(char s1[], char s2[]) {
	int j;
	int k;
	bool pieniKirjain;
	bool isoKirjain;
	bool numero;

	for(int i = 0, j = 0; s1[i] != '\0'; i++) {
		pieniKirjain = isoKirjain = numero = false;

		if(s1[i] >= 'a' && s1[i] <= 'z') {
			pieniKirjain = true;
		} else if (s1[i] >= 'A' && s1[i] <= 'Z') {
			isoKirjain = true;
		} else if (s1[i] >= '0' && s1[i] <= '9') {
			numero = true;
		}


		// kirjaimet
		if(pieniKirjain || isoKirjain) {
			s2[j] = s1[i];
			j++;

		// numerot			
		} else if(numero) {
			s2[j] = s1[i];
			j++;
		} else if (s1[i] == '-') {
			// eka tai vika
			if(i == 0 || s1[i + 1] == '\0') {
				s2[j] = s1[i];
				j++;				
			}

			// keskellä
			else {
				//pienet kirjaimet
				if(s1[i - 1] >= 'a' && s1[i - 1] <= 'z' && s1[i + 1] >= 'a' && s1[i + 1] <= 'z' && s1[i - 1] <= s1[i + 1]) {
					k = s1[i - 1] + 1;

					while(k < s1[i + 1]) {
						s2[j] = k;
						k++;
						j++;
					}
					s2[j + 1] = '\0';
				}

				//isot kirjaimet
				else if(s1[i - 1] >= 'A' && s1[i - 1] <= 'Z' && s1[i + 1] >= 'A' && s1[i + 1] <= 'Z' && s1[i - 1] <= s1[i + 1]) {
					k = s1[i - 1] + 1;

					while(k < s1[i + 1]) {
						s2[j] = k;
						k++;
						j++;
					}
					s2[j + 1] = '\0';					
				}

				//numerot
				else if(s1[i - 1] >= '0' && s1[i - 1] <= '9' && s1[i + 1] >= '0' && s1[i + 1] <= '9' && s1[i - 1] <= s1[i + 1]) {
					k = s1[i - 1] + 1;

					while(k < s1[i + 1]) {
						s2[j] = k;
						k++;
						j++;
					}
					s2[j + 1] = '\0';					
				}	else {
					s2[j] = s1[i];
					j++;				
				}						
			}
		}





	}

}