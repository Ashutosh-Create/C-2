/*
 * Program Description: To sort an array using bubble sort
 * Input: Elements of an array
 * Output: Sorted array
 */

#include <stdio.h>

void bubble_sort(int arr[], int size);
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

    bubble_sort(arr, size);

    printf("After sorting: \n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return (0);
}

/*
 * Sorts an array using bubble sort
 */
void
bubble_sort(int arr[], int size)
{
    int i, j;       /* Array index */

    for (i = 0; i < size-1; i++) {
        for (j = 0; j < size-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr, j, j+1);
            }
        }
    }
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
