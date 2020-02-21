/*
 * Program Description: To solve simple conduction problems using various
 *      forms of the formula H = kA(T2 - T1) / X
 * Input: H, k, A, T2, T1, X
 * Output: unknown value
 */

#include <stdio.h>

int get_value(double *value);
void calc_h(double *h, double k, double a, double t2, double t1, double x);
void calc_k(double h, double *k, double a, double t2, double t1, double x);
void calc_a(double h, double k, double *a, double t2, double t1, double x);
void calc_t2(double h, double k, double a, double *t2, double t1, double x);
void calc_t1(double h, double k, double a, double t2, double *t1, double x);
void calc_x(double h, double k, double a, double t2, double t1, double *x);

int
main(void)
{
    double h;           /* Rate of heat transfer */
    double k;           /* Coefficient of thermal conductivity */
    double a;           /* Cross-sectional area */
    double t2;          /* Temperature of one side */
    double t1;          /* Temperature of other side */
    double x;           /* Thickness of conductor */

    int input_status;   /* Value returned by scanf */
    char question;      /* Question mark for unknown value */

    int h_unknown;      /* Flag for k is unknown */
    int k_unknown;      /* Flag for k is unknown */
    int a_unknown;      /* Flag for a is unknown */
    int t2_unknown;     /* Flag for t2 is unknown */
    int t1_unknown;     /* Flag for t1 is unknown */
    int x_unknown;      /* Flag for x is unknown */

    printf("Respond to the prompts with the data known. For the\n");
    printf("unknown quantity, enter a question mark (?).\n");

    printf("Rate of heat transfer (watts): ");
    h_unknown = get_value(&h);

    printf("Coefficient of thermal conductivity (W/m-k): ");
    k_unknown = get_value(&k);

    printf("Cross-sectional area of conductor (m^2): ");
    a_unknown = get_value(&a);

    printf("Temperature on one side (K): ");
    t2_unknown = get_value(&t2);

    printf("Temperature on other side (K): ");
    t1_unknown = get_value(&t1);

    printf("Thickness of conductor (m): ");
    x_unknown = get_value(&x);

    printf("             kA (T2 - T1)\n");
    printf("     H = ----------------\n");
    printf("                  X      \n");

    if (h_unknown) {
        calc_h(&h, k, a, t2, t1, x);
        printf("Rate of heat transfer is %.1f W.\n", h);
    } else if (k_unknown) {
        calc_k(h, &k, a, t2, t1, x);
        printf("Coefficient of thermal conductivity is %.3f W/m-K.\n", k);
    } else if (a_unknown) {
        calc_a(h, k, &a, t2, t1, x);
        printf("Cross-sectional area of conductor is %.3f m^2.\n", a);
    } else if (t2_unknown) {
        calc_t2(h, k, a, &t2, t1, x);
        printf("Temperature on one side is %.0f K.\n", t2);
    } else if (t1_unknown) {
        calc_t1(h, k, a, t2, &t1, x);
        printf("Temperature on other side is %.0f K.\n", t1);
    } else if (x_unknown) {
        calc_x(h, k, a, t2, t1, &x);
        printf("Thickness of conductor is %.4f m.\n", x);
    }

    printf("H = %.1f W             T2 = %.0f K\n", h, t2);
    printf("k = %.3f W/m-k         T1 = %.0f K\n", k, t1);
    printf("A = %.3f m^2            X = %.4f m\n", a, x);

    return (0);
}

/*
 * Reads a value, or question mark from user
 * Returns 0 if value was input, 1 if question mark was input
 */
int
get_value(double *value)
{
    int input_status;
    char question_mark;

    input_status = scanf("%lf", value);
    if (input_status == 0) {
        scanf(" %c", &question_mark);
    }

    return !input_status;
}

/*
 * Calculates rate of heat transfer
 */
void
calc_h(double *h, double k, double a, double t2, double t1, double x)
{
    *h = (k * a  * (t2 - t1)) / x;
}

/*
 * Calculates coefficient of thermal conductivity
 */
void
calc_k(double h, double *k, double a, double t2, double t1, double x)
{
    *k = (h * x) / (a * (t2 - t1));
}

/*
 * Calculates cross-sectional area
 */
void
calc_a(double h, double k, double *a, double t2, double t1, double x)
{
    *a = (h * x) / (k * (t2 - t1));
}

/*
 * Calculates temperature of one side
 */
void
calc_t2(double h, double k, double a, double *t2, double t1, double x)
{
    *t2 = ((h * x) / (k * a)) + t1;
}

/*
 * Calculates temperature of other side
 */
void
calc_t1(double h, double k, double a, double t2, double *t1, double x)
{
    *t1 = t2 - ((h * x) / (k * a));
}

/*
 * Calculates thickness of conductor
 */
void
calc_x(double h, double k, double a, double t2, double t1, double *x)
{
    *x = (k * a  * (t2 - t1)) / h;
}
