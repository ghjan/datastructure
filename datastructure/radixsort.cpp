#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "radixsort.h"
#include "array.h"

const int RADIX_FLAGS[] = { 10, 100, 1000, 10000, 100000, 1000000 };
const int NEG_RADIX_FLAGS[] = { -10, -100, -1000, -10000, -100000, -1000000 };

/* �������� - ��λ���� */

/* Ĭ�ϴ�λD=1, ��λD<=MaxDigit */
int GetDigit(int X, int D, bool isNeg)
{
	int d, i;

	for (i = 1; i <= D; i++) {
		d = X % Radix;
		X /= Radix;
	}
	if (isNeg) {
		d = -1 * d;
	}
	return d;
}

////////////////�������� - ��λ����///////////////

PtrToRadixNode lsdRadixSort(PtrToRadixNode List, bool isNeg) {
	int D, Di, i;
	Bucket bucket;
	PtrToRadixNode tmp, p;
	for (i = 0; i < Radix; i++) /* ��ʼ��ÿ��ͰΪ������ */
		bucket[i].head = bucket[i].tail = NULL;

	bool shouldEnd = false;
	bool toMaxD = false;
	for (D = 1; !toMaxD && !shouldEnd && D <= MaxDigit; D++) { /* �����ݵ�ÿһλѭ������ */
										  /* �����Ƿ���Ĺ��� */
		p = List;
		toMaxD = true;
		while (p) {
			Di = GetDigit(p->key, D, isNeg); /* ��õ�ǰԪ�صĵ�ǰλ���� */
									  /* ��List��ժ�� */
			tmp = p; p = p->next;
			if (!isNeg) {
				toMaxD = toMaxD && tmp->key < RADIX_FLAGS[D - 1];// pow(10, D);

				/* ����B[Di]��Ͱβ */
				tmp->next = NULL;
				if (bucket[Di].head == NULL)
					bucket[Di].head = bucket[Di].tail = tmp;
				else {
					bucket[Di].tail->next = tmp;
					bucket[Di].tail = tmp;
				}
			}
			else {//����
				toMaxD = toMaxD && tmp->key > NEG_RADIX_FLAGS[D - 1];// pow(10, D);
				//��Ϊ�µ�Ͱͷ
				tmp->next = bucket[Di].head;
				if (bucket[Di].head == NULL)
					bucket[Di].head = bucket[Di].tail = tmp;
				else {
					bucket[Di].head = tmp;
				}
			}

		}
		if (!toMaxD) {
			//�Ƿ�Ӧ��ֹͣѭ���ˣ�Ҳ����˵���е�����������bucket[0]������
			shouldEnd = bucket[0].head != NULL;
			for (i = 1; i < Radix && shouldEnd; i++) {
				shouldEnd = shouldEnd && bucket[i].head == NULL;
			}
		}

		/* �������ռ��Ĺ��� */
		List = NULL;
		if (!isNeg) {
			for (Di = Radix - 1; Di >= 0; Di--) { /* ��ÿ��Ͱ��Ԫ��˳���ռ���List */
				if (bucket[Di].head) { /* ���Ͱ��Ϊ�� */
									   /* ��Ͱ����List��ͷ */
					bucket[Di].tail->next = List;
					List = bucket[Di].head;
					bucket[Di].head = bucket[Di].tail = NULL; /* ���Ͱ */
				}
			}
		}
		else { //����
			for (Di = 0; Di < Radix; Di++) { /* ��ÿ��Ͱ��Ԫ��˳���ռ���List */
				if (bucket[Di].head) { /* ���Ͱ��Ϊ�� */
									   /* ��Ͱ����List��ͷ */
					bucket[Di].tail->next = List;
					List = bucket[Di].head;
					bucket[Di].head = bucket[Di].tail = NULL; /* ���Ͱ */
				}
			}
		}
	}
	return List;
}

