/*
 * Program Descriptipn: To merge two sorted arrays
 * Input: two sorted arrays
 * Output: a single merged array
 */

#include <stdio.h>

int merge(double arr1[], double arr2[], double arr3[], int size1, int size2);

int
main(void)
{
    double arr1[] = {-10.5, -1.8, 3.5, 6.3, 7.2};
    double arr2[] = {-1.8, 3.1, 6.3};
    double arr3[6];
    int size1 = 5;
    int size2 = 3;
    int size3;
    int i;

    printf("First array: ");
    for (i = 0; i < size1; i++) {
        printf("%.1f ", arr1[i]);
    }

    printf("\nSecond array: ");
    for (i = 0; i < size2; i++) {
        printf("%.1f ", arr2[i]);
    }

    size3 = merge(arr1, arr2, arr3, size1, size2);

    printf("\nResult array: ");
    for (i = 0; i < size3; i++) {
        printf("%.1f ", arr3[i]);
    }
    printf("\n");

    return (0);
}

/*
 * Merges two sorted arrays
 */
int
merge(double arr1[], double arr2[], double arr3[], int size1, int size2)
{
    int i, j, k;        /* Loop index */

    i = 0;
    j = 0;
    k = 0;

    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            arr3[k] = arr1[i];
            i++;
        } else if (arr1[i] > arr2[j]) {
            arr3[k] = arr2[j];
            j++;
        } else {
            arr3[k] = arr1[i];
            i++;
            j++;
        }
        k++;
    }

    if (i == size1) {
        while (j < size2) {
            arr3[k] = arr2[j];
            j++;
            k++;
        }
    } {
        while (i < size1) {
            arr3[k] = arr1[i];
            i++;
            k++;
        }
    }

    return k;
}
