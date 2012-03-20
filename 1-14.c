/* K&R exercise 1-14 p. 24 */

#include <stdio.h>

#define SPACE ' '

/* Write a program to print a histogram of the frequencies of different
 * in its characters in its input. */
int main()
{
    int c, i, prevc, padding;

    int num_digits[]   = {0,0,0,0,0,0,0,0,0,0};  /* 10 elements */
    int num_whitespace = 0;
    int num_others     = 0;

    while ((c = getchar()) != EOF)
    {
        if ( c == SPACE || c == '\t' || c == '\n' )
        {
            num_whitespace++;
        }
        else if ( c >= '0' && c <= '9' )
        {
            num_digits[c-'0']++;
        }
        else
        {
            num_others++;
        }

        prevc = c;
    }

    printf("whitespace  |");
    for ( i=0; i<num_whitespace; i++)
    {
        putchar('#');
    }
    putchar('\n');

    for (i=0; i<10; i++)
    {
        printf("digit %d     |", i);

        for (c=0; c<num_digits[i]; c++)
        {
            putchar('#');
        }
        
        putchar('\n');
    }

    printf("others      |");
    for ( i=0; i<num_others; i++)
    {
        putchar('#');
    }
    putchar('\n');
}

