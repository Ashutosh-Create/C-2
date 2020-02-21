/*
 * Program Description: To take a line and reverse the words of the line
 * Input: a line
 * Output: the line with words reversed
 */

#include <stdio.h>
#include <string.h>

void reverse_words(char input[], char reverse[]);

int
main(void)
{
    char input[500];        /* Input line */
    char reverse[500];      /* Reversed words */

    printf("Input: ");
    gets(input);

    reverse_words(input, reverse);
    printf("Reversed: %s\n", reverse);

    return (0);
}

/*
 * Reverses the words of the input line
 */
void reverse_words(char input[], char reverse[])
{
    int i, j;               /* Loop index */
    int n;                  /* Number of words */
    char words[100][10];    /* Array of words */
    char *word;             /* A single word of the line */
    char tmp_word[10];      /* Temp char array for swapping */

    n = 0;

    /* Extract words from the line and put them in an array */
    word = strtok(input, " ");
    while (word != NULL) {
        strcpy(words[n], word);
        word = strtok(NULL, " ");
        n++;
    }

    /* Reverse the array of words */
    for (i = 0, j = n-1; i < j; i++, j--) {
        strcpy(tmp_word, words[i]);
        strcpy(words[i], words[j]);
        strcpy(words[j], tmp_word);
    }

    /* Join the words array into a string */
    reverse[0] = '\0';
    for (i = 0; i < n; i++) {
        strcat(reverse, words[i]);
        strcat(reverse, " ");
    }
}
