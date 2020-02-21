/*
 * Name: Abhijit Parida		Date: 17-02-17
 * Program Description: To use Newton's method to find the root of an equation
 * Input: values of c and n
 * Output: nth root of c
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define ERROR 1E-6	/* Error tolerance */
#define MAX_TRIALS 100	/* Maximum number of iterations to perform */

double f(double x, int n, int c);
double f2(double x, int n);

int main(void)
{
	int n;		/* Value of n - input by user */
	int c;		/* Value of c - input by user */
	double x;	/* Approximate value of the nth root of c */
	double x_prev;	/* Previous value of x */
	int i;		/* Number of iterations */

	/* Get values of n and c */
	printf("Enter value of n: ");
	scanf("%d", &n);
	printf("Enter value of c: ");
	scanf("%d", &c);

	/* Use c/2 as initial guess */
	x = c/2;

	x_prev = 0;
	i = 0;

	/* Approximate nth root of c correct to 6 decimal places, or
	terminate after 100 trials */
	while (fabs(x - x_prev) > ERROR && i < MAX_TRIALS) {
		x_prev = x;
		x = x - f(x, n, c) / f2(x, n);
		i++;
	}

	/* Display result */
	printf("nth root of c = %f\n", x);
}

/*
 * Returns value of f(x) = x^n - c
 */
double f(double x, int n, int c)
{
	return pow(x, n) - c;
}

/*
 * Returns value of f'(x) = n * x^(n-1)
 */
double f2(double x, int n)
{
	return n * pow(x, n-1);
}
