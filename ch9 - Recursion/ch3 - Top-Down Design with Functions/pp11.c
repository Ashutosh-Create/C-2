/*
 * Name: Abhijit Parida		Date: DD-MM-17
 * Program Description: To find speed ratio of a six-speed gearbox
 * Inputs: maximum and minimum speed in rpm
 * Output: ratio of gearbox
 * Algorithm:
 *	1. Get the maximum and minimum speeds
 *	2. Calculate gearbox ratio
 *	3. Display the result in sentence form
 * Algorithm Refinements:
 *	2.1. ratio = 5th root of (maximum speed / minimum speed)
 */

#include <stdio.h>
#include <math.h>

double speeds_ratio(double max_speed, double min_speed);

int
main(void)
{
	int max_speed, min_speed;	/* Maximum and minimum speed in rpm */
	double ratio;			/* Ratio of gearbox */

	/* Get the maximum and minimum speeds */
	printf("Enter maximum and minimum speed (in rpm): ");
	scanf("%d%d", &max_speed, &min_speed);

	/* Calculate gearbox ratio */
	ratio = speeds_ratio(max_speed, min_speed);

	/* Display the result in sentence form */
	printf("The ratio between successive speeds of a six-speed gearbox ");
	printf("with maximum speed %d rpm and minimum speed ", max_speed);
	printf("%d rpm is %.3f.\n", min_speed, ratio);
}

/*
 * Calculates ratio between successive speeds of a six-speed gearbox
 * Pre: maximum speed (in rpm), minimum speed (in rpm)
 */
double
speeds_ratio(double max_speed, double min_speed)
{
	return pow(max_speed / min_speed, 1.0 / 5.0);
}
