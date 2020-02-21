/*
 * Program Description: To calculate checksums for lines of messages
 * Input: single-line message ending with a period
 * Output: checksum character
 */

#include <stdio.h>

char checksum(int *sum, char ch);

int
main(void)
{
    char ch;            /* Scanned character */
    int input_status;   /* Value returned by scanf */
    int sum;            /* Sum of integer value of characters */
    char chk_sum;       /* Checksum */

    /* Initialize sum of character to zero */
    sum = 0;

    /* Scan the first character */
    printf("Line: ");
    input_status = scanf("%c", &ch);

    while (input_status == 1) {

        /* Calculate checksum */
        chk_sum = checksum(&sum, ch);

        /* Exit if line contains only a period */
        if (sum == '.') {
            break;
        }

        /* Display calculated checksum at the end of line */
        if (chk_sum != -1) {
            printf("Checksum: %c\n\n", chk_sum);
            printf("Line: ");

            /* Re-initialize sum of character to zero */
            sum = 0;
        }

        /* Scan next character */
        input_status = scanf("%c", &ch);
    }
}

/*
 * Returns checksum on reaching end of line, otherwise returns -1
 */
char
checksum(int *sum, char ch)
{
    /* Increment sum of characters ignoring line breaks */
    if (ch != '\n') {
        *sum += ch;
    }

    /* Return checksum at the end of line */
    if (ch == '.') {
        return (*sum % 64 + ' ');
    }

    /* Return -1 if the line hasn't ended yet */
    return (-1);
}
