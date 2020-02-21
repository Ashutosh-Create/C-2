/*
 * Name: Abhijit Parida		Date: 17-02-17
 * Program Description: To compute and print in table form the amount of
 *	cobalt-60 isotope that remains after each year for 5 years
 * Input: initial amount
 * Output: amount left after each year for 5 years
 * Algorithm:
 *	1. Get initial amount of cobalt
 *	2. Calculate amount after each year for 5 years
 *	3. Calculate final amount
 *	4. Display amount left
 */

#include <stdio.h>
#include <math.h>

#define C 0.50007	/* e^-0.693 */
#define HALFLIFE 5.272	/* half life of cobalt-60 */

int
main(void)
{
	double initial_amount;
	double final_amount;
	int year;

	/* Get initial amount of cobalt */
	printf("Enter initial amount: ");
	scanf("%lf", &initial_amount);

	/* Calculate amount after each year for 5 years */
	for (year = 1; year <= 5; year++) {
		/* Calculate final amount */
		final_amount = initial_amount * pow(C, year/HALFLIFE);
		/* Display amount left */
		printf("Amount left after year %d is %.2f\n",
			year, final_amount);
	}

	return (0);
}
