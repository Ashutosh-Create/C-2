/*
 * Program Description: To calculate charges for an Internet service provider
 * Input: file containing month, year, customer number, hours used
 * Output: file containing charge per hour and average cost
 */

#include <stdio.h>
#include <math.h>

#define FLAT_RATE_HOURS 10.0    /* 10 hours */
#define FLAT_RATE 7.99          /* $ 7.99 */
#define NORMAL_RATE 1.99        /* $ 1.99 */

void calculate_charges(double hours_used,
    double *charge_per_hour, double *average_cost);

int
main(void)
{
    FILE *usage;                /* Input file - "usage.txt" */
    FILE *charges;              /* Output file - "charges.txt" */
    int month, year;            /* Current month and year input from file */
    int customer_number;        /* Customer number input from file */
    double hours_used;          /* Hours used by customer */
    double charge_per_hour;     /* Charge per hour */
    double average_cost;        /* Average cost */
    int input_status;           /* Value returned by scanf */

    usage = fopen("usage.txt", "r");
    charges = fopen("charges.txt", "w");

    fscanf(usage, "%d%d", &month, &year);

    fprintf(charges, "Charges for %d/%d\n\n", month, year);
    fprintf(charges, "Customer\tHours used\tCharge/hour\tAverage Cost\n");

    input_status = fscanf(usage, "%d%lf", &customer_number, &hours_used);
    while (input_status == 2) {
        calculate_charges(hours_used, &charge_per_hour, &average_cost);
        fprintf(charges, "%d\t\t%.1f\t\t%.2f\t\t%.2f\n", customer_number,
            hours_used, charge_per_hour, average_cost);
        input_status = fscanf(usage, "%d%lf", &customer_number, &hours_used);
    }

    fclose(usage);
    fclose(charges);

    return (0);
}

/*
 * Calculates charge per hour and average cost
 * Pre: hours used
 */
void
calculate_charges(double hours_used,
    double *charge_per_hour, double *average_cost)
{
    if (hours_used <= FLAT_RATE_HOURS) {
        *charge_per_hour = FLAT_RATE;
    } else {
        *charge_per_hour = FLAT_RATE
            + ceil(hours_used - FLAT_RATE_HOURS) * NORMAL_RATE;
    }

    *average_cost = *charge_per_hour / hours_used;
}
