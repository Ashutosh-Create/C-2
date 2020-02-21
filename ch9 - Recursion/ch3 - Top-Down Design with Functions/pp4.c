/*
 * Name: Abhijit Parida 	Date: 13-01-17
 * Program Description: To use Gosper's formula to find the approximate
 *		factorial of an integer
 * Constant: PI
 * Input: N
 * Output: factorial of N
 * Algorithm:
 *	1. Get the value of N
 *	2. Calculate the approximate factorial of N using Gosper's formula
 *	3. Display the factorial
 */

#include <stdio.h>
#include <math.h>

#define PI 3.14159265

int
main(void)
{
	int N;		/* Value of N input by user */
	double i1, i2;	/* Intermediate variables */
	double fact;	/* Approximate factorial of N */

	/* Get the value of N */
	printf("Enter the value of N: ");
	scanf("%d", &N);

	/* Calculate the approximate factorial of N */
	i1 = 2 * N + 1.0 / 3.0;
	i2 = sqrt(i1 * PI);
	fact = pow(N, N) * exp(-N) * i2;

	/* Display the factorial */
	printf("%d! equals approximately %f\n", N, fact);

	return (0);
}
