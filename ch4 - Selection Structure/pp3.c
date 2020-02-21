/*
 * Name: Abhijit Parida		Date: 25-01-17
 * Program Description: To find compass bearing from compass heading
 * Input: compass heading
 * Output: compass bearing
 * Algorithm:
 *	1. Get compass heading
 *	2. Calculate direction to face and how much to turn
 *	3. Display bearing
 */

#include <stdio.h>

int
main(void)
{
	double heading;
	double turn;

	/* Get compass heading */
	printf("Enter compass heading (0 to 360): ");
	scanf("%lf", &heading);

	/* Calculate direction to face and how much to turn */
	if (heading == 0 || heading == 360) {
		printf("North 0.0 degrees East/West\n");
	} else if (heading == 90) {
		printf("North/South 90.0 degrees East\n");
	} else if (heading == 180) {
		printf("South 0.0 degrees East/West\n");
	} else if (heading == 270) {
		printf("North/South 90.0 degrees West\n");
	} else if (heading > 0 && heading < 90) {
		turn = heading;
		printf("North %.1f degrees East\n", turn);
	} else if (heading > 90 && heading < 180) {
		turn = 180 - heading;
		printf("South %.1f degrees East\n", turn);
	} else if (heading > 180 && heading < 270) {
		turn = heading - 180;
		printf("South %.1f degrees West\n", turn);
	} else if (heading > 270 && heading < 360) {
		turn = 360 - heading;
		printf("North %.1f degrees West\n", turn);
	} else {
		printf("Invalid compass heading\n");
	}

	return (0);
}
