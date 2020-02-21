/*
 * Program Description: To calculate center of gravity of 3D point mass system
 * Input: File containing point mass system
 * Output: Point mass system with meaningful labels
 */

#include <stdio.h>

#define MAX_PTS 10
#define X 0
#define Y 1
#define Z 2

int fget_point_mass(FILE *input, int max_n, int location[][3], int mass[]);
void center_grav(int location[][3], int mass[], int n, double center[3]);
void fwrite_point_mass(FILE *output, int location[][3], int mass[], int n);

int
main(void)
{
    int location[MAX_PTS][3];   /* Location matrix */
    int mass[MAX_PTS];          /* Mass vector */
    int n;                      /* Number of points */
    FILE *input;                /* Input file - "pointmass_input.txt" */
    FILE *output;               /* Output file - "pointmass_output.txt" */

    input = fopen("pointmass_input.txt", "r");
    output = fopen("pointmass_output.txt", "w");

    n = fget_point_mass(input, MAX_PTS, location, mass);
    fwrite_point_mass(output, location, mass, n);

    fclose(input);
    fclose(output);

    return (0);
}

/*
 * Takes an open input file and a maximum value for n as parameters and fills
 * a two-dimensional array output parameter with a location matrix and a one-
 * dimensional array output parameter with a mass vector from the data file
 *
 * Returns the actual value of n
 */
int
fget_point_mass(FILE *input, int max_n, int location[][3], int mass[])
{
    int i;      /* Loop index */
    int n;      /* Number of points */

    fscanf(input, "%d", &n);

    if (n > max_n) {
        n = max_n;
    }

    for (i = 0; i < n; i++) {
        fscanf(input, "%d %d %d %d", &location[i][X], &location[i][Y],
            &location[i][Z], &mass[i]);
    }

    return n;
}

/*
 * Takes a location matrix, mass vector, and n value as parameters and returns
 * the center of gravity as output parameter
 */
void
center_grav(int location[][3], int mass[], int n, double center[3])
{
    int i;              /* Loop index */
    int total_mass;     /* Sum of mass of all points */

    total_mass = 0;
    for (i = 0; i < n; i++) {
        total_mass += mass[i];
    }

    center[X] = 0.0;
    center[Y] = 0.0;
    center[Z] = 0.0;
    for (i = 0; i < n; i++) {
        center[X] += mass[i] * location[i][X];
        center[Y] += mass[i] * location[i][Y];
        center[Z] += mass[i] * location[i][Z];
    }
    center[X] /= (double) total_mass;
    center[Y] /= (double) total_mass;
    center[Z] /= (double) total_mass;
}

/*
 * Takes an open output file and the location matrix, mass vector, and n value
 * of a point-mass system as parameters and writes the system to the file with
 * meaningful labels
 */
void
fwrite_point_mass(FILE *output, int location[][3], int mass[], int n)
{
    int i;
    double center[3];

    fprintf(output, "    Point     Mass\n");
    for (i = 0; i < n; i++) {
        fprintf(output, "(%2d, %2d, %2d)   %d\n", location[i][X],
            location[i][Y], location[i][Z], mass[i]);
    }

    center_grav(location, mass, n, center);
    fprintf(output, "\nCenter of gravity: (%.2f, %.2f, %.2f)\n",
        center[X], center[Y], center[Z]);
}
