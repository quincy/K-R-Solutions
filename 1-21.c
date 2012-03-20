/* K&R Exercise 1-21 p.34 
 *
 * Write a program entab that replaces strings of blanks by the proper number
 * of tabs and blanks to achieve the same spacing.  Use the same tab stops as 
 * for detab.  When either a tab or a single space would suffice to reach a 
 * tab stop,                            which should be given preference?
 */

#include <stdio.h>

#define TAB_WIDTH 8
#define TAB '\t'
#define SPACE ' '
#define NEWLINE '\n'

void entab(int);

int main()
{
    int i, j, c;
    int n = 0;

    for ( i=0; (c = getchar()) != EOF; ++i )
    {
        if ( c == SPACE )
        {
            ++n;
        }
        /* Reset the current char position if there is a newline */
        else if ( c == NEWLINE )
        {
            entab(n);
            putchar(c);
            n = 0;
            i = -1;
        }
        else
        {
            entab(n);
            putchar(c);
            n = 0;
        }
    }
}

void entab(int n)
{
    while ( n >= TAB_WIDTH )
    {
        putchar(TAB);
        n -= TAB_WIDTH;
    }

    while ( n > 0 )
    {
        putchar(SPACE);
        --n;
    }
}

