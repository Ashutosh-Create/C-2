/*
 * Name: Abhijit Parida		Date: 11-01-17
 * Program: pp12.c
 * Program description: To calculate acceleration of a jet fighter and
 *	time for the fighter to be accelerated to takeoff speed.
 * Input: takeoff speed, distance
 * Output: time, acceleration
 * Algorithm:
 *	1. Get the velocity in km/h and distance travelled in meters
 *	2. Convert velocity to m/s
 *	3. Calculate time and acceleration
 *	4. Display the calculated time and acceleration
 */

#include <stdio.h>

int
main(void)
{
	double v; // velocity in km/h
	double v2; // velocity in m/s
	double s; // distance
	double t; // time
	double a; // acceleration

	// Get the takeoff speed and distance
	printf("Enter takeoff speed (in km/hr): ");
	scanf("%lf", &v);
	printf("Enter distance travelled (in meters): ");
	scanf("%lf", &s);

	// Calculate time and acceleration
	v2 = v * 1000.0 / 3600.0;
	t = (s * 2.0) / v2;
	a = v2 / t;

	// Display results
	printf("Acceleration of jet fighter = %.2f m/s^2\n", a);
	printf("Time for which jet must be accelerated = %.2f sec\n", t);

	return (0);
}
