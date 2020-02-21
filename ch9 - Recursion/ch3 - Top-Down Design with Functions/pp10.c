/*
 * Name: Abhijit Parida		Date: 14-01-17
 * Program Description: To calculate temperature at a given depth inside earth
 * Inputs: depth
 * Output: temperature in Celsius and Fahrenheit
 * Algorithm:
 *	1. Get the depth inside earth
 *	2. Calculate Celsius temperature and convert it to Fahrenheit
 *	3. Display both Celsius and Fahrenheit temperature
 * Algorithm Refinements:
 *	2.1. celsius at depth = 10 * depth + 20
 *	2.2. fahrenheit = 1.8 * celcius + 32
 */

#include <stdio.h>

double celsius_at_depth(double depth);
double fahrenheit(double celcius);

int
main(void)
{
	double depth;	/* Depth in kilometers inside earth */
	double celsius;	/* Celsius temperature */
	double fahr;	/* Fahrenheit temperature */

	/* Get the depth inside earth */
	printf("Enter depth inside earth (in kilometers): ");
	scanf("%lf", &depth);

	/* Calculate Celsius temperature and convert it to Fahrenheit */
	celsius = celsius_at_depth(depth);
	fahr = fahrenheit(celsius);

	/* Display both Celsius and Fahrenheit temperature */
	printf("Temperature in Celsius = %.3f C\n", celsius);
	printf("Temperature in Fahrenheit = %.3f F\n", fahr);

	return (0);
}

/*
 * Calculates the Celsius temperature at depth inside earth
 * Pre: depth (in kilometers)
 */
double
celsius_at_depth(double depth)
{
	return 10 * depth + 20;
}

/*
 * Converts a Celsius temperature to Fahrenheit
 * Pre: celcius
 */
double
fahrenheit(double celcius)
{
	return 1.8 * celcius + 32;
}
