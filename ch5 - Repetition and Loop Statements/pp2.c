/*
 * Name: Abhijit Parida		Date: 10-02-17
 * Program Description: To check if a number is divisible by 9
 * Input: integer N
 * Output: whether N is divisible by 9 or not
 * Algorithm:
 *	1. Get the value of n character by character
 *		2. Find numerical value by subtracting '0' from the character
 *		3. Add it to sum
 *	4. If sum is divisible by 9
 *		5. Display that n is divisible by 9
 *	6. Otherwise n is not divisible by 9
 */

#include <stdio.h>

int
main(void)
{
	char digit;
	int digit_value, sum;

	sum = 0;

	/* Get value of N character by character */
	printf("Enter number N: ");
	scanf(" %c", &digit);
	while (digit != '\n') {
		/* Find numerical value by subtracting '0' from character */
		digit_value = (int) digit - (int) '0';
		sum += digit_value;
		printf("%d\n", digit_value);
		scanf("%c", &digit);
	}

	/* Check if sum of digits is divisible by 9 */
	if (sum % 9 == 0) {
		printf("The number is divisible by 9\n");
	} else {
		printf("The number is not divisible by 9\n");
	}

	return (0);
}
