/* K&R exercise 1-8 p. 20 */

#include <stdio.h>

int main()
{
    long space_count, tab_count, newline_count;
    int c;

    space_count   = 0;
    tab_count     = 0;
    newline_count = 0;

    while ((c = getchar()) != EOF)
    {
        switch(c)
        {
            case '\t': tab_count++;     break;
            case '\n': newline_count++; break;
            case ' ' : space_count++;   break;
            default  : break;
        }
    }

    printf("spaces    : %ld\n", space_count);
    printf("tabs      : %ld\n", tab_count);
    printf("new lines : %ld\n", newline_count);
}
