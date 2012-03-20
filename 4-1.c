/* K&R Exercise 4-1 p. 71 */

/* Write the function strrindex(s, t) which returns the position of the
 * rightmost occurrence of t in s, or -1 if there is none.
 */

#include <stdio.h>

int strrindex(char *s, char t);

int main(int argc, char *argv[])
{
    int pos;

    if (argc != 3)
    {
        printf("Usage: 4-1 [string] [char]\n");
        return 1;
    }
    else
    {
        pos = strrindex(argv[1], argv[2][0]);
        
        if (pos != -1)
        {
            printf("Char '%c' found at position %d.\n", argv[2][0], pos);
        }
        else
        {
            printf("Char '%c' not found in string [%s].\n", argv[2][0], argv[1]);
        }
    }

    return 0;
}

/*
 * Find the rightmost occurrence of t in the string s.
 *
 * @param s the string to search.
 * @param t the char to look for.
 *
 * @return the last position of t; -1 if not found.
 */
int strrindex(char *s, char t)
{
    int pos = -1;
    int i;

    for (i=0; s[i] != '\0'; ++i)
    {
        if (s[i] == t)
        {
            pos = i;
        }
    }

    return pos;
}

