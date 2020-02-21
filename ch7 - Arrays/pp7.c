/*
 * Program Description: To normalize vectors
 * Input: a vector
 * Output: normalized vector
 */

#include <stdio.h>
#include <math.h>

#define MAX_SIZE 10
#define SENTINEL -1

int scan_vector(double vector[]);
void normalize_vector(double vector[], int size);
void print_vector(double vector[], int size);

int
main(void)
{
    double vector[MAX_SIZE];    /* The vector */
    int size;                   /* Size of vector */

    size = scan_vector(vector);
    while (size != SENTINEL) {
        normalize_vector(vector, size);

        printf("Normalized vector: ");
        print_vector(vector, size);

        size = scan_vector(vector);
    }

    return (0);
}

/*
 * Scans a vector and fills vector[]
 * Returns size of vector
 */
int
scan_vector(double vector[])
{
    int size;       /* Size of vector */
    int i;          /* Loop index */

    printf("Enter size of vector (%d to quit): ", SENTINEL);
    scanf("%d", &size);

    if (size != SENTINEL) {
        printf("Enter vector: ");
        for (i = 0; i < size; i++) {
            scanf("%lf", &vector[i]);
        }
    }

    return (size);
}

/*
 * Normalizes a vector
 */
void
normalize_vector(double vector[], int size)
{
    int i;          /* Loop index*/
    double sum_sq;  /* Sum of squares of all original vector's elements */
    double root;    /* Square root of sum of squares */

    sum_sq = 0.0;
    for (i = 0; i < size; i++) {
        sum_sq += vector[i] * vector[i];
    }

    root = sqrt(sum_sq);

    for (i = 0; i < size; i++) {
        vector[i] = vector[i] / root;
    }
}

/*
 * Prints a vector
 */
void
print_vector(double vector[], int size)
{
    int i;      /* Loop index */

    printf("<  ");
    for (i = 0; i < size; i++) {
        printf("%.2f  ", vector[i]);
    }
    printf(">\n\n");
}
