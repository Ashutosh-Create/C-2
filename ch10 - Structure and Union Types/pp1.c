/*
 * Program Description: To use structs to represent automobiles.
 * Input: automobile make and model, odometer reading, manufacture and purchase
 *      dates, gas tank capacity and current fuel level
 * Output: automobile details
 */

#include <stdio.h>

/*
 * Data type for storing date.
 */
typedef struct {
    int day;
    int month;
    int year;
} date_t;

/*
 * Data type for storing fuel tank info of an automobile.
 */
typedef struct {
    double tank_capacity;   /* Tank capacity */
    double fuel_level;      /* Current fuel level */
} tank_t;

/*
 * Data type for storing automobile info.
 */
typedef struct {
    char make[20];      /* Automobile make */
    char model[20];     /* Automobile model */
    int odometer;       /* Odometer reading */
    date_t manufacture; /* Manufacture date */
    date_t purchase;    /* Purchase date */
    tank_t tank;         /* Gas tank info */
} auto_t;

int scan_date(FILE *input, date_t *date);
int scan_tank(FILE *input, tank_t *tank);
int scan_auto(FILE *input, auto_t *automobile);
void print_date(date_t *date);
void print_tank(tank_t *tank);
void print_auto(auto_t *automobile);

int
main(void)
{
    FILE *input;        /* Input file - "automobile.txt" */
    auto_t automobile;  /* Automobile struct */
    int input_status;   /* Input status */

    input = fopen("automobile.txt", "r");

    input_status = scan_auto(input, &automobile);
    while (input_status != 0) {
        print_auto(&automobile);
        input_status = scan_auto(input, &automobile);
    }

    fclose(input);

    return (0);
}

/*
 * Fills a date_t structure with user input.
 * Returns 1 if data was scanned successfully, returns 0 otherwise.
 */
int
scan_date(FILE *input, date_t *date)
{
    int input_status;   /* Value returned by scanf() */

    input_status = fscanf(input, "%d%d%d", &date->day, &date->month,
        &date->year);

    return (input_status == 3);
}

/*
 * Fills a tank_t structure with user input.
 * Returns 1 if data was scanned successfully, returns 0 otherwise.
 */
int
scan_tank(FILE *input, tank_t *tank)
{
    int input_status;   /* Value returned by scanf() */

    input_status = fscanf(input, "%lf%lf", &tank->tank_capacity,
        &tank->fuel_level);

    return (input_status == 2);
}

/*
 * Fills an auto_t structure with user input.
 * Returns 1 if data was scanned successfully, returns 0 otherwise.
 */
int
scan_auto(FILE *input, auto_t *automobile)
{
    int input_status;   /* Value returned by scanf() */

    input_status = fscanf(input, "%s%s%d", automobile->make,
        automobile->model, &automobile->odometer);

    input_status = (input_status == 3);

    input_status &= scan_date(input, &automobile->manufacture);
    input_status &= scan_date(input, &automobile->purchase);
    input_status &= scan_tank(input, &automobile->tank);

    return (input_status);
}

/*
 * Prints a date_t structure.
 */
void
print_date(date_t *date)
{
    printf("%d/%d/%d\n", date->day, date->month, date->year);
}

/*
 * Prints a tank_t structure.
 */
void
print_tank(tank_t *tank)
{
    printf("  Tank capacity: %.2f L\n", tank->tank_capacity);
    printf("  Current fuel level: %.2f L\n", tank->fuel_level);
}

/*
 * Prints an automobile_t structure.
 */
void
print_auto(auto_t *automobile)
{
    printf("Make and model: %s %s\n", automobile->make, automobile->model);
    printf("Odometer reading: %d\n", automobile->odometer);
    printf("Manufacture date: ");
    print_date(&automobile->manufacture);
    printf("Purchase date: ");
    print_date(&automobile->purchase);
    printf("Gas tank:\n");
    print_tank(&automobile->tank);
    printf("\n");
}
