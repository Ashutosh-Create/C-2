/*
 * Program Description: To convert from two-point form and point-slope form
 *      to slope-intercept form
 * Input: line in two-point form or point-slope form
 * Output: line in slope-intercept form
 */

#include <stdio.h>

int get_problem();
void get2_pt(double *x1, double *y1, double *x2, double *y2);
void get_pt_slope(double *x, double *y, double *slope);
void slope_intcpt_from2_pt(double x1, double y1, double x2, double y2,
    double *slope, double *b);
double intcpt_from_pt_slope(double x, double y, double slope);
void display2_pt(double x1, double y1, double x2, double y2);
void display_pt_slope(double x, double y, double slope);
void display_slope_intcpt(double slope, double b);

int
main(void)
{
    double x1, y1;              /* x-y coordinates of first point */
    double x2, y2;              /* x-y coordinates of second point */
    double slope;               /* Slope of line */
    double b;                   /* y-intercept */
    int problem;                /* Problem number */
    char another;               /* Y/N for another conversion */

    do {
        problem = get_problem();

        switch (problem) {
            case 1:  /* Convert from two-point form to slope-intercept form */
                get2_pt(&x1, &y1, &x2, &y2);
                slope_intcpt_from2_pt(x1, y1, x2, y2, &slope, &b);
                display2_pt(x1, y1, x2, y2);
                display_slope_intcpt(slope, b);
                break;

            case 2:  /* Convert from point-slope to slope-intercept form */
                get_pt_slope(&x1, &y1, &slope);
                b = intcpt_from_pt_slope(x1, y1, slope);
                display_pt_slope(x1, y1, slope);
                display_slope_intcpt(slope, b);
                break;

            default:
                printf("Invalid choice\n");
        }

        printf("\nDo another conversion? (Y or N): ");
        scanf(" %c", &another);
    } while (another == 'Y');

    return (0);
}

/*
 * Displays user menu
 * Returns problem number
 */
int
get_problem()
{
    int problem;

    printf("\nSelect the form that you would line to convert to ");
    printf("slope-intercept form:\n");
    printf("1) Two-point form (you know two points on the line)\n");
    printf("2) Point-slope form (you know the line's slope and one point)\n");
    printf("=> ");
    scanf("%d", &problem);

    return problem;
}

/*
 * Prompts user to enter data for problem 1
 * Returns x-y coordinates of two points
 */
void
get2_pt(double *x1, double *y1, double *x2, double *y2)
{
    printf("\nEnter the x-y coordinates of first point separated by a space: ");
    scanf("%lf%lf", x1, y1);
    printf("Enter the x-y coordinates of second point separated by a space: ");
    scanf("%lf%lf", x2, y2);
}

/*
 * Prompts user to enter data for problem 2
 * Returns x-y coordinates of a point and slope of line
 */
void
get_pt_slope(double *x, double *y, double *slope)
{
    printf("\nEnter the slope: ");
    scanf("%lf", slope);
    printf("Enter the x-y coordinates of point separated by a space: ");
    scanf("%lf%lf", x, y);
}

/*
 * Returns slope and y-intercept
 * Pre: x-y coordinates of two points
 */
void
slope_intcpt_from2_pt(double x1, double y1, double x2, double y2,
    double *slope, double *b)
{
    *slope = (y2 - y1) / (x2 - x1);
    *b = intcpt_from_pt_slope(x1, y1, *slope);
}

/*
 * Returns y-intercept
 * Pre: x-y coordinates of a point and slope
 */
double
intcpt_from_pt_slope(double x, double y, double slope)
{
    double b;

    b = y - slope * x;

    return (b);
}

/*
 * Displays the two-point line equation with a heading
 * Pre: x-y coordinates of two points
 */
void
display2_pt(double x1, double y1, double x2, double y2)
{
    printf("\nTwo point form\n");
    printf("    (%.2f - %.2f)\n", y2, y1);
    printf("m = -------------------\n");
    printf("    (%.2f - %.2f)\n", x2, x1);
}

/*
 * Displays the point-slope line equation with a heading
 * Pre: x-y coordinates of a point, slope
 */
void
display_pt_slope(double x, double y, double slope)
{
    printf("\nPoint slope form\n");
    printf("  y - %.2f = %.2f(x - %.2f)\n", y, slope, x);
}

/*
 * Displays the slope-intercept line equation with a heading
 * Pre: slope, y-intercept
 */
void
display_slope_intcpt(double slope, double b)
{
    printf("\nSlope-intercept form\n");
    printf("  y = %.2fx + %.2f\n", slope, b);
}
