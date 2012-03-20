/* K&R Exercise 2-3 p. 46 */

/* Write the function htoi(s), which converts a string of hexadecimal
 * digits (including an optional 0x or 0X) into its equivalent integer value.
 * The allowable digits are 0 through 9, a through f, and A through F. */

#include <stdio.h>
#include <math.h>

int htoi(char s[]);
int strlen(char s[]);

int main()
{
    int dec;
    char hex[] = "0x164";
    
    dec = htoi(hex);

    printf("%s in decimal is %d.\n", hex, dec);
}

int htoi(char s[])
{
    int len, i, sum, start;
    int p = 0;               /* current place value */
    sum   = 0;               /* the decimal value of s */

    /* Determine the string length */
    for (i=0; s[i] != '\0'; ++i) {}
    len = i;

    /* start will be the index of the last digit to examine. */
    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
    {
        start = 2;
    }
    else
    {
        start = 0;
    }

    /* Examine each digit by increasing place value.  Multiply
     * the digit by 16^p and the result to sum.  Finally increase p.*/
    for (i=len-1; i>=start; --i)
    {
        if (s[i] == 'a' || s[i] == 'A')
        {
            sum += 10 * pow(16,p);
        }
        else if (s[i] == 'b' || s[i] == 'B')
        {
            sum += 11 * pow(16,p);
        }
        else if (s[i] == 'c' || s[i] == 'C')
        {
            sum += 12 * pow(16,p);
        }
        else if (s[i] == 'd' || s[i] == 'D')
        {
            sum += 13 * pow(16,p);
        }
        else if (s[i] == 'e' || s[i] == 'E')
        {
            sum += 14 * pow(16,p);
        }
        else if (s[i] == 'f' || s[i] == 'F')
        {
            sum += 15 * pow(16,p);
        }
        else if (s[i] >= '0' || s[i] <= '9')
        {
            /* Subtracting '0' from s[i] results in the decimal value for the
             * characters '0'-'9'. */
            sum += (s[i] - '0') * pow(16,p);
        }
        else
        {
            printf("Invalid character in string!\n");
        }

        ++p;
    }

    return sum;
}

