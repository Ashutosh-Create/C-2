/*
 * Program Description: To approximate the square root of n
 * Input: n
 * Output: square root of n
 */

#include <stdio.h>

#define ERROR 0.005

void squareroot(double n, double *root);

int
main(void)
{
    double n;       /* Number input by user */
    double root;    /* Square root of n */

    printf("Enter value of n: ");
    scanf("%lf", &n);

    squareroot(n, &root);
    printf("squareroot(%.4f) = %.4f\n", n, root);

    return (0);
}

/*
 * Calculates the square root of n
 */
void
squareroot(double n, double *root)
{
    double last_guess;      /* Last square root guess */
    double next_guess;      /* Next square root guess */
    double diff;            /* Difference between guesses */

    /* Initial guess = 1.0 */
    next_guess = 1.0;

    do {
        last_guess = next_guess;
        next_guess = 0.5 * (last_guess + (n / last_guess));
        diff = last_guess - next_guess;
        diff = (diff < 0.0) ? -diff : diff;
    } while (diff > ERROR);

    *root = next_guess;
}
