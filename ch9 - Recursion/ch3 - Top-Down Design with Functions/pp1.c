/*
 * Name: Abhijit Parida		Date: 11-01-17
 * Program Description: To find monthly payments for the purchase of a car
 * Inputs: purchase price, down payment, annual interest, number of payments
 * Output: amount borrowed, monthly payments
 * Algorithm:
 *	1. Get purchase price, down payment, annual interest rate
 *	and total number of payments
 *	2. Calculate principal and monthly interest rate
 *	3. Calculate monthly payment
 *	4. Display the amount borrowed and the amount to be paid monthly
 * Algorithm Refinements:
 *	2.1. principal  = purchase price - down payment
 *	2.2. monthly interest = annual interest / 12
 *	3.1. monthly payment = (i * P) / (1 - (1 + i) ^ -n) where i = monthly
 *	interest, P = principal and n = number of payment
 */

#include <stdio.h>
#include <math.h>

int
main(void)
{
	double purchase_price;	/* Purchase price of the car */
	double down_payment;	/* Down payment */
	double annual_interest;	/* Annual interest rate */
	double num_payments;	/* Total number of payments */
	double principal;	/* Amount borrowed */
	double montly_interest;	/* Monthly interest rate */
	double monthly_payment;	/* Monthly payment */

	/* Get purchase price, down payment, annual interest rate
	and total number of payments */
	printf("Enter purchase price: ");
	scanf("%lf", &purchase_price);
	printf("Enter down payment: ");
	scanf("%lf", &down_payment);
	printf("Enter annual interest rate: ");
	scanf("%lf", &annual_interest);
	printf("Enter number of payments: ");
	scanf("%lf", &num_payments);

	/* Calculate principal and monthly interest rate */
	principal  = purchase_price - down_payment;
	montly_interest = annual_interest / 12.0;

	/* Calculate monthly payment */
	monthly_payment = (montly_interest * principal) /
		(1 - pow(1 + montly_interest, -num_payments));

	/* Display the amount borrowed and the amount to be paid monthly */
	printf("Amount borrowed = $%.2f\n", principal);
	printf("Monthly payment = $%.2f\n", monthly_payment);

	return (0);
}
