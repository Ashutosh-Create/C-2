/*
 * Program Description: To model a finite state machine for recognizing
 *      identifiers and numbers
 * Input: data separated by blanks and ending with a period
 * Output: categorization of the input data as identifier/number
 */

#include <stdio.h>
#include <ctype.h>

typedef enum
    {start, build_num, number, build_id, identifier, stop}
state_t;

state_t transition(state_t current_state, char transition_char);

int
main(void)
{
    char transition_char;   /* Scanned character */
    state_t current_state;  /* Current transition state */

    current_state = start;
    do {
        if (current_state == identifier) {
            printf(" - Identifier\n");
            current_state = start;
        } else if (current_state == number) {
            printf(" - Number\n");
            current_state = start;
        }
        scanf("%c", &transition_char);
        if (transition_char != ' ') {
            printf("%c", transition_char);
        }
        current_state = transition(current_state, transition_char);
    } while (current_state != stop);

    return (0);
}

/*
 * Returns the next state given the current state and transition character
 */
state_t
transition(state_t current_state, char transition_char)
{
    state_t next_state;

    switch (current_state) {
        case start:
            if (isalpha(transition_char)) {
                next_state = build_id;
            } else if (isdigit(transition_char)) {
                next_state = build_num;
            } else if (transition_char == '.') {
                next_state = stop;
            } else if (transition_char == ' ') {
                next_state = start;
            }
            break;

        case build_num:
            if (isdigit(transition_char)) {
                next_state = build_num;
            } else if (transition_char == ' ') {
                next_state = number;
            }
            break;

        case number:
            next_state = start;
            break;

        case build_id:
            if (isalpha(transition_char) || isdigit(transition_char) ||
                    transition_char == '_') {
                next_state = build_id;
            } else if (transition_char == ' ') {
                next_state = identifier;
            }
            break;

        case identifier:
            next_state = start;
            break;

        case stop:
            next_state = stop;
            break;
    }

    return next_state;
}
