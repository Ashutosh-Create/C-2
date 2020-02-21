/*
 * Name: Abhijit Parida		Date: 25-01-17
 * Program Description: To take the x-y coordinates of a point in the
 *	Cartesian plane and print a message telling on which axis or quadrant
 *	the point lies
 * Input: x and y coordinates of a point
 * Output: axis or quadrant on which the point lies
 * Algorithm:
 *	1. Get the coordinates of the point
 *	2. Display on which axis or quadrant the point lies
 */

#include <stdio.h>

int
main(void)
{
	double x, y;

	/* Get the coordinates of the point */
	printf("Enter coordinates (x, y): ");
	scanf("%lf%lf", &x, &y);

	/* Display on which axis or quadrant the point lies */
	if (x == 0 && y == 0) {
		printf("(%.2f, %.2f) is on the origin\n", x, y);
	} else if (x == 0) {
		printf("(%.2f, %.2f) is on the y-axis\n", x, y);
	} else if (y == 0) {
		printf("(%.2f, %.2f) is on the x-axis\n", x, y);
	} else if (x > 0 && y > 0) {
		printf("(%.2f, %.2f) is in quadrant I\n", x, y);
	} else if (x < 0 && y > 0) {
		printf("(%.2f, %.2f) is in quadrant II\n", x, y);
	} else if (x < 0 && y < 0) {
		printf("(%.2f, %.2f) is in quadrant III\n", x, y);
	} else if (x > 0 && y < 0) {
		printf("(%.2f, %.2f) is in quadrant IV\n", x, y);
	}

	return (0);
}
