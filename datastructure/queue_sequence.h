#pragma once

#define MAXSIZE 20
typedef int ElemType;

typedef struct
{
	ElemType data[MAXSIZE];
	int front; /* ͷָ�� */
	int rear; /* βָ�룬�����в��գ�ָ�����βԪ�ص���һ��λ�� */
	int count; //Ԫ�ظ���
} SqQueue;
bool InitQueue(SqQueue &Sq);
bool ClearQueue(SqQueue &Sq);
bool QueueEmpty(SqQueue &Sq);
bool QueueFull(SqQueue &Sq);
int QueueLength(SqQueue &Sq);
/* ����ͷԪ�� */
bool GetHead(SqQueue &Sq, ElemType *pe);
bool EnQueue(SqQueue &Sq, ElemType Elem);
bool DeQueue(SqQueue &Sq, ElemType *pe);
bool QueueTraverse(SqQueue &Sq);

