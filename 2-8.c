/* K&R Exercise 2-8 p. 49 */

/* Write a function rightrot(x,n) that returns the value of the 
 * integer x rotated to the right by n bit positions. */

#include <stdio.h>

int rightrot(int x, int n);

int main()
{
    int num = 0xF;
    printf("num = 0x%x\n", num);
    num = rightrot(num, 4);

    printf("num = 0x%x\n", num);
}

int rightrot(int x, int n)
{
    int mask = (1 << n) - 1;

    return ( ( x & mask ) << (32-n) ) ^ ( x >> n );
}


