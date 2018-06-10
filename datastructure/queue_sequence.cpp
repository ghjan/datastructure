#include "stdafx.h"
#include<iostream>
#include <stdio.h> 
#include <stdlib.h>
#include "queue_sequence.h"

using namespace std;

bool InitQueue(SqQueue &Sq)
{
	cout << "Init Queue ..." << endl;
	Sq.front = 0;
	Sq.rear = 0;
	Sq.count = 0;
	return true;
}

bool ClearQueue(SqQueue &Sq)
{
	cout << "Clear Queue ..." << endl;
	Sq.front = 0;
	Sq.rear = 0;
	Sq.count = 0;
	return true;
}

bool QueueEmpty(SqQueue &Sq)
{
	return Sq.count == 0; /* ���пյı�־ */
}

bool QueueFull(SqQueue &Sq)
{
	return Sq.count == MAXSIZE;
}

int QueueLength(SqQueue &Sq)
{
	if (QueueFull(Sq))
		return MAXSIZE;

	/* ���еĵ�ǰ���� */
	return (Sq.rear - Sq.front + MAXSIZE) % MAXSIZE;
}
/* ����ͷԪ�� */
bool GetHead(SqQueue &Sq, ElemType *pe)
{
	if (QueueEmpty(Sq))
		return false;
	else
	{
		*pe = Sq.data[Sq.front];
		cout << "Get Head Item " << *pe << endl;
		return true;
	}
}

bool EnQueue(SqQueue &Sq, ElemType Elem)
{
	/* ������ */
	if (QueueLength(Sq) == MAXSIZE)
		return false;
	cout << "EnQueue Item " << Elem << endl;
	Sq.data[Sq.rear] = Elem;/* ��Ԫ�ظ�ֵ����β */
	Sq.rear = (Sq.rear + 1) % MAXSIZE;/* rearָ�������һλ�ã� */
									  /* ���������ת������ͷ�� */
	Sq.count++;
	return true;
}

bool DeQueue(SqQueue &Sq, ElemType *pe)
{
	if (QueueEmpty(Sq))
		return false;
	*pe = Sq.data[Sq.front];/* ����ͷԪ�ظ�ֵ��*pe */
	cout << "DeQueue Item " << *pe << endl;
	Sq.front = (Sq.front + 1) % MAXSIZE;/* frontָ�������һλ�ã� */
										/* ���������ת������ͷ�� */

	Sq.count--;
	return true;
}

bool QueueTraverse(SqQueue &Sq)
{
	if (QueueEmpty(Sq))
	{
		cout << "Queue is empty" << endl;
		return false;
	}

	cout << "Queue Traverse ..." << endl;
	for (int i = 0; i < Sq.count; i++)
		cout << Sq.data[i + Sq.front] << ' ';
	cout << endl;
	return true;
}

int queue_sequence_demo(void)
{
	SqQueue Sq;
	InitQueue(Sq);
	for (int i = 0; i < 20; i++)
		EnQueue(Sq, i);
	QueueTraverse(Sq);
	if (!QueueEmpty(Sq))
		cout << "Queue Length: " << QueueLength(Sq) << endl;
	int result;
	GetHead(Sq, &result);
	DeQueue(Sq, &result);
	DeQueue(Sq, &result);
	if (!QueueEmpty(Sq))
		cout << "Queue Length: " << QueueLength(Sq) << endl;
	QueueTraverse(Sq);

	return 0;
}