/* K&R Exercise 2-6 p. 49 */

/* Write a function setbits(x,p,n,y) that returns x with the n 
 * bits that begin at position p set to the rightmost n bits of y, leaving the other 
 * bits unchanged. */

#include <stdio.h>

int setbits(int x, int p, int n, int y);

int main()
{
    int num = 0xFFF;
    printf("num = 0x%x\n", num);

    num = setbits(num, 7, 4, 0xFFF5);
    printf("num = 0x%x\n", num);
}

/* Sets the n bits in x beginning with bit p to the right most
 * n bits in y and returns the resulting x. */
int setbits(int x, int p, int n, int y)
{
    /* Mask off only the wanted bits from y and move them into the correct 
     * position. */
    int mask = (1 << n) - 1;
    y = (y & mask) << (p-n+1);

    /* Clear all bits in x in the area to set. */
    mask = ~(((1 << n) - 1) << (p-n+1));
    x &= mask;

    /* Set the bits and return the result. */
    return x | y;
}

