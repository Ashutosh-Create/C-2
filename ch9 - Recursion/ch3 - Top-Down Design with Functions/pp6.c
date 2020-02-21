/*
 * Name: Abhijit Parida		Date: 13-01-17
 * Program Description: To calculate the speed of Penn Relays mile race stars
 * Constants: TRACK_LENGTH, FEET_PER_MILE, METERS_PER_MILE
 * Inputs: time in minutes and seconds
 * Output: speed in feet per second and meters per second
 * Algorithm:
 *	1. Get time in minutes and seconds
 *	2. Calculate race time in term of seconds
 *	3. Calculate speed in feet per second and meters per second
 *	4. Display the speed
 * Algorithm Refinements:
 *	2.1. race time = minutes * 60.0 + seconds
 *	3.1. fps = TRACK_LENGTH * FEET_PER_MILE / race time
 *	3.2. mps = TRACK_LENGTH * METERS_PER_MILE / race time
 */

#include <stdio.h>

#define TRACK_LENGTH 1		/* Track length = 1 mile */
#define FEET_PER_MILE 5280	/* 1 mile = 5280 feet */
#define METERS_PER_MILE 1609	/* 1 mile = 1609 meters (approx.) */

void instruct(void);

int
main(void)
{
	int minutes;		/* Minutes input by user */
	double seconds;		/* Seconds input by user */
	double race_time;	/* Race time in seconds */
	double fps, mps;	/* Feet per second, Meters per second */

	/* Get time in minutes and seconds */
	instruct();
	scanf("%d%lf", &minutes, &seconds);

	/* Calculate race time in term of seconds */
	race_time = minutes * 60.0 + seconds;

	/* Calculate speed in feet per second and meters per second */
	fps = TRACK_LENGTH * FEET_PER_MILE / race_time;
	mps = TRACK_LENGTH * METERS_PER_MILE / race_time;

	/* Display the speed */
	printf("Speed = %.2f feet/second = %.2f meters/second\n", fps, mps);

	return (0);
}

/*
 * Displays instructions to the program user
 */
void
instruct(void)
{
	printf("Enter race time in minutes and seconds: ");
}
