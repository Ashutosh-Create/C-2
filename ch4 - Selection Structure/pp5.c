/*
 * Name: Abhijit Parida		Date: 25-01-17
 * Program Description: To find damage by earthquake according to Richter scale
 * Input: richter scale number
 * Output: damage characterization
 * Algorithm:
 *	1. Get Richter Scale number
 *	2. Display characterization
 */

#include <stdio.h>

int
main(void)
{
	double n;

	/* Get Richter Scale number */
	printf("Enter Richter Scale number: ");
	scanf("%lf", &n);

	/* Display characterization */
	if (n < 5) {
		printf("Little or no damage\n");
	} else if (n < 5.5) {
		printf("Some damage\n");
	} else if (n < 6.5) {
		printf("Serious damage: walls may crack or fall\n");
	} else if (n < 7.5) {
		printf("Disaster: houses and buildings may collapse\n");
	} else {
		printf("Catastrophe: most buildings destroyed\n");
	}

	return (0);
}
