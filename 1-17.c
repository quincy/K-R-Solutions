/* K&R Exercise 1-17 p.31 */

#include <stdio.h>
#define MINLINE 81      /* minimum length to be printed */

int getline(char line[], int maxline);
void printline(char line[]);

/* print longest input line */
int main()
{
    int len;                /* current line length */
    char line[MINLINE];     /* current input line */

    while ( (len = getline(line, MINLINE)) > 0 )
    {
        if ( len >= MINLINE-1 )
        {
            printline(line);
        }
    }

    return 0;
}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
    int c, i;

    for ( i=0; i<lim-1 && (c = getchar()) != EOF && c != '\n'; ++i )
    {
        s[i] = c;
    }

    if ( c == '\n' )
    {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}

/* Prints the portion of the line stored in line and then reads the rest of
 * the line in and prints. */
void printline(char line[])
{
    char c;

    printf("%s", line);

    if ( line[MINLINE-1] == '\n' )
    {
        return;
    }

    while ( (c = getchar()) != EOF )
    {
        putchar(c);

        if ( c== '\n' )
        {
            return;
        }
    }
}

