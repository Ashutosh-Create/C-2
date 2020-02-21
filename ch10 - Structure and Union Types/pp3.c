/*
 * Program Description: Scientific notation calculator
 * Input: two numbers in scientific notation (example: 0.25000e3)
 * Output: sum, difference, product and quotient of the two numbers
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * Data type for a number in scientific notation.
 */
typedef struct {
    int exponent;
    double mantissa;
} sci_not_t;

sci_not_t scan_sci(void);
void print_sci(sci_not_t sci_not);

sci_not_t add(sci_not_t a, sci_not_t b);
sci_not_t subtract(sci_not_t a, sci_not_t b);
sci_not_t multiply(sci_not_t a, sci_not_t b);
sci_not_t divide(sci_not_t a, sci_not_t b);
sci_not_t normalize(sci_not_t sci_not);

int
main(void)
{
    sci_not_t a, b;         /* Values input by user */
    sci_not_t sum;          /* Sum of the two numbers */
    sci_not_t difference;   /* Difference of the two numbers */
    sci_not_t product;      /* Product of the two numbers */
    sci_not_t quotient;     /* Quotient of the two numbers */

    printf("Enter first number:\n");
    a = scan_sci();
    printf("Enter second number:\n");
    b = scan_sci();

    sum = add(a, b);
    difference = subtract(a, b);
    product = multiply(a, b);
    quotient = divide(a, b);

    printf("\nValues input:  ");
    print_sci(a);
    printf("  ");
    print_sci(b);

    printf("\nSum: ");
    print_sci(sum);
    printf("\nDifference: ");
    print_sci(difference);
    printf("\nProduct: ");
    print_sci(product);
    printf("\nQuotient: ");
    print_sci(quotient);
    printf("\n");

    return (0);
}

/*
 * Returns a sci_not_t structure filled with user input.
 */
sci_not_t
scan_sci(void)
{
    sci_not_t sci_not;

    printf("  Mantissa: ");
    scanf("%lf", &sci_not.mantissa);

    if (sci_not.mantissa < 0.1 || sci_not.mantissa > 1.0) {
        printf("ERROR: mantissa must satisfy 0.1 <= m <= 1.0\n");
        exit(0);
    }

    printf("  Exponent: ");
    scanf("%d", &sci_not.exponent);

    return sci_not;
}

/*
 * Prints a sci_not_t structure.
 */
void
print_sci(sci_not_t sci_not)
{
    printf("%.5fe%d", sci_not.mantissa, sci_not.exponent);
}

/*
 * Returns sum of two numbers in scientific notation.
 */
sci_not_t
add(sci_not_t a, sci_not_t b)
{
    sci_not_t sum;
    int exp_diff;

    /* Compare the exponents of the two numbers and shift the smaller number
    to the right until its exponent matches the larger number */
    exp_diff = abs(a.exponent - b.exponent);
    if (a.exponent < b.exponent) {
        sum.exponent = b.exponent;
        a.mantissa /= pow(10, exp_diff);
    } else if (b.exponent < a.exponent) {
        sum.exponent = a.exponent;
        b.mantissa /= pow(10, exp_diff);
    }

    /* Add the mantissa */
    sum.mantissa = a.mantissa + b.mantissa;

    /* Normalize the sum */
    sum = normalize(sum);

    return (sum);
}

/*
 * Returns difference of two numbers in scientific notation.
 */
sci_not_t
subtract(sci_not_t a, sci_not_t b)
{
    sci_not_t difference;
    int exp_diff;

    /* Compare the exponents of the two numbers and shift the smaller number
    to the right until its exponent matches the larger number */
    exp_diff = abs(a.exponent - b.exponent);
    if (a.exponent < b.exponent) {
        difference.exponent = b.exponent;
        a.mantissa /= pow(10, exp_diff);
    } else if (b.exponent < a.exponent) {
        difference.exponent = a.exponent;
        b.mantissa /= pow(10, exp_diff);
    }

    /* Subtract the mantissa */
    difference.mantissa = a.mantissa - b.mantissa;

    /* Normalize the difference */
    difference = normalize(difference);

    return (difference);
}

/*
 * Returns product of two numbers in scientific notation.
 */
sci_not_t
multiply(sci_not_t a, sci_not_t b)
{
    sci_not_t product;

    /* Add the exponents and multiply the mantissa */
    product.exponent = a.exponent + b.exponent;
    product.mantissa = a.mantissa * b.mantissa;

    /* Normalize the product */
    product = normalize(product);

    return (product);
}

/*
 * Returns quotient of two numbers in scientific notation.
 */
sci_not_t
divide(sci_not_t a, sci_not_t b)
{
    sci_not_t quotient;

    /* Subtract the exponents and divide the mantissa */
    quotient.exponent = a.exponent - b.exponent;
    quotient.mantissa = a.mantissa / b.mantissa;

    /* Normalize the product */
    quotient = normalize(quotient);

    return (quotient);
}

/*
 * Returns the normalized form of a number scientific notation.
 */
sci_not_t
normalize(sci_not_t sci_not)
{
    if (sci_not.mantissa == 0.0) {
        return (sci_not);
    }

    while (fabs(sci_not.mantissa) < 0.1) {
        sci_not.exponent -= 1;
        sci_not.mantissa *= 10;
    }

    while (fabs(sci_not.mantissa) > 1.0) {
        sci_not.exponent += 1;
        sci_not.mantissa /= 10;
    }

    return (sci_not);
}
