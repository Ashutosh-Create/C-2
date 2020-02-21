/*
 * Program Descriptiopn: To validate UPCs scanned by a barcode scanner
 * Input: 12 digits of a barcode
 * Output: valid/invalid
 */

#include <stdio.h>

int barcode_valid(int barcode[]);

int
main(void)
{
    int i;              /* Loop index */
    int barcode[12];    /* The barcode */

    printf("Enter 12 digits of barcode separated by spaces: \n");
    for (i = 0; i < 12; i++) {
        scanf("%d", &barcode[i]);
    }

    if (barcode_valid(barcode)) {
        printf("validated.\n");
    } else {
        printf("error in barcode.\n");
    }

    return (0);
}

/*
 * Returns 1 if the barcode is valid, returns 0 otherwise
 * Pre: barcode - array of 12 ints
 */
int
barcode_valid(int barcode[])
{
    int i;          /* Loop index */
    int odd_sum;    /* Sum of odd-numbered positions */
    int even_sum;   /* Sum of even-numbered positions */
    int step1;      /* Result obtained in  step 1 */
    int step2;      /* Result obtained in step 2*/
    int last_dgt;   /* Last digit of step2 */
    int check_dgt;  /* The check digit */

    /* Calculate sum of odd and even numbered positions */
    odd_sum = 0;
    even_sum = 0;
    for (i = 0; i <= 10; i++) {
        if (i % 2 == 0) {
            even_sum += barcode[i];
        } else {
            odd_sum += barcode[i];
        }
    }

    /* Step 1 */
    step1 = even_sum * 3;
    printf("*** Step 1 result: %d\n", step1);

    /* Step 2 */
    step2 = odd_sum + step1;
    printf("*** Step 2 result: %d\n", step2);

    /* Step 3 - calculate the check digit */
    last_dgt = step2 % 10;
    if (last_dgt == 0) {
        check_dgt = 0;
    } else {
        check_dgt = 10 - last_dgt;
    }

    /* Step 4 - the check digit must match the final digit of the 12-digit UPC
       for the barcode to be valid */
    return (check_dgt == barcode[11]);
}
