/*
 * Program Description: To list all of the one-element, two-element and
 *      three-element subsets of a given set of letters.
 * Input: a set of letters
 * Output: all the one-element, two-element and three-element subsets
 */

#include <stdio.h>
#include <string.h>

void one_ele_subs(char set[], int size, int i);
void two_ele_subs(char set[], int size, int i, int j);
void three_ele_subs(char set[], int size, int i, int j, int k);

int
main(void)
{
    char set[5];
    int size;
    int i;

    printf("Enter set of letters: ");
    gets(set);
    size = strlen(set);

    printf("\nOne-element subsets:\n");
    one_ele_subs(set, size, 0);

    printf("\nTwo-element subsets:\n");
    two_ele_subs(set, size, 0, 1);

    printf("\nThree-element subsets:\n");
    three_ele_subs(set, size, 0, 1, 2);

    return (0);
}

/*
 * Prints all one-element subsets of the given set of letters.
 */
void
one_ele_subs(char set[], int size, int i)
{
    if (i == size) {
        return;
    }

    printf("{%c}\n", set[i]);

    one_ele_subs(set, size, i + 1);
}

/*
 * Prints all two-element subsets of the given set of letters.
 */
void
two_ele_subs(char set[], int size, int i, int j)
{
    if (i == size - 2) {
        return;
    }

    if (j == size) {
        i = i + 1;
        j = i + 1;
    }

    printf("{%c, %c}\n", set[i], set[j]);

    two_ele_subs(set, size, i, j + 1);
}

/*
 * Prints all three-element subsets of the given set of letters.
 */
void
three_ele_subs(char set[], int size, int i, int j, int k)
{
    if (i == size - 3) {
        return;
    }

    if (j == size - 2) {
        i = i + 1;
        j = i + 1;
        k = j + 1;
    }

    if (k == size) {
        j = j + 1;
        k = j + 1;
    }

    printf("{%c, %c, %c}\n", set[i], set[j], set[k]);

    three_ele_subs(set, size, i, j, k + 1);
}
