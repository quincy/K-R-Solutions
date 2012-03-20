/* K&R Exercise 3-2 p. 60 */

/* Write a function escape(s,t) that converts characters like 
 * newline and tab into visible escape sequences like \n and \t
 * as it copies the string t to s.  Use a switch.  Write a function
 * for the other direction as well, converting escape sequences into
 * real characters. */

#include <stdio.h>

void escape(char s[], char t[]);
void unescape(char s[], char t[]);

int main()
{
    char sentence[] = "There are tabs\t\tembedded in this sentence.  \\As well as newlines\n\nand one \b backspace.";
    char new[1000];

    printf("ORIGINAL\n%s\n", sentence);
    escape(new, sentence);
    printf("ESCAPED\n%s\n", new);
    unescape(sentence, new);
    printf("UNESCAPED\n%s\n", sentence);
}

void escape(char s[], char t[])
{
    int i = 0;  /* index in t */
    int j = 0;  /* index in s */
    
    while (t[i] != '\0')
    {
        switch(t[i])
        {
            case '\n':
                s[j++] = '\\';
                s[j]   = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j]   = 't';
                break;
            case '\b':
                s[j++] = '\\';
                s[j]   = 'b';
                break;
            default:
                s[j] = t[i];
                break;
        }

        ++i;
        ++j;
    }

    s[j] = '\0';
}

void unescape(char s[], char t[])
{
    int i = 0;  /* index in t */
    int j = 0;  /* index in s */
    
    while (t[i] != '\0')
    {
        switch(t[i])
        {
            case '\\':
                ++i;
                if (t[i] == 'n')
                {
                    s[j] = '\n';
                }
                else if (t[i] == 't')
                {
                    s[j] = '\t';
                }
                else if (t[i] == 'b')
                {
                    s[j] = '\b';
                }
                else
                {
                    s[j] = '\\';
                    --i;
                }
                break;
            default:
                s[j] = t[i];
                break;
        }

        ++i;
        ++j;
    }

    s[j] = '\0';
}


