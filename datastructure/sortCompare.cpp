#include "stdafx.h"
#include <math.h>
#include <stdlib.h>
#include "basesort.h"
#include "time.h"

#define MaxN 100000
double countTickForSort(void pf(ElementType[], int), ElementType A[], int N) {

	clock_t start, stop;
	start = clock();
	pf(A, N);
	stop = clock();
	return (double)(stop - start) / CLK_TCK;
}

void copy(ElementType source[], ElementType target[], int N)
{
	for (int i = 0; i < N; i++) {
		target[i] = source[i];
	}
}

void reverse(ElementType BaseA[], int N){
	for (int i = 0; i < N && i < N - i; i++) {
		Swap(&BaseA[i], &BaseA[N - i]);
	}
}

void generateArray(ElementType BaseA[], int N, int dataset)
{
	srand(time(NULL));//������������ӡ�
	for (int i = 0; i < N; i++) {
		BaseA[i] = rand();
		switch (dataset) {
		case 5: //�������
		case 6: //˳������
		case 7: //��������
		case 8: //�������������
			BaseA[i] = (BaseA[i] % 2 > 0 ? 1 : -1)*BaseA[i];
			break;
		case 9: //�����������ÿ�����ֲ�����1000
			BaseA[i] = BaseA[i] % 1000;
			break;
		}
	}
	switch (dataset) {
	case 6: //˳������
		MergeSort2(BaseA, N); //ʹ�ù鲢����
		break;
	case 7: //��������
		MergeSort2(BaseA, N); //ʹ�ù鲢����
		reverse(BaseA, N);    //����
		break;
	case 8: //�������������
		MergeSort2(BaseA, N); //ʹ�ù鲢����
		srand(time(NULL));//�������������
		int count1 = sqrt(N) / 3;
		for (int i = 0; i < count1; i++) {
			int index = rand();
			int index2 = rand();
			Swap(&BaseA[index], &BaseA[index2]);
		}
		break;
	}
}

void SortCompareDemo() {
	ElementType BaseA[MaxN], A[MaxN];
	int dataset = 8;
	generateArray(BaseA, MaxN, dataset);
	printf("---------dataset:%d\n", dataset);
	copy(BaseA, A, MaxN);
	double duration4 = countTickForSort(Bubble_Sort, A, MaxN);
	printf("duration(Bubble_Sort) = %10.5e\n", duration4);

	copy(BaseA, A, MaxN);
	double duration3 = countTickForSort(InsertionSort, A, MaxN);
	printf("duration(InsertionSort) = %10.5e\n", duration3);

	copy(BaseA, A, MaxN);
	double duration2 = countTickForSort(ShellSortSedgewick, A, MaxN);
	printf("duration(ShellSortSedgewick) = %10.5e\n", duration2);

	copy(BaseA, A, MaxN);
	double duration1 = countTickForSort(SelectionSort, A, MaxN);
	printf("duration(SelectionSort) = %10.5e\n", duration1);

	copy(BaseA, A, MaxN);
	duration1 = countTickForSort(HeapSort, A, MaxN);
	printf("duration(HeapSort) = %10.5e\n", duration1);

	copy(BaseA, A, MaxN);
	duration1 = countTickForSort(MergeSort1, A, MaxN);
	printf("duration(MergeSort1) = %10.5e\n", duration1);

	copy(BaseA, A, MaxN);
	duration1 = countTickForSort(MergeSort2, A, MaxN);
	printf("duration(MergeSort2) = %10.5e\n", duration1);
}