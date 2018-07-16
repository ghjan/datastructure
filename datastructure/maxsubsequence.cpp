#include "stdafx.h"
#include <math.h>
#include <stdlib.h>
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

void test_subsequence(int count) {
	double duration1 = count_tick(f1, count);
	printf("duration1 = %6.2e\n", duration1);
	double duration2 = count_tick(f2, count);
	printf("duration2 = %6.2e\n", duration2);

}

void demo_maxsubsequence() {
	int A[N];
	for (int i = 0;i < N;i++) {
		A[i] = rand() % 100;
		A[i] = (A[i] % 3 > 0 ? 1 : -1)*A[i];
	}
	double duration4 = count_tick_2(MaxSubsequenceSum4, A, N);
	printf("duration4 = %10.5e\n", duration4);
	double duration3 = count_tick_2(MaxSubsequenceSum3, A, N);
	printf("duration3 = %10.5e\n", duration3);
	double duration2 = count_tick_2(MaxSubsequenceSum2, A, N);
	printf("duration2 = %10.5e\n", duration2);
	double duration1 = count_tick_2(MaxSubsequenceSum1, A, N);
	printf("duration1 = %10.5e\n", duration1);

}