/*
 * Name: Abhijit Parida		Date: 27-01-17
 * Program Description: To check if emissions exceed permitted levels
 * Inputs: pollutant number, grams emitted per mile, odometer reading
 * Output: if emissions exceed permitted levels or not
 * Algorithm:
 *  1. Display list of pollutants
 *	2. Get pollutant number, grams emitted per mile and odometer reading
 *	2. Check if emissions exceed permitted levels
 */

#include <stdio.h>

int
main(void)
{
	int pollutant_number;
	double grams_per_mile;
	int odometer_reading;

	/* Display list of pollutants */
	printf("(1) Carbon monoxide\n");
	printf("(2) Hydrocarbon\n");
	printf("(3) Nitrogen oxides\n");
	printf("(4) Nonmethane hydrocarbons\n");

	/* Get pollutant number, grams emitted per mile and odometer reading */
	printf("Enter pollutant number: ");
	scanf("%d", &pollutant_number);
	printf("Enter number of grams emitted per mile: ");
	scanf("%lf", &grams_per_mile);
	printf("Enter odometer reading: ");
	scanf("%d", &odometer_reading);

	/* Check if emissions exceed permitted levels */
	switch (pollutant_number) {
		case 1:
		if (odometer_reading < 50000 && grams_per_mile > 3.4) {
			printf("Emissions exceed permitted levels of 3.4 grams/mile\n");
		} else if (odometer_reading > 50000 && grams_per_mile > 4.2) {
			printf("Emissions exceed permitted levels of 4.2 grams/mile\n");
		} else {
			printf("Emission is under limits\n");
		}
		break;

		case 2:
		if (odometer_reading < 50000 && grams_per_mile > 0.31) {
			printf("Emissions exceed permitteid levels of 0.31 grams/mile\n");
		} else if (odometer_reading > 50000 && grams_per_mile > 0.39) {
			printf("Emissions exceed permitteid levels of 0.39 grams/mile\n");
		} else {
			printf("Emission is under limits\n");
		}
		break;

		case 3:
		if (odometer_reading < 50000 && grams_per_mile > 0.4) {
			printf("Emissions exceed permitteid levels of 0.4 grams/mile\n");
		} else if (odometer_reading > 50000 && grams_per_mile > 0.5) {
			printf("Emissions exceed permitteid levels of 0.5 grams/mile\n");
		} else {
			printf("Emission is under limits\n");
		}
		break;

		case 4:
		if (odometer_reading < 50000 && grams_per_mile > 0.25) {
			printf("Emissions exceed permitteid levels of 0.25 grams/mile\n");
		} else if (odometer_reading > 50000 && grams_per_mile > 0.31) {
			printf("Emissions exceed permitteid levels of 0.31 grams/mile\n");
		} else {
			printf("Emission is under limits\n");
		}
		break;

		default:
		printf("Unknown pollutant\n");
	}

	return (0);
}
