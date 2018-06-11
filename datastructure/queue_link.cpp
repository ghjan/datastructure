#include "stdafx.h"
#include<iostream>
#include <stdio.h> 
#include <stdlib.h>

#include "queue_link.h"

using namespace std;

/* ����һ���ն��� */
bool InitQueue(LinkQueue *Lp)
{
	cout << "Init Queue ..." << endl;
	NodePtr p = (NodePtr)malloc(sizeof(Node));
	p->next = NULL;
	Lp->front = Lp->rear = p;
	return true;
}
/* ���ٶ���,����ͷ�ڵ� */
bool DestroyQueue(LinkQueue *Lp)
{
	cout << "Destroy Queue ..." << endl;
	while (Lp->front)
	{
		Lp->rear = Lp->front->next;
		free(Lp->front);
		Lp->front = Lp->rear;
	}

	return true;
}
/* ��Ϊ�ն��У�����ͷ�ڵ� */
bool ClearQueue(LinkQueue *Lp)
{
	cout << "Clear Queue ..." << endl;
	NodePtr p = Lp->front->next;
	Lp->front->next = NULL;
	Lp->rear = Lp->front;
	NodePtr q;

	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}

	return true;
}

bool QueueEmpty(LinkQueue LQ)
{
	return LQ.front == LQ.rear;
}

int QueueLength(LinkQueue LQ)
{
	int i = 0;
	if (LQ.front == NULL)
		return 0;
	NodePtr p = LQ.front->next;
	while (p)
	{
		++i;
		p = p->next;
	}

	return i;
}

bool GetHead(LinkQueue LQ, ElemType *pe)
{
	NodePtr p;
	if (LQ.front == LQ.rear)
		return false;
	p = LQ.front->next;
	*pe = p->data;
	cout << "Get Head Item : " << *pe << endl;
	return true;
}

/* ����Ԫ��ElemΪ���е��µĶ�βԪ�� */
bool EnQueue(LinkQueue *Lp, ElemType Elem)
{
	cout << "EnQueue Item " << Elem << endl;
	NodePtr s = (NodePtr)malloc(sizeof(Node));
	s->data = Elem;
	s->next = NULL;
	Lp->rear->next = s;
	Lp->rear = s;

	return true;
}
/*ɾ�����еĶ�ͷԪ��,��*pe������ֵ */
bool DeQueue(LinkQueue *Lp, ElemType *pe)
{
	if (Lp->front == Lp->rear)
		return false;
	NodePtr p = Lp->front->next;
	*pe = p->data;
	cout << "DeQueue Item " << *pe << endl;
	Lp->front->next = p->next;
	if (Lp->rear == p)/* ����ͷ���Ƕ�β����ɾ����rearָ��ͷ���*/
		Lp->rear = Lp->front;
	free(p);

	return true;
}
/* �Ӷ�ͷ����β���ζԶ�����ÿ��Ԫ����� */
bool QueueTraverse(LinkQueue LQ)
{
	cout << "Queue Traverse ..." << endl;
	NodePtr p = LQ.front->next;
	while (p)
	{
		cout << p->data << ' ';
		p = p->next;
	}

	cout << endl;
	return true;
}

int queue_link_demo(void)
{
	LinkQueue LQ;
	InitQueue(&LQ);
	for (int i = 0; i < 5; i++)
		EnQueue(&LQ, i);
	QueueTraverse(LQ);
	int result;
	GetHead(LQ, &result);
	DeQueue(&LQ, &result);
	QueueTraverse(LQ);
	if (!QueueEmpty(LQ))
		cout << "Queue Length : " << QueueLength(LQ) << endl;
	/*ClearQueue(&LQ);*/
	DestroyQueue(&LQ);
	cout << "Queue Length : " << QueueLength(LQ) << endl;

	return 0;
}