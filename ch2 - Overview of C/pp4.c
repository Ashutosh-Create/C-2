/*
 * Name: Abhijit Parida [1541012143]	Date: 06-01-17
 * Program Name: pp4.c
 * Program Description: To convert a temperature from degrees Fahrenheit
 *		to degrees Celcius.
 * Input: fahrenheit
 * Output: celcius
 * Algorithm:
 *	1. Get the temperature in degrees Fahrenheit
 * 	2. Convert the temperature to degrees Celcius using the formula
 *	3. Display the temperature in degrees Celcius
 */

#include <stdio.h>

int
main(void)
{
	int fahrenheit;	/* Temperature in degrees Fahrenheit */
	double celcius;	/* Temperature in degrees Celcius */

	/* Get the temperature in degrees Fahrenheit */
	printf("Enter temperature (in degrees Fahrenheit):\n");
	scanf("%d", &fahrenheit);
	printf("Temperature in degrees Fahrenheit = %d\n", fahrenheit);

	/* Convert the temperature to celcius and display it */
	celcius = 5.0 / 9.0 * (fahrenheit - 32);
	printf("Temperature in degrees Celcius = %.2f\n", celcius);

	return (0);
}
