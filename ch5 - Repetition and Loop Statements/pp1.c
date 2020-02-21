/*
 * Name: Abhijit Parida		Date: 03-02-17
 * Program Description: To check if an integer n is divisible by 9
 * Input: value of n
 * Output: whether n is divisible by 9 or not
 * Algorithm:
 *	1. Get the value of n
 *	2. While n is not zero
 *		3. Find remainder of n divided by 10
 *		4. Add remainder to sum
 *		5. Divide n by 10
 *	6. If sum is divisible by 9
 *		7. Display that n is divisible by 9
 *	8. Otherwise n is not divisible by 9
 */

#include <stdio.h>

int
main(void)
{
	int n, rem, sum;

	/* Get the value of n */
	printf("Enter the value of n: ");
	scanf("%d", &n);

	sum = 0;

	/* Display each digit and find sum */
	while (n != 0) {
		rem = n % 10;
		printf("%d\n", rem);
		sum += rem;
		n = n / 10;
	}

	/* Check if sum of digits is divisible by 9 */
	if (sum % 9 == 0) {
		printf("Divisible by 9\n");
	} else {
		printf("Not divisible by 9\n");
	}

	return (0);
}
