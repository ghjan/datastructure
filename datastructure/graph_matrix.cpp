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

/* 构造一个空队列 */
bool InitQueue(LinkQueue *Lp)
{
	cout << "Init Queue ..." << endl;
	NodePtr p = (NodePtr)malloc(sizeof(Node));
	p->next = NULL;
	Lp->front = Lp->rear = p;
	return true;
}
/* 销毁队列,包括头节点 */
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
/* 清为空队列，保留头节点 */
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

/* 插入元素Elem为队列的新的队尾元素 */
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
/*删除队列的队头元素,用*pe返回其值 */
bool DeQueue(LinkQueue *Lp, ElemType *pe)
{
	if (Lp->front == Lp->rear)
		return false;
	NodePtr p = Lp->front->next;
	*pe = p->data;
	cout << "DeQueue Item " << *pe << endl;
	Lp->front->next = p->next;
	if (Lp->rear == p)/* 若队头就是队尾，则删除后将rear指向头结点*/
		Lp->rear = Lp->front;
	free(p);

	return true;
}
/* 从队头到队尾依次对队列中每个元素输出 */
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
{ /* 初始化一个有VertexNum个顶点但没有边的图 */
	Vertex V, W;
	MGraph Graph;

	Graph = (MGraph)malloc(sizeof(struct GNode)); /* 建立图 */
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	/* 初始化邻接矩阵 */
	/* 注意：这里默认顶点编号从0开始，到(Graph->Nv - 1) */
	for (V = 0; V<Graph->Nv; V++)
		for (W = 0; W<Graph->Nv; W++)
			Graph->G[V][W] = INFINITY;

	return Graph;
}

void InsertEdge(MGraph Graph, Edge E)
{
	/* 插入边 <V1, V2> */
	Graph->G[E->V1][E->V2] = E->Weight;
	/* 若是无向图，还要插入边<V2, V1> */
	Graph->G[E->V2][E->V1] = E->Weight;
}

MGraph BuildGraph()
{
	MGraph Graph;
	Edge E;
	Vertex V;
	int Nv, i;

	scanf("%d", &Nv);   /* 读入顶点个数 */
	Graph = CreateGraph(Nv); /* 初始化有Nv个顶点但没有边的图 */

	scanf("%d", &(Graph->Ne));   /* 读入边数 */
	if (Graph->Ne != 0) { /* 如果有边 */
		E = (Edge)malloc(sizeof(struct ENode)); /* 建立边结点 */
												/* 读入边，格式为"起点 终点 权重"，插入邻接矩阵 */
		for (i = 0; i<Graph->Ne; i++) {
			scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
			/* 注意：如果权重不是整型，Weight的读入格式要改 */
			InsertEdge(Graph, E);
		}
	}

	/* 如果顶点有数据的话，读入数据 */
	for (V = 0; V<Graph->Nv; V++)
		scanf(" %c", &(Graph->Data[V]));

	return Graph;
}
/* 邻接矩阵存储的图 - BFS */

/* IsEdge(Graph, V, W)检查<V, W>是否图Graph中的一条边，即W是否V的邻接点。  */
/* 此函数根据图的不同类型要做不同的实现，关键取决于对不存在的边的表示方法。*/
/* 例如对有权图, 如果不存在的边被初始化为INFINITY, 则函数实现如下:         */
bool IsEdge(MGraph Graph, Vertex V, Vertex W)
{
	return Graph->G[V][W]<INFINITY ? true : false;
}

/* Visited[]为全局变量，已经初始化为false */
void BFS(MGraph Graph, Vertex S, void(*Visit)(Vertex))
{   /* 以S为出发点对邻接矩阵存储的图Graph进行BFS搜索 */
	LinkQueue *Q;
	Vertex V, W;

	InitQueue(Q); /* 创建空队列, MaxSize为外部定义的常数 */
							  /* 访问顶点S：此处可根据具体访问需要改写 */
	Visit(S);
	Visited[S] = true; /* 标记S已访问 */
	EnQueue(Q, S); /* S入队列 */

	while (!QueueEmpty(*Q)) {
		DeQueue(Q, &V);  /* 弹出V */
		for (W = 0; W<Graph->Nv; W++) /* 对图中的每个顶点W */
									  /* 若W是V的邻接点并且未访问过 */
			if (!Visited[W] && IsEdge(Graph, V, W)) {
				/* 访问顶点W */
				Visit(W);
				Visited[W] = true; /* 标记W已访问 */
				EnQueue(Q, W); /* W入队列 */
			}
	} /* while结束*/
}