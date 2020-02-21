/*
 * Name: Abhijit Parida		Date: 17-02-17
 * Program Description: To approximate the value of pi
 * Output: approximation of pi upto 99 terms
 */

#include <stdio.h>

int
main(void)
{
	int i;
	double sum;
	double pi;

	sum = 0;

	for (i = 0; i < 50; i++) {
		if (i % 2 == 0) {
			sum += 1 / (double) (2 * i + 1);
		} else {
			sum -= 1 / (double) (2 * i + 1);
		}
	}

	pi = 4 * sum;

	printf("%f\n", pi);
}
