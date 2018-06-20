#pragma once
/* ͼ���ڽӾ����ʾ�� */

#define MaxVertexNum 100    /* ��󶥵�����Ϊ100 */
#define INFINITY 65535        /* ����Ϊ˫�ֽ��޷������������ֵ65535*/
typedef int Vertex;         /* �ö����±��ʾ����,Ϊ���� */
typedef int WeightType;        /* �ߵ�Ȩֵ��Ϊ���� */
typedef char DataType;        /* ����洢������������Ϊ�ַ��� */
							  /* �ߵĶ��� */
typedef struct ENode *PtrToENode;

struct ENode {
	Vertex V1, V2;      /* �����<V1, V2> */
	WeightType Weight;  /* Ȩ�� */
};
typedef PtrToENode Edge;

/* ͼ���Ķ��� */
typedef struct GNode *PtrToGNode;
struct GNode {
	int Nv;  /* ������ */
	int Ne;  /* ����   */
	WeightType G[MaxVertexNum][MaxVertexNum]; /* �ڽӾ��� */
	DataType Data[MaxVertexNum];      /* �涥������� */
									  /* ע�⣺�ܶ�����£����������ݣ���ʱData[]���Բ��ó��� */
};
typedef PtrToGNode MGraph; /* ���ڽӾ���洢��ͼ���� */

int *Visited = new int[MaxVertexNum];

typedef Vertex ElemType;

typedef struct Node
{
	ElemType data;
	struct Node *next;
} Node, *NodePtr;

typedef struct
{
	NodePtr front;/* ��ͷ����βָ�� */
	NodePtr rear;
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

