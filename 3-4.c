#include <stdio.h>
#include <limits.h>


void itoaJee(int n, char s[]);
char *strrev(char *str);

int main(void) {
	int j = -2147483648;
	char s[600];



	printf("%i\n", j);
	itoaJee(j, s);
	printf("%s\n", s);






}

void itoaJee(int n, char s[]) {
	int i, sign;
	long j = n;

	if ((sign = j) < 0) {
		j = -j;
	}

	i = 0;

	do {
		s[i++] = j % 10 + '0';
	} while ((j /= 10) > 0);

	if (sign < 0) {
		s[i++] = '-';
		s[i] = '\0';
	}
	strrev(s);
}


/*
**  STRREV.C - reverse a string in place
**
**  public domain by Bob Stout
*/

#include <string.h>

char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}

#ifdef TEST

#include <stdio.h>

int main(int argc, char *argv[])
{
      while (--argc)
      {
            printf("\"%s\" backwards is ", *++argv);
            printf("\"%s\"\n", strrev(*argv));
      }
}

#endif /* TEST */