/*
 * Name: Abhijit Parida [1541012143]	Date: 04-01-17
 * Program Name: supermarket.c
 * Program Description: To determine the value of a collection of coins.
 * Algorithm:
 *	1. Get and display the customer's initials
 *	2. Get the count of each kind of coin
 *	3. Compute the total value in cents
 * 	4. Find the value in dollars and change
 *	5. Display the value in dollars and change
 */

#include <stdio.h>

int
main(void)
{
	char first, middle, last;	/* Customer's initials */
	int pennies, nickels, dimes,
		quarters, dollars;		/* Count of each coin type */
	int change;					/* Change amount */
	int total_dollars;			/* Dollar amount */
	int total_cents;			/* Total cents */

	/* Get and display the customer's initials */
	printf("Type in your 3 initials > ");
	scanf("%c%c%c", &first, &middle, &last);
	printf("\n%c%c%c, please enter your coin information.\n",
		first, middle, last);

	/* Get the count of each kind of coin */
	printf("Number of dollar coins > ");
	scanf("%d", &dollars);
	printf("Number of quarters > ");
	scanf("%d", &quarters);
	printf("Number of dimes > ");
	scanf("%d", &dimes);
	printf("Number of nickels > ");
	scanf("%d", &nickels);
	printf("Number of pennies > ");
	scanf("%d", &pennies);

	/* Compute the total value in cents */
	total_cents = 100 * dollars + 25 * quarters + 10 * dimes
		+ 5 * nickels + pennies;

	/* Find the value in dollars and change */
	total_dollars = total_cents / 100;
	change = total_cents % 100;

	/* Display the credit slip with value in dollars and change */
	printf("\n\n%c%c%c Coin Credit\nDollars: %d\nChange: %d cents\n",
		first, middle, last, total_dollars, change);

	return (0);
}
