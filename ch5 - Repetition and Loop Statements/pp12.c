/*
 * Name: Abhijit Parida		Date: 17-02-17
 * Program Description: To predict fast food charges of US
 * Input: year after 2005
 * Output: fast food charge
 * Algorithm:
 *	1. Get year from user
 *	2. While year is after 2005
 *		3. Calculate fast food charge
 *		4. Get next year from user
 * Algorithm refinements:
 *	3.1 charge = 33.2 + 16.8 * t, where t is year - 2005
 */

#include <stdio.h>

double fast_food_billions(int year);

int
main(void)
{
	int year;
	double charge;

	/* Get year from user */
	printf("Enter year after 2005: ");
	scanf("%d", &year);
	/* Continue if year is greater than 2005 */
	while (year >= 2005) {
		/* Calculate food charge */
		charge = fast_food_billions(year);
		printf("Fast food charge for %d is $%.2f billion\n",
			year, charge);
		/* Get next year from user */
		printf("Enter year after 2005: ");
		scanf("%d", &year);
	}

	return (0);
}

/*
 * Calculates fast food charges
 * Pre: year after 2005
 */
double
fast_food_billions(int year)
{
	int t;
	double charge;

	t = year - 2005;
	charge = 33.2 + 16.8 * t;

	return charge;
}
