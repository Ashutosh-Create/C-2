/*
 * Name: Abhijit Parida		Date: 29-03-2017
 * Program Description: To take a string and return a copy with all
 *	blanks removed.
 * Input: a string
 * Output: the string with all blanks removed
 */

#include <stdio.h>
#include <ctype.h>

void deblank(char input[], char output[]);

int
main(void)
{
	char input[100];
	char output[100];

	printf("Enter string: ");
	gets(input);

	deblank(input, output);
	printf("String without blanks:\n%s\n", output);

	return (0);
}

void
deblank(char input[], char output[])
{
	int i, j;
	char ch;

	i = 0;
	j = 0;
	while ((ch = input[i]) != '\0') {
		if (!isspace(ch)) {
			output[j] = ch;
			j++;
		}
		i++;
	}
	output[j] = '\0';
}
