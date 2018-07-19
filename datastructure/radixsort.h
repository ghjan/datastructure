#pragma once
#include "basesort.h"
/* 假设元素最多有MaxDigit个关键字，基数全是同样的Radix */
#define MaxDigit 4
#define Radix 10
/* 桶元素结点 */
typedef struct Node *PtrToNode;
struct Node {
	int key;
	PtrToNode next;
};

/* 桶头结点 */
struct HeadNode {
	PtrToNode head, tail;
};
typedef struct HeadNode Bucket[Radix];

int GetDigit(int X, int D);
void LSDRadixSort(ElementType A[], int N);
void MSDRadixSort(ElementType A[], int N);
