/*
 * Program Description: To calculate how much change to dispense
 * Input: amount paid and amount due
 * Output: quantity of change
 */

#include <stdio.h>

void dispense_change(int change, int *dollars, int *quarters, int *dimes,
    int *nickels, int *pennies);

int
main(void)
{
    double amount_paid;             /* Amount paid */
    double amount_due;              /* Amount due */
    int change;                     /* Change in cents */
    int dollars, quarters,          /* Amount of change */
        dimes, nickels, pennies;

    printf("Enter amount paid: ");
    scanf("%lf", &amount_paid);
    printf("Enter amount due: ");
    scanf("%lf", &amount_due);

    change = (int) ((due - paid) * 100.0);

    dispense_change(change, &dollars, &quarters, &dimes, &nickels, &pennies);

    printf("\nNumber of dollars: %d\n", dollars);
    printf("Number of quarters: %d\n", quarters);
    printf("Number of dimes: %d\n", dimes);
    printf("Number of nickels: %d\n", nickels);
    printf("Number of pennies: %d\n", pennies);

    return (0);
}

/*
 * Calculates number of dollars, quarters, dimes, nickels & pennies to dispense
 * Pre: amount of change (in cents)
 */
void
dispense_change(int change, int *dollars, int *quarters, int *dimes,
    int *nickels, int *pennies)
{
    *dollars = change / 100;
    change = change % 100;

    *quarters = change / 25;
    change = change % 25;

    *dimes = change / 10;
    change = change % 10;

    *nickels = change / 5;
    change = change % 5;

    *pennies = change;
}
