/*
 * Name: Abhijit Parida [1541012143]	Date: 06-01-17
 * Program Name: pp3.c
 * Program Description: To estimate the temperature in a freezer since
 *		a power failure given the time elapsed.
 * Inputs: hours, minutes
 * Output: temp
 * Algorithm:
 *	1. Get the time elapsed in hours and minutes
 *	2. Find the time elapsed in terms of hours
 * 	3. Compute the temperature of the freezer
 *	4. Display the temperature
 */

#include <stdio.h>

int
main(void)
{
	int hours, minutes;	/* Time input as hours and minutes */
	double t;			/* Time elapsed in terms of hours */
	double temp;		/* Temperature of freezer */

	/* Get the time elapsed */
	printf("Enter the time elapsed in hours and minutes:\n");
	scanf("%d%d", &hours, &minutes);
	printf("Hours = %d, Minutes = %d\n", hours, minutes);

	/* Calculate time elapsed in hours */
	t = hours + (double) minutes / 60.0;
	printf("Time elapsed = %.2f\n", t);

	/* Calculate and display the temperature of the freezer */
	temp = ((4 * t * t) / (t + 2)) - 20;
	printf("Temperature of freezer = %.2f\n", temp);

	return (0);
}
