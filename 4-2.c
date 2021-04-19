#include <stdio.h>
#include <ctype.h>
#include <math.h>

long double atof(char s[]);

int main(void) {

char s[] = "123.450000000000000e-10";

printf("%.20Lf\n", atof(s));


}

long double atof(char s[]) {
	double val, power;
	int i, sign;
	long double luku;
	long double kerroin = 1.0;
	int scientific = 0;
	int kertoimenEtumerkki = 1;


	for (i = 0; isspace(s[i]); i++) {
		;
	}

	sign = (s[i] == '-') ? -1 : 1;

	if (s[i] == '+' || s[i] == '-') {
		i++;
	}

	for (val = 0.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
	}

	if (s[i] == '.') {
		i++;
	} else if (s[i] == 'e' || s[i] == 'E') {
		i++;
		scientific = 1;
			if (s[i] == '+' || s[i] == '-') {
				if (s[i] == '-') {
					kertoimenEtumerkki = -1;
				}	
			i++;
		}

		// kerroin doubleksi
		for(kerroin = 0.0; isdigit(s[i]); i++) {
			kerroin = kerroin * 10 +(s[i] - '0');
		}	

	}

	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0; 
	}

	if (s[i] == 'e' || s[i] == 'E') {
		i++;
		scientific = 1;
			if (s[i] == '+' || s[i] == '-') {
				if (s[i] == '-') {
					kertoimenEtumerkki = -1;
				}	
			i++;
		}

		// kerroin doubleksi
		for(kerroin = 0.0; isdigit(s[i]); i++) {
			kerroin = kerroin * 10 + (s[i] - '0');		
		}	

	}

	kerroin *= kertoimenEtumerkki;
	kerroin = pow(10, kerroin);
	luku = sign * val / power;


	if(scientific == 1) {
		return luku * kerroin;
	} else {
		return luku;
	}
}