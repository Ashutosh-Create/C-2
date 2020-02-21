/*
 * Name: Abhijit Parida		Date: 10-02-17
 * Program Description: To display a customized loan amortization table
 * Inputs: amount borrowed, annual interest rate, number of payments
 * Output: loan amortization table
 * Algorithm:
 *	1. Get amount borrowed, annual interest rate and number of payments
 *	2. Calculate monthly interest rate and monthly payment
 *	3. Set initial balance to the amount borrowed
 *	4. For N number of payments,
 *		5. Set interest = monthly rate * balance
 *		6. Set principal = monthly payment - interest
 *		7. Set balance = balance - principal
 *		8. Display interest, principal and balance
 *	9. Display the final payment as interest + principal
 */

#include <stdio.h>
#include <math.h>

int
main(void)
{
	double amount_borrowed;	/* Amount borrowed */
	double annual_rate;	/* Annual interest rate */
	double monthly_rate;	/* Monthly interest rate */
	int i, num_payments;	/* Number of payments */
	double payment;		/* Monthly payment */
	double interest;
	double principal;
	double balance;

	/* Get amount borrowed, annual interest rate and number of payments */
	printf("Enter amount borrowed: ");
	scanf("%lf", &amount_borrowed);
	printf("Enter annual interest rate: ");
	scanf("%lf", &annual_rate);
	printf("Enter number of payments: ");
	scanf("%d", &num_payments);

	/* Calculate monthly interest rate and monthly payment */
	monthly_rate = (annual_rate / 12.0) / 100.0;
	payment = (monthly_rate * amount_borrowed) /
			(1 - pow(1 + monthly_rate, -num_payments));

	/* Display table header */
	printf("Principal: $%.2f\tPayment: $%.2f\n", amount_borrowed, payment);
	printf("Annual interest: %.2f%%\tTerm: %d months\n",
		annual_rate, num_payments);
	printf("Payment  Interest  Principal  Balance\n");

	/* Display loan amortization table */
	balance = amount_borrowed;
	for (i = 1; i <= num_payments; i++) {
		interest = monthly_rate * balance;
		principal = payment - interest;
		balance = balance - principal;
		printf("%d\t%.2f\t%.2f\t%.2f\n",i, interest, principal, balance);
	}

	/* Display the final payment */
	printf("Final payment\t$%.2f\n", interest + principal);

	return (0);
}
