/*
 * Name: Abhijit Parida		Date: 14-01-17
 * Program Description: To find the cost of making cylindrical containers
 * Constants: PI
 * Inputs: radius and height of container, cost per sq cm, number of containers
 * Output: cost of each container and cost of producing all containers
 * Algorithm:
 *	1. Get the radius of circular base, height of container, cost per
 *	sq cm of material and number of containers
 *	2. Calculate surface area and cost of making each container, and the
 *	cost of making all the containers
 *	3. Display cost of each container and the cost of producing all the
 *	containers
 * Algorithm Refinements:
 *	2.1. base area = PI * radius * radius
 *	2.2. outside area = 2 * PI * radius * height
 *	2.3. surface area = base area + outside area
 *	2.4. cost = surface area * cost per sq cm
 *	2.5. total cost = cost * quantity
 */

#include <stdio.h>

#define PI 3.14159265

void instruct(void);
double surface_area(double radius, double height);

int
main(void)
{
	double radius;		/* Radius of circular base */
	double height;		/* Height of container */
	double cost_per_sqcm;	/* Cost per sq cm of the material */
	int quantity;		/* Number of containers to be produced */
	double area;		/* Total surface area of a container */
	double cost;		/* Cost of a single container */
	double total_cost;	/* Cost of all containers */

	/* Get the radius of circular base, height of container, cost per
	sq cm of material and number of containers */
	instruct();
	scanf("%lf%lf%lf%d", &radius, &height, &cost_per_sqcm, &quantity);

	/* Calculate surface area and cost of making each container, and the
	cost of making all the containers */
	area = surface_area(radius, height);
	cost = area * cost_per_sqcm;
	total_cost = cost * quantity;

	/* Display cost of each container and the cost of producing all the
	containers */
	printf("Surface area of each container is %.3f cm^2\n", area);
	printf("The cost of each container is Rs.%.2f\n", cost);
	printf("Total cost of making %d containers is Rs.%.2f\n", quantity,
		total_cost);

	return (0);
}

/*
 * Displays instructions to the program user
 */
void
instruct(void)
{
	printf("Enter radius of circular base, height of container,\n");
	printf("cost per sq cm of material and number of containers: ");
}

/*
 * Calculates surface area of an open-top cylindrical container
 * Pre: radius, height
 */
double
surface_area(double radius, double height)
{
	double base_area = PI * radius * radius;
	double outside_area = 2 * PI * radius * height;

	return base_area + outside_area;
}
