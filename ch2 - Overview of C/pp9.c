/*
 * Name: Abhijit Parida		Date: 11-01-17
 * Program name: pp9.c
 * Program description: To calculate the time required to cut grass
 * Inputs: yard_length, yard_width, house_length, house_width
 * Outputs: time_to_cut
 * Algorithm:
 *	1. Get the length and width of the yard and house
 *	2. Calculate area of yard and house
 *	3. Calculate area of grass by subtracting house area from yard area
 *	4. Find rate of cutting grass and display it
 */

#include <stdio.h>

#define CUTTING_RATE 0.5

int
main(void)
{
	double yard_length, yard_width;
	double house_length, house_width;
	double yard_area;
	double house_area;
	double grass_area;
	double time_to_cut;

	printf("Enter length and width of yard: ");
	scanf("%lf%lf", &yard_length, &yard_width);
	printf("Enter length and width of house: ");
	scanf("%lf%lf", &house_length, &house_width);

	yard_area = yard_length * yard_width;
	house_area = house_length * house_width;
	grass_area = yard_area - house_area;

	time_to_cut = grass_area * CUTTING_RATE;
	printf("Time required to cut the grass is %f\n", time_to_cut);

	return(0);
}
