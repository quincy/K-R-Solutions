/* K&R Exercise 1-9 p. 20 */

#include <stdio.h>

#define SPACE ' '  /* a space literal */

int main()
{
    int c;
    int prevc;

    while ( (c = getchar()) != EOF )
    {
        switch(c)
        {
            case SPACE:
                if ( prevc == SPACE )
                {
                    break;
                }
                printf("%c", c);
                prevc = c;
                break;
            default:
                printf("%c", c);
                prevc = c;
                break;
        }
    }
}

