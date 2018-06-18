#include "stdafx.h"
#include <stdio.h>  
#include <stdlib.h>  

#include"maxheap.h"  

MaxHeap CreateMaxHeap(int MaxSize)
{
	//��������ΪMaxSize�Ŀյ�����
	MaxHeap H = (MaxHeap)malloc(sizeof(HeapStruct));
	H->Elements = (ElementType *)malloc((MaxSize + 1) * sizeof(ElementType));
	H->Size = 0;
	H->Capicity = MaxSize;
	H->Elements[0] = MaxData;//�����ڱ�Ϊ���ڶ������п���Ԫ�ص�ֵ�������Ժ�������
	return H;
}
bool IsFull(MaxHeap H)
{
	return H->Size >= H->Capicity;

}

bool IsEmpty(MaxHeap H)
{
	return H->Size <= 0;
}
void MaxHeapInsert(MaxHeap H, ElementType item)
{
	//��Ԫ��item�������ѣ�����H->Elements[0]�Ѿ�����Ϊ�ڱ�
	int i;
	if (IsFull(H)) {
		printf("��������");
		return;
	}
	i = ++H->Size; //iָ��������е����һ��Ԫ�ص�λ��
	for (; H->Elements[i / 2] < item; i /= 2)
	{
		H->Elements[i] = H->Elements[i / 2]; //���¹��˽��
	}
	H->Elements[i] = item; //��item����
}

ElementType * DeleteMax(MaxHeap H)
{
	//������H��ȡ����ֵΪ����Ԫ�أ�����ɾ��һ�����
	int Parent, Child;
	ElementType MaxItem, temp;
	if (IsEmpty(H)) {
		printf("�����ѿ�");
		return NULL;
	}
	MaxItem = H->Elements[1]; //ȡ�����ڵ����ֵ
	//�����������һ��Ԫ�شӸ���㿪ʼ���Ϲ����²���
	temp = H->Elements[H->Size--];
	for (Parent = 1; Parent * 2 <= H->Size; Parent = Child)
	{
		Child = Parent * 2;
		if ((Child != H->Size) &&
			(H->Elements[Child] < H->Elements[Child + 1]))
			Child++;  //Childָ�������ӽ��Ľϴ���
		if (temp >= H->Elements[Child]) break;
		else
			H->Elements[Parent] = H->Elements[Child];
	}
	H->Elements[Parent] = temp;
	return &MaxItem;
}