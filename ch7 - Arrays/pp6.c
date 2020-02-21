/*
 * Program Description: To summarize accident count reports and display a
 *      frequency distributation table
 * Input: number of accidents
 * Output: frequency distribution table in the range 0-99, 100-199, 200-299,
 *      300-399, 400-499, 500 or above
 */

#include <stdio.h>

int
main(void)
{
    int n;          /* Number of accident counts */
    int i;          /* Loop index */
    int count;      /* Accident count */
    int freq[6];    /* Frequency distribution table */

    /* Initialize frequency distribution table */
    for (i = 0; i < 6; i++) {
        freq[i] = 0;
    }

    /* Get the number of accident counts */
    printf("Enter number of accident counts: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {

        /* Get accident counts */
        printf("Enter accident count: ");
        scanf("%d", &count);

        /* Increment frequency */
        if (count >= 500) {
            freq[5]++;
        } else {
            freq[count/100]++;
        }
    }

    /* Display frequency table */
    printf("\nFREQUENCY DISTRIBUTION TABLE\n");
    for (i = 0; i < 5; i++) {
        printf("%d-%d accidents: %d\n", i*100, i*100+99, freq[i]);
    }
    printf("500 or above accidents: %d\n", freq[5]);

    return (0);
}
