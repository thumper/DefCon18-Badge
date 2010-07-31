#include <stdio.h>
#include <string.h>

#if 1
/*
**  LTOSTR.C -- routine and example program to convert a long int to
**  the specified numeric base, from 2 to 36.
**
**  Written by Thad Smith III, Boulder, CO. USA  9/06/91 
**  and contributed to the Public Domain.
*/

#include <stdlib.h>

char *                  /* addr of terminating null */
ltostr (
    char *str,          /* output string */
    long val,           /* value to be converted */
    unsigned base)      /* conversion base       */
{
    ldiv_t r;           /* result of val / base */

    if (base > 36)      /* no conversion if wrong base */
    {
        str = '\0';
        return str;
    }
    if (val < 0)    *str++ = '-';
    r = ldiv (labs(val), base);

    /* output digits of val/base first */

    if (r.quot > 0)  str = ltostr (str, r.quot, base);

    /* output last digit */

    *str++ = "0123456789abcdefghijklmnopqrstuvwxyz"[(int)r.rem];
    *str   = '\0';
    return str;
}
#endif


void decode(unsigned int val, unsigned int bit, unsigned int a, unsigned int b) {
    if (bit >= 13) {
	int i;
        unsigned int final = (a << 12) | b;
	char str[25];
	ltostr(str, final, 3);
#if 1
	int finalZero = 0;
	if (strlen(str) < 15)
	    finalZero = 15 - strlen(str);
	for (i=strlen(str); i>15; i--) {
	    if (str[i-1] != '0') return;
	}
	for (;i>0; i--) {
	    printf("%c", str[i-1]);
	}
	for (i=finalZero; i>0; i--)
	    printf("0");
	printf("\n");
#else
	printf("%s\n", str);
#endif
	return;
    }
    int pos = val & (1 << bit);
    if (pos) {
	decode(val, bit+1, a | (1<<bit), b);
	decode(val, bit+1, a, b | (1<<bit));
    } else {
	decode(val, bit+1, a, b);
	decode(val, bit+1, a | (1<<bit), b | (1<<bit));
    }
}

int main() {

    int x = 2326;

    decode(x, 0, 0, 0);
    return 0;
}


