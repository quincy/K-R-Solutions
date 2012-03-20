/* K&R Exercise 1-23 p.34 
 *
 * Write a program to remove all comments from a C program.
 * Don't forget to handle quoted strings and character constants properly.
 * C comments do not nest.
 */

#include <stdio.h>

#define SLASH      '/'
#define STAR       '*'
#define APOSTROPHE '\''
#define QUOTE      '"'
#define BACKSLASH  '\\'

int main()
{
    int c;
    char prev = '\0';
    int state = 0;

    while ( (c = getchar()) != EOF )
    {
        switch (state)
        {
            /* Not in a comment, string, or char constant; haven't seen a SLASH. */
            case 0: 
                if ( c == SLASH )
                {
                    state = 1;
                }
                else if ( c == APOSTROPHE )
                {
                    state = 4;
                    putchar(c);
                }
                else if ( c == QUOTE )
                {
                    state = 5;
                    putchar(c);
                }
                else
                {
                    putchar(c);
                }
                prev = c;
                break;
            /* Not in a comment, previous char was a SLASH. */
            case 1: 
                if ( c == STAR )
                {
                    state = 2;
                }
                else
                {
                    putchar(prev);
                    putchar(c);
                    state = 0;
                }
                prev = c;
                break;
            /* Inside a comment, haven't seen a STAR. */
            case 2: 
                if ( c == STAR )
                {
                    state = 3;
                }
                prev = c;
                break;
            /* Inside a comment, previous char was a STAR. */
            case 3:
                if ( c == SLASH )
                {
                    state = 0;
                }
                prev = c;
                break;
            /* Inside a char constant. */
            case 4:
                if ( c == APOSTROPHE && prev != BACKSLASH )
                {
                    state = 0;
                }
                putchar(c);
                prev = c;
                break;
            /* Inside a quoted string. */
            case 5:
                if ( c == QUOTE && prev != BACKSLASH )
                {
                    state = 0;
                }
                putchar(c);
                prev = c;
                break;
            /* Invalid state. */
            default:
                break;
        }
    }
}

