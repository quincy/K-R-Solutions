/* K&R Exercise 2-1 p. 37 */

/* Write a program to determine the ranges of char, short, int,
 * and long variables, both signed and unsigned, by printing 
 * appropriate values from standard headers and by direct 
 * computation.  Harder if you compute them: determine the ranges
 * of the various floating-point types. */

#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>

int main()
{
    printf("Variable limits from headers:\n");
    printf("signed char        [%d, %d]\n", SCHAR_MIN, SCHAR_MAX);
    printf("unsigned char      [%d, %d]\n", 0,         UCHAR_MAX);
    printf("char               [%d, %d]\n", CHAR_MIN,  CHAR_MAX);
    printf("short int          [%d, %d]\n", SHRT_MIN,  SHRT_MAX);
    printf("unsigned short     [%d, %d]\n", 0,         USHRT_MAX);
    printf("int                [%d, %d]\n", INT_MIN,   INT_MAX);
    printf("unsigned int       [%d, %u]\n", 0,         UINT_MAX);
    printf("long int           [%d, %d]\n", LONG_MIN,  LONG_MAX);
    printf("unsigned long      [%d, %u]\n", 0,         ULONG_MAX);
}

