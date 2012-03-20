/* K&R Exercise 2-7 p. 49 */

/* Write a function invert(x,p,n) that returns x with the n bits 
 * that begin at position p inverted (i.e., 1 changed into 0 and vice versa), leaving
 * the others unchanged. */

#include <stdio.h>

int invert(int x, int p, int n);

int main()
{
    int num = 0xF5F;
    printf("num = 0x%x\n", num);

    num = invert(num, 7, 4);
    printf("num = 0x%x\n", num);
}

int invert(int x, int p, int n)
{
    return x ^ (((1 << n) - 1) << p-n+1);
}

