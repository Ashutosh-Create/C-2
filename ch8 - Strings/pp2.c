/*
 * Name: Abhijit Parida		Date: 31-03-2017
 * Program Description: To find resistance value of a resister given the
 *	band colors.
 * Input: colors of band 1, band 2 and band 3
 * Output: Resistance value
 */

#include <stdio.h>
#include <string.h>
#include <math.h>

#define NUM_COLORS 10

double decode_resister(int b1, int b2, int b3);
int search(char codes[][7], int size, char target[]);

int
main(void)
{
	char band1[7], band2[7], band3[7];
	int b1, b2, b3;
	char COLOR_CODES[NUM_COLORS][7] = {"black", "brown", "red", "orange",
		"yellow", "green", "blue", "violet", "gray", "white"};
	double resistance;
	char another;

	do {
		printf("Enter the colors of the resistor's three bands, \n");
		printf("beginning with the band nearest the end. Type \n");
		printf("the colors in lowercase letters only, NO CAPS.\n");

		printf("Band 1: ");
		scanf("%s", band1);
		b1 = search(COLOR_CODES, NUM_COLORS, band1);

		printf("Band 2: ");
		scanf("%s", band2);
		b2 = search(COLOR_CODES, NUM_COLORS, band2);

		printf("Band 3: ");
		scanf("%s", band3);
		b3 = search(COLOR_CODES, NUM_COLORS, band3);

		if (b1 == -1) {
			printf("Invalid color %s\n", band1);
		} else if (b2 == -1) {
			printf("Invalid color %s\n", band2);
		} else if (b3 == -1) {
			printf("Invalid color %s\n", band3);
		} else {
			resistance = decode_resister(b1, b2, b3);
			printf("Resistance value: %.2f kilo-ohms\n", resistance);
		}

		printf("Do you want to decode another resistor? (y/n) ");
		scanf(" %c", &another);
	} while (another == 'y');

	return (0);
}

/*
 * Calculates resistance of a register from band numbers
 */
double
decode_resister(int b1, int b2, int b3)
{
	return (b1 * 10 + b2) * pow(10, b3) / 1000;
}

/*
 * Finds the position of target in list of codes
 * Returns position if found, -1 otherwise
 */
int
search(char codes[][7], int size, char target[])
{
	int i;

	for (i = 0; i < size; i++) {
		if (strcmp(target, codes[i]) == 0) {
			return i;
		}
	}

	return -1;
}
