/*
 * Program Description: To find roots of g(x) and h(X) using bisection method.
 * Input: interval endpoints, error tolerance
 * Output: roots of g(x) = 5x^3 - 2x^2 + 3 and h(x) = x^4 - 3x^2 - 8
 */

#include <stdio.h>
#include <math.h>

#define FALSE 0
#define TRUE 1
#define NO_ROOT -0

double bisect(double x_left, double x_right, double epsilon,
    double f(double farg));
double find_root(double x_left, double x_right, double epsilon,
    double f(double farg));
double g(double x);
double h(double x);

int
main(void)
{
    double x_left, x_right;     /* left, right endpoints of interval */
    double epsilon;             /* error tolerance */
    double root;

    /* Get endpoints and error tolerance from user */
    printf("\nEnter interval endpoints> ");
    scanf("%lf%lf", &x_left, &x_right);
    printf("\nEnter tolerance> ");
    scanf("%lf", &epsilon);

    /* Use bisect function to look for roots of g */
    printf("\n\nFunction g");
    root = bisect(x_left, x_right, epsilon, g);
    if (root != NO_ROOT) {
        printf("\n g(%.7f) = %e\n", root, g(root));
    }

    /* Use bisect function to look for roots of h */
    printf("\n\nFunction h");
    root = bisect(x_left, x_right, epsilon, h);
    if (root != NO_ROOT) {
        printf("\n h(%.7f) = %e\n", root, h(root));
    }

    return (0);
}

/*
 * Returns a root if signs of fp(x_left) and fp(x_right) are different.
 * Otherwise returns NO_ROOT.
 * Pre: x_left, x_right - endpoints of interval, epsilon - error tolerance,
 *      f() - the functions
 */
double
bisect(double x_left, double x_right, double epsilon, double f(double farg))
{
    double f_left;  /* f(x_left) */
    double f_right; /* f(x_right) */

    /* Compute function values at initial endpoints of interval */
    f_left = f(x_left);
    f_right = f(x_right);

    /* If no change of sign occurs on the interval there is not a
    unique root. Exit function and return NO_ROOT */
    if (f_left * f_right > 0) {
        printf("\nMay be no root in [%.7f, %.7f]", x_left, x_right);
        return NO_ROOT;
    }

    return (find_root(x_left, x_right, epsilon, f));
}

/*
 * Returns root of f() using bisection method
 */
double
find_root(double x_left, double x_right, double epsilon, double f(double farg))
{
    double x_mid;   /* midpoint of interval */
    double f_left;  /* f(x_left) */
    double f_mid;   /* f(x_mid) */
    double f_right; /* f(x_right) */

    /* Compute function values at initial endpoints of interval */
    f_left = f(x_left);
    f_right = f(x_right);

    /* If there is a root, it is the midpoint of [x_left, x_right] */
    if (fabs(x_right - x_left) < epsilon) {
        return ((x_left + x_right) / 2.0);
    }

    /* Computes midpoint and function value at midpoint */
    x_mid = (x_left + x_right) / 2.0;
    f_mid = f(x_mid);

    if (f_mid == 0) {
        printf("\nRoot found at x = %.7f, midpoint of [%.7f, %.7f]", x_mid,
            x_left, x_right);
        return (x_mid);
    }

    /* Searches as long as interval size is large enough
    and no root has been found */

    f_left = f(x_left);
    f_right = f(x_right);

    if (f_left * f_mid < 0) {
        printf("\nNew interval is [%.7f, %.7f]", x_left, x_mid);
        return (find_root(x_left, x_mid, epsilon, f));
    } else {
        printf("\nNew interval is [%.7f, %.7f]", x_mid, x_right);
        return (find_root(x_mid, x_right, epsilon, f));
    }
}

/*
 * Returns value of g(x) = 5x^3 - 2x^2 + 3
 */
double
g(double x)
{
    return (5 * pow(x, 3.0) - 2 * pow(x, 2.0) + 3);
}

/*
 * Returns value of h(x) = x^4 - 3x^2 - 8
 */
double
h(double x)
{
    return (pow(x, 4.0) - 3 * pow(x, 2.0) - 8);
}
