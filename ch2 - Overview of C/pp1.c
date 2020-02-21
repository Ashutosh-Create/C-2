/*
 * Name: Abhijit Parida [1541012143]	Date: 04-01-17
 * Program Name: pp1.c
 * Program Description: To calculate mileage reimbursement for a salesperson
 *		given the initial and final odometer readings.
 * Inputs: odo_begin, odo_end
 * Outputs: dist, cost
 * Algorithm:
 *	1. Get the beginning and ending odometer readings
 *	2. Compute the distance travelled
 * 	3. Find the amount to be reimbursed to the salesperson
 *	4. Display the distance and amount to be reimbursed
 */

#include <stdio.h>
#define COST_PER_MILE 0.35

int
main(void)
{
	double odo_begin, odo_end; /* Odometer readings */
	double dist; /* Distance travelled */
	double cost; /* Reimbursement for the salesperson */

	printf("MILEAGE REIMBURSEMENT CALCULATOR\n");

	/* Get the odometer readings */
	printf("Enter beginning odometer reading=> ");
	scanf("%lf", &odo_begin);
	printf("Enter ending odometer reading=> ");
	scanf("%lf", &odo_end);

	/* Calculate distance travelled and amount to be reimbursed */
	dist = odo_end - odo_begin;
	cost = dist * COST_PER_MILE;

	/* Display the distance and amount */
	printf("You traveled %.2f miles.\t", dist);
	printf("At $0.35 per mile,\nyour reimbursement is $%.2f.\n", cost);

	return (0);
}
