/* K&R Exercise 3-5 p. 64 */

/* Write the function itob(n,s,b) that converts the integer n
 * into a base b character representation in the string s.  In
 * particular, itob(n,s,16) formats n as a hexadecimal integer 
 * in s.
 */

#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

void itob(int n, char *s, int b);
void reverse(char s[]);

/* Converts the number on the command line to base 16 or to the base indicated
 * by the second number on the command line. */
int main(int argc, char *argv[])
{
    int num;
    int base = 16;      // convert to hex by default
    char str[100];
    
    if (argc > 1)
    {
        num  = atoi(argv[1]);
    }
    else
    {
        printf("Must provide a number to convert!\n");
        exit(1);
    }

    if (argc > 2)
    {
        base = atoi(argv[2]);
    }

    str[0] = '\0';

    printf("%d in base 10 is ", num);
    itob(num, str, base);
    printf("%s in base %d\n", str, base);
}

/*
 * Converts the number n to the base indicated by b and copies its string 
 * representation to s.
 *
 * @param n the base 10 integer number to convert.
 * @param s a string pointer to hold the converted value.
 * @param b the base to convert to.
 */
void itob(int n, char *s, int b)
{
    int i, sign, remainder;
    int converting = 1;
    long long int num = n;

    i=0;
    if ((sign = num) < 0)           /* record sign */
    {
        num = -num;                 /* make n positive */
    }

    /* While the number is greater than 0 it is divided by the base b.  The
     * number becomes the result of the integer division and the next digit
     * of the converted number is created by (remainder % 10).  This is added
     * to the char value of '0' or 'A' if the value is greater than 10.
     * Finally, the correct sign is appended and the string is reversed since
     * it was build up in the 'wrong' order. */
    while (converting)
    {
        remainder = num % b;
        num       = num / b;

        if (remainder < 10)
        {
            s[i++] = remainder % 10 + '0';
            s[i]   = '\0';
        }
        else if (remainder >= 10)
        {
            s[i++] = remainder % 10 + 'A';
            s[i]   = '\0';
        }

        if (num == 0)
        {
            converting = 0;
        }
    }

    if (sign < 0)
    {
        s[i++] = '-';
        s[i] = '\0';
    }

    reverse(s);

    s[i] = '\0';
}

/*
 * Reverses the string s in place.
 *
 * @param s the string to reverse.
 */
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

