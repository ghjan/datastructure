#pragma once
#include "basesort.h"
/* ����Ԫ�������MaxDigit���ؼ��֣�����ȫ��ͬ����Radix */
#define MaxDigit 4
#define Radix 10
/* ͰԪ�ؽ�� */
typedef struct Node *PtrToNode;
struct Node {
	int key;
	PtrToNode next;
};

/* Ͱͷ��� */
struct HeadNode {
	PtrToNode head, tail;
};
typedef struct HeadNode Bucket[Radix];

int GetDigit(int X, int D);
void LSDRadixSort(ElementType A[], int N);
void MSDRadixSort(ElementType A[], int N);
