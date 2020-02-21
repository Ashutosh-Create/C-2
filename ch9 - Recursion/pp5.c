/*
 * Program Description: To solve a maze
 * Input: a 8x8 maze consisting of blanks representing paths and x's
 *      representing that the path is blocked
 * Output: a path through the maze to get from location (0,1) to location (7,7)
 */

#include <stdio.h>
#include <string.h>

#define MAZE_SIZE 8   /* The maze is a 8x8 grid */

#define PATH ' '      /* Path is represented by blank character */
#define WALL 'x'      /* Blocked path is represented by 'x' character */

int find_path(char maze[][MAZE_SIZE], int start_x, int start_y,
    int end_x, int end_y, char path[]);

int
main(void)
{
    char maze[MAZE_SIZE][MAZE_SIZE];   /* The maze */
    FILE *input;            /* Input file maze.txt */
    char ch;                /* Character read from file */
    char path[1000];        /* Path from (0,1) to (7,7) */
    int path_exists;        /* Flag for path exists or not */
    int i, j;               /* Loop index */

    input = fopen("maze.txt", "r");
    path[0] = '\0';

    /* Read maze from input file */
    for (i = 0; i <= MAZE_SIZE; i++) {
        for (j = 0; j <= MAZE_SIZE; j++) {
            fscanf(input, "%c", &ch);
            if (ch == PATH || ch == WALL) {
                maze[i][j] = ch;
            }
        }
    }

    /* Display the maze */
    printf("The maze:\n");
    for (i = 0; i < MAZE_SIZE; i++) {
        for (j = 0; j < MAZE_SIZE; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }

    /* Find path from (0,1) to (7,7) */
    path_exists = find_path(maze, 0, 1, 7, 7, path);

    /* Display the path, if found */
    if (path_exists) {
        printf("\nPath from (0,1) to (7,7):\n%s\n", path);
    } else {
        printf("\nNo path exists from (0,1) to (7,7)\n");
    }

    fclose(input);

    return (0);
}

/*
 * Finds a path from location (start_x, start_y) to location (end_x, end_y) in
 * the given maze.
 * Returns 0 on reaching a dead end, returns 1 otherwise.
 */
int
find_path(char maze[][MAZE_SIZE], int start_x, int start_y,
    int end_x, int end_y, char path[])
{
    int path_exists;    /* Flag for path exists or not */
    char curr_loc[15];  /* Coordinates of current location */

    /* If current coordinates are outside the maze */
    if (start_x < 0 || start_x >= MAZE_SIZE ||
        start_y < 0 || start_y >= MAZE_SIZE) {
        return (0);
    }

    /* If current coordinates are blocked */
    if (maze[start_x][start_y] == WALL) {
        return (0);
    }

    /* If we are in (end_x, end_y) */
    if (start_x == end_x && start_y == end_y) {
        sprintf(curr_loc, "(%d,%d)", start_x, start_y);
        strcat(path, curr_loc);
        return (1);
    }

    path_exists = 0;
    maze[start_x][start_y] = WALL;

    /* Keep searching for a way to (end_x, end_y) */
    path_exists |= find_path(maze, start_x, start_y+1, end_x, end_y, path);
    path_exists |= find_path(maze, start_x-1, start_y, end_x, end_y, path);
    path_exists |= find_path(maze, start_x+1, start_y, end_x, end_y, path);
    path_exists |= find_path(maze, start_x, start_y-1, end_x, end_y, path);

    if (path_exists) {
        sprintf(curr_loc, " <- (%d,%d)", start_x, start_y);
        strcat(path, curr_loc);
    }

    return (path_exists);
}
