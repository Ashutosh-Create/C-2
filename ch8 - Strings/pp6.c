/*
 * Program Description: To store a list of names and ages in parallel arrays
 *      and sorts the names into alphabetical order keeping the ages with the
 *      correct names.
 * Input: list of names and ages
 * Output: list of names and ages sorted in alphabetical order
 */

#include <stdio.h>
#include <string.h>

void select_sort(char names[][20], int ages[], int n);
int find_min_index(char names[][20], int start, int end);

int
main(void)
{
    int i;                  /* Loop index */
    int n;                  /* Number of entries */
    char names[100][20];    /* Names array */
    int ages[100];          /* Ages array */
    char c;

    printf("Enter number of entries: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        do {
            scanf("%c", &c);
        } while (c != '\n');

        printf("Name: ");
        gets(names[i]);
        printf("Age: ");
        scanf("%d", &ages[i]);
        printf("\n");
    }

    printf("Original list\n");
    printf("-----------------------------\n");
    for (i = 0; i < n; i++) {
        printf("    %-20s%d\n", names[i], ages[i]);
    }
    printf("\n");

    select_sort(names, ages, n);

    printf("\nAlphabetized list\n");
    printf("-----------------------------\n");
    for (i = 0; i < n; i++) {
        printf("    %-20s%d\n", names[i], ages[i]);
    }

    return (0);
}

/*
 * Sorts the data in names[] array. Also sorts ages[] array accordingly.
 */
void select_sort(char names[][20], int ages[], int n)
{
    int i;              /* Loop index */
    int min;            /* Index of smallest element */
    char tmp_name[20];  /* Temp variable for swapping names */
    int tmp_age;        /* Temp variable for swapping ages */

    for (i = 0; i < n; i++) {
        min = find_min_index(names, i, n);
        if (i != min) {

            /* Swap names */
            strcpy(tmp_name, names[i]);
            strcpy(names[i], names[min]);
            strcpy(names[min], tmp_name);

            /* Swag ages */
            tmp_age = ages[i];
            ages[i] = ages[min];
            ages[min] = tmp_age;
        }
    }
}

/*
 * Returns the position of the smallest element in the sub array names[start]
 * through names[end]
 */
int find_min_index(char names[][20], int start, int end)
{
    int i;      /* Loop index */
    int min;    /* Index of smallest element */

    min = start;
    for (i = start; i < end; i++) {
        if (strcmp(names[i], names[min]) < 0) {
            min = i;
        }
    }

    return min;
}
