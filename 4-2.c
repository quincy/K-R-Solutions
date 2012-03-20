/* K&R Exercise 4-2 p. 73 */

/* Extend atof to handle scientific notation of the form
 *
 *      123.45e-6
 *
 * where a floating point number may be followed by e or E and an 
 * optionally signed exponent.
 */

#include <stdio.h>

double atof(char s[]);

int main(int argc, char *argv[])
{
    char s[] = "123.45e-6";
    char t[] = "123.45E-6";
    char u[] = "123.45e6";
    char v[] = "123.45E6";
    
    printf("%10s -> %25.15f\n", s, atof(s));
    printf("%10s -> %25.15f\n", t, atof(t));
    printf("%10s -> %25.15f\n", u, atof(u));
    printf("%10s -> %25.15f\n", v, atof(v));

    return 0;
}

/*
 * Convert a string to a double.
 *
 * atof can convert strings of the form 123.45e-6 to a double.  The exponent
 * marker e, can be lower case or upper case.  The exponent is optinally 
 * signed.
 *
 * @param s the string to convert to double.
 *
 * @return the double representation of the string s.
 */
double atof(char s[])
{
    double val, power;
    int i, sign, exponent, esign;

    /* Skip whitespace */
    for (i=0; isspace(s[i]); i++) {}

    /* Convert the sign if present. */
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') {i++;}

    /* Convert the whole number portion. */
    for (val = 0.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
    }
    if (s[i] == '.') {i++;}

    /* Convert the fractional portion.  power keeps track of the number of 
     * place values after the decimal. */
    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }

    /* Check for exponent marker. */
    exponent = 0.0;

    if (s[i] == 'e' || s[i] == 'E')
    {
        i++;

        /* Convert sign on the exponent. */
        esign = (s[i] == '-') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-') {i++;}

        /* Convert the exponent. */
        for (exponent = 0.0; isdigit(s[i]); i++)
        {
            exponent = 10.0 * exponent + (s[i] - '0');
        }
    }

    /* Return the converted value.  The position for the decimal point must be
     * calculated before returning.  Floats of the form 123.45e-6 will need
     * to be calculated slightly differently. */
    if (exponent)
    {
        val = val * sign / power;

        while (exponent)
        {
            if (esign == 1)
            {
                val *= 10.0;
            }
            else
            {
                val /= 10.0;
            }
            exponent--;
        }

        return val;
    }
    else
    {
        return sign * val / power;
    }
}

