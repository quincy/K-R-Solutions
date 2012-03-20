/* K&R Exercise 2-2 p. 42 */

/* for (i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
 * {
 *     s[i] = c;
 * }
 *
 * Write a loop equivalent to the for loop above without using && or ||. 
 */

#include <stdio.h>

int main()
{
    int i, c;
    int lim = 1000;
    char s[lim];

    for (i=0; i<lim-1; ++i)
    {
        if ((c = getchar()) == '\n')
        {
            break;
        }

        if (c == EOF)
        {
            break;
        }

        s[i] = c;
    }

    s[i] = '\0';

    printf("%s\n", s);
}

