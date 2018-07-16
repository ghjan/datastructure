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
} LinkQueue;

/* ����һ���ն��� */
bool InitQueue(LinkQueue *Lp);
/* ���ٶ���,����ͷ�ڵ� */
bool DestroyQueue(LinkQueue *Lp);
/* ��Ϊ�ն��У�����ͷ�ڵ� */
bool ClearQueue(LinkQueue *Lp);
bool QueueEmpty(LinkQueue LQ);
int QueueLength(LinkQueue LQ);
bool GetHead(LinkQueue LQ, ElemType *pe);
/* ����Ԫ��ElemΪ���е��µĶ�βԪ�� */
bool EnQueue(LinkQueue *Lp, ElemType Elem);
/*ɾ�����еĶ�ͷԪ��,��*pe������ֵ */
bool DeQueue(LinkQueue *Lp, ElemType *pe);
/* �Ӷ�ͷ����β���ζԶ�����ÿ��Ԫ����� */
bool QueueTraverse(LinkQueue LQ);

