/*
 * Program Description: To calculate the least number of bills for a given
 *      amount of money
 * Input: amount of money (multiple of 10)
 * Output: number of bills of each kind
 */

#include <stdio.h>

void dispense_bills(int amount, int *fifty, int *twenty, int *ten);

int
main(void)
{
    int amount;                 /* Amount of money to dispense */
    int fifty, twenty, ten;     /* Number of bills */

    printf("Enter amount (multiple of 10): ");
    scanf("%d", &amount);

    dispense_bills(amount, &fifty, &twenty, &ten);

    printf("\n$50 dollar bills: %d\n", fifty);
    printf("$20 dollar bills: %d\n", twenty);
    printf("$10 dollar bills: %d\n", ten);

    return (0);
}

/*
 * Calculates number of $50, $20 and $10 bills to dispense
 * Pre: amount of money (multiple of 10)
 */
void
dispense_bills(int amount, int *fifty, int *twenty, int *ten)
{
    *fifty = amount / 50;
    amount = amount % 50;

    *twenty = amount / 20;
    amount = amount % 20;

    *ten = amount / 10;
}
