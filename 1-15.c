/* K&R Exercise 1-15 p. 27 */

#include <stdio.h>

/* print Fahrenheit-Celsius table
 * for fahr = 0, 20, ..., 300; floating-point version */

float ftoc(float fahr);

int main()
{
    float fahr;
    int lower, upper, step;

    lower = 0;      /* lower limit of temperature table */
    upper = 300;    /* upper limit */
    step  = 20;     /* step size */

    printf("%3s %6s\n", "'F", "'C");
    printf("%3s %6s\n", "---", "-----");

    fahr = lower;
    while (fahr <= upper)
    {
        printf("%3.0f %6.1f\n", fahr, ftoc(fahr));
        fahr = fahr + step;
    }
}

/*
 * Convert temperature in Fahrenheit to Celsius.
 *
 * @param fahr the temperature in Fahrenheit.
 * @return the temperature in Celsius.
 */
float ftoc(float fahr)
{
    return (5.0 / 9.0) * (fahr - 32.0);
}

