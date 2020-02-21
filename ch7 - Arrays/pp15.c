/*
 * Program Description: To process a grid of power values and display the
 *      sectors that have power outages.
 * Input: a 3x4 grid in which each cell represents power service in one sector
 * Output: display which sectors have power outages, otherwise display that
 *      power is on throughout the grid.
 */

#include <stdio.h>

void get_grid(FILE *input, int grid[3][4]);
void display_grid(int grid[3][4]);
int power_ok(int grid[3][4]);
void where_off(int grid[3][4]);

int
main(void)
{
    FILE *input;        /* File containing power service status grid */
    int grid[3][4];     /* Grid of power values */

    input = fopen("power.txt", "r");

    /* Read power grid values */
    get_grid(input, grid);

    /* Display the power grid */
    printf("Power service grid:\n");
    display_grid(grid);
    printf("\n");

    /* Check if there are any power outages */
    if (power_ok(grid)) {
        printf("Power is on throughout grid.\n");
    } else {
        printf("Power is off in sectors:\n");
        where_off(grid);
    }

    fclose(input);

    return (0);
}

/*
 * Fills grid array with date from input file
 */
void
get_grid(FILE *input, int grid[3][4])
{
    int i, j;           /* Loop index */

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            fscanf(input, "%d", &grid[i][j]);
        }
    }
}

/*
 * Displays the power service grid
 */
void
display_grid(int grid[3][4])
{
    int i, j;           /* Loop index */

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

/*
 * Returns 1 if power is on throughout the grid, returns 0 otherwise
 */
int
power_ok(int grid[3][4])
{
    int i, j;           /* Loop index */

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            if (grid[i][j] == 0) {
                return 0;
            }
        }
    }

    return 1;
}

/*
 * Displays in which sectors there are power outages
 */
void
where_off(int grid[3][4])
{
    int i, j;           /* Loop index */

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            if (grid[i][j] == 0) {
                printf("\t(%d,%d)\n", i, j);
            }
        }
    }
}
