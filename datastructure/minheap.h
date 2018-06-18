#pragma once
typedef struct MinHeap *MinPriorityQueue;
typedef int ElementType;
/* 标记节点，类似于链表中的表头节点
* 该值必须小于所有最小堆中的元素，设其值为-1
*/
#define SentinelElement -1  

/*
* 使用数组实现堆
*
* capacity 数组的最大容量
* size     数组的长度
* elements 堆中的元素存放的数组
*/
struct MinHeap
{
	int capacity;
	int size;
	ElementType *elements; // 堆的元素个数为size，实际上用来存储的数组的长度为size + 1，还包括一个sentinel元素  
};


// 初始化堆  
MinPriorityQueue initialize(int maxElements);

// 销毁堆  
void destroy(MinPriorityQueue pqueue);

// 清空堆中的元素  
void makeEmpty(MinPriorityQueue pqueue);

// 插入操作  
void insert(ElementType x, MinPriorityQueue pqueue);

// 删除最小者操作，返回被删除的堆顶元素  
ElementType deleteMin(MinPriorityQueue pqueue);

// 查找最小者（堆顶）  
ElementType findMin(MinPriorityQueue pqueue);

// 判断堆是否为空  
int isEmpty(MinPriorityQueue pqueue);

// 判断堆是否满  
int isFull(MinPriorityQueue pqueue);

// 通过一个数组来建堆，相当于将用数组实现的无序树转换为堆序树  
MinPriorityQueue buildHeap_percolate(ElementType *arr, int n);
MinPriorityQueue buildHeap_insert(ElementType *arr, int n);

// 打印堆  
void printMinPriorityQueue(MinPriorityQueue pqueue);
