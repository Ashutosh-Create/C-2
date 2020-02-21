/*
 * Program Description: To display all binary numbers represented by a string
 *      of x's, 0's and 1's
 * Input: binary number string
 * Output: all binary numbers represented by the string
 */

#include <stdio.h>
#include <string.h>

void replace_first_x(char str[], int i);
int is_element(char ele, char set[]);

int
main(void)
{
    char str[10];

    printf("Enter binary string consisting of 0's, 1's and x's\n");
    printf("x's will be replaced by 0's and 1's\n");
    printf(">> ");
    gets(str);

    replace_first_x(str, 0);

    return (0);
}

/*
 * Builds two strings based on its input argument. In one, the first 'x' is
 * replaced by a '0', and in the other by a '1'.
 */
void
replace_first_x(char str[], int i)
{
    char str1[10], str2[10];

    if (str[i] == '\0') {
        printf("%s\n", str);
        return;
    }

    if (!is_element('x', &str[i])) {
        printf("%s\n", str);
        return;
    }

    strcpy(str1, str);
    strcpy(str2, str);

    while (str[i] != 'x') {
        i++;
    }

    str1[i] = '0';
    replace_first_x(str1, i + 1);

    str2[i] = '1';
    replace_first_x(str2, i + 1);
}

/*
 * Determines if ele is an element of set.
 * Returns 1 if ele is found in the set, returns 0 otherwise.
 */
int
is_element(char ele, char set[])
{
    if (set[0] == '\0') {
        return (0);
    }

    if (set[0] == ele) {
        return (1);
    }

    return (is_element(ele, &set[1]));
}
