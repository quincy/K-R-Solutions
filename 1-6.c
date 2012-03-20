/* K&R exercise 1-6 p 17 */

#include <stdio.h>

int main()
{
    int c;

    while (c = getchar() != EOF)
    {
        putchar(c);
        printf("%d", c);
    }
    printf(">%d\n", c);
}

