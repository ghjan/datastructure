#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "time.h"
#include "array.h"
#include "basesort.h"

void Copy(ElementType source[], ElementType target[], int N)
{
	for (int i = 0; i < N; i++) {
		target[i] = source[i];
	}
}

void Reverse(ElementType BaseA[], int N) {
	for (int i = 0; i < N && i < N - i; i++) {
		Swap(&BaseA[i], &BaseA[N - i]);
	}
}

void GenerateArray(ElementType BaseA[], int N, int dataset)
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
		Reverse(BaseA, N);    //����
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

void PrintArray(int data[], int size)
{
	int i;

	for (i = 0; i < size; i++)
		printf("%d ", data[i]);

	printf("\n");
}

void PrintNode(Node data[], int size)
{
	int i;

	for (i = 0; i < size; i++)
		printf("(%d %d) ", data[i].key1, data[i].key2);

	printf("\n");
}

//�ָ����飬�������бȻ�׼С���Ƶ���׼��ߣ�����Ƶ��ұ�
int SplitArrayWithPivot(ElementType A[], int Low, int High, int Pivot) {

	while (Low < High) {
		while (A[Low] < Pivot)Low++;
		while (A[High] >= Pivot)High--;
		if (Low < High) Swap(&A[Low], &A[High]);
		else break;
	}
	return Low;
}

double CountTickForSort(void pf(ElementType[], int), ElementType A[], int N) {

	clock_t start, stop;
	start = clock();
	pf(A, N);
	stop = clock();
	return (double)(stop - start) / CLK_TCK;
}
