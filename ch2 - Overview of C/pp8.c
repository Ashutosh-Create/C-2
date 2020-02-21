/*
 * Name: Abhijt Parida		Date: 07-01-17
 * Program name: pp8.c
 * Program description: To estimate the magnitude and cost of water saved.
 * Inputs: population
 * Outputs: water_saved, cost
 * Algorithm:
 * 	1. Get the population of the city
 * 	2. Calculate number of toilets and number of flushes per day
 * 	3. Calculate liters of water saved per day
 * 	4. Calculate cost of installing new toilets
 * 	5. Display the amount of water saved and the cost
 */
#include <stdio.h>

int
main(void)
{
	int population;		/* Population of the city */
	int toilets;		/* Number of toilets */
	int flushes;		/* Flushes per day */
	int liters_flushed_old;	/* Water flushed in old toilet */
	int liters_flushed_new;	/* Water flushed in new toilet */
	int water_saved;	/* Liters of water saved per day */
	int cost;		/* Cost of installing new toilets */

	/* Get the population of the city */
	printf("Enter population of city: ");
	scanf("%d", &population);

	/* Calculate number of toilets and number of flushes per day */
	toilets = population / 3;
	flushes = toilets * 14;

	/* Calculate liters of water saved per day */
	liters_flushed_old = flushes * 15;
	liters_flushed_new = flushes * 2;
	water_saved = liters_flushed_old - liters_flushed_new;

	/* Calculate cost of installing new toilets */
	cost = toilets * 150;

	/* Display the amount of water saved and the cost */
	printf("Amount of water saved: %d liters per day\n", water_saved);
	printf("Cost of installing new toilets: $%d\n", cost);

	return (0);
}
