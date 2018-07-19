#include "stdafx.h"
#include <stdio.h>
#include <math.h>
#include <time.h>

#define MAXN  10

double CountTick(double pf(int , double [], double ), int count) {
	double a[MAXN];
	for (int i = 0;i < MAXN; i++) a[i] = (double)i;

	clock_t start, stop;
	start = clock();
	for (int i = 0;i < count;i++)
		pf(MAXN -1, a, 1.1);
	stop = clock();
	return (double)(stop - start) / CLK_TCK;

}

double CountTick2(int pf(int[], int ), int A[], int N) {

	clock_t start, stop;
	start = clock();
		pf(A, N);
	stop = clock();
	return (double)(stop - start) / CLK_TCK;

}
