/*
 * Name: Abhijit Parida		Date: 13-01-17
 * Program Description: To draw triangles and rectangles using functions
 * Output: Figures of triangles and rectangles
 * Algorithm:
 *	1. Draw a triangle
 *	2. Draw a rectangle
 *	3. Display 2 blank lines
 *	4. Draw a triangle
 *	5. Draw a rectangle
 */

#include <stdio.h>

void draw_triangle(void);
void draw_rectangle(void);

int
main(void)
{
	/* Draw a triangle */
	draw_triangle();

	/* Draw a rectangle */
	draw_rectangle();

	/* Display 2 blank lines */
	printf("\n\n");

	/* Draw a triangle */
	draw_triangle();

	/* Draw a rectangle */
	draw_rectangle();

	return (0);
}

/*
 * Draws a triangle
 */
void
draw_triangle(void)
{
	printf("   /\\   \n");
	printf("  /  \\  \n");
	printf(" /    \\ \n");
	printf("/      \\\n");
	printf("-------- \n");
}

/*
 * Draws a rectangle
 */
void
draw_rectangle(void)
{
	printf("--------\n");
	printf("|      |\n");
	printf("--------\n");
}
