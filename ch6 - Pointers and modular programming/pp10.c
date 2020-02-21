/*
 * Program Descriptipn: Simple calculator
 * Input: operator and operands
 * Output: result
 */

#include <stdio.h>
#include <math.h>

#define ADD '+'
#define SUBTRACT '-'
#define MULTIPLY '*'
#define DIVIDE '/'
#define POWER '^'
#define QUIT 'q'

void do_next_op(char operator, double operand, double *accumulator);

int
main(void)
{
    char operator;
    double operand;
    double accumulator;

    accumulator = 0.0;
    scanf(" %c%lf", &operator, &operand);
    while (operator != QUIT) {
        do_next_op(operator, operand, &accumulator);
        printf("result so far is %.1f\n", accumulator);
        scanf(" %c%lf", &operator, &operand);
    }
    printf("final result is %.1f\n", accumulator);

    return (0);
}

/*
 * Performs operation with operator and operand, stores result
 * in accumulator
 */
void
do_next_op(char operator, double operand, double *accumulator)
{
    switch(operator) {
        case ADD:
            *accumulator += operand;
            break;

        case SUBTRACT:
            *accumulator -= operand;
            break;

        case MULTIPLY:
            *accumulator *= operand;
            break;

        case DIVIDE:
            *accumulator /= operand;
            break;

        case POWER:
            *accumulator = pow(*accumulator, operand);
            break;
    }
}
