#pragma once


#define ElementType int
#define MaxN 100000

#define CUTOFF 100
struct Node {
	ElementType key1, key2;
};

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

void Copy(ElementType source[], ElementType target[], int N);
void Reverse(ElementType BaseA[], int N);
void GenerateArray(ElementType BaseA[], int N, int dataset);