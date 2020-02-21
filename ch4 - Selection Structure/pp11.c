/*
 * Name: Abhijit Parida		Date: 27-01-17
 * Program Description: To identify substances from their boiling point
 * Input: boiling point
 * Output: substance name
 * Algorithm:
 *	1. Get observed boiling point
 *	2. Identify and display substance
 */

#include <stdio.h>

#define WATER 100
#define MERCURY 357
#define COPPER 1187
#define SILVER 2193
#define GOLD 2660

int within_x_percent(double ref, double data, double x);

int
main(void)
{
	double boiling_point;

	/* Get observed boiling point */
	printf("Entered observed boiling point: ");
	scanf("%lf", &boiling_point);

	/* Identify and display substance */
	if (within_x_percent(WATER, boiling_point, 10)) {
		printf("Water\n");
	} else if (within_x_percent(MERCURY, boiling_point, 10)) {
		printf("Mercury\n");
	} else if (within_x_percent(COPPER, boiling_point, 10)) {
		printf("Copper\n");
	} else if (within_x_percent(SILVER, boiling_point, 10)) {
		printf("Silver\n");
	} else if (within_x_percent(GOLD, boiling_point, 10)) {
		printf("Gold\n");
	} else {
		printf("Substance unknown\n");
	}

	return (0);
}

/*
 * Returns true if data is within x% of ref
 * Pre: reference value, data value, x
 */
int
within_x_percent(double ref, double data, double x)
{
	double x_per = x / 100.0 * ref;
	return (ref - x_per <= data && ref + x_per >= data);
}
