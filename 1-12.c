/* K&R Exercise 1-12 p. 21 */

#include <stdio.h>

int main()
{
    int c, prevc;

    while ( (c = getchar()) != EOF )
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            if (!(prevc == ' ' || prevc == '\n' || prevc == '\t'))
            {
                putchar('\n');
            }
        }
        else
        {
            putchar(c);
        }

        prevc = c;
    }
}

