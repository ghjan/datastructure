#pragma once
typedef struct HeapStruct *MaxHeap;
//typedef struct HeapStruct *MinHeap;
typedef int ElementType;
#define MaxData 2147483647
struct HeapStruct {
	ElementType *Elements;	//�洢��Ԫ��
	int Size;				//�ѵĵ�ǰԪ�ظ���
	int Capicity;			//�ѵ��������
};
MaxHeap CreateMaxHeap(int MaxSize);
bool IsFull(MaxHeap H);
bool IsEmpty(MaxHeap H);
void MaxHeapInsert(MaxHeap H, ElementType item);
ElementType * DeleteMax(MaxHeap H);
