/*
 * Name: Abhijit Parida		Date: 15-02-17
 * Program Description: To process a collection of daily high temperatures.
 * Input: collection of daily high temperatures
 * Output: number of hot days, pleasant days & cold days, and average temp
 * Algorithm:
 *	1. Read temperatures from input file
 *	2. If temperature is 85 or higher
 *		3. Increment number of hot days
 *	4. Else if temperature is 60 to 84
 *		5. Increment number of pleasant days
 *	6. Else increment number of cold days
 *	7. Calculate average temperature
 *	8. Display number of hot, pleasant and cold days
 *	9. Display average temperature
 */

#include <stdio.h>

int
main(void)
{
	int temperature;
	int hot_days, pleasant_days, cold_days;
	int n, sum;
	double average;
	int input_status;

	/* Initialize counter variables */
	hot_days = 0;
	pleasant_days = 0;
	cold_days = 0;
	sum = 0;
	n = 0;

	/* Read temperatures until end of file */
	input_status = scanf("%d", &temperature);
	while (input_status == 1) {
		printf("Temperature = %d ", temperature);

		/* Classify temperatures into hot, cold or pleasant */
		if (temperature >= 85) {
			printf("category: hot day\n");
			hot_days++;
		} else if (temperature >= 60) {
			printf("category: pleasant day\n");
			pleasant_days++;
		} else {
			printf("category: cold day\n");
			cold_days++;
		}

		/* Increment sum and number of temperatures */
		sum += temperature;
		n++;

		input_status = scanf("%d", &temperature);
	}

	/* Calculate average */
	average = sum / (double) n;

	/* Display number of hot, pleasant and cold days */
	printf("Number of hot days = %d\n", hot_days);
	printf("Number of pleasant days = %d\n", pleasant_days);
	printf("Number of cold days = %d\n", cold_days);

	/* Display average temperature */
	printf("Average temperature = %.2f\n", average);

	return (0);
}
