#pragma once


#define ElementType int
#define MaxN 100000

#define CUTOFF 100
struct Node {
	ElementType key1, key2;
};

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

void Copy(ElementType source[], ElementType target[], int N);
void Reverse(ElementType BaseA[], int N);
void GenerateArray(ElementType BaseA[], int N, int dataset);