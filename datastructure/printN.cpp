#include "stdafx.h"
#include <math.h>
#include "ch1.h"
void printN1(int NN) {

	for (int i = 0;i < NN;i++) {
		printf("%d\n", i);
	}
	return;
}

void printN2(int NN) {
	if (N) {
		printN2(N - 1);
		printf("%d\n", NN);
	}
	else {
		return;
	}
}