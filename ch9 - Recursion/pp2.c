/*
 * Program Description: To check if a string is a palindrome
 * Input: A string
 * Output: Palindrome / Not palindrome
 */

#include <stdio.h>
#include <string.h>

int palindrome(char str[], int i, int j);

int
main(void)
{
    char str[50];

    printf("Enter string [without blanks and punctuation]: ");
    gets(str);

    if (palindrome(str, 0, strlen(str) - 1)) {
        printf("'%s' is a palindrome", str);
    } else {
        printf("'%s' is not a palindrome", str);
    }

    return (0);
}

/*
 * Returns 1 if str is a palindrome, returns 0 otherwise
 * Pre: a string str, start and end index i & j
 */
int
palindrome(char str[], int i, int j)
{
    if (i > j) {
        return (1);
    }

    if (str[i] != str[j]) {
        return (0);
    }

    return (palindrome(str, i + 1, j - 1));
}
