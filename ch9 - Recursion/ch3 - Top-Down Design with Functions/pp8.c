/*
 * Name: Abhijit Parida		Date: 14-01-17
 * Program Description: To find the time it will take a cyclist to come to rest
 * Inputs: Initial velocity, final velocity, time to reach final velocity
 * Output: Constant acceleration, time to come to rest
 * Algorithm:
 *	1. Get the initial and velocity, and time to reach final velocity
 *	2. Calculate the constant rate of acceleration
 *	3. Calculate the time needed to come to rest
 *	4. Display how long it will take for the cyclist to come to rest
 * Algorithm refinements:
 *	2.1. a = (vf - vi) / t
 *	3.1. t0 = (0 - vi) / a
 */

#include <stdio.h>

void instruct(void);
double acceleration(double vi, double vf, double t);

int
main(void)
{
	double vi, vf;	/* Initial and final velocity */
	double t;	/* Time taken to reach final velocity */
	double a;	/* Acceleration */
	double t0;	/* Time needed to come to rest */

	/* Get the initial and velocity, and time to reach final velocity */
	instruct();
	scanf("%lf%lf%lf", &vi, &vf, &t);

	/* Calculate the constant rate of acceleration */
	a = acceleration(vi, vf, t / 60.0);

	/* Calculate the time needed to come to rest */
	t0 = 60.0 * (0.0 - vi) / a;

	/* Display how long it will take for the cyclist to come to rest */
	printf("Constant rate of acceleration is %.3f miles/hours^2\n", a);
	printf("The cyclist will take %.2f minutes to come to rest\n", t0);

	return (0);
}

/*
 * Displays instructions to the program user
 */
void
instruct(void)
{
	printf("Enter initial velocity, final velocity\n");
	printf("and time to reach final velocity: ");
}

/*
 * Calculates acceleration (in miles/hour^2)
 * Pre: initial velocity (in miles/hour),
 *		final velocity (in miles/hour),
 *		time(in minutes)
 */
double
acceleration(double vi, double vf, double t)
{
	return (vf - vi) / t;
}
