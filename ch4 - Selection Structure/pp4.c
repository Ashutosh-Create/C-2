/*
 * Name: Abhijit Parida 	Date: 25-01-17
 * Program Description: To find contents of compressed gas cylinders
 * Input: cylinder color
 * Output: contents of cylinder
 * Algorithm:
 *	1. Get cylinder color
 *	2. Find contents of cylinder according to color
 *	3. Display contents of cylinder
 */

#include <stdio.h>

int
main(void)
{
	char color;

	/* Get cylinder color */
	printf("Enter cylinder color: ");
	scanf(" %c", &color);

	/* Display contents of cylinder */
	switch(color) {
		case 'o':
		case 'O':
			printf("Ammonia\n");
			break;

		case 'b':
		case 'B':
			printf("Carbon onoxide\n");
			break;

		case 'y':
		case 'Y':
			printf("Hydrogen\n");
			break;

		case 'g':
		case 'G':
			printf("Oxygen\n");
			break;

		default:
			printf("Contents unknown\n");
	}

	return (0);
}
