#include "stdafx.h"
#include <stdio.h>  
#include <stdlib.h>  

#include"maxheap.h"  

MaxHeap CreateMaxHeap(int MaxSize)
{
	//创建容量为MaxSize的空的最大堆
	MaxHeap H = (MaxHeap)malloc(sizeof(HeapStruct));
	H->Elements = (ElementType *)malloc((MaxSize + 1) * sizeof(ElementType));
	H->Size = 0;
	H->Capicity = MaxSize;
	H->Elements[0] = MaxData;//定义哨兵为大于堆中所有可能元素的值，便于以后更快操作
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
	//将元素item插入最大堆，其中H->Elements[0]已经定义为哨兵
	int i;
	if (IsFull(H)) {
		printf("最大堆已满");
		return;
	}
	i = ++H->Size; //i指向插入后堆中的最后一个元素的位置
	for (; H->Elements[i / 2] < item; i /= 2)
	{
		H->Elements[i] = H->Elements[i / 2]; //向下过滤结点
	}
	H->Elements[i] = item; //将item插入
}

ElementType * DeleteMax(MaxHeap H)
{
	//从最大堆H中取出键值为最大的元素，并且删除一个结点
	int Parent, Child;
	ElementType MaxItem, temp;
	if (IsEmpty(H)) {
		printf("最大堆已空");
		return NULL;
	}
	MaxItem = H->Elements[1]; //取出根节点最大值
	//用最大堆中最后一个元素从根结点开始向上过滤下层结点
	temp = H->Elements[H->Size--];
	for (Parent = 1; Parent * 2 <= H->Size; Parent = Child)
	{
		Child = Parent * 2;
		if ((Child != H->Size) &&
			(H->Elements[Child] < H->Elements[Child + 1]))
			Child++;  //Child指向左右子结点的较大者
		if (temp >= H->Elements[Child]) break;
		else
			H->Elements[Parent] = H->Elements[Child];
	}
	H->Elements[Parent] = temp;
	return &MaxItem;
}