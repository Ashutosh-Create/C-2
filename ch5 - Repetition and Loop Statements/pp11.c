/*
 * Name: Abhijit Parida		Date: 15-02-17
 * Program Description: To calculate flow of water
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define DEPTH 10.0	/* 10 feet deep */
#define WIDTH 15.0	/* 15 feet wide */
#define SLOPE 0.0015	/* slope 0.0015 feet/foot */
#define ROUGHNESS 0.014	/* roughness coefficient */
#define TARGET 1000.0	/* target flow */
#define TOLERANCE 0.1	/* error tolerance 0.1% */

double water_flow(double roughness, double width, double depth, double slope);

int
main(void)
{
	double flow, depth, error;

	depth = DEPTH/2.0;
	flow = water_flow(ROUGHNESS, WIDTH, depth, SLOPE);
	printf("At a depth of %.4f feet, the flow is %.4f\n",
		depth, flow);

	printf("Enter guess> ");
	scanf("%lf", &depth);
	flow = water_flow(ROUGHNESS, WIDTH, depth, SLOPE);
	error = (TARGET - flow) / TARGET * 100;
	while (abs(error) > TOLERANCE) {
		printf("Depth: %.4f Flow: %.4f cfs Target: %.4f cfs\n",
			depth, flow, TARGET);
		printf("Difference: %.4f Error %.4f percent\n",
			TARGET - flow, error);

		printf("Enter guess> ");
		scanf("%lf", &depth);
		flow = water_flow(ROUGHNESS, WIDTH, depth, SLOPE);
		error = (TARGET - flow) / TARGET * 100;
	}

	return (0);
}

double water_flow(double roughness, double width, double depth, double slope) {
	double area;
	double radius;
	double flow;

	area = depth * width;
	radius = (depth * width) / (2 * depth + width);
	flow = (1.486 / roughness) * area * pow(radius, 2.0/3.0)
		* pow(slope, 1.0/2.0); 

	return flow;
}