void LSDRadixSort(ElementType A[], int N)
{ /* �������� - ��λ���� */

	PtrToRadixNode tmp, List = NULL, ListNeg = NULL;

	for (int i = 0; i < N; i++) { /* ��ԭʼ������������ʼ����List */
		tmp = (PtrToRadixNode)malloc(sizeof(struct RadixNode));
		tmp->key = A[i];
		if (A[i] >= 0) { //�Ǹ���
			tmp->next = List;
			List = tmp;
		}
		else { //����
			tmp->next = ListNeg;
			ListNeg = tmp;
		}
	}
	/* ���濪ʼ���� */
	List = lsdRadixSort(List, false);
	ListNeg = lsdRadixSort(ListNeg, true);

	/* ��List����A[]���ͷſռ� */
	int i = 0;
	for (; i < N; i++) {
		tmp = ListNeg;
		ListNeg = ListNeg->next;
		A[i] = tmp->key;
		if (ListNeg == NULL) {
			break;
		}
		free(tmp);
	}
	for (; i < N; i++) {
		tmp = List;
		List = List->next;
		A[i] = tmp->key;
		if (List == NULL) {
			break;
		}
		free(tmp);
	}

}


void MSD(ElementType A[], int L, int R, int D, bool isNeg)
{ /* ���ĵݹ麯��: ��A[L]...A[R]�ĵ�Dλ���������� */
	int Di, i, j;
	Bucket B;
	PtrToRadixNode tmp, p, List = NULL;
	if (D == 0) return; /* �ݹ���ֹ���� */

	for (i = 0; i < Radix; i++) /* ��ʼ��ÿ��ͰΪ������ */
		B[i].head = B[i].tail = NULL;
	for (i = L; i <= R; i++) { /* ��ԭʼ������������ʼ����List */
		tmp = (PtrToRadixNode)malloc(sizeof(struct RadixNode));
		tmp->key = A[i];
		tmp->next = List;
		List = tmp;
	}
	/* �����Ƿ���Ĺ��� */
	p = List;
	while (p) {
		Di = GetDigit(p->key, D, isNeg); /* ��õ�ǰԪ�صĵ�ǰλ���� */
								  /* ��List��ժ�� */
		tmp = p; p = p->next;
		/* ����B[Di]��Ͱ */
		if (B[Di].head == NULL) B[Di].tail = tmp;
		tmp->next = B[Di].head;
		B[Di].head = tmp;
	}
	/* �������ռ��Ĺ��� */
	i = j = L; /* i, j��¼��ǰҪ�����A[]�����Ҷ��±� */
	for (Di = 0; Di < Radix; Di++) { /* ����ÿ��Ͱ */
		if (B[Di].head) { /* ���ǿյ�Ͱ��Ͱ����A[], �ݹ����� */
			p = B[Di].head;
			while (p) {
				tmp = p;
				p = p->next;
				A[j++] = tmp->key;
				free(tmp);
			}
			/* �ݹ�Ը�Ͱ��������, λ����1 */
			MSD(A, i, j - 1, D - 1, isNeg);
			i = j; /* Ϊ��һ��Ͱ��Ӧ��A[]��� */
		}
	}
}

void MSDRadixSort(ElementType A[], int N)
{ /* ͳһ�ӿ� */
	MSD(A, 0, N - 1, MaxDigit, false);
}

void RadixSortDemo() {
	int BaseA[] = { 100, -300, -32, -29, 6, 2, 19, 25, 15, 55,
		35, 5, 110, 120, -240 };
	int A[15];
	int N = 15;
	Copy(BaseA, A, 15);
	LSDRadixSort(A, N);
	PrintArray(A, 15);

	//Copy(BaseA, A, 15);
	//MSDRadixSort(A, N);
	//PrintArray(A, 15);

	//ElementType BaseA[MaxN], A[MaxN];
	//int dataset = 5;
	//GenerateArray(BaseA, MaxN, dataset);
	//printf("---------dataset:%d\n", dataset);
	//int N = MaxN;
	//Copy(BaseA, A, MaxN);
	//LSDRadixSort(A, N);
	//PrintArray(A, 100);

	//Copy(BaseA, A, 15);
	//MSDRadixSort(A, N);
	//PrintArray(A, 100);
	//for (int D = 1; D <= MaxDigit; D++) {
	//	printf("%d ", GetDigit(125, D, false));
	//}

	//for (int D = 1; D <= MaxDigit; D++) {
	//	printf("%d ", GetDigit(-125, D, true));
	//}
}


