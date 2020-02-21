/*
 * Program Description: To lookup combination of positives on MPN table
 * Input: combination of positives
 * Output: MPN, 95 percent confidence limits
 */

#include <stdio.h>
#include <string.h>

#define FILENAME "mpn_table.txt"
#define MAX_SIZE 20

typedef struct {
    char positives[6];      /* Combination of positives */
    int mpn_index;          /* MPN index / 100 ml */
    int lower_limit;        /* 95% lower confidence limit */
    int upper_limit;        /* 95% upper confidence limit */
} mpn_t;

int load_mpn_table(char filename[], mpn_t mpn_table[], int size);
int search(mpn_t mpn_table[], int size, char positives[6]);

int
main(void)
{
    mpn_t mpn_table[MAX_SIZE];      /* Array of mpn_t entries */
    int size;                       /* Size of mpn_table */
    char positives[6];              /* Combination-of-positives triplet */
    int position;                   /* Search result index */
    mpn_t mpn;                      /* Search result */

    size = load_mpn_table(FILENAME, mpn_table, MAX_SIZE);

    printf("Enter combination-of-positives triplet: ");
    gets(positives);
    while (positives != NULL) {
        position = search(mpn_table, size, positives);
        if (position == -1) {
            printf("Not found!\n");
        } else {
            mpn = mpn_table[position];
            printf("For %s, MPN = %d; 95%% of samples contain between %d and %d bacteria/ml.\n",
                mpn.positives, mpn.mpn_index, mpn.lower_limit, mpn.upper_limit);
        }
        printf("Enter combination-of-positives triplet: ");
        gets(positives);
    }

    return (0);
}

/*
 * Reads the input file and fills the mpn_table array. Displays a message if
 * the file contains too much data.
 * Returns the actual size of the array.
 */
int
load_mpn_table(char filename[], mpn_t mpn_table[], int size)
{
    FILE *input;
    int i;
    int input_status;
    mpn_t mpn;

    input = fopen(filename, "r");

    i = 0;
    input_status = fscanf(input, "%s%d%d%d", mpn.positives, &mpn.mpn_index,
        &mpn.lower_limit, &mpn.upper_limit);
    mpn_table[i] = mpn;
    while (input_status == 4) {
        i++;
        if (i >= size) {
            printf("**Warining: some data has been ignored.\n");
            break;
        }
        input_status = fscanf(input, "%s%d%d%d", mpn.positives, &mpn.mpn_index,
            &mpn.lower_limit, &mpn.upper_limit);
        mpn_table[i] = mpn;
    }

    fclose(input);

    return (i);
}

/*
 * Returns an index in mpn_table where the combination-of-positives triplet is
 * found. Returns -1 otherwise.
 */
int
search(mpn_t mpn_table[], int size, char positives[6])
{
    int i;      /* Loop index */

    for (i = 0; i < size; i++) {
        if (strcmp(mpn_table[i].positives, positives) == 0) {
            return (i);
        }
    }

    return (-1);
}
