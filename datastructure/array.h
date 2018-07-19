#pragma once


#define ElementType int
#define MaxN 100000

#define CUTOFF 100
struct NodeWithkeys {
	ElementType *keys;
};


void Copy(ElementType source[], ElementType target[], int N);
void Reverse(ElementType BaseA[], int N);
void GenerateArray(ElementType BaseA[], int N, int dataset);


void PrintArray(int data[], int size);//打印数组
void PrintNode(NodeWithkeys data[], int size, int countKeys);//打印节点

int SplitArrayWithPivot(ElementType A[], int Left, int Right, int Pivot);

double CountTickForSort(void pf(ElementType[], int), ElementType A[], int N);
