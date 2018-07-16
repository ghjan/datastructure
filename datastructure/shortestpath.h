#pragma once
#pragma once

typedef int Vertex;
typedef Vertex ElemType;

typedef struct GraphNode
{
	ElemType data;
	struct GraphNode *next;
} GraphNode, *GraphNodePtr;

typedef struct
{
	GraphNodePtr front;/* ��ͷ����βָ�� */
	GraphNodePtr rear;
} GraphLinkQueue;

/* ����һ���ն��� */
bool InitQueue(GraphLinkQueue *Lp);
/* ���ٶ���,����ͷ�ڵ� */
bool DestroyQueue(GraphLinkQueue *Lp);
/* ��Ϊ�ն��У�����ͷ�ڵ� */
bool ClearQueue(GraphLinkQueue *Lp);
bool QueueEmpty(GraphLinkQueue LQ);
int QueueLength(GraphLinkQueue LQ);
bool GetHead(GraphLinkQueue LQ, ElemType *pe);
/* ����Ԫ��ElemΪ���е��µĶ�βԪ�� */
bool EnQueue(GraphLinkQueue *Lp, ElemType Elem);
/*ɾ�����еĶ�ͷԪ��,��*pe������ֵ */
bool DeQueue(GraphLinkQueue *Lp, ElemType *pe);
/* �Ӷ�ͷ����β���ζԶ�����ÿ��Ԫ����� */
bool QueueTraverse(GraphLinkQueue LQ);

