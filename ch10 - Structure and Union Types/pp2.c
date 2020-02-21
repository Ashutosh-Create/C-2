/*
 * Program Description: To use structs to represent elements of periodic table.
 * Input: atomic number, name, chemical symbol, class, atomic weight and number
 *      of electrons in each cell
 * Output: details of the chemical element
 */

#include <stdio.h>

/*
 * Data type for storing chemical element.
 */
typedef struct {
    int atomic_number;      /* Atomic number */
    char name[20];          /* Name of the chemical element */
    char symbol[3];         /* Chemical symbol */
    char class[20];         /* Element class */
    double atomic_weight;   /* Atomic weight */
    int electrons[7];       /* Electrons in each shell */
} element_t;

int scan_element(FILE *input, element_t *element);
void print_element(element_t *element);

int
main(void)
{
    FILE *input;        /* Input file - "elements.txt" */
    element_t element;  /* Element struct */
    int input_status;   /* Input status */

    input = fopen("elements.txt", "r");

    input_status = scan_element(input, &element);
    while (input_status != 0) {
        print_element(&element);
        input_status = scan_element(input, &element);
    }

    fclose(input);

    return (0);
}

/*
 * Fills a element_t structure with user input.
 * Returns 1 if data was scanned successfully, returns 0 otherwise.
 */
int
scan_element(FILE *input, element_t *element)
{
    int i;              /* Loop index */
    int input_status;   /* Value returned by scanf() */

    input_status = fscanf(input, "%d%s%s%s%lf",
        &element->atomic_number, element->name, element->symbol,
        element->class, &element->atomic_weight);

    if (input_status != 5) {
        return (0);
    }

    for (i = 0; i < 7; i++) {
        input_status = fscanf(input, "%d", &element->electrons[i]);
        if (input_status != 1) {
            return (0);
        }
    }

    return (1);
}

/*
 * Prints a element_t structure.
 */
void
print_element(element_t *element)
{
    int i;      /* Loop index */

    printf("Atomic number: %d\n", element->atomic_number);
    printf("Name: %s\n", element->name);
    printf("Chemical symbol: %s\n", element->symbol);
    printf("Class: %s\n", element->class);
    printf("Atomic weight: %.4f\n", element->atomic_weight);
    printf("Electrons:\n");
    for (i = 0; i < 7; i++) {
        printf("  In shell %d: %d\n", i + 1, element->electrons[i]);
    }
    printf("\n");
}
