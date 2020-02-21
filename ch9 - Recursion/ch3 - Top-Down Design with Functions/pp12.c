/*
 * Name: Abhijit Parida		Date: 18-01-17
 * Program description: To calculate the speed of sound in air
 * Input: Temperature of air
 * Output: Speed of sound
 * Algorithm:
 *	1. Get the temperature
 *	2. Calculate the speed of sound
 *	3. Display the speed of sound
 * Algorithm refinements:
 *	2.1. speed = 1086 * sqrt((temp * 5 + 297) / 247.0)
 */

#include <stdio.h>
#include <math.h>

double sound_speed(double T);

int
main(void)
{
	double T;	/* Temperature */
	double a;	/* Speed of sound */

	/* Get the temperature */
	printf("Enter temperature (in fahrenheit): ");
	scanf("%lf", &T);

	/* Calculate the speed of sound */
	a = sound_speed(T);

	/* Display the speed of sound */
	printf("Speed of sound is %.3f ft/sec\n", a);

	return (0);
}

/*
 * Calculates the speed of sound
 * Pre: temperature T
 */
double
sound_speed(double T)
{
	return 1086 * sqrt((T * 5 + 297) / 247.0);
}
