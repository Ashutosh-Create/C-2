/*
 * Name: Abhijit Parida		Date: 11-01-17
 * Program: pp10.c
 * Program Description: To find the equation of the perpendicular bisector
 *	of the line segment between two points
 * Inputs: x1, x2, y1, y2
 * Output: equation of perpendicular bisector
 * Algorithm:
 *	1. Get the coordinates of two points
 * 	2. Calculate slope and midpoint of the line joining the two points
 *	3. Calculate slope and y-intercept of the perpendicular bisector
 *	4. Display equation of the perpendicular bisector
 */

#include <stdio.h>

int
main(void)
{
	double x1, y1; // coordinates of the first point
	double x2, y2; // coordinates of the second point
	double m1; // slope of the line
	double m2; // slope of perpendicular bisector
	double mid_x, mid_y; // coordinates of the midpoint
	double b; // y intercept of perpendicular bisector
	
	/* Get the coordinates of the points */
	printf("Enter coordinates of first point: ");
	scanf("%lf%lf", &x1, &y1);
	printf("Enter coordinates of second point: ");
	scanf("%lf%lf", &x2, &y2);

	/* Calculate slope of the line */
	m1 = (y2 - y1) / (x2 - x1);

	/* Calculate coordinates of the midpoint */
	mid_x = (x1 + x2) / 2.0;
	mid_y = (y1 + y2) / 2.0;

	/* Calculate slope of the perpendicular bisector */
	m2 = -1.0 / m1;

	/* Calculate y intercept of the perpendicular bisector */
	b = mid_y - m2 * mid_x;

	/* Display the points and equation of perpendicular bisector */
	printf("The two points are: (%.2f, %.2f) and (%.2f, %.2f)\n",
		x1, y1, x2, y2);
	printf("Equation of perpendicular bisector is y = %.2f x + %.2f\n",
		m2, b);
	
	return(0);
}
