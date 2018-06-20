#include "stdafx.h"
#include <stdio.h>  
#include <stdlib.h>  
#include "queue_link.h"

#include "stdafx.h"
#include<iostream>
#include <stdio.h> 
#include <stdlib.h>

#include "graph_matrix.h"

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

MGraph CreateGraph(int VertexNum)
{ /* ��ʼ��һ����VertexNum�����㵫û�бߵ�ͼ */
	Vertex V, W;
	MGraph Graph;

	Graph = (MGraph)malloc(sizeof(struct GNode)); /* ����ͼ */
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	/* ��ʼ���ڽӾ��� */
	/* ע�⣺����Ĭ�϶����Ŵ�0��ʼ����(Graph->Nv - 1) */
	for (V = 0; V<Graph->Nv; V++)
		for (W = 0; W<Graph->Nv; W++)
			Graph->G[V][W] = INFINITY;

	return Graph;
}

void InsertEdge(MGraph Graph, Edge E)
{
	/* ����� <V1, V2> */
	Graph->G[E->V1][E->V2] = E->Weight;
	/* ��������ͼ����Ҫ�����<V2, V1> */
	Graph->G[E->V2][E->V1] = E->Weight;
}

MGraph BuildGraph()
{
	MGraph Graph;
	Edge E;
	Vertex V;
	int Nv, i;

	scanf("%d", &Nv);   /* ���붥����� */
	Graph = CreateGraph(Nv); /* ��ʼ����Nv�����㵫û�бߵ�ͼ */

	scanf("%d", &(Graph->Ne));   /* ������� */
	if (Graph->Ne != 0) { /* ����б� */
		E = (Edge)malloc(sizeof(struct ENode)); /* �����߽�� */
												/* ����ߣ���ʽΪ"��� �յ� Ȩ��"�������ڽӾ��� */
		for (i = 0; i<Graph->Ne; i++) {
			scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
			/* ע�⣺���Ȩ�ز������ͣ�Weight�Ķ����ʽҪ�� */
			InsertEdge(Graph, E);
		}
	}

	/* ������������ݵĻ����������� */
	for (V = 0; V<Graph->Nv; V++)
		scanf(" %c", &(Graph->Data[V]));

	return Graph;
}
/* �ڽӾ���洢��ͼ - BFS */

/* IsEdge(Graph, V, W)���<V, W>�Ƿ�ͼGraph�е�һ���ߣ���W�Ƿ�V���ڽӵ㡣  */
/* �˺�������ͼ�Ĳ�ͬ����Ҫ����ͬ��ʵ�֣��ؼ�ȡ���ڶԲ����ڵıߵı�ʾ������*/
/* �������Ȩͼ, ��������ڵı߱���ʼ��ΪINFINITY, ����ʵ������:         */
bool IsEdge(MGraph Graph, Vertex V, Vertex W)
{
	return Graph->G[V][W]<INFINITY ? true : false;
}

/* Visited[]Ϊȫ�ֱ������Ѿ���ʼ��Ϊfalse */
void BFS(MGraph Graph, Vertex S, void(*Visit)(Vertex))
{   /* ��SΪ��������ڽӾ���洢��ͼGraph����BFS���� */
	LinkQueue *Q;
	Vertex V, W;

	InitQueue(Q); /* �����ն���, MaxSizeΪ�ⲿ����ĳ��� */
							  /* ���ʶ���S���˴��ɸ��ݾ��������Ҫ��д */
	Visit(S);
	Visited[S] = true; /* ���S�ѷ��� */
	EnQueue(Q, S); /* S����� */

	while (!QueueEmpty(*Q)) {
		DeQueue(Q, &V);  /* ����V */
		for (W = 0; W<Graph->Nv; W++) /* ��ͼ�е�ÿ������W */
									  /* ��W��V���ڽӵ㲢��δ���ʹ� */
			if (!Visited[W] && IsEdge(Graph, V, W)) {
				/* ���ʶ���W */
				Visit(W);
				Visited[W] = true; /* ���W�ѷ��� */
				EnQueue(Q, W); /* W����� */
			}
	} /* while����*/
}