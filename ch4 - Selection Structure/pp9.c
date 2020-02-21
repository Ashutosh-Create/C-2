/*
 * Name: Abhijit Parida		Date: 27-01-17
 * Program Description: To calculate charges for Chatflow Wireless
 * Input: number of weekday minutes, night minutes and weekend minutes
 * Output: pretax bill, average minute cost, taxes, total bill
 * Algorithm:
 *	1. Get number of weekday minutes, night minutes and weekend minutes
 *	2. Calculate weekday charges
 *	3. Calculate average charge per minute
 *	4. Calculate taxes
 *	5. Display bill
 */

#include <stdio.h>

#define WEEKDAY_LIMIT 600	/* 600 minutes */
#define WEEKDAY_RATE 3999	/* 39.99 dollars */
#define WEEKDAY_CHARGE_EXTRA 40	/* 0.40 dollars */
#define TAX 0.0525		/* 5.25 % */

int
main(void)
{
	int weekday_min, night_min, weekend_min;
	int total_min;
	int weekday_ext_min;
	double weekday_ext_chg;
	double charge;
	double avg_min_chg;
	double tax;
	double total_chg;
	
	/* Get input from user */
	printf("Enter weekday minutes: ");
	scanf("%d", &weekday_min);
	printf("Enter night minutes (8PM to 7AM): ");
	scanf("%d", &night_min);
	printf("Enter weekend minutes: ");
	scanf("%d", &weekend_min);

	/* Calculate weekday charges */
	charge = WEEKDAY_RATE;
	if (weekday_min > WEEKDAY_LIMIT) {
		weekday_ext_min = weekday_min - WEEKDAY_LIMIT;
		weekday_ext_chg = weekday_ext_min * WEEKDAY_CHARGE_EXTRA;
		charge += weekday_ext_chg;
	}

	/* Calculate average cost per minute */
	total_min = weekday_min + weekend_min + night_min;
	avg_min_chg = charge / total_min;

	/* Calculate tax */
	tax = charge * TAX;

	/* Calculate total bill amount */
	total_chg = charge + tax;

	/* Display bill */
	printf("Weekday minutes: %d\n", weekday_min);
	printf("Weekend minutes: %d\n", weekend_min);
	printf("Night minutes: %d\n", night_min);

	printf("Weekday flat rate: $ %.2f\n", WEEKDAY_RATE / 100.0);
	if (weekday_min > WEEKDAY_LIMIT) {
		printf("Weekday extra minutes: %d\n", weekday_ext_min);
		printf("Weekday extra charge ($0.40/min): $ %.2f\n",
			weekday_ext_chg / 100.0);
	}

	printf("Bill amount: $ %.2f\n", charge / 100.0);
	printf("Average cost per minute: $ %.2f\n", avg_min_chg / 100.0);
	printf("Tax: $ %.2f\n", tax / 100.0);
	printf("Total bill: $ %.2f\n", total_chg / 100.0);

	return (0);
}
