/*
 * Program Description: To display the factorial calculation of a number inside
 *      a box
 * Input: value of n
 * Output: the factorial calculation n! = n x n-1 x ... x 1 = n! inside a box
 */

#define MAX_BOX_LEN 50

#include <stdio.h>
#include <string.h>

void make_box(char box[], int n);
int factorial(int n);
int box_length(int n);

int
main(void)
{
    int n;
    char box[MAX_BOX_LEN * 3];

    printf("Enter integer between 0 to 9, or -1 to quit: ");
    scanf("%d", &n);

    while (n != -1) {

        if (n > 0 && n < 9) {
            make_box(box, n);
            printf("%s\n", box);
            box[0] = '\0';
        } else {
            printf("Invalid entry\n");

        }

        printf("Enter integer between 0 to 9, or -1 to quit: ");
        scanf("%d", &n);
    }

    return (0);
}

void
make_box(char box[], int n)
{
    int i;
    int f;
    char box_upper[MAX_BOX_LEN];
    char box_middle[MAX_BOX_LEN];
    char box_lower[MAX_BOX_LEN];

    f = factorial(n);

    sprintf(box_upper, "*******");
    sprintf(box_lower, "*******");
    i = sprintf(box_middle, "* %d! = ", n);

    while (n != 1) {
        sprintf(&box_upper[i], "****");
        sprintf(&box_lower[i], "****");
        i += sprintf(&box_middle[i], "%d x ", n--);

    }

    sprintf(&box_upper[i], "***********\n\0");
    sprintf(&box_lower[i], "***********\n\0");
    sprintf(&box_middle[i], "%d = %d *\n\0", n--, f);

    strcat(box, box_upper);
    strcat(box, box_middle);
    strcat(box, box_lower);
}

/*
 * Returns n!
 * Pre: n
 */
int
factorial(int n)
{
    int f;      /* Factorial value */

    f = 1;
    while (n != 0) {
        f *= n--;
    }

    return f;
}
