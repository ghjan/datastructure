#pragma once
#include "basesort.h"

/* ����Ԫ�������MaxDigit���ؼ��֣�����ȫ��ͬ����Radix */
#define MaxDigit 4
#define Radix 10
/* ͰԪ�ؽ�� */
typedef struct RadixNode *PtrToRadixNode;
struct RadixNode {
	int key;
	PtrToRadixNode next;
};

/* Ͱͷ��� */
struct HeadBucketNode {
	PtrToRadixNode head, tail;
};
typedef struct HeadBucketNode Bucket[Radix];

int GetDigit(int X, int D);
void LSDRadixSort(ElementType A[], int N);
void MSDRadixSort(ElementType A[], int N);
