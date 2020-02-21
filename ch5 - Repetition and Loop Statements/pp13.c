/*
 * Name: Abhijit Parida		Date: 17-02-17
 * Program Description: To calculate a baseball player's batting average
 * Input: players batting record
 * Output: batting average
 * Algorithm:
 * 	1. Get batting records until end of file
 *	2. Display player number and batting record
 *	3. Count number of hits and at-bats
 *	4. Calculate batting average
 */

#include <stdio.h>

#define HIT 'H'
#define OUT 'O'

int
main(void)
{
	int player_number;	/* Player number */
	int num_hits;		/* Number of hits */
	int num_at_bats;	/* Number of htis and outs */
	char batting_record;	/* Players batting record */
	double batting_average;	/* Hits divided by at-bats */
	int input_status;

	/* Get batting records until end of file */
	input_status = scanf("%d", &player_number);
	while (input_status == 1) {
		num_hits = 0;
		num_at_bats = 0;

		/* Display player number and batting record */
		printf("Player %d's record: ", player_number);

		/* Count number of hits and at-bats */
		scanf(" %c", &batting_record);
		while (batting_record != '\n') {
			printf("%c", batting_record);
			switch (batting_record) {
				/* Increment number of hits on HIT */
				case HIT: num_hits++;
				/* Increment number of at bats on both
				HIT and OUT */
				case OUT: num_at_bats++;
			}
			scanf("%c", &batting_record);
		}

		/* Calculate batting average */
		batting_average = num_hits / (double) num_at_bats;
		printf("\nPlayer %d's batting average: %.3f\n",
			player_number, batting_average);

		input_status = scanf("%d", &player_number);
	}

	return (0);
}
