/* K&R Exercise 1-5 p. 14 */

#include <stdio.h>

/* print Fahrenheit-Celsius table
 * for fahr = 300, 280, ..., 20, 0; floating-point version */

int main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;      /* lower limit of temperature table */
    upper = 300;    /* upper limit */
    step  = 20;     /* step size */

    printf("%3s %6s\n", "'F", "'C");
    printf("%3s %6s\n", "---", "-----");

    fahr = upper;
    while (fahr >= lower)
    {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr -= step;
    }
}

