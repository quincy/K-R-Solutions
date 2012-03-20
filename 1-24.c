/* K&R Exercise 1-24 p.34 
 *
 * Write a program to check a C program for rudimentary syntax
 * errors like unbalanced parentheses, brackets, and braces.
 * Don't forget about quotes, both single and double, escape
 * sequences, and comments.  (This program is hard if you do it
 * in full generality.)
 */

#include <stdio.h>

#define MAXLINE  1000
#define MAXSTACK 1000
#define FALSE    0
#define TRUE     1

/* char constants */ 
#define SLASH                '/'
#define STAR                 '*'
#define APOSTROPHE           '\''
#define QUOTE                '"'
#define BACKSLASH            '\\'
#define SEMICOLON            ';'
#define LEFT_SQUARE_BRACKET  '['
#define RIGHT_SQUARE_BRACKET ']'
#define LEFT_PARENTHESIS     '('
#define RIGHT_PARENTHESIS    ')'
#define LEFT_CURLY_BRACKET   '{'
#define RIGHT_CURLY_BRACKET  '}'

/* global error flag */
int error = FALSE;

int getline(char s[], int lim);
char pop(char stack[], int *top);
void push(char stack[], char c, int *top);

int main()
{
    extern int error;

    int c, i, len;
    char prev = '\0';
    char line[MAXLINE];

    int line_num = 0;
    
    int in_comment = FALSE;
    int escaping   = FALSE;

    int ticks  = 0;
    int quotes = 0;

    char stack[MAXLINE];
    int top = 0; /* Points to the top of the stack. */

    /* read the input a line at a time */ 
    while ( ((len = getline(line, MAXLINE)) > 0) && (! error) )
    {
        ++line_num;

        /* examine each character one at a time */
        for ( c=0; c<len; ++c )
        {
            i = c+1;
            switch (line[c])
            {
                /* If a / then determine if it is part of an ending comment marker
                 * and set appropriate flag.  If it looks like an ending comment
                 * marker but we're not in a comment, error. */
                case SLASH:
                    if ( prev == STAR && in_comment )
                    {
                        in_comment = FALSE;
                    }
                    else if ( prev == STAR && ! in_comment )
                    {
                        error = TRUE;
                        printf("Unmatched ending comment marker at line %d, character %d.\n", line_num, i);
                        printf("%s", line);
                    }
                    else
                    {
                        /* do nothing */
                    }
                    if ( escaping )
                    {
                        escaping = FALSE;
                    }
                    break;
                /* If a * then determing if it is part of a beginning comment marker
                 * and set appropriate flag.  If it looks like a beginning comment
                 * marker but we're already in a comment, error. */
                case STAR:
                    if ( prev == SLASH && ! in_comment )
                    {
                        in_comment = TRUE;
                    }
                    else if ( prev == SLASH && in_comment )
                    {
                        error = TRUE;
                        printf("Attempt to nest comments at line %d, character %d.\n", line_num, i);
                        printf("%s", line);
                    }
                    else
                    {
                        /* do nothing */
                    }
                    if ( escaping )
                    {
                        escaping = FALSE;
                    }
                    break;
                /* Keep track of this ' if it is not escaped or quoted. */
                case APOSTROPHE:
                    if ( in_comment )
                    {
                        /* do nothing */
                    }
                    else if ( quotes == 0 && ticks == 0 )
                    {
                        ++ticks; /* start of a single quoted char */
                    }
                    else if ( quotes == 0 && ticks > 0 && ! escaping )
                    {
                        --ticks; /* end of a single quoted char */
                    }
                    else if ( quotes == 0 && ticks > 0 && escaping )
                    {
                        /* literal ' being escaped, do nothing */
                    }
                    else if ( quotes > 0 )
                    {
                        /* ignore tick in a quoted string */
                    }
                    else
                    {
                        printf("Unmatched ' at line %d, character %d.\n", line_num, i);
                        printf("%s", line);
                    }
                    if ( escaping )
                    {
                        escaping = FALSE;
                    }
                    break;
                /* Keep track of this " if it is not escaped or quoted. */
                case QUOTE:
                    if ( in_comment )
                    {
                        /* do nothing */
                    }
                    else if ( quotes == 0 && ticks == 0 )
                    {
                        ++quotes; /* start of a quoted string */
                    }
                    else if ( quotes == 0 && ticks > 0 )
                    {
                        /* this is a char constant so ignore */
                    }
                    else if ( quotes > 0 && prev == BACKSLASH ) 
                    {
                        /* ignore escaped quote in a string */
                    }
                    else if ( quotes > 0 && prev != BACKSLASH )
                    {
                        --quotes;
                    }
                    else
                    {
                        error = TRUE;
                        printf("Unmatched \" at line %d, character %d.\n", line_num, i);
                        printf("%s", line);
                    }
                    if ( escaping )
                    {
                        escaping = FALSE;
                    }
                    break;
                /* Set flags to keep track of whether the next character should be escaped. */
                case BACKSLASH:
                    if ( in_comment )
                    {
                        /* do nothing */
                    }
                    else if ( ! escaping && (quotes || ticks))
                    {
                        escaping = TRUE;
                    }
                    else if ( escaping )
                    {
                        escaping = FALSE;
                    }
                    break;
                /* All of the remaining cases deal with matched braces "(), [], and {}".
                 * When an opening brace is encountered it is pushed onto the stack. 
                 * When a closing brace is found the stack is popped and if the return 
                 * value is not the same type of brace we error. */
                case LEFT_SQUARE_BRACKET:
                    if ( ! (quotes || ticks || escaping || in_comment) )
                    {
                        push(stack, line[c], &top);
                    }
                    if ( escaping )
                    {
                        escaping = FALSE;
                    }
                    break;
                case RIGHT_SQUARE_BRACKET:
                    if ( ! (quotes || ticks || escaping || in_comment) )
                    {
                        if ( pop(stack, &top) != LEFT_SQUARE_BRACKET )
                        {
                            error = TRUE;
                            printf("Unmatched ] at line %d, character %d.\n", line_num, i);
                            printf("%s", line);
                        }
                    }
                    if ( escaping )
                    {
                        escaping = FALSE;
                    }
                    break;
                case LEFT_PARENTHESIS:
                    if ( ! (quotes || ticks || escaping || in_comment) )
                    {
                        push(stack, line[c], &top);
                    }
                    if ( escaping )
                    {
                        escaping = FALSE;
                    }
                    break;
                case RIGHT_PARENTHESIS:
                    if ( ! (quotes || ticks || escaping || in_comment) )
                    {
                        if ( pop(stack, &top) != LEFT_PARENTHESIS )
                        {
                            error = TRUE;
                            printf("Unmatched ) at line %d, character %d.\n", line_num, i);
                            printf("%s", line);
                        }
                    }
                    if ( escaping )
                    {
                        escaping = FALSE;
                    }
                    break;
                case LEFT_CURLY_BRACKET:
                    if ( ! (quotes || ticks || escaping || in_comment) )
                    {
                        push(stack, line[c], &top);
                    }
                    if ( escaping )
                    {
                        escaping = FALSE;
                    }
                    break;
                case RIGHT_CURLY_BRACKET:
                    if ( ! (quotes || ticks || escaping || in_comment) )
                    {
                        if ( pop(stack, &top) != LEFT_CURLY_BRACKET )
                        {
                            error = TRUE;
                            printf("Unmatched } at line %d, character %d.\n", line_num, i);
                            printf("%s", line);
                        }
                    }
                    if ( escaping )
                    {
                        escaping = FALSE;
                    }
                    break;
                default:
                    if ( escaping )
                    {
                        escaping = FALSE;
                    }
                    break;
            }

            prev = line[c];
        }
    }

    /* Summarize the results. */
    if ( quotes > 0 )
    {
        printf("Unmatched \"s were found.  %d\n", quotes);
    }
    if ( ticks > 0 )
    {
        printf("Unmatched 's were found.  %d\n", ticks);
    }
    if ( top )
    {
        for (c=0; c<top; ++c)
        {
            printf("Unmatched %c found.\n", stack[c]);
        }
    }
}

/* From K&R page 29. */
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

/* pop the top value from the stack and return it. */
char pop(char stack[], int *top)
{
    extern int error;
    char c;

    if ( *top > 0 )
    {
        --(*top);
        c = stack[*top];
        return c;
    }
    else
    {
        error = TRUE;
        printf("Cannot pop stack becuase it is empty!\n");
        return '\0';
    }
}

/* push the give value onto the stack. */
void push(char stack[], char c, int *top)
{
    extern int error;

    if (*top < MAXSTACK)
    {
        stack[*top] = c;
        ++(*top);
    }
    else
    {
        error = TRUE;
        printf("Cannot push stack because it is full!\n");
    }

    return;
}

