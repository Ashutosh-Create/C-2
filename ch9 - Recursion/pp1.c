/*
 * Program Description: To count pixels belonging to an object in a photograph
 * Input: a 2D grid of pixels, each of which may be empty (0) or filled (1)
 * Output: number of pixels in the blob to which the indicated cell belongs
 */

#include <stdio.h>

#define GRID_SIZE 5

int blob_check(int pixels[][GRID_SIZE], int x, int y);

int
main(void)
{
    int pixels[GRID_SIZE][GRID_SIZE];   /* Pixels grid */
    FILE *input;       /* Input file pixels.txt */
    int x, y;          /* Coordinates of selected cell */
    int num_pixels;    /* Number of pixels in blob containing pixel (x, y) */
    int i, j;          /* Loop index */

    input = fopen("pixels.txt", "r");

    /* Get pixel values from input file */
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            fscanf(input, "%d", &pixels[i][j]);
        }
    }

    /* Display pixel grid */
    printf("\nPixel Grid:\n");
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            printf("%d ", pixels[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("Enter x and y coordinates of pixel to check: ");
    scanf("%d%d", &x, &y);

    num_pixels = blob_check(pixels, x, y);
    printf("Number of pixels in blob containing pixel (%d, %d) = %d\n",
        x, y, num_pixels);

    fclose(input);

    return (0);
}

/*
 * Returns the number of pixels in the blob containing pixel (x, y)
 */
int
blob_check(int pixels[][GRID_SIZE], int x, int y)
{
    int num_pixels;    /* Number of pixels in blob containing pixel (x, y) */
    int i, j;          /* Loop index */

    /* If (x, y) lies outside the grid */
    if (x < 0 || x >= GRID_SIZE || y < 0 || y >= GRID_SIZE) {
        return (0);
    }

    /* If (x, y) is empty */
    if (pixels[x][y] == 0) {
        return (0);
    }

    /* If (x, y) is filled */

    /* Mark (x, y) as empty to avoid counting it more than once */
    pixels[x][y] = 0;

    /* Return number of pixels in surrounding cells + 1 */
    num_pixels = 1;
    for (i = -1; i <= 1; i++) {
        for (j = -1; j <= 1; j++) {
            num_pixels += blob_check(pixels, x + i, y + j);
        }
    }

    return (num_pixels);
}
