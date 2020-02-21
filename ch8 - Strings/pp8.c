/*
 * Program Description: To find the longest common suffix of two words
 * Input: Two words
 * Output: The longest common suffix
 */

#include <stdio.h>
#include <string.h>

#define MAX_LEN 50

void find_suffix(char word_1[], char word_2[], char suffix[]);

int
main(void)
{
    char word_1[MAX_LEN];
    char word_2[MAX_LEN];
    char suffix[MAX_LEN];

    printf("Enter first word: ");
    gets(word_1);
    printf("Enter second word: ");
    gets(word_2);

    find_suffix(word_1, word_2, suffix);
    printf("Longest common suffix is '%s'\n", suffix);

    return (0);
}

/*
 * Fills suffix[] with the longest common suffix of word_1 and word_2
 */
void
find_suffix(char word_1[], char word_2[], char suffix[])
{
    int word_1_len;     /* Length of word 1 */
    int word_2_len;     /* Length of word 2 */
    int suffix_len;     /* Suffix length */
    int i, j;           /* Loop index */

    word_1_len = strlen(word_1);
    word_2_len = strlen(word_2);
    suffix_len = 0;

    i = word_1_len - 1;
    j = word_2_len - 1;
    while (i >= 0 && j >= 0) {
        if (word_1[i] != word_2[j]) {
            break;
        }

        suffix_len++;
        i--;
        j--;
    }

    strncpy(suffix, &word_1[word_1_len - suffix_len], word_1_len);
}
