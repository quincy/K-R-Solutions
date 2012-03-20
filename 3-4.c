/* K&R Exercise 3-4 p. 64 */

/* In a two's complement number representation, our version of 
 * itoa does not handle the largest negative number, that is,
 * the value of n equal to -(2^(wordsize-1)).  Explain why not.
 * Modify it to print the value correctly, regardless of the 
 * machine on which it runs. */

/* EXPLANATION
 *
 * The smallest int is -2147483648 but the largest int is 2147483647.
 * The itoa function starts by forcing the number to a positive value.
 * If the incoming number is INT_MIN then there is no valid positive
 * representation that can be stored in an int.
 */

#include <stdio.h>
#include <string.h>
#include <limits.h>

void itoa(int n, char s[]);
void reverse(char s[]);

int main()
{
    int num = INT_MIN;
    char str[10];
    
    printf("INTEGER: %d\n", num);
    itoa(num, str);
    printf("STRING : %s\n", str);
}

void itoa(int n, char s[])
{
    int i, sign;
    long long int num = n;

    if ((sign = num) < 0)           /* record sign */
    {
        num = -num;                 /* make n positive */
    }

    i = 0;
    do                              /* generate digits in reverse order */
    {
        s[i++] = num % 10 + '0';    /* get next digit */
    } while ((num /= 10) > 0);      /* delete it */

    if (sign < 0)
    {
        s[i++] = '-';
    }

    s[i] = '\0';
    reverse(s);
}

void reverse(char s[])
{
    int c, i, j;

    for (i=0, j=strlen(s)-1; i<j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

