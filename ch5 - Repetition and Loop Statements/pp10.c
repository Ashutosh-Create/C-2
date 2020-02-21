/*
 * Name: Abhijit Parida		Date: 15-02-17
 * Program Description: To display the relationship between the pressure
 *	and the volume of n moles of co2 at constant absolute temperature
 * Input: moles of co2, temperature, initial & final volume
 * Output: relationship between volume and pressure
 * Algorithm:
 *	1. Get quantity, temperature and volume
 *	2. Display number of moles of co2
 *	3. Display tabular relationship between volume and pressure
 */

#include <stdio.h>

#define A 3.592
#define B 0.0427
#define R 0.08206

int
main(void)
{
	double moles;		/* Quantity of co2 */
	int temperature;	/* Temperature in kelvin */
	int initial_volume;	/* Initial volume in milliliters */
	int final_volume;	/* Final volume in milliliters */
	int volume_increment;	/* Incrememnt amount */
	int v;

	double volume;
	double pressure;

	/* Get quantity, temperature and volume */
	printf("Quantity of carbon dioxide (moles)> ");
	scanf("%lf", &moles);
	printf("Temperature (kelvin)> ");
	scanf("%d", &temperature);
	printf("Initial volume (milliliters)> ");
	scanf("%d", &initial_volume);
	printf("Final volume (milliliters)> ");
	scanf("%d", &final_volume);
	printf("Volume increment (milliliters)> ");
	scanf("%d", &volume_increment);

	/* Display number of moles of co2 */
	printf("%.4f moles of carbon dioxide at %d kelvin\n",
		moles, temperature);

	/* Display tabular relationship between volume and pressure */
	printf("Volume (ml)\tPressure (atm)\n");
	for (v = initial_volume;
		v <= final_volume;
		v += volume_increment) {
		volume = v / 1000.0;
		pressure = (moles * R * temperature) / (volume - B * moles)
			- (A * moles * moles) / (volume * volume);
		printf("%d\t\t%.4f\n", v, pressure);
	}

	return (0);
}
