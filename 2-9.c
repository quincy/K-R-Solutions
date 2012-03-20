/* K&R Exercise 2-9 p. 51 */

/* In a two's complement number system, x &= (x-1) deletes the
 * rightmost 1-bit in x.  Explain why.  Use this observation to write a faster
 * version of bitcount. 
 *
 * Explanation
 * Let's say x has a value of 7.  In 4-bit binary this is 0111.  In one's complement
 * we invert every bit to get a value of 1000.  Then we add 1 to get the two's 
 * complement which gives us a value os 1001.
 *
 * Therefore, x &= (x-1) using the two's complement values looks like this:
 *
 *      1001  (x)
 *    & 1010  (x-1)  
 *    = 1000  (result)
 *
 * For any x, the two's complement of x and (x-1) will only differ by the 
 * position of the rightmost 1-bit.  Neither bit will survive the AND logic
 * and so the the rightmost 1 will be erased leaving the rest of the digits
 * intact.
 * */

#include <stdio.h>

int bitcount(unsigned int x);

int main()
{
    int num = 7;
    printf("There are %d 1-bits in %d.\n", bitcount(num), num);
}

int bitcount(unsigned int x)
{
    int count = 0;

    while (x != 0)
    {
        x &= (x-1);
        count++;
    }

    return count;
}


