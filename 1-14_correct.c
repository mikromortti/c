/**
 *
 * Histogram of Frequency of Different Characters in Input
 *
 **/

#include<stdio.h>

#define TOTAL_CHARS 128  /* Total Number of characters is 128: 0 - 127 */

int main(void)
{
    int c, i, j;

    int merkit[TOTAL_CHARS];

    for(i=0; i < TOTAL_CHARS; ++i) {
        merkit[i] = 0;
    }

    
    while((c=getchar()) != EOF) {
        merkit[c] = merkit[c] + 1;
    }

    for(i=0; i<TOTAL_CHARS; ++i)
    {
        if(merkit[i] > 0) {
            putchar(i);
        
            for(j=0; j < merkit[i]; ++j)
                putchar('*');

            putchar('\n');
        }
    }
    return 0;
}