/*
 * Name: Abhijit Parida		Date: 18-01-17
 * Program Description: To predict the population of Gotham City
 * Input: year
 * Output: population
 * Algorithm:
 *	1. Get the year
 *	2. Calculate the population
 *	3. Display the predicted population
 * Algorithm refinements:
 *	2.1. population = 52.966 + 2.184 * t,
 *	 where t is number of years after 1990
 */

#include <stdio.h>

double population(int year);

int
main(void)
{
	int year;	/* Year after 1990 */
	double P;	/* Predicted population */

	/* Get the year */
	printf("Enter a year after 1990> ");
	scanf("%d", &year);

	/* Calculate the population */
	P = population(year);

	/* Display the predicted population */
	printf("Predicted Gotham City population for %d ", year);
	printf("(in thousands): %.3f\n", P);

	return (0);
}

/*
 * Calculates population of Gotham City
 * Pre: year after 1990
 */
double
population(int year)
{
	int t = year - 1990;
	return 52.966 + 2.184 * t;
}
