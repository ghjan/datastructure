#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

#include "time.h"
#include "basesort.h"
#pragma warning(disable:4996)
//using namespace std;

int readArrayData(int A[], int *N, int *missPosition, int *positionZero)
{
	int countMissed = 0;
	scanf("%d", N);
	char *strNumbers = NULL;
	int data;

	bool isFirst = true;
	for (int count = 0; count < *N && scanf("%d", &data); count++) {
		A[count] = data;
		if (*positionZero < 0 && data == 0) {
			*positionZero = count;
		}
		if (count != data) {
			missPosition[data] = count;
			countMissed++;
		}
	}

	return countMissed;
}

int nextUsed(bool *finished, int N, int positionZero, int positionZeroNew) {
	int i = N;
	for (i = N; i > 0; i--) {
		if (i == positionZero && i == positionZeroNew)
			continue;
		if (!finished[i])
			return i;
	}
	return i;
}
int sortWithSwaps(int A[], int N, int countMissed, int* missPosition, int positionZero) {
	int i = 0;
	bool *finished = (bool *)malloc(N * sizeof(bool));
	for (int jj = 0; jj < N; jj++) {
		if (jj > 0 && A[jj] == jj)finished[jj] = true;
		else
			finished[jj] = false;
	}
	for (i = 0; i < countMissed - 1; i++) {
		bool isEffective = true;
		int positionZeroNew = missPosition[positionZero];
		if (finished[positionZeroNew] || (positionZeroNew == 0 && i < countMissed - 2)) {//避免过早把0交换到0位置
			positionZeroNew = nextUsed(finished, N, positionZero, positionZeroNew);
			countMissed++;
			isEffective = false; //这次交换没有让某个数字到达finished状态，算一次过渡的
			missPosition[A[positionZeroNew]] = positionZero; //因为这次交换是无效交换，所以必须更新missPosition信息
		}
		if (positionZeroNew == positionZero) {
			break;
		}
		Swap(&A[positionZero], &A[positionZeroNew]);
		if (isEffective)
			finished[positionZero] = true;
		positionZero = positionZeroNew;
	}
	return i;
}

int SolveSortWithSwap() {
	int N = 0;
	int countMissed = 0;
	int A[MaxN];
	int missPosition[MaxN];
	int positionZero = -1;
	countMissed = readArrayData(A, &N, missPosition, &positionZero);
	int realSwaped = sortWithSwaps(A, N, countMissed, missPosition, positionZero);
	printf("%d\n", realSwaped);
	//PrintArray(A, N);

	return 0;

}