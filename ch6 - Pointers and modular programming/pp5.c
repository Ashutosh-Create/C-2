/*
 * Program Description: To check if a number is multiple of 7, 11 or 13, the
 *      sum of digits is odd or even, the number is prime or not.
 * Input: a number
 * Output: multiple of 7, 11 or 13, sum of digits odd/even, prime or not
 */

#include <stdio.h>

void get_answers(int value, int *is_multiple, int *is_odd_sum, int *is_prime);
int check_multiple(int value);
int check_odd_sum(int value);
int check_prime(int value);

int
main(void)
{
    int value;          /* Number input by user */
    int is_multiple;    /* Multiple of 7, 11 or 13 */
    int is_odd_sum;     /* Sum of digits */
    int is_prime;       /* Prime or composite */
    int input_status;   /* Value returned by scanf */

    printf("Enter number: ");
    input_status = scanf("%d", &value);

    while (input_status == 1) {
        get_answers(value, &is_multiple, &is_odd_sum, &is_prime);

        printf("Value: %d\n", value);

        if (is_multiple) {
            printf("A multiple of 7, 11 or 13.\n");
        } else {
            printf("Not a multiple of 7, 11 or 13.\n");
        }

        if (is_odd_sum) {
            printf("Sum of the digits is odd.\n");
        } else {
            printf("Sum of the digits is even.\n");
        }

        if (is_prime) {
            printf("A prime number.\n");
        } else {
            printf("Not a prime number.\n");
        }

        printf("\nEnter number: ");
        input_status = scanf("%d", &value);
    }

    return (0);
}

/*
 * Returns answers to if the number is multiple of 7, 11 or 13, the
 * sum of digits is odd or even, the number is prime or not
 */
void
get_answers(int value, int *is_multiple, int *is_odd_sum, int *is_prime)
{
    *is_multiple = check_multiple(value);
    *is_odd_sum = check_odd_sum(value);
    *is_prime = check_prime(value);
}

/*
 * Returns 1 if value is a multiple of 7, 11 or 13, returns 0 otherwise
 */
int
check_multiple(int value)
{
    return (value % 7 == 0 || value % 11 == 0 || value % 13 == 0);
}

/*
 * Retuns 1 if the sum of digits of value is odd, returns 0 otherwise
 */
int
check_odd_sum(int value)
{
    int sum, rem;

    sum = 0;
    while (value != 0) {
        rem = value % 10;
        sum = sum + rem;
        value = value / 10;
    }

    return (sum % 2 == 1);
}

/*
 * Returns 1 if value is prime, returns 0 otherwise
 */
int
check_prime(int value)
{
    int i;

    for (i = 2; i < value; i++) {
        if (value % i == 0) {
            return 0;
        }
    }

    return 1;
}
