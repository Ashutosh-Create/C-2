/*
 * Program Description: To find plural form of nouns
 * Input: a noun
 * Output: plural of noun
 */

#include <stdio.h>
#include <string.h>

#define MAXLEN 20

void get_plural(char noun[], char plural[]);

int
main(void)
{
	char noun[MAXLEN];
	char plural[MAXLEN];

	printf("Enter noun: ");
	gets(noun);

	get_plural(noun, plural);
	printf("Plural: %s\n", plural);

	return (0);
}

/*
 * Returns the plural of given noun
 */
void
get_plural(char noun[], char plural[])
{
	int len;
	char last, last2[3];

	strcpy(plural, noun);

	len = strlen(noun);
	last = noun[len-1];
	strncpy(last2, &noun[len-2], 3);

	if (last == 'y') {
		strcpy(&plural[len-1], "ies");
	} else if (last == 's' || !strcmp(last2, "ch")
		|| !strcmp(last2, "sh")) {
		strcpy(&plural[len], "es");
	} else {
		strcpy(&plural[len], "s");
	}
}
