#pragma once
#include "basesort.h"

/* 假设元素最多有MaxDigit个关键字，基数全是同样的Radix */
#define MaxDigit 4
#define Radix 10
/* 桶元素结点 */
typedef struct RadixNode *PtrToRadixNode;
struct RadixNode {
	int key;
	PtrToRadixNode next;
};

/* 桶头结点 */
struct HeadBucketNode {
	PtrToRadixNode head, tail;
};
typedef struct HeadBucketNode Bucket[Radix];

int GetDigit(int X, int D);
void LSDRadixSort(ElementType A[], int N);
void MSDRadixSort(ElementType A[], int N);
