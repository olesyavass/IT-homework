#include <stdio.h>
#include <math.h>
double Integral(double (*f)(double), double from, double to, double step) {
	int n = (int)((to - from) / step);
	if (n <= 0) return 0;
	double h = (to - from) / n;
	double sum = (f(from) + f(to)) / 2;
	for (int(i) = 1; i < n; i++) {
		sum += f(from + h * i);
	}
	return sum * h;
}
int main() {
	double res = Integral(sin, 0.0, 3.14159/4, 0.0001);
	printf("Result: %lf\n", res);
	return 0;
}
