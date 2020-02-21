/*
 * Program Description: To process a data file of names and store the surname,
 *      first name and middle initial
 * Input: data file of names
 * Output: surname, first name and middle initial
 */

#include <stdio.h>
#include <string.h>

int get_name(FILE *data, char surname[16], char first[11], char *middle_init);

int
main(void)
{
    FILE *data;             /* Data file of names */
    FILE *names;            /* Output file */
    char surname[16];       /* Surname */
    char first[11];         /* First name */
    char middle_init;       /* Middle initial */

    data = fopen("data.txt", "r");
    names = fopen("names.txt", "w");

    while (get_name(data, surname, first, &middle_init)) {
        fprintf(names, "%-20s%-15s%c\n", surname, first, middle_init);
    }

    fclose(data);
    fclose(names);

    return (0);
}

/*
 * Reads a name from data file and fills surname[], first[] and middle initial
 * Returns 1 on successfully reading a name, returns 0 otherwise on reaching
 * the end of file
 */
int
get_name(FILE *data, char surname[16], char first[11], char *middle_init)
{
    char name[81];          /* A line from the data file */
    char *temp;
    int len;

    if (fgets(name, 80, data) == NULL) {
        return (0);
    }

    temp = strtok(name, ", ");
    len = strlen(temp);
    if (len > 15) {
        strncpy(surname, temp, 15);
    } else {
        strcpy(surname, temp);
    }

    temp = strtok(NULL, " ");
    len = strlen(temp);
    strcpy(first, temp);
    if (first[len-1] == '.') {
        first[len-1] = '\0';
    }

    temp = strtok(NULL, ".");
    *middle_init = temp[0];

    return (1);
}
