/* K&R Exercise 3-3 p. 63 */

/* Write a function expand(s1,s2) that expands shorthand notation
 * like a-z in the string s1 into the equivalent complete list
 * abc...xyz in s2.  Allow for letters of either case and digits,
 * and be prepared to handle cases like a-b-c and a-z0-9 and -a-z.
 * Arrange that a leading - is taken literally. 
 */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void expand(char *s1, char *s2);

int main()
{
    char str1[]     = "String expansion\na-z\nA-Z\n0-9\na-b-z\na-z0-9\n-a-z\na--z.\n";
    char str2[1000] = "";

    expand(str1, str2);

    printf("STRING 1\n%s", str1);
    printf("\nSTRING 2\n%s", str2);

    return 0;
}

/* Expands shorthand notation like a-z and 0-9 into the complete list of characters.
 * This function uses a three state DFA (finite state machine).  
 *
 * State 0 is the state where the current string has not been recognized as a 
 * potential for expansion.  
 *
 * State 1 is the state where it is recognized that an alphnum character has been 
 * followed by a '-', and therefore expansion may be required on the next char.
 *
 * State 2 is the state where it is recognized that a expansion string has
 * been found.  Expansion is performed when entering this state.
 */
void expand(char *s1, char *s2)
{
    int c, i, j, k;
    int state = 0;

    for (i=0, j=0, c=s1[i]; c != '\0'; c = s1[++i])
    {
        switch (state)
        {
            case 0:
                /* This char is not a '-' so we need to copy the previous 
                 * char to the new string. */
                if (c != '-')
                {
                    s2[j++] = c;
                }
                /* This char is a - not preceded by an alphnum so need to
                 * copy the previous char to the new string. */
                else if (c == '-' && ! isalnum(s1[i-1]))
                {
                    s2[j++] = c;
                }
                /* This char is a - preceded by an alphnum.  Enter state 1. */
                else
                {
                    state = 1;
                }
                break;
            case 1:
                /* The char is an alphnum so an expansion string has been found.
                 * Enter state 2.  Expand the expansion string and copy the
                 * chars to the new string. */
                if (isalnum(c))
                {
                    state = 2;

                    for (k=(s1[i-2])+1; k<=c; ++k)
                    {
                        s2[j++] = k;
                    }
                }
                /* An expansion string was not realized.  Return to state 0.  Copy
                 * the previous two characters, the - and this character, to the 
                 * new string. */
                else
                {
                    state   = 0;
                    s2[j++] = s1[i-1];
                    s2[j++] = s1[i];
                }
                break;
            case 2:
                /* A - at this point may signify a more complicated expansion string
                 * like a-c-z.  Return to state 1. */
                if (c == '-')
                {
                    state = 1;
                }
                /* Any other character signals a return to state 0. */
                else
                {
                    state = 0;
                    s2[j++] = c;
                }
                break;
            /* We should never be able to reach this condition. */    
            default: 
                fprintf(stderr, "Unexpected state!\n");
                exit(1);
        }
    }
}

