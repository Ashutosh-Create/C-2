/*
 * Program Description: To assist with calculation of IV rates.
 * Input: medical order
 * Output: IV rate
 */

#include <stdio.h>

#define QUIT 5

int get_problem();

void get_rate_drop_factor(double *rate, int *drop);
void get_kg_rate_conc(double *rate, int *weight, int *conc);
void get_units_conc(double *rate, int *conc);

int fig_drops_min(double rate, int drop);
int fig_ml_hr(int hours);
int by_weight(double rate, int weight, int conc);
int by_units(double rate, int conc);

int
main(void)
{
    int problem;        /* Problem number */
    double rate_inp;    /* IV rate input */
    int rate_out;       /* IV rate output */
    int drop;           /* Number of drops */
    int hours;          /* Number of hours */
    int weight;         /* Weight of patient */
    int conc;           /* Drug concentration */

    problem = get_problem();

    while (problem != QUIT) {
        switch(problem) {
            case 1:
                get_rate_drop_factor(&rate_inp, &drop);
                rate_out = fig_drops_min(rate_inp, drop);
                printf("The drop rate per minute is %d.\n\n", rate_out);
                break;

            case 2:
                printf("Enter number of hours: ");
                scanf("%d", &hours);
                rate_out = fig_ml_hr(hours);
                printf("The rate in milliliters per hour is %d.\n\n", rate_out);
                break;

            case 3:
                get_kg_rate_conc(&rate_inp, &weight, &conc);
                rate_out = by_weight(rate_inp, weight, conc);
                printf("The rate in milliliters per hour is %d\n\n.", rate_out);
                break;

            case 4:
                get_units_conc(&rate_inp, &conc);
                rate_out = by_units(rate_inp, conc);
                printf("The rate in milliliters per hour is %d\n\n.", rate_out);
                break;
        }

        problem = get_problem();
    }

    return (0);
}

/*
 * Displays a menu with the list of problems to assist with
 * Returns the problem number selected by user
 */
int
get_problem()
{
    int problem;

    printf("INTRAVENOUS RATE ASSISTANT\n\n");
    printf("Enter the number of the problem you wish to solve.\n");
    printf("    GIVEN A MEDICAL ORDER IN                CALCULATE RATE IN\n");
    printf("(1) ml/hr & tubing drop factor              drops / min\n");
    printf("(2) 1 L for n hr                            ml / hr\n");
    printf("(3) mg/kg/hr & concentration in mg/ml       ml / hr\n");
    printf("(4) units/hr & concentration in units/ml    ml / hr\n");
    printf("(5) QUIT\n\n");
    printf("Problem: ");
    scanf("%d", &problem);

    return problem;
}

/*
 * Prompts user to enter data for problem 1
 * Returns rate (ml/hr) and drop factor (drops/ml)
 */
void
get_rate_drop_factor(double *rate, int *drop)
{
    printf("Enter rate in ml/hr: ");
    scanf("%lf", rate);
    printf("Enter tubing's drop factor(drops/ml): ");
    scanf("%d", drop);
}

/*
 * Prompts user to enter data for problem 3
 * Returns rate (mg/kg/hr), patient weight (kg) and concentration (mg/ml)
 */
void
get_kg_rate_conc(double *rate, int *weight, int *conc)
{
    printf("Enter rate in mg/kg/hour: ");
    scanf("%lf", rate);
    printf("Enter patient weight in kg: ");
    scanf("%d", weight);
    printf("Enter concentration in mg/ml: ");
    scanf("%d", conc);
}

/*
 * Prompts user to enter data for problem 4
 * Returns rate (units/hour), concentration (units/ml)
 */
void
get_units_conc(double *rate, int *conc)
{
    printf("Enter rate in units/hr: ");
    scanf("%lf", rate);
    printf("Enter concentration in units/ml: ");
    scanf("%d", conc);
}

/*
 * Pre: rate (ml/hr) and drop factor (drops/ml)
 * Returns rate in drop/minute
 */
int
fig_drops_min(double rate, int drop)
{
    double ml_min;

    ml_min = rate / 60.0;
    rate = ml_min * drop;

    return ((int) rate);
}

/*
 * Pre: hours
 * Returns rate in ml/hr
 */
int
fig_ml_hr(int hours)
{
    double rate;

    rate = 1000 / (double) hours;

    return ((int) rate);
}

/*
 * Pre: rate (mg/kg/hr), weight (kg), concentration (mg/ml)
 * Returns rate in ml/hr
 */
int
by_weight(double rate, int weight, int conc)
{
    rate = rate * weight * 1.0 / conc;

    return ((int) rate);
}

/*
 * Pre: rate (units/hour), concentration (units/ml)
 * Returns rate in ml/hr
 */
int
by_units(double rate, int conc)
{
    rate = rate / (double) conc;

    return ((int) rate);
}
