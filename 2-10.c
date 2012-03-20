/* K&R Exercise 2-10 p. 52 */

/* Rewrite the function lower, which converts upper case letters
 * to lwoer case, with a conditional expression instead of if-else. */

#include <stdio.h>

int lower(int c);

int main()
{
    char foo[] = "FOOBAR";
    int i;

    for (i=0; foo[i] != '\0'; ++i)
    {
        foo[i] = lower(foo[i]);
    }

    printf("%s\n", foo);
}

int lower(int c)
{
    return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c;
}

