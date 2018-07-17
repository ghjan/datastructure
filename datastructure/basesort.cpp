#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "basesort.h"


//ð������ ��С�����ݷŵ����� �ô����ǳ��� ���ܲ��ã��� O(N*N)
//�������Ԫ�����������棬ð������Ƚ��ʺ��������ݽṹ
void Bubble_Sort(ElementType A[], int N)
{
	for (int P = N - 1; P >= 0; P--) { //���N��
		int flag = 0;  //0��ʾû��ִ�н���
		for (int i = 0; i < P; i++) { /* һ��ð�� ȷ�����ĳ��������� */
			if (A[i] > A[i + 1]) { //�������ݱȽϴ�С��С��������ð
				Swap(&A[i], &A[i + 1]);
				flag = 1; /* ��ʶ�����˽���*/
			}
		}
		if (flag == 0) break; /* ȫ���޽���*/
	}
}

//�������� һ��ֽ�� 
//��Ƚ�ð������ �������������˵ �Ƚ����Ĳ�����
void InsertionSort(ElementType A[], int N)
{ /* �������� */
	int P, i;
	ElementType Tmp;

	for (P = 1; P < N; P++) {
		Tmp = A[P]; /* ȡ��δ���������еĵ�һ��Ԫ�� ����һ����*/
		for (i = P; i > 0 && A[i - 1] > Tmp; i--) //�����һ���� ��ǰ�Ƚ�
			A[i] = A[i - 1]; /*������������������Ԫ�رȽϲ�����  �����ڴ����Ƴ���λ*/
		A[i] = Tmp; /* �Ž����ʵ�λ��  ������λ*/
	}
}

////////////////ϣ������/////////////

//ԭʼshell����
void ShellSort(ElementType A[], int N)
{
	for (int D = N / 2; D > 0; D /= 2) { /* ϣ����������*/
		for (int P = D; P < N; P++) { /* ��������*/
			ElementType Tmp = A[P];
			int i;
			for (i = P; i >= D && A[i - D] > Tmp; i -= D)
				A[i] = A[i - D];
			A[i] = Tmp;
		}
	}
}

//Sedgewick��������
// ���������и�ֵ �� �ҳ�����Ҫ���������.
// �� Rebort Sedgewick(�޲��ء���������) ����� increment = 9*4^i - 9*2^i +1  �� increment = 4^i - 3*2^i +1;
// incrementSeq[] ���� 0 ��ʼ.
//https://blog.csdn.net/PacosonSWJTU/article/details/52093398
int incrementSeqFunc(int* incrementSeq, int length)
{
	int i, startup1 = 0, startup2 = 2;

	for (i = 0; i < length; i++)
	{
		if (i % 2 == 0)
		{
			incrementSeq[i] = 9 * pow(4, startup1) - 9 * pow(2, startup1) + 1;
			startup1++;
		}
		else
		{
			incrementSeq[i] = pow(4, startup2) - 3 * pow(2, startup2) + 1;
			startup2++;
		}
		if (incrementSeq[i] >= length)
		{
			break;
		}
	}
	return i; // ����������ÿ�ֶ�ʹ�ã�����һ�֣���С����������
}

void printArray(int data[], int size)
{
	int i;

	for (i = 0; i < size; i++)
		printf("%d ", data[i]);

	printf("\n");
}
//ʹ��Sedgewick�������е�ϣ������
void ShellSortSedgewick(int* array, int length)
{
	int incrementSeq[255]; // ��������(startup == 0).
	int i, j, round = incrementSeqFunc(incrementSeq, length);
	int increment, temp;

	for (; round >= 1; round--)
	{
		increment = incrementSeq[round - 1];
		for (i = 1 * increment; i < length; i += increment) // Ĭ�ϵ�,array[0*increment]�������Դ�1*increment��ʼ.
		{
			temp = array[i]; // ��1�������Ա.
			for (j = i - increment; j >= 0; j -= increment) // j �����򲿷ֽ��л���.
			{
				if (temp < array[j])
				{
					array[j + increment] = array[j];
				}
				else
				{
					break;
				}
			}
			array[j + increment] = temp;
		}
	}
}

int ShellSortSedgewickDemo()
{
	int array[] = { 100, 1000, 100, 10, 6, 2, 19, 25, 15, 55,
		35, 5, 110, 120, 119 };
	int length = 15;

	ShellSortSedgewick(array, length);
	printArray(array, length);
	return 0;
}
////////////////////ѡ������Ͷ�����//////////////

//ɨ����Сֵλ��
int ScanForMin(ElementType A[], int start, int end) {
	return 0;
}
//ѡ������
void SelectionSort(ElementType A[], int N)
{
	for (int i = 0; i < N; i++) {
		int MinPosition = ScanForMin(A, i, N - 1);
		/* ��A[i]��A[N�C1]������СԪ��������λ�ø���MinPosition */
		Swap(&A[i], &A[MinPosition]);
		/* ��δ���򲿷ֵ���СԪ�������򲿷ֵ����λ��*/
	}
}
//��������Ԫ��
void Swap(ElementType *a, ElementType *b)
{
	ElementType t = *a; *a = *b; *b = t;
}

