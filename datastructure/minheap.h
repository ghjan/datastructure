#pragma once
typedef struct MinHeap *MinPriorityQueue;
typedef int ElementType;
/* ��ǽڵ㣬�����������еı�ͷ�ڵ�
* ��ֵ����С��������С���е�Ԫ�أ�����ֵΪ-1
*/
#define SentinelElement -1  

/*
* ʹ������ʵ�ֶ�
*
* capacity ������������
* size     ����ĳ���
* elements ���е�Ԫ�ش�ŵ�����
*/
struct MinHeap
{
	int capacity;
	int size;
	ElementType *elements; // �ѵ�Ԫ�ظ���Ϊsize��ʵ���������洢������ĳ���Ϊsize + 1��������һ��sentinelԪ��  
};


// ��ʼ����  
MinPriorityQueue initialize(int maxElements);

// ���ٶ�  
void destroy(MinPriorityQueue pqueue);

// ��ն��е�Ԫ��  
void makeEmpty(MinPriorityQueue pqueue);

// �������  
void insert(ElementType x, MinPriorityQueue pqueue);

// ɾ����С�߲��������ر�ɾ���ĶѶ�Ԫ��  
ElementType deleteMin(MinPriorityQueue pqueue);

// ������С�ߣ��Ѷ���  
ElementType findMin(MinPriorityQueue pqueue);

// �ж϶��Ƿ�Ϊ��  
int isEmpty(MinPriorityQueue pqueue);

// �ж϶��Ƿ���  
int isFull(MinPriorityQueue pqueue);

// ͨ��һ�����������ѣ��൱�ڽ�������ʵ�ֵ�������ת��Ϊ������  
MinPriorityQueue buildHeap_percolate(ElementType *arr, int n);
MinPriorityQueue buildHeap_insert(ElementType *arr, int n);

// ��ӡ��  
void printMinPriorityQueue(MinPriorityQueue pqueue);
