/*
 * Name: Abhijit Parida		Date: 31-03-2017
 * Program Description: To check if a chemical compound ends with OH
 * Input: chemical compound
 * Output: if chemical compounds ends with OH
 */

#include <stdio.h>
#include <string.h>

int hydroxide(char compound[]);

int
main(void)
{
	char compound[10];

	printf("Enter chemical compound: ");
	gets(compound);

	if (hydroxide(compound)) {
		printf("%s is a hydroxide\n", compound);
	} else {
		printf("%s is not a hydroxide\n", compound);
	}

	return (0);
}

/*
 * Returns 1 if compound is a hydroxide
 * Returns 0 otherwise
 */
int
hydroxide(char compound[])
{
	int len;
	char oh[3];

	len = strlen(compound);
	strncpy(oh, &compound[len-2], 2);
	oh[2] = '\0';

	return (!strcmp(oh, "OH"));
}
