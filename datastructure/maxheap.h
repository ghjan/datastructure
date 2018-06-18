#pragma once
typedef struct HeapStruct *MaxHeap;
//typedef struct HeapStruct *MinHeap;
typedef int ElementType;
#define MaxData 2147483647
struct HeapStruct {
	ElementType *Elements;	//存储堆元素
	int Size;				//堆的当前元素个数
	int Capicity;			//堆的最大容量
};
MaxHeap CreateMaxHeap(int MaxSize);
bool IsFull(MaxHeap H);
bool IsEmpty(MaxHeap H);
void MaxHeapInsert(MaxHeap H, ElementType item);
ElementType * DeleteMax(MaxHeap H);
