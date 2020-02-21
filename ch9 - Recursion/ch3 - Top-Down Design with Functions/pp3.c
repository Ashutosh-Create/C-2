/*
 * Name: Abhijit Parida		Date: 13-01-17
 * Program description: To draw a rocket and some stick figures
 * Output: Figure of a rocket, and a female figure standing on a male figure
 * Algorithm:
 *	1. Draw a rocket
 *	2. Display 5 blank lines
 *	3. Draw a female stick figure and male stick figure
 */

#include <stdio.h>

void draw_intersect(void);
void draw_base(void);
void draw_parallel(void);
void draw_rectangle(void);
void draw_triangle(void);
void draw_circle(void);
void skip_5_lines(void);

int
main(void)
{
	/* Draw a rocket */
	draw_triangle();
	draw_rectangle();
	draw_rectangle();
	draw_intersect();

	/* Display 5 blank lines */
	skip_5_lines();

	/* Draw a female stick figure and male stick figure */
	draw_circle();
	draw_triangle();
	draw_intersect();
	draw_circle();
	draw_rectangle();
	draw_intersect();

	return (0);
}

/*
 * Draws two intersecting lines
 */
void
draw_intersect(void)
{
	printf("  / \\  \n");
	printf(" /   \\ \n");
	printf("/     \\\n");
}

/*
 * Draws a base line
 */
void
draw_base(void)
{
	printf("-------\n");
}

/*
 * Draws two parallel lines
 */
void
draw_parallel(void)
{
	printf("|     |\n");
}

/*
 * Draws a rectangle
 */
void
draw_rectangle(void)
{
	draw_base();
	draw_parallel();
	draw_base();
}

/*
 * Draws a triangle
 */
void
draw_triangle(void)
{
	draw_intersect();
	draw_base();
}

/*
 * Draws a circle
 */
void
draw_circle(void)
{
	printf("   *   \n");
	printf(" *   * \n");
	printf("  * *  \n");
}

/*
 * Draws five blank lines
 */
void
skip_5_lines(void)
{
	printf("\n\n\n\n\n");
}
