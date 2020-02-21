/*
 * Name: Abhijit Parida		Date: 27-01-17
 * Program Description: To compute baking time for a bread machine
 * Input: bread type, double loaf, manual baking
 * Output: baking times
 */

#include <stdio.h>

int
main(void)
{
	char bread_type;
	char double_loaf;
	char manual_bake;

	/* Get bread type, double loaf and manual baking */
	printf("Enter bread type, white or sweet [W/S]: ");
	scanf(" %c", &bread_type);
	printf("Loaf size double? [y/n]: ");
	scanf(" %c", &double_loaf);
	printf("Manual baking? [y/n]: ");
	scanf(" %c", &manual_bake);

	/* Display baking times */
	if (bread_type == 'W') {
		printf("White Bread\n");
		printf("Primary kneading: 15 mins\n");
		printf("Primary rising: 60 mins\n");
		printf("Secondary kneading: 18 mins\n");
		printf("Secondary rising: 20 mins\n");
		printf("Loaf shaping: 2 seconds\n");
		if (manual_bake == 'y') {
			printf("Manual baking mode selected\n");
			printf("Remove dough for manual baking\n");
		} else {
			printf("Final rising: 75 mins\n");
			if (double_loaf == 'y') {
				printf("Baking: 67.5 mins\n");
			} else {
				printf("Baking: 45 mins\n");
			}
			printf("Cooling: 30 mins\n");
		}
	} else if (bread_type == 'S') {
		printf("Sweet Bread\n");
		printf("Primary kneading: 20 mins\n");
		printf("Primary rising: 60 mins\n");
		printf("Secondary kneading: 33 mins\n");
		printf("Secondary rising: 30 mins\n");
		printf("Loaf shaping: 2 seconds\n");
		if (manual_bake == 'y') {
			printf("Manual baking mode selected\n");
			printf("Remove dough for manual baking\n");
		} else {
			printf("Final rising: 75 mins\n");
			if (double_loaf == 'y') {
				printf("Baking: 52.5 mins\n");
			} else {
				printf("Baking: 35 mins\n");
			}
			printf("Cooling: 30 mins\n");
		}
	}

	return (0);
}
