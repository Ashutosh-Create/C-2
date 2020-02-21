/*
 * Name: Abhijit Parida		Date: 13-01-17
 * Program Description: To calculate the total cost of a house
 * Inputs: initial house cost, annual fuel cost, tax rate
 * Output: total house cost
 * Algorithm:
 *	1. Get the initial house cost, annual fuel cost and tax rate
 *	2. Calculate the total house cost
 *	3. Display the total house cost
 * Algorithm Refinements:
 *	2.1. house cost = initial cost + 5 * fuel cost + 5 * tax * initial cost
 */

#include <stdio.h>

void instruct(void);

int
main(void)
{
	int initial_cost;  /* Initial house cost */
	int fuel_cost;     /* Annual fuel cost */
	double tax_rate;   /* Tax rate */
	double house_cost; /* Total house cost */

	/* Get the initial house cost, annual fuel cost and tax rate */
	instruct();
	scanf("%d%d%lf", &initial_cost, &fuel_cost, &tax_rate);

	/* Calculate the total house cost */
	house_cost = initial_cost
		+ 5 * fuel_cost
		+ 5 * tax_rate * initial_cost;

	/* Display the total house cost */
	printf("Total house cost = Rs.%.2f\n", house_cost);

	return (0);
}

/*
 * Displays instructions to the program user
 */
void
instruct(void)
{
    printf("Enter initial house cost, annual fuel cost and tax rate: ");
}
