/* K&R Exercise 1-20 p.34 
 *
 * Write a program detab that replaces tabs in the input with the proper number
 * of blanks to space to the next tab stop.  Assume a fixed set of tab stops, 
 * say every n columns.  Should n be a variable or a symbolic parameter?
 */

#include <stdio.h>

#define TAB_WIDTH 8
#define TAB '\t'
#define SPACE ' '
#define NEWLINE '\n'

int main()
{
    int i, j, n;
    int c;

    for ( i=0; (c = getchar()) != EOF; ++i )
    {
        n = i;

        if ( c == TAB )
        {
            /* Find the next tab stop and store in n */
            while ( (n % TAB_WIDTH) != 0 )
            {
                ++n;
            }

            /* If n is 0 we need to move to the first tab stop */
            if ( n == 0 )
            {
                n = TAB_WIDTH;
            }

            /* Print a number of spaces equal to the difference between the
             * current char position and the next tab stop. */
            for ( j=0; j<n-i; ++j )
            {
                putchar(SPACE);
            }
        }
        /* Reset the current char position if there is a newline */
        else if ( c == NEWLINE )
        {
            putchar(c);
            i = -1;
        }
        else
        {
            putchar(c);
        }
    }
}

