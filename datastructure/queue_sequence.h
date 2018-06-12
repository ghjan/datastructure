#pragma once

#define MAXSIZE 20
typedef int ElemType;

typedef struct
{
	ElemType data[MAXSIZE];
	int front; /* 头指针 */
	int rear; /* 尾指针，若队列不空，指向队列尾元素的下一个位置 */
	int count; //元素个数
} SqQueue;
bool InitQueue(SqQueue &Sq);
bool ClearQueue(SqQueue &Sq);
bool QueueEmpty(SqQueue &Sq);
bool QueueFull(SqQueue &Sq);
int QueueLength(SqQueue &Sq);
/* 返回头元素 */
bool GetHead(SqQueue &Sq, ElemType *pe);
bool EnQueue(SqQueue &Sq, ElemType Elem);
bool DeQueue(SqQueue &Sq, ElemType *pe);
bool QueueTraverse(SqQueue &Sq);

