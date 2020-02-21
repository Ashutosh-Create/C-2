/*
 * Program description: To search an array of integers using binary search
 * Input: array, element to search
 * Output: position of element
 */

#include <stdio.h>

#define MAX_SIZE 100
#define NOT_FOUND -1

int binary_search(int arr[], int size, int target);

int
main(void)
{
    int arr[MAX_SIZE];
    int i;
    int size;       /* Size of array */
    int target;     /* Element to search for */
    int position;   /* Position of target element */

    printf("Enter number of array elements: ");
    scanf("%d", &size);

    for (i = 0; i < size; i++) {
        printf("Enter array element: ");
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search for: ");
    scanf("%d", &target);

    position = binary_search(arr, size, target);

    if (position == NOT_FOUND) {
        printf("%d not found in array\n", target);
    } else {
        printf("%d found at arr[%d]\n", target, position);
    }

    return (0);
}

/*
 * Returns the index of target element in arr[]
 */
int
binary_search(int arr[], int size, int target)
{
    int top;
    int bottom;
    int middle;
    int found;
    int index;

    bottom = 0;
    top = size - 1;
    found = 0;

    while (bottom <= top && found == 0) {
        middle = (top + bottom) / 2;
        if (arr[middle] == target) {
            found = 1;
            index = middle;
        } else if (arr[middle] > target) {
            top = middle - 1;
        } else {
            bottom = middle + 1;
        }
    }

    if (found == 1) {
        return index;
    } else {
        return NOT_FOUND;
    }
}
