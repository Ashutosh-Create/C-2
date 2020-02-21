/*
 * Name: Abhijit Parida		Date: 07-01-17
 * Program name: pp7.c
 * Program description: To calculate the BTU's of energy generated
 *	given gallons of oil and efficiency of furnace.
 * Inputs: oil_volume, efficiency
 * Output: energy
 * Algorithm:
 *	1. Get the gallons of oil burned and efficiency of furnace
 * 	2. Calculate and display the energy generated
 */

#include <stdio.h>

#define ENERGY_PER_GALLON 138095.23

int
main(void)
{
	int oil_volume;	/* Gallons of oil burned */
	int efficiency;	/* Efficieny of oil furnace */
	double energy;	/* BTU's of energy generated */

	/* Get the gallons of oil burned and efficiency of furnace */
	printf("Enter number of gallons of oil: ");
	scanf("%d", &oil_volume);
	printf("Enter efficiency of oil furnace: ");
	scanf("%d", &efficiency);

	/* Calculate and display the energy generated */
	energy = oil_volume * ENERGY_PER_GALLON * efficiency / 100;
	printf("Energy generated = %.2f BTUs\n", energy);

	return (0);
}
