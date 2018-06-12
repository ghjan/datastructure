#pragma once
#include "bstree.h"

typedef BSTreeNode ElemType;

typedef struct Node
{
	ElemType data;
	struct Node *next;
} Node, *NodePtr;

typedef struct
{
	NodePtr front;/* ��ͷ����βָ�� */
	NodePtr rear;
} LinkQueue_bst;

/* ����һ���ն��� */
bool InitQueue(LinkQueue_bst *Lp);
/* ���ٶ���,����ͷ�ڵ� */
bool DestroyQueue(LinkQueue_bst *Lp);
/* ��Ϊ�ն��У�����ͷ�ڵ� */
bool ClearQueue(LinkQueue_bst *Lp);
bool QueueEmpty(LinkQueue_bst LQ);
int QueueLength(LinkQueue_bst LQ);
bool GetHead(LinkQueue_bst LQ, ElemType *pe);
/* ����Ԫ��ElemΪ���е��µĶ�βԪ�� */
bool EnQueue(LinkQueue_bst *Lp, ElemType Elem);
/*ɾ�����еĶ�ͷԪ��,��*pe������ֵ */
ElemType * DeQueue(LinkQueue_bst *Lp);
/* �Ӷ�ͷ����β���ζԶ�����ÿ��Ԫ����� */
bool QueueTraverse(LinkQueue_bst LQ);

