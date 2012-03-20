/* K&R Exercise 3-1 p. 58 */

/* Our binary search makes two tests inside the loop, when one
 * would suffice (at the price of more tests outside).  Write a
 * version with only one test inside the loop and measure the 
 * difference in run-time. */

#include <stdio.h>

#define LENGTH 100000

int binsearch(int x, int v[], int n);
int binsearch2(int x, int v[], int n);

int ops1 = 0;    /* The number of operations performed by the binsearch loop */
int ops2 = 0;    /* The number of operations performed by the binsearch2 loop */

int main()
{
    extern int ops1, ops2;
    int a[LENGTH];
    int s = 1;
    int i,j;

    for (i=0; i<LENGTH; ++i)
    {
        a[i] = i+1;
    }

    i = binsearch(s, a, LENGTH);
    j = binsearch2(s, a, LENGTH);

    switch(i)
    {
        case -1: 
            printf("binsearch: Could not find %d in array!  (%d operations were performed)\n", s, ops1); 
            break;
        default: 
            printf("binsearch: Found %d at index %d.  (%d operations were performed)\n", s, i, ops1); 
            break;
    }

    switch(j)
    {
        case -1: 
            printf("binsearch2: Could not find %d in array!  (%d operations were performed)\n", s, ops2); 
            break;
        default: 
            printf("binsearch2: Found %d at index %d.  (%d operations were performed)\n", s, i, ops2); 
            break;
    }
}

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
    extern int ops1;
    int low, high, mid;

    low  = 0;
    high = n-1;

    while (low <= high)
    {
        ++ops1;
        mid = (low+high) / 2;

        if (x < v[mid])
        {
            ++ops1;
            high = mid - 1;
        }
        else if (x > v[mid])
        {
            ++ops1;
            low = mid + 1;
        }
        else
        {
            return mid;
        }
    }

    return -1;  /* no match */
}

/* binsearch2: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch2(int x, int v[], int n)
{
    extern int ops2;
    int low, high, mid;

    low  = 0;
    high = n-1;

    while (low <= high)
    {
        ++ops2;
        mid = (low+high) / 2;

        if (x < v[mid])
        {
            ++ops2;
            high = mid - 1;
        }
        else
        {
            ++ops2;
            low = mid + 1;
        }
    }

    if (x == mid)
    {
        return mid;
    }
    else
    {
        return -1;  /* no match */
    }
}

