#include "stdafx.h"
#include <math.h>
#include "ch1.h"
using namespace std;

double f1(int n, double a[], double x) {
	int i;
	double p = a[0];
	for (i = 1;i <= n;i++) {
		p += (a[i] * pow(x, i));
	}
	return p;
}

double f2(int n, double a[], double x) {
	int i;
	double p = a[0];
	for (i = n;i >0;i--) {
		p = a[i - 1] + x * p;
	}
	return p;
}

void polynomial(int count) {
	double duration1 = count_tick(f1, count);
	printf("duration1 = %6.2e\n", duration1);
	double duration2 = count_tick(f2, count);
	printf("duration2 = %6.2e\n", duration2);

}
