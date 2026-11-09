#include <stdio.h>
#include <math.h>
double teylor_sin(double x0, double accuracy, int N, int *steps) {
	int n = 1;
	double el = x0;
	double sum = el;
	for (int i = 1; i < N; i++) {
		el = el * (-x0 * x0) / ((2 * i + 1) * 2 * i);
		sum += el;
		n += 1;
		if (fabs(el) < accuracy) {
			break;
		}	
	}
	*steps = n;
	return sum;
}
double teylor_cos(double x0, double accuracy, int N, int *steps) {
	int n = 1;
	double el = 1;
	double sum = el;
	for (int i = 1; i < N; i++) {
		el = el * (-x0 * x0) / ((2 * i - 1) * 2 * i);
		sum += el;
		n += 1;
		if (fabs(el) < accuracy) {
			break;
		}
	}
	*steps = n;
	return sum;
}
double teylor_exp(double x0, double accuracy, int N, int *steps) {
	int n = 1;
	double el = 1;
	double sum = el;
	for (int i = 1; i < N; i++) {
		el = el * x0 / i;
		sum += el;
		n += 1;
		if (fabs(el) < accuracy) {
			break;
		}
	}
	*steps = n;
	return sum;
}
double teylor_ch(double x0, double accuracy, int N, int *steps) {
	int n = 1;
	double el = 1;
	double sum = el;
	for (int i = 1; i < N; i++) {
		el = el * x0*x0 / ((2*i-1)*2*i);
		sum += el;
		n += 1;
		if (fabs(el) < accuracy) {
			break;
		}
	}
	*steps = n;
	return sum;
}
int main(void) {
	int mode;
	int func;

	printf("Select the operating mode:\n");
	printf("1 - A single calculation of the point at the specified location\n2 - Serial experiment\n");
	scanf_s("%d", &mode);
	printf("Choose the function:\n");
	printf("1 - sin(x)\n2 - cos(x)\n3 - exp(x)\n4 - ch(x)\n");
	scanf_s("%d", &func);

	if (mode == 1) {
		double x0;
		double accuracy;
		int N;
		int steps = 0;
		double result_1 = 0;
		double result_2 = 0;
		printf("Enter the point x at which the value needs to be calculated:\n");
		scanf_s("%lf", &x0);
		printf("Enter the calculation accuracy (from 0.000001 and above):\n");
		scanf_s("%lf", &accuracy);
		printf("Enter the number of elements in the series to perform the calculation (N from 1 to 1000):\n");
		scanf_s("%d", &N);
		if (func == 1) {
			result_1 = sin(x0);
			result_2 = teylor_sin(x0, accuracy, N, &steps);

		}
		if (func == 2) {
			result_1 = cos(x0);
			result_2 = teylor_cos(x0, accuracy, N, &steps);
		}
		if (func == 3) {
			result_1 = exp(x0);
			result_2 = teylor_exp(x0, accuracy, N, &steps);

		}
		if (func == 4) {
			result_1 = cosh(x0);
			result_2 = teylor_ch(x0, accuracy, N, &steps);
		}
		printf("Referens value: %lf\n", result_1);
		printf("Estimated value: %lf\n", result_2);
		printf("Difference in values: %lf\n", fabs(result_1 - result_2));
		printf("Number of addends: %d\n", steps);
	} 
	if (mode == 2) {
		double x0;
		int num_e;
		int steps = 0;
		double (*ref)(double) = NULL;
		double (*teylor)(double, double, int, int*) = NULL;
		printf("Enter the point x at which the value needs to be calculated:\n");
		scanf_s("%lf", &x0);
		printf("Select the number of experiments (NMax from 1 to 25):\n");
		scanf_s("%d", &num_e);

		if (func == 1) {
			ref = sin;
			teylor = teylor_sin;

		}
		if (func == 2) {
			ref = cos;
			teylor = teylor_cos;
		}
		if (func == 3) {
			ref = exp;
			teylor = teylor_exp;

		}
		if (func == 4) {
			ref = cosh;
			teylor = teylor_ch;
		}
		double ref_val = ref(x0);
		printf("Reference value: %lf\n", ref_val);
		printf("N     Estimated value    Difference\n");
		for (int i = 1; i < num_e + 1; i++) {
			double est = teylor(x0, 0, i, &steps);
			double difference = fabs(est - ref_val);
			if (i < 10) {
				printf("%d         %lf        %lf\n", i, est, difference);
			}
			else {
				printf("%d        %lf        %lf\n", i, est, difference);
			}
			
		}
	}
}
