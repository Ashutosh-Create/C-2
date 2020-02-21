/*
 * Name: Abhijit Parida		Date: 27-01-17
 * Program Description: To determine the day number in a year for a date
 *	that is provided as input data
 * Input: day, month and year
 * Output: day number
 * Algorithm:
 *	1. Get the day, month and year
 *	2. Count number of days
 *	3. Display the day number
 */

#include <stdio.h>

int leap(int year);

int
main(void)
{
	int day, month, year;
	int day_num;

	/* Get the day, month and year */
	printf("Enter day, month and year: ");
	scanf("%d%d%d", &day, &month, &year);

	/* Count number of days */
	day_num = day;
	switch (month) {
		case 12: day_num += 30;
		case 11: day_num += 31;
		case 10: day_num += 30;
		case 9: day_num += 31;
		case 8: day_num += 30;
		case 7: day_num += 31;
		case 6: day_num += 31;
		case 5: day_num += 30;
		case 4: day_num += 31;
		case 3:
			if (leap(year)) {
				day_num += 29;
			} else {
				day_num += 28;
			}
		case 2: day_num += 31;
		case 1: day_num += 0;
	}

	/* Display the day number */
	printf("Day number is %d\n", day_num);

	return (0);
}

/*
 * Returns 1 if called with a leap year, 0 otherwise
 * Pre: year
 */
int
leap(int year)
{
	return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
}
