#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "time.h"
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
//��Ƚ�ð������ �������������˵ ��ð�������еĽ���������
void InsertionSort(ElementType A[], int N)
{ /* �������� */
	int P, i;
	ElementType Tmp;

	for (P = 1; P < N; P++) {
		//����������ص㣺0~P-1�Ѿ��������
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

//ʹ��Sedgewick�������е�ϣ������
void ShellSortSedgewick(ElementType array[] , int N)
{
	int incrementSeq[255]; // ��������(startup == 0).
	int i, j, round = incrementSeqFunc(incrementSeq, N);
	int increment, temp;

	for (; round >= 1; round--)
	{
		increment = incrementSeq[round - 1];
		for (i = 1 * increment; i < N; i += increment) // Ĭ�ϵ�,array[0*increment]�������Դ�1*increment��ʼ.
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
	PrintArray(array, length);
	return 0;
}
////////////////////ѡ������Ͷ�����//////////////

//ɨ����Сֵλ��
int scanForMin(ElementType A[], int start, int end) {
	return 0;
}
//ѡ������
void SelectionSort(ElementType A[], int N)
{
	for (int i = 0; i < N; i++) {
		int MinPosition = scanForMin(A, i, N - 1);
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
void percDown(ElementType A[], int p, int N)
{ /* �ı����4.24��percDown( MaxHeap H, int p )    */
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
		percDown(A, i, N);

	for (i = N - 1; i > 0; i--) {
		/* ɾ�����Ѷ� */
		Swap(&A[0], &A[i]); /* ������7.1 */
		percDown(A, 0, i);
	}
}

//////////////////�鲢����/////////////////
/* �鲢���� - �ݹ�ʵ�� */

/* L = �����ʼλ��, R = �ұ���ʼλ��, RightEnd = �ұ��յ�λ��*/
void merge(ElementType A[], ElementType TmpA[], int L, int R, int RightEnd)
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

void msort(ElementType A[], ElementType TmpA[], int L, int RightEnd)
{ /* ���ĵݹ������� */
	int Center;

	if (L < RightEnd) {
		Center = (L + RightEnd) / 2;
		msort(A, TmpA, L, Center);              /* �ݹ������ */
		msort(A, TmpA, Center + 1, RightEnd);     /* �ݹ����ұ� */
		merge(A, TmpA, L, Center + 1, RightEnd);  /* �ϲ������������� */
	}
}

void MergeSort1(ElementType A[], int N)
{ /* �鲢���� */
	ElementType *TmpA;
	TmpA = (ElementType *)malloc(N * sizeof(ElementType));

	if (TmpA != NULL) {
		msort(A, TmpA, 0, N - 1);
		free(TmpA);
	}
	else printf("�ռ䲻��");
}

/* �鲢���� - ѭ��ʵ�� */
/* ����merge�����ڵݹ�汾�и��� */
/* length = ��ǰ�������еĳ���*/
void merge_pass(ElementType A[], ElementType TmpA[], int N, int length)
{ /* �����鲢������������ */
	int i, j;

	for (i = 0; i <= N - 2 * length; i += 2 * length)
		merge(A, TmpA, i, i + length, i + 2 * length - 1);
	if (i + length < N) /* �鲢���2������*/
		merge(A, TmpA, i, i + length, N - 1);
	else /* ���ֻʣ1������*/
		for (j = i; j < N; j++) TmpA[j] = A[j];
}

//�鲢���� - ѭ��ʵ��
void MergeSort2(ElementType A[], int N)
{
	int length;
	ElementType *TmpA;

	length = 1; /* ��ʼ�������г���*/
	TmpA = (ElementType *)malloc(N * sizeof(ElementType));

	if (TmpA != NULL) {
		while (length < N) {
			merge_pass(A, TmpA, N, length);
			length *= 2;
			merge_pass(TmpA, A, N, length);
			length *= 2;
		}
		free(TmpA);
	}
	else printf("�ռ䲻��");
}


/////////////��������//////////
/* �������� - ֱ�ӵ��ÿ⺯�� */
/*---------------����������--------------------*/
int compare(const void *a, const void *b)
{ /* �Ƚ����������ǽ������� */
	return (*(int*)a - *(int*)b);
}

void QsortWithLibDemo1() {

	/* ���ýӿ� */
	/*---------------����������--------------------*/
	int A[] = { 100, 1000, 100, 10, 6, 2, 19, 25, 15, 55,
		35, 5, 110, 120, 119 };
	int N = 15;
	qsort(A, N, sizeof(int), compare);
	PrintArray(A, 15);
}

/*--------------- һ������£��Խṹ��Node�е�ĳ��ֵkey���� ---------------*/

int compare2keys(const void *a, const void *b)
{ /* �Ƚ����ּ�ֵ����key1���������У����key1��ȣ���key2�ǽ������� */
	int k;
	if (((const struct Node*)a)->key1 < ((const struct Node*)b)->key1)
		k = 1;
	else if (((const struct Node*)a)->key1 >((const struct Node*)b)->key1)
		k = -1;
	else { /* ���key1��� */
		if (((const struct Node*)a)->key2 < ((const struct Node*)b)->key2)
			k = -1;
		else
			k = 1;
	}
	return k;
}


void QsortWithLibDemo2() {

	/* ���ýӿ� */
	/*--------------- �Խṹ��Node�еļ�ֵkey1,key2���� ---------------*/
	int N = MaxN;
	ElementType *A = new int[N];
	ElementType *B = new int[N];
	int dataset = 5; //�������
	GenerateArray(A, N, dataset);
	GenerateArray(B, N, dataset);
	Node *nodesA = new Node[N];
	for (int i = 0; i < N; i++) {
		nodesA[i].key1 = A[i];
		nodesA[i].key2 = B[i];
	}
	/* ���ýӿ� */
	qsort(nodesA, N, sizeof(struct Node), compare2keys);
	PrintNode(nodesA, N);

	delete[]A;
	delete[]B;
	delete []nodesA;
}


/* ��������-��ʵ�� */

ElementType Median3(ElementType A[], int Left, int Right)
{
	int Center = (Left + Right) / 2;
	if (A[Left] > A[Center])
		Swap(&A[Left], &A[Center]);
	if (A[Left] > A[Right])
		Swap(&A[Left], &A[Right]);
	if (A[Center] > A[Right])
		Swap(&A[Center], &A[Right]);
	/* ��ʱA[Left] <= A[Center] <= A[Right] */
	Swap(&A[Center], &A[Right - 1]); /* ����׼Pivot�ص��ұ�*/
									 /* ֻ��Ҫ����A[Left+1] �� A[Right-2] */
	return  A[Right - 1];  /* ���ػ�׼Pivot */
}

void Qsort(ElementType A[], int Left, int Right)
{ /* ���ĵݹ麯�� */
	int Pivot, Cutoff, Low, High;
	Cutoff = CUTOFF;
	if (Cutoff <= Right - Left) { /* �������Ԫ�س�ֶ࣬������� */
		Pivot = Median3(A, Left, Right); /* ѡ��׼ */
		Low = Left; High = Right - 1;

		//while (1) { /*�������бȻ�׼С���Ƶ���׼��ߣ�����Ƶ��ұ�*/
		//	while (A[++Low] < Pivot);
		//	while (A[--High] > Pivot);
		//	if (Low < High) Swap(&A[Low], &A[High]);
		//	else break;
		//}
		//�ָ����飬�������бȻ�׼С���Ƶ���׼��ߣ�����Ƶ��ұ�
		SplitArrayWithPivot(A, Left, Right-1, Pivot);

		Swap(&A[Low], &A[Right - 1]);   /* ����׼������ȷ��λ�� */
		Qsort(A, Left, Low - 1);    /* �ݹ������ */
		Qsort(A, Low + 1, Right);   /* �ݹ����ұ� */
	}
	else InsertionSort(A + Left, Right - Left + 1); /* Ԫ��̫�٣��ü����� */
}

void QuickSort(ElementType A[], int N)
{ /* ͳһ�ӿ� */
	Qsort(A, 0, N - 1);
}

void QuickSortDemo() {
	int N = MaxN;
	ElementType *A = new int[N];
	int dataset = 5; //�������
	GenerateArray(A, N, dataset);
	QuickSort(A, N);
	PrintArray(A, N);
}
