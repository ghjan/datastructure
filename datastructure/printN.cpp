#include "stdafx.h"
#include <math.h>
#include "ch1.h"
void printN1(int N) {

	for (int i = 0;i < N;i++) {
		printf("%d\n", i);
	}
	return;
}

void printN2(int N) {
	if (N) {
		printN2(N - 1);
		printf("%d\n", N);
	}
	else {
		return;
	}
}