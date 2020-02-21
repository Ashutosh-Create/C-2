/*
 * Name: Abhijit Parida		Date: 13-01-17
 * Program Description: To round off a positive number with fractional
 *		part to two decimal places
 * Input: Positive number with fractional part
 * Output: The number rounded off to two decimal places
 * Algorithm:
 *	1. Get a positive number with fractional part
 *	2. Round the number to two decimal places
 *	3. Display the result
 * Algorithm Refinements:
 *	2.1. round_N = ((int) (N * 100 + 0.5)) / 100.0
 */

#include <stdio.h>

int
main(void)
{
	double N;	/* A positive number input by user */
	double round_N;	/* N rounded off to two decimal places */

	/* Get a positive number with fractional part */
	printf("Enter a number with fractional part: ");
	scanf("%lf", &N);

	/* Round the number to two decimal places */
	round_N = ((int) (N * 100 + 0.5)) / 100.0;

	/* Display the result */
	printf("After rounding, the number is %f\n", round_N);

	return (0);
}
