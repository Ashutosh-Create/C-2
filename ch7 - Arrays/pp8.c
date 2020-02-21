/*
 * Program Description: To display summary of this year and last years rainfall
 * Input: data pairs of this year and last years rainfall of every month
 * Output: total rainfall and average monthly rainfall for this year and
 *      last year
 */

#include <stdio.h>

int
main(void)
{
    FILE *rainfall;         /* Input file - "rainfall.txt" */
    int i;                  /* Loop index */
    double this_year[12];   /* Rainfall statistics of this year */
    double last_year[12];   /* Rainfall statistics of last year */
    double this_year_total; /* Total rainfall this year */
    double last_year_total; /* Total rainfall last year */
    double this_year_avg;   /* Average monthly rainfall for this year */
    double last_year_avg;   /* Average monthly rainfall for last year */
    char month_names[][10] = {"January", "February", "March", "April",
        "May", "June", "July", "August", "September", "October",
        "November", "December"};

    rainfall = fopen("rainfall.txt", "r");

    /* Read rainfall data and calculate totals */
    this_year_total = 0.0;
    last_year_total = 0.0;
    for (i = 0; i < 12; i++) {
        fscanf(rainfall, "%lf %lf", &this_year[i], &last_year[i]);
        this_year_total += this_year[i];
        last_year_total += last_year[i];
    }
    this_year_avg = this_year_total / 12.0;
    last_year_avg = last_year_total / 12.0;

    printf("%16cTable of monthly rainfall\n%11c", ' ', ' ');

    /* Display month names */
    for (i = 0; i < 12; i++) {
        printf("%12s", month_names[i]);
    }
    printf("\n");

    /* Display rainfall statistics for this year */
    printf("This year  ");
    for (i = 0; i < 12; i++) {
        printf("%12.1f", this_year[i]);
    }
    printf("\n");

    /* Display rainfall statistics for last year */
    printf("Last year  ");
    for (i = 0; i < 12; i++) {
        printf("%12.1f", last_year[i]);
    }
    printf("\n");

    /* Display totals and averages */
    printf("Total rainfall this year:%6.1f\n", this_year_total);
    printf("Total rainfall last year:%6.1f\n", last_year_total);
    printf("Average monthly rainfall for this year:%6.1f\n", this_year_avg);
    printf("Average monthly rainfall for last year:%6.1f\n", last_year_avg);

    fclose(rainfall);

    return (0);
}
