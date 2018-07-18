#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "basesort.h"
#include "whichsortmethod.h"

/*
���ʹ�����������򷽷�
*/

//�Ƿ��������
//����һ��������˵��ǰ�漸��Ԫ���Ѿ�������ϣ��������Խ�󣬲�������Ŀ�����Խ��
/*
Insertion sort iterates, consuming one input element each repetition,
and growing a sorted output list.Each iteration,
insertion sort removes one element from the input data,
finds the location it belongs within the sorted list,
and inserts it there.It repeats until no input elements remain.
*/
int IsInsertSort(ElementType A[], ElementType B[], int N) {
	int i = 0;
	for (i = 0; i < N - 1 && B[i] < B[i + 1]; i++);
	return i;
}

//�Ƿ�鲢����
/*
Merge sort works as follows: Divide the unsorted list into N sublists,
each containing 1 element (a list of 1 element is considered sorted).
Then repeatedly merge two adjacent sublists to produce new sorted sublists
until there is only 1 sublist remaining.
*/
int IsMergeSort(ElementType A[], ElementType B[], int N) {
	int result = 0;
	for (result = 1; result < N / 2; result *= 2) {
		for (int i = 0; i + result < N - 1; i += result + 1) {
			int start = i;
			int end = start + result;
			if (!IsSortSuccess(B, start, end)) { //���벿�����򣬷��򷵻�
				return result - 1;
			}
		}
	}
	return result;
}

//�Ƿ񲿷�����(��start��end��
bool IsSortSuccess(ElementType A[], int start, int end) {
	for (int i = start; i + 1 <= end; i++) {
		if (A[i] > A[i + 1]) {
			return false;
		}
	}
	return true;
}
//�Ƿ������
/*
Heap sort divides its input into a sorted and an unsorted region,
and it iteratively shrinks the unsorted region by extracting the largest element
and moving that to the sorted region.
it involves the use of a heap data structure rather than a linear-time search to find the maximum.
�ص�����󼸸����Ǵ�С��������õģ����������һ����Խ�����Խ��
*/
int IsHeapSort(ElementType A[], ElementType B[], int N) {
	int result = 0;
	for (int i = N - 1; i >= 0; i--) {
		if (B[i - 1] > B[i]) {
			result = N - i - 1;
		}
	}
	return result;
}

void readArray(ElementType A[], ElementType B[], int N)
{
	int data;
	int index = 0;
	for (index = 0; index < N && scanf("%d", &data) != EOF; index++) {
		A[index] = data;
	}
	for (index = 0; index < N && scanf("%d", &data) != EOF; index++) {
		B[index] = data;
	}
}

void WhichSortMethodDemo() {
	int N;
	scanf("%d", &N);
	ElementType *A = new int[N];
	ElementType *B = new int[N];
	readArray(A, B, N);
	int degreeInsert = IsInsertSort(A, B, N);
	int degreeMerge = IsMergeSort(A, B, N);
	int degreeHeap= IsHeapSort(A, B, N);
	if (degreeInsert > degreeMerge) {
		if (degreeHeap > degreeInsert) {
			printf("Heap Sort\n");
		}
		else {
			printf("Insertion Sort\n");
		}
	}
	else {
		if (degreeHeap > degreeMerge) {
			printf("Heap Sort\n");
		}
		else {
			printf("Merge Sort\n");
		}
	}

	PrintArray(B, N);

	delete[]A;
	delete[]B;
}
