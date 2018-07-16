#include "stdafx.h"
#include <iostream>
#include<stdio.h>  
#include <stdlib.h>
#include "shortestpath.h"

using namespace std;

/* 构造一个空队列 */
bool InitQueue(GNodeLinkQueue *Lp)
{
	cout << "Init Queue ..." << endl;
	GraphNodePtr p = (GraphNodePtr)malloc(sizeof(GraphNode));
	p->next = NULL;
	Lp->front = Lp->rear = p;
	return true;
}
/* 销毁队列,包括头节点 */
bool DestroyQueue(GNodeLinkQueue *Lp)
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
bool ClearQueue(GNodeLinkQueue *Lp)
{
	cout << "Clear Queue ..." << endl;
	GraphNodePtr p = Lp->front->next;
	Lp->front->next = NULL;
	Lp->rear = Lp->front;
	GraphNodePtr q;

	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}

	return true;
}

bool QueueEmpty(GNodeLinkQueue LQ)
{
	return LQ.front == LQ.rear;
}

int QueueLength(GNodeLinkQueue LQ)
{
	int i = 0;
	if (LQ.front == NULL)
		return 0;
	GraphNodePtr p = LQ.front->next;
	while (p)
	{
		++i;
		p = p->next;
	}

	return i;
}

bool GetHead(GNodeLinkQueue LQ, ElemType *pe)
{
	GraphNodePtr p;
	if (LQ.front == LQ.rear)
		return false;
	p = LQ.front->next;
	*pe = p->data;
	cout << "Get Head Item : " << *pe << endl;
	return true;
}

/* 插入元素Elem为队列的新的队尾元素 */
bool EnQueue(GNodeLinkQueue *Lp, ElemType Elem)
{
	cout << "EnQueue Item " << Elem << endl;
	GraphNodePtr s = (GraphNodePtr)malloc(sizeof(GraphNode));
	s->data = Elem;
	s->next = NULL;
	Lp->rear->next = s;
	Lp->rear = s;

	return true;
}
/*删除队列的队头元素,用*pe返回其值 */
bool DeQueue(GNodeLinkQueue *Lp, ElemType *pe)
{
	if (Lp->front == Lp->rear)
		return false;
	GraphNodePtr p = Lp->front->next;
	*pe = p->data;
	cout << "DeQueue Item " << *pe << endl;
	Lp->front->next = p->next;
	if (Lp->rear == p)/* 若队头就是队尾，则删除后将rear指向头结点*/
		Lp->rear = Lp->front;
	free(p);

	return true;
}
/* 从队头到队尾依次对队列中每个元素输出 */
bool QueueTraverse(GNodeLinkQueue LQ)
{
	cout << "Queue Traverse ..." << endl;
	GraphNodePtr p = LQ.front->next;
	while (p)
	{
		cout << p->data << ' ';
		p = p->next;
	}

	cout << endl;
	return true;
}

int gnode_queue_link_demo(void)
{
	GNodeLinkQueue LQ;
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

/*
void Unweighted(ElemType S, ElemType []dist, ElemType [] path)
{
EnQueue(Q, S);
while (!QueueEmpty(Q)) {
ElemType V;
DeQueue(Q, &V);
for (V 的每个邻接点W)
if (dist[W] == -1) {
dist[W] = dist[V] + 1;
path[W] = V;
EnQueue(Q, S);
}
}
}

*/
