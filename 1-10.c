/* K&R exercise 1-10 p. 20 */

#include <stdio.h>

#define TAB       '\t'
#define BACKSLASH '\\'
#define BACKSPACE '\b'

int main()
{
    int c;

    while ( (c = getchar()) != EOF )
    {
        switch(c)
        {
            case TAB:
                printf("\\t");
                break;
            case BACKSLASH:
                printf("\\");
                break;
            case BACKSPACE:
                printf("\\b");
                break;
            default:
                printf("%c", c);
                break;
        }
    }
}

