/* K&R Exercise 1-18 p.31 */

#include <stdio.h>
#define MINLINE 81      /* minimum length to be printed */
#define SPACE ' '
#define TAB   '\t'

int getline(char line[], int maxline);

/* print longest input line */
int main()
{
    int len;                /* current line length */
    char line[MINLINE];     /* current input line */

    while ( (len = getline(line, MINLINE)) > 0 )
    {
        /* Nothing to do but read the next line */
    }

    return 0;
}

/* getline: Read the next line one char at a time.  Print the line
 * but strip off any trailing spaces or tabs.  If the char is not a tab
 * or a space it gets printed.  If it is a tab or a space it only gets 
 * printed if a non-whitespace character is encountered later. 
 *
 * The whitespace characters are stored in the array s until it is 
 * determined whether they should be printed or not.
 */
int getline(char s[], int lim)
{
    int c, i, k;
    int j = 0;

    for ( i=0; (c = getchar()) != EOF && c != '\n'; ++i )
    {
        if ( c == SPACE || c == TAB )
        {
            s[j] = c;
            ++j;
        }
        else
        {
            /* If there are whatespace chars waiting to be printed they
             * need to be printed before we print the next char. */
            if ( j > 0 )
            {
                for ( k=0; k<j; ++k )
                {
                    putchar(s[k]);
                }

                j = 0;
            }

            putchar(c);
        }
    }

    /* If the only thing on the line was a newline char then we ignore it. */
    if ( c == '\n' && i == 0 )
    {
        return ++i;
    }
    else if ( c == '\n' && i > 0 )
    {
        putchar(c);
        ++i;
    }

    return i;
}

