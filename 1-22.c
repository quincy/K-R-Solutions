/* K&R Exercise 1-22 p.34 
 *
 * Write a program to "fold" long input lines into two or more
 * shorter lines after the last non-blank character that occurs before the n-th
 * column of input.  Make sure your program does something intelligent with very
 * long lines, and if there are no blanks or tabs before the specified column.
 */

#include <stdio.h>

#define LINE_LENGTH 80
#define TAB '\t'
#define SPACE ' '
#define NEWLINE '\n'

void entab(int);

int main()
{
    int i, j, c;
    int n = -1;     /* The last column with a space. */
    char buff[LINE_LENGTH + 1];

    for ( i=0; (c = getchar()) != EOF; ++i )
    {
        /* Save the SPACE to the buffer. */
        if ( c == SPACE )
        {
            buff[i] = c;
        }
        /* Save the character to the buffer and note its position. */ 
        else
        {
            n = i;
            buff[i] = c;
        }

        /* Print the line and reset counts if a NEWLINE is encountered. */
        if ( c == NEWLINE )
        {
            buff[i+1] = '\0';
            printf("%s", buff);

            n = -1;
            i = -1;
        }
        /* If the LINE_LENGTH was reached instead, then print up to the last
         * non-space character. */
        else if ( i == LINE_LENGTH - 1 )
        {
            buff[n+1] = '\0';
            printf("%s\n", buff);

            n = -1;
            i = -1;
        }
    }
}

