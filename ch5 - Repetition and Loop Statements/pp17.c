/*
 * Name: Abhijit Parida		Date: 17-02-17
 * Program Description: To find the area under the curve
 */

#include <stdio.h>
#include <math.h>

double trap(double a, double b, int n, double f(double x));
double g(double x);
double h(double x);

int main()
{
	int n;		/* Number of subintervals */
	double a, b;	/* Lower and upper limits */
	double area;	/* Area under curve */

	/* Get lower and upper limits for g(x) */
	printf("g(x) = x^2 * sin(x)\n");
	printf("Enter lower and upper limits: ");
	scanf("%lf%lf", &a, &b);

	/* Calculate area under curve g(x) */
	for (n = 2; n <= 128; n = n * 2) {
		area = trap(a, b, n, g);
		printf("Area under g(x) with %d subintervals is %f\n", n, area);
	}

	/* Get lower and upper limits for h(x) */
	printf("\nh(x) = sqrt(4 - x^2)\n");
	printf("Enter lower and upper limits: ");
	scanf("%lf%lf", &a, &b);

	/* Calculate area under curve h(x) */
	for (n = 2; n <= 128; n = n * 2) {
		area = trap(a, b, n, h);
		printf("Area under h(x) with %d subintervals is %f\n", n, area);
	}
}

/*
 * Returns the area under the curve of f(x) with limits from a to b with
 * n subintervals using the trapezoidal rule
 */
double trap(double a, double b, int n, double f(double x))
{
	double h;	/* Subinterval length */
	double fa, fb;	/* Values of f(a) and f(b) */
	int i;
	double x;
	double sum;	/* Summation of f(xi) from i = 1 to n-1 */
	double area;	/* Area under curve */

	h = (b - a) / n;
	fa = f(a);
	fb = f(b);

	/* Summation of f(xi) from i = 1 to n-1 */
	sum = 0;
	for (i = 1, x = a + h; i <= n-1; i++, x += h) {
		sum += f(x);
	}

	/* Calculate area using trapezoidal rule */
	area = (h / 2.0) * (fa + fb + 2 * sum);

	return area;
}

/*
 * Returns the value of g(x) = x^2 * sin(x)
 */
double g(double x)
{
	return x * x * sin(x);
}

/*
 * Returns the value of h(x) = sqrt(4 - x^2)
 */
double h(double x)
{
	return sqrt(4 - x * x);
}
