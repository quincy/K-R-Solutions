/* K&R Exercise 3-6 p. 64 */

/* Write a version of itoa that accepts three argument sinstead of two.  The 
 * third argument is a minimum field with; the converted number must be padded
 * with blanks on the left if necessary to make it wide enough. 
 */

#include <stdio.h>
#include <string.h>

#define SPACE ' '

void itoa(int n, char s[], int min);
void reverse(char s[]);

int main(int argc, char *argv[])
{
    int num = 17;
    int min = 10;
    char str[20];
    
    printf("INTEGER: %d\n", num);
    itoa(num, str, min);
    printf("STRING : %s\n", str);

    return 0;
}

/*
 * Convert the number n to an ASCII string representation of the number.
 *
 * The resulting string will always be right justified according to the 
 * minimum field width min.  Empty space is padded with blanks.
 *
 * @param n the number.
 * @param s a char array to hold the converted string.
 * @param min the minimum width of the string.
 */
void itoa(int n, char s[], int min)
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

    while (i < min)
    {
        s[i++] = SPACE;
    }

    s[i] = '\0';
    reverse(s);
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

