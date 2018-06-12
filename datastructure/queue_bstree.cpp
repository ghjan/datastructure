#include "stdafx.h"
#include<iostream>
#include <stdio.h> 
#include <stdlib.h>

#include "queue_bstree.h"

using namespace std;

/* ����һ���ն��� */
bool InitQueue(LinkQueue_bst *Lp)
{
	cout << "Init Queue ..." << endl;
	NodePtr p = (NodePtr)malloc(sizeof(Node));
	p->next = NULL;
	Lp->front = Lp->rear = p;
	return true;
}
/* ���ٶ���,����ͷ�ڵ� */
bool DestroyQueue(LinkQueue_bst *Lp)
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
bool ClearQueue(LinkQueue_bst *Lp)
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

bool QueueEmpty(LinkQueue_bst LQ)
{
	return LQ.front == LQ.rear;
}

int QueueLength(LinkQueue_bst LQ)
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

bool GetHead(LinkQueue_bst LQ, ElemType *pe)
{
	NodePtr p;
	if (LQ.front == LQ.rear)
		return false;
	p = LQ.front->next;
	*pe = p->data;
	//cout << "Get Head Item : " << *pe << endl;
	return true;
}

/* ����Ԫ��ElemΪ���е��µĶ�βԪ�� */
bool EnQueue(LinkQueue_bst *Lp, ElemType Elem)
{
	//cout << "EnQueue Item " << Elem << endl;
	NodePtr s = (NodePtr)malloc(sizeof(Node));
	s->data = Elem;
	s->next = NULL;
	Lp->rear->next = s;
	Lp->rear = s;

	return true;
}
/*ɾ�����еĶ�ͷԪ��,��*pe������ֵ */
ElemType * DeQueue(LinkQueue_bst *Lp )
{
	ElemType *pe = (ElemType *)malloc(sizeof(ElemType));
	if (Lp->front == Lp->rear)
		return false;
	NodePtr p = Lp->front->next;
	*pe = p->data;
	//cout << "DeQueue Item " << *pe << endl;
	Lp->front->next = p->next;
	if (Lp->rear == p)/* ����ͷ���Ƕ�β����ɾ����rearָ��ͷ���*/
		Lp->rear = Lp->front;
	free(p);

	return pe;
}
/* �Ӷ�ͷ����β���ζԶ�����ÿ��Ԫ����� */
bool QueueTraverse(LinkQueue_bst LQ)
{
	cout << "Queue Traverse ..." << endl;
	NodePtr p = LQ.front->next;
	while (p)
	{
		//cout << p->data << ' ';
		p = p->next;
	}

	cout << endl;
	return true;
}
