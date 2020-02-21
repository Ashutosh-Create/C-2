/*
 * Name: Abhijit Parida		Date: 25-01-17
 * Program Description: To calculate BMI
 * Input: weight, height
 * Output: weight status
 * Algorithm:
 *	1. Get weight and height
 *	2. Calculate BMI
 *	3. Find weight status from BMI and display it
 */

#include <stdio.h>

int
main(void)
{
	double wt_lb, ht_in, bmi;

	/* Get weight and height */
	printf("Enter weight in pounds: ");
	scanf("%lf", &wt_lb);
	printf("Enter height in inches: ");
	scanf("%lf", &ht_in);

	/* Calculate BMI */
	bmi = (703.0 * wt_lb) / (ht_in * ht_in);

	/* Find weight status from BMI and display it */
	if (bmi < 18.5) {
		printf("Underweight\n");
	} else if (bmi < 25.0) {
		printf("Normal\n");
	} else if (bmi < 30.0) {
		printf("Overweight\n");
	} else {
		printf("Obese\n");
	}

	return (0);
}
