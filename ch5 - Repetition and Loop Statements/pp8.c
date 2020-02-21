/*
 * Name: Abhijit Parida		Date: 15-02-17
 * Program Description: To process weekly employee time cards for all
 *	employees of an organization
 * Inputs: indentification number, hourly wage rate, number of hours worked
 *	for each employee
 * Output: employee number and net pay, total payroll and average amount paid
 * Algorithm:
 * 	1. Read employee id, wage rate and number of hours from input file
 *		2. Calculate net pay
 *		3. Deduct taxes
 *		4. Display employee number and net pay
 *	5. Calculate average amount per employee
 *	6. Display total payroll and average amount paid
 */

#include <stdio.h>

#define TAX 0.03625

int
main(void)
{
	int emp_id;		/* Employee number */
	int wage_rate;		/* Hourly wage rate */
	int num_hours;		/* Number of hours worked */
	int net_pay;		/* Net pay */
	int total_payroll;	/* Total payroll */
	int num_employees;	/* Number of employees */
	double avg_amount;	/* Average amount paid */

	int input_status;

	num_employees = 0;
	total_payroll = 0;

	/* Read employee id, wage rate and number of hours from input file */
	input_status = scanf("%d %d %d", &emp_id, &wage_rate, &num_hours);
	while (input_status != -1) {
		/* Calculate net pay */
		if (num_hours > 40) {
			net_pay = wage_rate * 40 +
				wage_rate * (num_hours - 40) * 1.5;
		} else {
			net_pay = wage_rate * num_hours;
		}

		/* Deduct taxes */
		net_pay -= net_pay * TAX;

		/* Display employee number and net pay */
		printf("Employee number %d: Net pay $%d\n",
			emp_id, net_pay);

		total_payroll += net_pay;
		num_employees++;
		input_status = scanf("%d %d %d", &emp_id, &wage_rate,
			&num_hours);
	}

	/* Calculate average amount per employee */
	avg_amount = total_payroll / (double) num_employees;

	/* Display total payroll and average amount paid */
	printf("Total payroll = $%d\n", total_payroll);
	printf("Average amount paid = $%.2f\n", avg_amount);

	return (0);
}
