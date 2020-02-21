/*
 * Name: Abhijit Parida [1541012143]	Date: 06-01-17
 * Program Name: pp5.c
 * Program Description: To output information for labels of I.V. medication
 *	indicating volume of medication to be infused and the infusion rate.
 * Inputs: volume, minutes
 * Output: rate
 * Algorithm:
 *	1. Get the volume to be infused and minutes over which to infuse
 * 	2. Compute the infusion rate in terms of volume per hour
 *	3. Display the VTBI (Volume To Be Infused) and the infusion rate
 */

#include <stdio.h>

int
main (void)
{
	double volume;	/* Volume to be infused */
	int minutes;	/* Minutes over which to infuse */
	double rate;	/* Infusion rate */

	/* Get the volume to be infused and number of minutes */
	printf("Volume to be infused (ml): ");
	scanf("%lf", &volume);
	printf("Minutes over which to infuse: ");
	scanf("%d", &minutes);

	/* Calculate infusion rate */
	rate = volume / (double) minutes * 60.0;

	/* Display the VTBI and infusion rate */
	printf("VTBI: %.2f ml\n", volume);
	printf("Rate: %.2f ml/hr\n", rate);

	return (0);
}
