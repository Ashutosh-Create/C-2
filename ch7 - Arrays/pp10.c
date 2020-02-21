/*
 * Program Description: To process the results of mayor's election
 * Input: file containing votes for each candidate from each precinct
 * Output: the winner
 */

#include <stdio.h>

#define PRECINCTS 5     /* Number of precincts */
#define CANDIDATES 4    /* Number of candidates */

void get_votes(FILE *input, int votes[PRECINCTS][CANDIDATES]);
void display_votes(int votes[PRECINCTS][CANDIDATES]);
void calculate_totals(int votes[PRECINCTS][CANDIDATES],
    double percent[CANDIDATES]);
void find_winner(double percent[CANDIDATES]);

int
main(void)
{
    FILE *input;                        /* Input file - "votes.txt" */
    int votes[PRECINCTS][CANDIDATES];   /* Number of votes */
    double percent[CANDIDATES];         /* Percentage of votes received */

    input = fopen("votes.txt", "r");

    get_votes(input, votes);
    display_votes(votes);
    calculate_totals(votes, percent);
    find_winner(percent);

    fclose(input);

    return (0);
}

/*
 * Reads the input file and fills votes array
 */
void
get_votes(FILE *input, int votes[PRECINCTS][CANDIDATES])
{
    int precinct, candidate;     /* Loop index */

    for (precinct = 0; precinct < PRECINCTS; precinct++) {
        for (candidate = 0; candidate < CANDIDATES; candidate++) {
            fscanf(input, "%d", &votes[precinct][candidate]);
        }
    }
}

/*
 * Displays the table of votes with appropriate labels for the rows and columns
 */
void
display_votes(int votes[PRECINCTS][CANDIDATES])
{
    int precinct, candidate;     /* Loop index */

    printf("Precinct  Candidate A  Candidate B  Candidate C  Candidate D\n");
    for (precinct = 0; precinct < PRECINCTS; precinct++) {
        printf("%4d", precinct+1);
        for (candidate = 0; candidate < CANDIDATES; candidate++) {
            printf("%13d", votes[precinct][candidate]);
        }
        printf("\n");
    }
}

/*
 * Displays the total number of voted received by each candidate and the
 * percentage of the total votes cast and fills totals[] array
 */
void
calculate_totals(int votes[PRECINCTS][CANDIDATES], double percent[CANDIDATES])
{
    int precinct, candidate;     /* Loop index */
    int total;                   /* Sum total of all votes */
    int totals[CANDIDATES];      /* Total votes of each candidate */

    total = 0;
    for (candidate = 0; candidate < CANDIDATES; candidate++) {
        totals[candidate] = 0;
        for (precinct = 0; precinct < PRECINCTS; precinct++) {
            total += votes[precinct][candidate];
            totals[candidate] += votes[precinct][candidate];
        }

    }

    printf("\nTOTAL VOTES\n");
    for (candidate = 0; candidate < CANDIDATES; candidate++) {
        percent[candidate] = totals[candidate] / (double) total * 100.0;
        printf("Candidate %c: %d (%.2f%%)\n", 'A' + candidate,
            totals[candidate], percent[candidate]);
    }
}

/*
 * Displays the winner, or a runoff between two candidates
 */
void
find_winner(double percent[CANDIDATES])
{
    int max1, max2;     /* Index of candidates with highest and second
                           highest number of votes */
    int candidate;      /* Loop index */

    if (percent[0] > percent[1]) {
        max1 = 0;
        max2 = 1;
    } else {
        max1 = 1;
        max2 = 0;
    }

    for (candidate = 2; candidate < CANDIDATES; candidate++) {
        if (percent[candidate] > percent[max1]) {
            max2 = max1;
            max1 = candidate;
        } else if (percent[candidate] > percent[max2]) {
            max2 = candidate;
        }
    }

    if (percent[max1] > 50.0) {
        printf("\nWINNER IS CANDIDATE %c\n", 'A' + max1);
    } else {
        printf("\nRUNOFF BETWEEN CANDIDATE %c and CANDIDATE %c\n",
            'A' + max1, 'A' + max2);
    }
}
