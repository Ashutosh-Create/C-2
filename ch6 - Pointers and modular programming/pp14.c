/*
 * Program description: To approximate the value of e
 * Output: Various approximations of e and the value of e calculated by
 *      the exp() function
 */

#include <stdio.h>
#include <math.h>

#define ERROR 0.000001

double approximate_e(int x);

int
main(void)
{
    int x;              /* Value of x: 1, 2, 3... */
    double e_actual;    /* Actual value of e calculated by exp() */
    double e_approx;    /* Approximate value of e */
    double diff;        /* Difference between actual and approx values */

    e_actual = exp(1);

    x = 1;
    e_approx = approximate_e(x);
    diff = fabs(e_actual - e_approx);
    while (diff > ERROR) {
        printf("For x = %d, approx value of e = %f\n", x, e_approx);
        e_approx = approximate_e(++x);
        diff = fabs(e_actual - e_approx);
    }

    printf("Actual value of e = %f\n", e_actual);
    printf("For x = %d, approx value of e = %f\n", x, e_approx);

    return (0);
}

/*
 * Approximates the value of e as given by the expression
 *      e = ((2x + 1) / (2x - 1)) ^ x
 */
double
approximate_e(int x)
{
    return pow((2 * x + 1) / (double) (2 * x - 1), x);
}
