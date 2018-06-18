#include "stdafx.h"
#include <stdio.h>  
#include <stdlib.h>  
#include "minheap.h"  

void
PQueueNULLWarning()
{
	printf("Warning: Minimum Priority Queue is NULL");
}

void
outOfSpaceFatalError()
{
	printf("Fatal Error: Out of space");
	abort();
}

MinPriorityQueue
initialize(int maxElements)
{
	MinPriorityQueue pqueue;

	if (maxElements <= 0)
	{
		printf("Fail to initialize: maxElements <= 0");
		return NULL;
	}

	pqueue = (MinPriorityQueue)malloc(sizeof(struct MinHeap));
	if (pqueue == NULL)
		outOfSpaceFatalError();

	// ����ĵ�0��Ԫ���Ǹ�sentinel��ǽڵ㣬�������������У���������capcaity��size��  
	pqueue->size = 0;
	pqueue->capacity = maxElements;
	pqueue->elements = (ElementType *) malloc(sizeof(ElementType) * (pqueue->capacity + 1));
	if (pqueue->elements == NULL)
		outOfSpaceFatalError();
	else
		pqueue->elements[0] = SentinelElement;

	return pqueue;
}

void
destroy(MinPriorityQueue pqueue)
{
	if (pqueue != NULL)
	{
		// ��GNU99��׼�У�free(NULL)ʲô������ֱ�ӷ��أ����Բ����ж�pqueue->elements�Ƿ�ΪNULL  
		free(pqueue->elements);
		free(pqueue);
	}
}

void
makeEmpty(MinPriorityQueue pqueue)
{
	if (pqueue != NULL)
		pqueue->size = 0;
	else
		PQueueNULLWarning();
}

/*
* ����ʱ�����е�Ԫ��ִ�����˲���
* ɾ��ʱ�����е�Ԫ��ִ�����˲���
*/

/*
* �����ʱ�临�Ӷ�ΪO(log N)��NΪ��С���е�Ԫ�ظ���
* ʵ���ϣ���ƽ��ִ��ʱ��ΪO(1)
*/
void
insert(ElementType x, MinPriorityQueue pqueue)
{
	if (pqueue == NULL)
		PQueueNULLWarning();

	if (isFull(pqueue))
	{
		printf("Fail to insert: Priority Queue is Full");
		return;
	}
	else
	{
		int i;

		// sentinel element��������Ϊelements[0]���Ƚϣ���ѭ������ֹ����  
		for (i = ++pqueue->size; x < pqueue->elements[i / 2]; i /= 2)
			pqueue->elements[i] = pqueue->elements[i / 2]; // ���˲���  
		pqueue->elements[i] = x;
	}
}

/*
* ɾ��������ƽ��ʱ��ΪO(log N)
*/
ElementType
deleteMin(MinPriorityQueue pqueue)
{
	if (pqueue == NULL)
	{
		PQueueNULLWarning();
		return SentinelElement;
	}

	if (isEmpty(pqueue))
	{
		printf("Fail to delete: Priority Queue is Empty");
		return SentinelElement;
	}

	int i, child;
	ElementType minElement, lastElement;

	// ע���ĳ���ڵ�������˲���ʱ��Ҫ�жϸýڵ������������ӻ���һ������  
	minElement = pqueue->elements[1];
	lastElement = pqueue->elements[pqueue->size--];
	for (i = 1; i * 2 <= pqueue->size; i = child)
	{
		child = i * 2;

		// �ڵ�iֻ��һ������ʱ����i * 2 = pqueue->size  
		if (child < pqueue->size && pqueue->elements[child] > pqueue->elements[child + 1])
			child++;

		if (lastElement < pqueue->elements[child])
			break;
		else
			pqueue->elements[i] = pqueue->elements[child]; // ���˲���  
	}
	pqueue->elements[i] = lastElement;

	return minElement; // ���ر�ɾ����Ԫ��  
}

/*
* ִ��ʱ�䣺O(1)
*/
ElementType
findMin(MinPriorityQueue pqueue)
{
	if (pqueue == NULL)
	{
		PQueueNULLWarning();
		return SentinelElement;
	}
	else
		return pqueue->elements[1];
}

int
isEmpty(MinPriorityQueue pqueue)
{
	if (pqueue == NULL)
	{
		PQueueNULLWarning();
		return -1;
	}
	else
		return (pqueue->size == 0);
}

int
isFull(MinPriorityQueue pqueue)
{
	if (pqueue == NULL)
	{
		PQueueNULLWarning();
		return -1;
	}
	else
		return (pqueue->size == pqueue->capacity);
}

void
percolateDown(int *arr, int len, int i)
{
	int child;
	int n = len - 1;
	ElementType tmp;

	for (tmp = arr[i]; i * 2 < n; i = child)
	{
		child = i * 2;
		if (child < n && arr[child] > arr[child + 1])
			child++;

		if (tmp > arr[child])
			arr[i] = arr[child];
		else
			break;
	}
	arr[i] = tmp;
}

//ʹ�����˷�ʽ����
MinPriorityQueue
buildHeap_percolate(ElementType *arr, int n)
{
	if (arr == NULL)
	{
		printf("Error: Array is NULL");
		return NULL;
	}

	MinPriorityQueue pqueue;
	pqueue = (MinPriorityQueue)malloc(sizeof(struct MinHeap));

	if (pqueue == NULL)
		outOfSpaceFatalError();
	ElementType *elements = (ElementType *)malloc(sizeof(ElementType) * (n + 1));
	if (elements == NULL)
		outOfSpaceFatalError();

	int i;
	for (i = 1; i <= n; i++)
		elements[i] = arr[i - 1];
	elements[0] = SentinelElement;

	for (i = n / 2; i > 0; i--)
		percolateDown(elements, n + 1, i);

	pqueue->elements = elements;
	pqueue->size = n;
	pqueue->capacity = n * 2;

	return pqueue;
}

/*
ʹ�ò��뷽ʽ����
* ͨ��n�β���Ԫ�ؽ����ѣ�����ÿ�β����ƽ��ִ��ʱ��ΪO(1)�����Խ���ƽ��ʱ��ΪO(N)
*/
MinPriorityQueue
buildHeap_insert(ElementType *arr, int n)
{
	MinPriorityQueue pqueue;

	if (arr == NULL)
	{
		printf("Array is NULL, fail to build heap");
		return NULL;
	}

	pqueue = initialize(n * 2);
	for (int i = 0; i < n; i++)
		insert(arr[i], pqueue);

	return pqueue;
}

void
printMinPriorityQueue(MinPriorityQueue pqueue)
{
	if (pqueue == NULL)
	{
		PQueueNULLWarning();
		return;
	}

	if (pqueue->elements == NULL)
	{
		printf("Fail to print: Elements of priority queue is NULL");
		return;
	}

	if (isEmpty(pqueue))
	{
		printf("Empty Prioirty Queue\n");
		return;
	}

	printf("Priority Queue\n");
	for (int i = 1; i <= pqueue->size; i++)
		printf("Element[%d] = %d\n", i, pqueue->elements[i]);
	printf("\n");
}



void buildHeapTest()
{
	int a[9] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };

	MinPriorityQueue pqueue_ins = buildHeap_insert(a, 9);
	MinPriorityQueue pqueue_per = buildHeap_percolate(a, 9);
	printMinPriorityQueue(pqueue_ins);
	printMinPriorityQueue(pqueue_per);
	destroy(pqueue_ins);
	destroy(pqueue_per);
}

