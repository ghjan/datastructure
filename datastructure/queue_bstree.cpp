#include "stdafx.h"
#include<iostream>
#include <stdio.h> 
#include <stdlib.h>

#include "queue_bstree.h"

using namespace std;

/* 构造一个空队列 */
bool InitQueue(LinkQueue_bst *Lp)
{
	cout << "Init Queue ..." << endl;
	NodePtr p = (NodePtr)malloc(sizeof(Node));
	p->next = NULL;
	Lp->front = Lp->rear = p;
	return true;
}
/* 销毁队列,包括头节点 */
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
/* 清为空队列，保留头节点 */
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

/* 插入元素Elem为队列的新的队尾元素 */
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
/*删除队列的队头元素,用*pe返回其值 */
ElemType * DeQueue(LinkQueue_bst *Lp )
{
	ElemType *pe = (ElemType *)malloc(sizeof(ElemType));
	if (Lp->front == Lp->rear)
		return false;
	NodePtr p = Lp->front->next;
	*pe = p->data;
	//cout << "DeQueue Item " << *pe << endl;
	Lp->front->next = p->next;
	if (Lp->rear == p)/* 若队头就是队尾，则删除后将rear指向头结点*/
		Lp->rear = Lp->front;
	free(p);

	return pe;
}
/* 从队头到队尾依次对队列中每个元素输出 */
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
