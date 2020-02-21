/*
 * Program Description: To store two numerical lists, calculate their product,
 *      and the square root of sum of products.
 * Input: 2 numerical lists of same length ending with sentinel value
 * Output: product of corresponding elements, square root of sum of products
 */

#include <stdio.h>
#include <math.h>

#define SIZE 20         /* Maximum number of elements in list */
#define SENTINEL -1     /* Sentinel value */

int
main(void)
{
    int x[SIZE];        /* List x */
    int y[SIZE];        /* List y */
    int z[SIZE];        /* List z */
    int n;              /* Actual number of elements */
    int i;              /* Loop index */
    int elem;
    int prod_sum;       /* Sum of products */

    /* Get elements of list x */
    i = 0;
    printf("Enter element of list x (%d to end input): ", SENTINEL);
    scanf("%d", &x[i]);
    while (x[i] != SENTINEL && i < SIZE-1) {
        printf("Enter element of list x (%d to end input): ", SENTINEL);
        scanf("%d", &x[++i]);
    }
    n = i;
    if (x[i] != SENTINEL) {
        /* Discard elements till sentinel value found */
        scanf("%d", &elem);
        while (elem != SENTINEL) {
            scanf("%d", &elem);
        }
        n++;
    }

    /* Get elements of list y */
    for (i = 0; i < n; i++) {
        printf("Enter element of list y: ");
        scanf("%d", &y[i]);
    }

    /* Store product of corresponding elements of list x and y in list z, and
       and find sum of the products */
    prod_sum = 0;
    for (i = 0; i < n; i++) {
        z[i] = x[i] * y[i];
        prod_sum += z[i];
    }

    /* Display the arrays x, y and z in a three column table */
    printf("%5c%5c%5c\n", 'x', 'y', 'z');
    for (i = 0; i < n; i++) {
        printf("%5d%5d%5d\n", x[i], y[i], z[i]);
    }

    /* Display square root of sum of items in z */
    printf("\nSquare root of sum of products = %.4f\n", sqrt(prod_sum));

    return (0);
}
