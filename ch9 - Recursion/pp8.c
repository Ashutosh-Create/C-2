/*
 * Program Description: To sort an array using selection sort
 * Input: Elements of an array
 * Output: Sorted array
 */

#include <stdio.h>

void selection_sort(int arr[], int start, int end);
int get_min_index(int arr[], int start, int end);
void swap(int arr[], int a, int b);

int
main(void)
{
    int arr[100];   /* The array */
    int size;       /* Size of array */
    int i;          /* Loop index */

    printf("Enter number of array elements: ");
    scanf("%d", &size);

    for (i = 0; i < size; i++) {
        printf("Enter array element: ");
        scanf("%d", &arr[i]);
    }

    selection_sort(arr, 0, size);

    printf("\nAfter sorting: \n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return (0);
}

/*
 * Sorts an array using selection sort
 */
void
selection_sort(int arr[], int start, int end)
{
    int min;    /* Index of minimum value */

    if (start < end) {
        min = get_min_index(arr, start, end);
        swap(arr, start, min);
        selection_sort(arr, start + 1, end);
    }
}

/*
 * Returns the index of minimum value in arr[start ... end]
 */
int
get_min_index(int arr[], int start, int end)
{
    int i;     /* Loop index */
    int min;   /* Index of minimum value */

    min = start;
    for (i = start; i < end; i++) {
        if (arr[i] < arr[min]) {
            min = i;
        }
    }

    return min;
}

/*
 * Swaps arr[a] with arr[b]
 */
void
swap(int arr[], int a, int b)
{
    int tmp;        /* Temporary variable */

    tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}
