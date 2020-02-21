/*
 * Program Description: To calculate when revenues will exceed $1 trillion
 *      and create a table of estimated revenues for all years
 * Output: table of revenues
 */

#include <stdio.h>
#include <math.h>

#define BASE_YEAR 1984
#define MAX_REV 1000    /* $1000 million */

double revenue(int t);
int predict(double revenues);

int
main(void)
{
    FILE *revenues;
    int exceed_year, year;

    revenues = fopen("revenues.txt", "w");

    /* Find when revenues will exceed $1 trillion */
    exceed_year = predict(MAX_REV);

    /* Create table of estimated revenues for all years from 1984 thru
    the year when the revenues should exceed $1 trillion */
    fprintf(revenues, "Year  Revenues (in million dollars)\n");
    for (year = BASE_YEAR; year <= exceed_year; year++) {
        fprintf(revenues, "%d  %.3f\n", year, revenue(year - BASE_YEAR));
    }

    fclose(revenues);

    return (0);
}

/*
 * Calculates revenue for a year
 * Pre: t (years since 1984)
 */
double
revenue(int t)
{
    return (203.265 * pow(1.071, t));
}

/*
 * Calculates the year in which revenues will first equal or exceed the
 * given revenues
 * Pre: revenues (in millions)
 */
int
predict(double revenues)
{
    int year;

    year = 0;
    while (revenue(year) < revenues) {
        year++;
    }

    return (BASE_YEAR + year);
}
