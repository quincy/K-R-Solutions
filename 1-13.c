/* K&R exercise 1-13 p. 24 */

#include <stdio.h>

#define MAX_LENGTH 100
#define SPACE      ' '

/* Write a program to print a histogram of the lengths of words in its input.
 * It is easy to draw the histogram with the bars horizontal; a vertical
 * orientation is more challenging. */
int main()
{
    int c, i, num_chars, prevc, biggest;
    int words[MAX_LENGTH];

    for (i=0; i<MAX_LENGTH; ++i)
    {
        words[i] = 0;
    }

    num_chars = 0;
    biggest   = 0;

    while ((c = getchar()) != EOF)
    {
        if ( c == SPACE || c == '\t' || c == '\n' )
        {
            if ( ! (prevc == SPACE || prevc == '\t' || prevc == '\n') )
            {
                ++words[num_chars];

                if ( num_chars > biggest )
                {
                    biggest = num_chars;
                }
            }

            num_chars = 0;
        }
        else
        {
            num_chars++;
        }

        prevc = c;
    }

    /* print the histogram */
    for (i=1; i<=biggest; ++i)
    {
        printf("%3d | ", i);

        for (c=0; c<words[i]; ++c)
        {
            putchar('#');
        }

        putchar('\n');
    }
}

