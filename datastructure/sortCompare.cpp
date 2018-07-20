#include "stdafx.h"
#include <math.h>
#include <stdlib.h>
#include "time.h"
#include "basesort.h"
#include "radixsort.h"
#include "array.h"

void sortCompare(int dataset) {
	ElementType BaseA[MaxN], A[MaxN];
	GenerateArray(BaseA, MaxN, dataset);
	printf("---------dataset:%d\n", dataset);

	Copy(BaseA, A, MaxN);
	double duration4 = CountTickForSort(Bubble_Sort, A, MaxN);
	printf("duration(Bubble_Sort) = %10.5e\n", duration4);

	Copy(BaseA, A, MaxN);
	double duration3 = CountTickForSort(InsertionSort, A, MaxN);
	printf("duration(InsertionSort) = %10.5e\n", duration3);

	Copy(BaseA, A, MaxN);
	double duration2 = CountTickForSort(ShellSortSedgewick, A, MaxN);
	printf("duration(ShellSortSedgewick) = %10.5e\n", duration2);

	Copy(BaseA, A, MaxN);
	double duration1 = CountTickForSort(SelectionSort, A, MaxN);
	printf("duration(SelectionSort) = %10.5e\n", duration1);

	Copy(BaseA, A, MaxN);
	duration1 = CountTickForSort(HeapSort, A, MaxN);
	printf("duration(HeapSort) = %10.5e\n", duration1);

	Copy(BaseA, A, MaxN);
	duration1 = CountTickForSort(MergeSort1, A, MaxN);
	printf("duration(MergeSort1) = %10.5e\n", duration1);

	Copy(BaseA, A, MaxN);
	duration1 = CountTickForSort(MergeSort2, A, MaxN);
	printf("duration(MergeSort2) = %10.5e\n", duration1);

	Copy(BaseA, A, MaxN);
	duration1 = CountTickForSort(QuickSort, A, MaxN);
	printf("duration(QuickSort) = %10.5e\n", duration1);

	Copy(BaseA, A, MaxN);
	duration1 = CountTickForSort(LSDRadixSort, A, MaxN);
	printf("duration(LSDRadixSort) = %10.5e\n", duration1);


	Copy(BaseA, A, MaxN);
	duration1 = CountTickForSort(MSDRadixSort, A, MaxN);
	printf("duration(MSDRadixSort) = %10.5e\n", duration1);
}

void SolveSortCompare() {
	for (int dataset = 5; dataset <= 9; dataset++) {
		sortCompare(dataset);
	}

}
