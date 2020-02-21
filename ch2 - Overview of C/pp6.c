/*
 * Name: Abhijit Parida		Date: 07/07/17
 * Program name: pp6.c
 * Program description: To predict the score needed on a final exam to
 *	acheive a desired grade.
 * Input: grade, req_avg, cur_avg, percent
 * Output: score
 * Algorithm:
 * 	1. Get the desired grade, minimum and current average
 * 	2. Calculate and display required score in finals
 */

#include <stdio.h>

int
main(void)
{
	char grade;	/* Desired grade */
	double req_avg;	/* Minimum required average */
	double cur_avg;	/* Current average in course */
	int percent;	/* How much final counts as % of course grade */
	double score;	/* Final score to get required grade */

	/* Get the desired grade, minimum and current average */
	printf("Enter desired grade> ");
	scanf(" %c", &grade);
	printf("Enter minimum average required> ");
	scanf("%lf", &req_avg);
	printf("Enter current average in course> ");
	scanf("%lf", &cur_avg);
	printf("Enter how much the final counts\n");
	printf("as a percentage of the course grade> ");
	scanf("%d", &percent);

	/* Calculate and display required score in finals */
	score = (req_avg - (cur_avg * (100 - percent) / 100)) * 100 / percent;
	printf("You need a score of %.2f on the final to get a %c.\n",
		score, grade);

	return (0);
}
