/*
 * Program description: To search an array of integers using recursive binary
 *      search
 * Input: array, element to search
 * Output: position of element
 */

#include <stdio.h>

#define MAX_SIZE 100
#define NOT_FOUND -1

int binary_search(int arr[], int start, int end, int target);

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

    position = binary_search(arr, 0, size, target);

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
binary_search(int arr[], int start, int end, int target)
{
    int mid;

    if (start > end) {
        return (NOT_FOUND);
    }

    mid = (start + end) / 2;

    if (arr[mid] == target) {
        return mid;
    }

    if (target < arr[mid]) {
        return (binary_search(arr, start, mid - 1, target));
    } else {
        return (binary_search(arr, mid + 1, end, target));
    }
}
