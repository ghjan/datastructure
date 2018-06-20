#pragma once
/* 图的邻接矩阵表示法 */

#define MaxVertexNum 100    /* 最大顶点数设为100 */
#define INFINITY 65535        /* ∞设为双字节无符号整数的最大值65535*/
typedef int Vertex;         /* 用顶点下标表示顶点,为整型 */
typedef int WeightType;        /* 边的权值设为整型 */
typedef char DataType;        /* 顶点存储的数据类型设为字符型 */
							  /* 边的定义 */
typedef struct ENode *PtrToENode;

struct ENode {
	Vertex V1, V2;      /* 有向边<V1, V2> */
	WeightType Weight;  /* 权重 */
};
typedef PtrToENode Edge;

/* 图结点的定义 */
typedef struct GNode *PtrToGNode;
struct GNode {
	int Nv;  /* 顶点数 */
	int Ne;  /* 边数   */
	WeightType G[MaxVertexNum][MaxVertexNum]; /* 邻接矩阵 */
	DataType Data[MaxVertexNum];      /* 存顶点的数据 */
									  /* 注意：很多情况下，顶点无数据，此时Data[]可以不用出现 */
};
typedef PtrToGNode MGraph; /* 以邻接矩阵存储的图类型 */

int *Visited = new int[MaxVertexNum];

typedef Vertex ElemType;

typedef struct Node
{
	ElemType data;
	struct Node *next;
} Node, *NodePtr;

typedef struct
{
	NodePtr front;/* 队头、队尾指针 */
	NodePtr rear;
} LinkQueue;

/* 构造一个空队列 */
bool InitQueue(LinkQueue *Lp);
/* 销毁队列,包括头节点 */
bool DestroyQueue(LinkQueue *Lp);
/* 清为空队列，保留头节点 */
bool ClearQueue(LinkQueue *Lp);
bool QueueEmpty(LinkQueue LQ);
int QueueLength(LinkQueue LQ);
bool GetHead(LinkQueue LQ, ElemType *pe);
/* 插入元素Elem为队列的新的队尾元素 */
bool EnQueue(LinkQueue *Lp, ElemType Elem);
/*删除队列的队头元素,用*pe返回其值 */
bool DeQueue(LinkQueue *Lp, ElemType *pe);
/* 从队头到队尾依次对队列中每个元素输出 */
bool QueueTraverse(LinkQueue LQ);

