/* K&R Exercise 1-19 p.31 */

#include <stdio.h>
#define MAXLINE 1000      /* minimum length to be printed */

int getline(char line[], int maxline);
void reverse(char s[], int len);

/* print longest input line */
int main()
{
    int len;                /* current line length */
    char line[MAXLINE];     /* current input line */

    while ( (len = getline(line, MAXLINE)) > 0 )
    {
        reverse(line, len);
        printf("%s", line);
    }

    return 0;
}

int getline(char s[], int lim)
{
    int c, i, k;
    int j = 0;

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

void reverse(char s[], int len)
{
    int i;
    int j = 0;
    char r[len+1];

    for ( i=len-1; i>=0; --i )
    {
        r[j] = s[i];
        ++j;
    }

    r[j] = '\0';
    
    for ( i=0; i<len+1; ++i )
    {
        s[i] = r[i];
    }
}

