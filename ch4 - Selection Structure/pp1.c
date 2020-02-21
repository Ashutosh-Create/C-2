/*
 * Name: Abhijit Parida		Date: 25-01-17
 * Program Description: To generate receipt for a music store
 * Inputs: total purchase, teacher or not
 * Output: receipt
 * Algorithm:
 *	1. Get input from user
 *	2. Calculate discount
 *	3. Calculate sales tax
 *	4. Calculate total
 *	5. Display receipt
 */

#include <stdio.h>

int
main(void)
{
	double purchase;
	char teacher;
	int discount;
	double discount_price;
	double discount_total;
	double sales_tax;
	double total;

	/* Get input from user */
	printf("Enter total purchase: ");
	scanf("%lf", &purchase);
	printf("Are you a teacher (y/n): ");
	scanf(" %c", &teacher);

	/* Calculate discount */
	if (teacher == 'y') {
		if (purchase >= 100.0) {
			discount = 12;
		} else {
			discount = 10;
		}
	} else {
		discount = 0;
	}
	discount_price = discount / 100.0 * purchase;
	discount_total = purchase - discount_price;

	/* Calculate sales tax */
	sales_tax = discount_total * 0.05;

	/* Calculate total */
	total = discount_total + sales_tax;

	/* Display receipt */
	printf("Total purchase\t\t\t\t$ %.2f\n", purchase);
	if (teacher == 'y') {
		printf("Teacher's discount (%d%%)\t\t%.2f\n", discount, discount_price);
		printf("Discounted total\t\t\t%.2f\n", discount_total);
	}
	printf("Sales tax (5%%)\t\t\t\t%.2f\n", sales_tax);
	printf("Total\t\t\t\t\t$ %.2f\n", total);

	return (0);
}
