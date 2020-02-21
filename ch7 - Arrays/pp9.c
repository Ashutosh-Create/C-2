/*
 * Program Description: Interactive game of hangman
 */

#include <stdio.h>

int make_guess(char word[], char guessed[], char letter);
int fully_guessed(char guessed[]);

int
main(void)
{
    char word[] = "spaceship";      /* Word to be guessed */
    char guessed[] = "*********";   /* Letters guessed so far */
    int guesses_left = 5;           /* Number of incorrect guesses left */
    char letter;                    /* Guessed letter */

    printf("\n\tHANGMAN\n\n");

    while (guesses_left > 0 && !fully_guessed(guessed)) {
        printf("Guessed so far: %s [guesses left: %d]\n", guessed, guesses_left);
        printf("Enter guess: ");
        scanf(" %c", &letter);

        if (make_guess(word, guessed, letter)) {
            printf("Correct guess!\n\n");
        } else {
            printf("Incorrect guess!\n\n");
            guesses_left--;
        }
    }

    if (guesses_left == 0) {
        printf("YOU ARE OUT OF GUESSES.\n");
        printf("YOU LOSE :(\n");
    } else {
        printf("YOU WIN! :)\n");
    }

    return (0);
}

/*
 * Replaces '*' in guessed[] with the corresponding letter.
 * Returns 0 if guess was incorrect, non-zero otherwise
 */
int
make_guess(char word[], char guessed[], char letter)
{
    int i;
    int correct;

    i = 0;
    correct = 0;

    while (word[i] != '\0') {
        if (word[i] == letter) {
            guessed[i] = letter;
            correct++;
        }
        i++;
    }

    return (correct);
}

/*
 * Returns 1 if the word was fully guessed, 0 otherwise
 */
int
fully_guessed(char guessed[])
{
    int i;

    i = 0;
    while (guessed[i] != '\0') {
        if (guessed[i] == '*') {
            return (0);
        }
        i++;
    }

    return (1);
}
