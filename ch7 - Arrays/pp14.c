/*
 * Program Description: To evaluate a polynomial at a given value of x
 * Input: degree and coefficients of polynomial, value of x
 * Output: value of polynomial at x
 */

#include <stdio.h>

#define MAX_DEGREE 8

void get_poly(double coeff[], int *degreep);
double eval_poly(const double coeff[], int degree, double x);

int
main(void)
{
    int degree;                         /* Degree of polynomial */
    double polynomial[MAX_DEGREE+1];    /* Array of coefficients */
    double x;                           /* Value of x to evaluate polynomial */
    double result;                      /* Value of polynomial at x */

    /* Get the polynomial */
    get_poly(polynomial, &degree);

    /* Get the value of x */
    printf("Enter value of x to evaluate polynomial: ");
    scanf("%lf", &x);

    /* Evaluate the polynomial at x and display result */
    result = eval_poly(polynomial, degree, x);
    printf("Value of the polynomial at x = %.4f is %.4f\n", x, result);

    return (0);
}

/*
 * Fills coeff[] array with real coefficients and sets the degree of
 * the polynomial
 */
void
get_poly(double coeff[], int *degreep)
{
    int i;              /* Loop index */

    printf("Enter degree of polynomial (max %d): ", MAX_DEGREE);
    scanf("%d", degreep);

    printf("Enter real coefficients separated by spaces:\n");
    for (i = 0; i <= *degreep; i++) {
        scanf("%lf", &coeff[i]);
    }
}

/*
 * Returns the value of the polynomial at x
 */
double
eval_poly(const double coeff[], int degree, double x)
{
    int n;              /* Power of coefficients */
    double xn;          /* x raised to the power n */
    double result;      /* Value of polynomial at x */

    result = 0;
    xn = 1;
    for (n = 0; n <= degree; n++) {
        result += coeff[n] * xn;
        xn *= x;
    }

    return result;
}
