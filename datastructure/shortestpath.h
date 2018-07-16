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
} GNodeLinkQueue;

/* ����һ���ն��� */
bool InitQueue(GNodeLinkQueue *Lp);
/* ���ٶ���,����ͷ�ڵ� */
bool DestroyQueue(GNodeLinkQueue *Lp);
/* ��Ϊ�ն��У�����ͷ�ڵ� */
bool ClearQueue(GNodeLinkQueue *Lp);
bool QueueEmpty(GNodeLinkQueue LQ);
int QueueLength(GNodeLinkQueue LQ);
bool GetHead(GNodeLinkQueue LQ, ElemType *pe);
/* ����Ԫ��ElemΪ���е��µĶ�βԪ�� */
bool EnQueue(GNodeLinkQueue *Lp, ElemType Elem);
/*ɾ�����еĶ�ͷԪ��,��*pe������ֵ */
bool DeQueue(GNodeLinkQueue *Lp, ElemType *pe);
/* �Ӷ�ͷ����β���ζԶ�����ÿ��Ԫ����� */
bool QueueTraverse(GNodeLinkQueue LQ);

