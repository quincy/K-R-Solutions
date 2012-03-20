/* K&R Exercise 1-16 p.30 */

#include <stdio.h>
#define MAXLINE 1000    /* maximum input line */

int getline(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
int main()
{
    int len;                /* current line length */
    int max;                /* maximum length see so far */
    char line[MAXLINE];     /* current input line */
    char longest[MAXLINE];  /* longest line saved here */

    max = 0;

    while ( (len = getline(line, MAXLINE)) > 0 )
    {
        if ( len > max )
        {
            max = len;
            copy(longest, line);
        }
    }

    /* there was a line */
    if ( max > 0 )
    {
        printf("Longest line was %d characters.\n", max);
        printf("%s\n", longest);
    }

    return 0;
}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
    int c, i;

    for ( i=0; (c = getchar()) != EOF && c != '\n'; ++i )
    {
        if ( i < lim-2 )
        {
            s[i] = c;
        }
    }

    if ( c == '\n' )
    {
        s[lim-2] = c;
        ++i;
    }

    s[lim-1] = '\0';
    return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;

    i = 0;

    while ( (to[i] = from[i]) != '\0' )
    {
        ++i;
    }
}


