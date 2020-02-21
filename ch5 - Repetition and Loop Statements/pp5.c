/*
 * Name: Abhijit Parida		Date: 10-02-17
 * Program Description: To find the greatest common divisor of two integers
 * Input: two integers
 * Output: gcd of the two integers
 * Algorithm:
 *	1. Get the two integers
 *	2. Keep dividing till the remainder becomes zero
 *	3. Display the gcd
 */

#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
	int a, b;
	int rem;

	/* Get two integers */
	printf("Enter two numbers: ");
	scanf("%d%d", &a, &b);

	a = abs(a);
	b = abs(b);

	/* Keep dividing till the remainder becomes zero */
	rem = a % b;
	while (rem != 0) {
		a = b;
		b = rem;
		rem = a % b;
	}

	/* Display the gcd */
	printf("gcd is %d\n", b);
}
