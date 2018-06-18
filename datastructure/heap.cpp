#include "stdafx.h"
#include <stdio.h>  
#include <stdlib.h>  

#include"heap.h"  

/*���ѵĲ������*/
/*ע���ѵ��±��Ǵ�1��ʼ,������0*/
void max_Heap_insert(int *heap, int *n, int item)
{
	int i, parent;//iΪ��ǰ�ڵ�,parentΪi�ĸ��ڵ�  
	if ((*n) == MAX_SIZE)//��Ϊ��  
	{
		printf("The heap is full\n");
		exit(1);
	}
	i = ++(*n);
	parent = i / 2;
	while ((i != 1) && (item > heap[parent]))//����Ϊ�ǿ�,������������item���ڸ��ڵ�Ĺؼ���ֵ  
	{
		heap[i] = heap[parent];//���ڵ�ؼ���ֵ����  
		i = parent;//�Ѹ��ڵ���Ϊ��ǰ�ڵ�  
		parent /= 2;//�����󸸽ڵ�  
	}
	heap[i] = item;//���뵽��ȷ��λ��  
}
/*���ѵ�ɾ������*/
int max_Heap_delete(int *heap, int *n)
{
	int item, temp;
	int child, parent;
	if (*n == 0)//��Ϊ�ն�  
	{
		printf("The heap is empty.\n");
		exit(1);
	}
	item = heap[1];//�����ѵ����Ԫ�ظ���item  
	temp = heap[(*n)--];//�ѵ����ڵ�ؼ���ֵ  
	parent = 1;
	child = 2 * parent;
	while (child <= (*n))
	{
		if (child < *n && heap[child] < heap[child + 1])
			child++;//�ҳ��������ؼ���ֵ�Ľڵ�  
		if (temp >= heap[child])break;//�����ڵ�ؼ���ֵ�����ڵ�ؼ���ֵ�Ƚ�  
		else
		{//�����д��ڱ����ڵ�ؼ���ֵ��Ľڵ�,�򽻻�λ��  
			heap[parent] = heap[child];
			parent = child;
			child *= 2;
		}
	}
	heap[parent] = temp;//���뵽��ȷλ��  
	return item;//����ɾ���Ĺؼ���ֵ  
}

void print_heap(int *heap, int n)
{
	for (int i = 1; i <= n; i++)
		printf("%d ", heap[i]);
}

int heap_demo()
{
	int item, i;
	int n = 0;
	for (i = 1; i < MAX_SIZE; i++)
	{
		scanf("%d", &item);
		max_Heap_insert(heap, &n, item);
	}
	print_heap(heap, n);
	printf("\n");
	item = max_Heap_delete(heap, &n);
	printf("The deleted data is:%d", item);
	printf("\n");
	print_heap(heap, n);
	return 0;
}