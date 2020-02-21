/*
 * Program Descriptipn: To calculate how much longer the life expectancy of
 *      black and white women than men of the same races in each decade from
 *      year 1950 to year 2000
 * Input: life expectency of black/white men/women
 * Output: how much longer life expectency was
 */

#include <stdio.h>

#define BLACK 0
#define WHITE 1

void matrix_read(FILE *file, double matrix[6][2]);
void matrix_diff(double a[6][2], double b[6][2], double c[6][2]);
void matrix_display(double matrix[6][2]);

int
main(void)
{
    FILE *female;       /* Life expectency of black and white females */
    FILE *male;         /* Life expectency of black and white males */
    double female_matrix[6][2];
    double male_matrix[6][2];
    double diff_matrix[6][2];

    female = fopen("female.txt", "r");
    male = fopen("male.txt", "r");

    /* Read data from file */
    matrix_read(female, female_matrix);
    matrix_read(male, male_matrix);

    /* Calculate how much longer life expectency was */
    matrix_diff(female_matrix, male_matrix, diff_matrix);

    /* Display results */
    printf("Female\n");
    matrix_display(female_matrix);
    printf("\nMale\n");
    matrix_display(male_matrix);
    printf("\nHow much longer life expectency was\n");
    matrix_display(diff_matrix);

    fclose(female);
    fclose(male);

    return (0);
}

/*
 * Fills up a matrix from input file
 */
void
matrix_read(FILE *file, double matrix[6][2])
{
    int i;      /* Loop index */

    for (i = 0; i < 6; i++) {
        fscanf(file, "%lf %lf", &matrix[i][BLACK], &matrix[i][WHITE]);
    }
}

/*
 * Calculates matrix c = matrix a - matrix b
 */
void
matrix_diff(double a[6][2], double b[6][2], double c[6][2])
{
    int i;      /* Loop index */

    for (i = 0; i < 6; i++) {
        c[i][BLACK] = a[i][BLACK] - b[i][BLACK];
        c[i][WHITE] = a[i][WHITE] - b[i][WHITE];
    }
}

/*
 * Displays life expectency matrix with appropriate year labels
 */
void
matrix_display(double matrix[6][2])
{
    int i;          /* Loop index */
    int year;       /* Year */

    printf("%10s%10s%10s\n", "Year", "Black", "White");
    for (i = 0, year = 1950; i < 6; i++, year += 10) {
        printf("%10d%10.1f%10.1f\n", year, matrix[i][BLACK], matrix[i][WHITE]);
    }
}
