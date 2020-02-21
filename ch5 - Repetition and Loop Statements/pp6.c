/*
 * Name: Abhijit Parida		Date: 10-02-17
 * Program Description: To process an input file of data on existing carpools
 *	and create an output file of the carpools that meet the passenger
 *	efficiency minimum.
 * Input: minimum required efficiency, number of passengers, distance travelled
 *	and gasoline consumed in 5 day week
 * Output: carpools meeting the minimum required efficiency
 * Algorithm:
 *	1. Get the minimum required efficiency
 *	2. Read input file until sentinel value is encountered
 *		3. Calculate efficiency
 *		4. If efficiency is higher than minimum required efficiency
 *			5. Calculate subsidy
 *			6. Display number of passengers, distance, gasoline
 *			consumed, efficiency and subsidy
 * Algorithm Refinements:
 *	3.1 efficiency = (passengers * distance) / gasoline
 *	5.1 subsidy = 0.08 * distance * passengers
 */

#include <stdio.h>

#define SUBSIDY 0.08	/* Subsidy for carpools meeting minimum
				required efficiency */
#define SENTINEL 0 	/* Value for exiting input loop */

int
main(void)
{
	int min_efficiency;	/* Minimum required efficiency */
	int passengers;		/* Number of passengers */
	int distance;		/* Distance travelled */
	double gasoline;	/* Gasoline consumed */
	double efficiency;	/* Efficiency of carpool */
	double subsidy;		/* Subsidy amount */

	/* Get the minimum required efficiency */
	scanf("%d", &min_efficiency);

	/* Print the output file header */
	printf("CARPOOLS MEETING MINIMUM PASSENGER EFFICIENCY OF ");
	printf("%d PASSENGERS KM/L\n", min_efficiency);
	printf("Passengers\tWeekly Commute (km)\tGasoline Consumption(L) ");
	printf("Efficiency (pass km/L)\tWeekly Subsidy($)\n");

	/* Get the first line from input file */
	scanf("%d %d %lf", &passengers, &distance, &gasoline);
	while (passengers != SENTINEL) {
		/* Calculate efficiency */
		efficiency = (passengers * distance) / gasoline;

		/* Calculate subsidy according to efficiency */
		if (efficiency >= min_efficiency) {
			subsidy = SUBSIDY * distance * passengers;

			/* Display calculated data */
			printf("%d\t%d\t%.1f\t%.1f\t%.2f\n", passengers,
				distance, gasoline, efficiency, subsidy);
		}

		/* Get the next line from input file */
		scanf("%d %d %lf", &passengers, &distance, &gasoline);
	}

	return (0);
}
