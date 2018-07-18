#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "basesort.h"
#include "whichsortmethod.h"

/*
辨别使用了哪种排序方法
*/

//是否插入排序
//返回一个整数，说明前面几个元素已经排序完毕，这个数字越大，插入排序的可能性越大
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

//是否归并排序
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
			if (!IsSortSuccess(B, start, end)) { //必须部分有序，否则返回
				return result - 1;
			}
		}
	}
	return result;
}

//是否部分有序(从start到end）
bool IsSortSuccess(ElementType A[], int start, int end) {
	for (int i = start; i + 1 <= end; i++) {
		if (A[i] > A[i + 1]) {
			return false;
		}
	}
	return true;
}
//是否堆排序
/*
Heap sort divides its input into a sorted and an unsorted region,
and it iteratively shrinks the unsorted region by extracting the largest element
and moving that to the sorted region.
it involves the use of a heap data structure rather than a linear-time search to find the maximum.
特点是最后几个都是从小到大排序好的，最大的在最后一个，越后面的越大
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
