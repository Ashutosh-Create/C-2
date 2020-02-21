/*
 * Name: Abhijit Parida 	Date: 11-01-17
 * Program: pp11.c
 * Program description: To generate Pythagorean triples
 * Inputs: m, n
 * Outputs: side1, side2, hypotenuse
 * Algorithm:
 *	1. Get the values of m and n
 *	2. Calculate side1 = m^2 - n^2
 *	3. Calculate side2 = 2mn
 *	4. Calculate hypotenuse = m^2 + n^2
 *	5. Display the values of side1, side2 and hypotenuse
 */

#include <stdio.h>

int
main(void)
{
	int m, n;
	int side1, side2;
	int hypotenuse;

	// Get the values of m and n
	printf("Enter value of m: ");
	scanf("%d", &m);
	printf("Enter value of n: ");
	scanf("%d", &n);

	// Calculate side1, side2 and hypotenuse
	side1 = m * m - n * n;
	side2 = 2 * m * n;
	hypotenuse = m * m + n * n;

	// Display the calculated values
	printf("Side1 = %d\n", side1);
	printf("Side2 = %d\n", side2);
	printf("Hypotenuse = %d\n", hypotenuse);

	return (0);
}