//����
void PercDown(ElementType A[], int p, int N)
{ /* �ı����4.24��PercDown( MaxHeap H, int p )    */
  /* ��N��Ԫ�ص���������A[p]Ϊ�����Ӷѵ���Ϊ���� */
	int Parent, Child;
	ElementType X;

	X = A[p]; /* ȡ��������ŵ�ֵ */
	for (Parent = p; (Parent * 2 + 1) < N; Parent = Child) {
		Child = Parent * 2 + 1;
		if ((Child != N - 1) && (A[Child] < A[Child + 1]))
			Child++;  /* Childָ�������ӽ��Ľϴ��� */
		if (X >= A[Child]) break; /* �ҵ��˺���λ�� */
		else  /* ����X */
			A[Parent] = A[Child];
	}
	A[Parent] = X;
}

/* ������ */
void HeapSort(ElementType A[], int N)
{
	int i;

	for (i = N / 2 - 1; i >= 0; i--)/* �������� */
		PercDown(A, i, N);

	for (i = N - 1; i > 0; i--) {
		/* ɾ�����Ѷ� */
		Swap(&A[0], &A[i]); /* ������7.1 */
		PercDown(A, 0, i);
	}
}

//////////////////�鲢����/////////////////
/* �鲢���� - �ݹ�ʵ�� */

/* L = �����ʼλ��, R = �ұ���ʼλ��, RightEnd = �ұ��յ�λ��*/
void Merge(ElementType A[], ElementType TmpA[], int L, int R, int RightEnd)
{ /* �������A[L]~A[R-1]��A[R]~A[RightEnd]�鲢��һ���������� */
	int LeftEnd, NumElements, Tmp;
	int i;

	LeftEnd = R - 1; /* ����յ�λ�� */
	Tmp = L;         /* �������е���ʼλ�� */
	NumElements = RightEnd - L + 1;

	while (L <= LeftEnd && R <= RightEnd) {
		if (A[L] <= A[R])
			TmpA[Tmp++] = A[L++]; /* �����Ԫ�ظ��Ƶ�TmpA */
		else
			TmpA[Tmp++] = A[R++]; /* ���ұ�Ԫ�ظ��Ƶ�TmpA */
	}

	while (L <= LeftEnd)
		TmpA[Tmp++] = A[L++]; /* ֱ�Ӹ������ʣ�µ� */
	while (R <= RightEnd)
		TmpA[Tmp++] = A[R++]; /* ֱ�Ӹ����ұ�ʣ�µ� */

	for (i = 0; i < NumElements; i++, RightEnd--)
		A[RightEnd] = TmpA[RightEnd]; /* �������TmpA[]���ƻ�A[] */
}

void Msort(ElementType A[], ElementType TmpA[], int L, int RightEnd)
{ /* ���ĵݹ������� */
	int Center;

	if (L < RightEnd) {
		Center = (L + RightEnd) / 2;
		Msort(A, TmpA, L, Center);              /* �ݹ������ */
		Msort(A, TmpA, Center + 1, RightEnd);     /* �ݹ����ұ� */
		Merge(A, TmpA, L, Center + 1, RightEnd);  /* �ϲ������������� */
	}
}

void MergeSort1(ElementType A[], int N)
{ /* �鲢���� */
	ElementType *TmpA;
	TmpA = (ElementType *)malloc(N * sizeof(ElementType));

	if (TmpA != NULL) {
		Msort(A, TmpA, 0, N - 1);
		free(TmpA);
	}
	else printf("�ռ䲻��");
}

/* �鲢���� - ѭ��ʵ�� */
/* ����Merge�����ڵݹ�汾�и��� */
/* length = ��ǰ�������еĳ���*/
void Merge_pass(ElementType A[], ElementType TmpA[], int N, int length)
{ /* �����鲢������������ */
	int i, j;

	for (i = 0; i <= N - 2 * length; i += 2 * length)
		Merge(A, TmpA, i, i + length, i + 2 * length - 1);
	if (i + length < N) /* �鲢���2������*/
		Merge(A, TmpA, i, i + length, N - 1);
	else /* ���ֻʣ1������*/
		for (j = i; j < N; j++) TmpA[j] = A[j];
}

void MergeSort2(ElementType A[], int N)
{
	int length;
	ElementType *TmpA;

	length = 1; /* ��ʼ�������г���*/
	TmpA = (ElementType *)malloc(N * sizeof(ElementType));

	if (TmpA != NULL) {
		while (length < N) {
			Merge_pass(A, TmpA, N, length);
			length *= 2;
			Merge_pass(TmpA, A, N, length);
			length *= 2;
		}
		free(TmpA);
	}
	else printf("�ռ䲻��");
}
