/*
 * Program description: To calculate area of a closed polygon
 * Input: (x, y) coordinates of the corners
 * Output: Area of polygon
 */

#include <stdio.h>
#include <math.h>

#define MAX_SIZE 20
#define INPUT_FILE "polygon_input.txt"
#define OUTPUT_FILE "polygon_output.txt"

int get_corners(FILE *input_file, double x[], double y[], int max_size);
void output_corners(FILE *output_file, double x[], double y[], int size);
double polygon_area(double x[], double y[], int size);

int
main(void)
{
    FILE *input_file, *output_file;     /* Input and output files */
    double x[MAX_SIZE], y[MAX_SIZE];    /* Arrays of x and y coordinates */
    int size;                           /* Number of (x, y) coordinates */
    double area;                        /* Area of the polygon */

    input_file = fopen(INPUT_FILE, "r");
    output_file = fopen(OUTPUT_FILE, "w");

    size = get_corners(input_file, x, y, MAX_SIZE);
    output_corners(output_file, x, y, size);
    area = polygon_area(x, y, size);

    printf("Area of polygon = %.3f square units\n", area);

    fclose(input_file);
    fclose(output_file);

    return (0);
}

/*
 * Takes an input file, arrays x and y, and the max array size as parameters.
 * Fills the arrays with data from input file and returns number of (x, y)
 * coordinates.
 */
int
get_corners(FILE *input_file, double x[], double y[], int max_size)
{
    int input_status;
    int i;

    i = 0;
    input_status = fscanf(input_file, "%lf %lf", &x[i], &y[i]);
    while (i < max_size - 1 && input_status == 2) {
        i++;
        input_status = fscanf(input_file, "%lf %lf", &x[i], &y[i]);
    }

    x[i] = x[0];
    y[i] = y[0];

    return (i + 1);
}

/*
 * Takes an output file, arrays x and y, and array size as parameters.
 * Writes the contents of the arrays to the output file.
 */
void
output_corners(FILE *output_file, double x[], double y[], int size)
{
    int i;

    fprintf(output_file, "x\ty\n");
    for (i = 0; i < size; i++) {
        fprintf(output_file, "%.2f\t%.2f\n", x[i], y[i]);
    }
}

/*
 * Takes arrays x and y, and array size as parameters.
 * Returns the area of the polygon formed by joining the (x, y) coordinates.
 */
double
polygon_area(double x[], double y[], int size)
{
    double sum;
    int i;
    double area;

    sum = 0.0;
    for (i = 0; i <= size - 2; i++) {
        sum += ((x[i+1] + x[i]) * (y[i+1] - y[i]));
    }

    area = 0.5 * fabs(sum);

    return area;
}
