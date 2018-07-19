#include "stdafx.h"
#include <math.h>
#include <stdlib.h>
#include "time.h"
#pragma warning(disable:4996)


int* readAgeData(int *N)
{
	scanf("%d", N);
	char *strNumbers = NULL;
	//char *number = NULL;
	int data;
	int *A = new int[*N];

	bool isFirst = true;
	for (int count = 0; count < *N && scanf("%d", &data) != EOF; count++) {
		A[count] = data;
	}

	return A;
}

int* sortAgeData(int* A, int N, int ageStart, int ageEnd) {
	int *bucket = new int[ageEnd - ageStart + 1];
	for (int i = 0; i < ageEnd - ageStart + 1; i++) {
		bucket[i] = 0;
	}
	for (int i = 0; i < N; i++) {
		bucket[A[i]]++;
	}
	return bucket;
}

int SolveAgeStastistics() {
	int N = 0;
	int *A = readAgeData(&N);
	int *bucket = sortAgeData(A, N, 0, 50);

	for (int i = 0; i <= 50; i++) {
		if (bucket[i] > 0) {
			printf("%d:%d\n", i, bucket[i]);
		}
	}
	return 0;
}

