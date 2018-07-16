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
	GraphNodePtr front;/* 队头、队尾指针 */
	GraphNodePtr rear;
} GraphLinkQueue;

/* 构造一个空队列 */
bool InitQueue(GraphLinkQueue *Lp);
/* 销毁队列,包括头节点 */
bool DestroyQueue(GraphLinkQueue *Lp);
/* 清为空队列，保留头节点 */
bool ClearQueue(GraphLinkQueue *Lp);
bool QueueEmpty(GraphLinkQueue LQ);
int QueueLength(GraphLinkQueue LQ);
bool GetHead(GraphLinkQueue LQ, ElemType *pe);
/* 插入元素Elem为队列的新的队尾元素 */
bool EnQueue(GraphLinkQueue *Lp, ElemType Elem);
/*删除队列的队头元素,用*pe返回其值 */
bool DeQueue(GraphLinkQueue *Lp, ElemType *pe);
/* 从队头到队尾依次对队列中每个元素输出 */
bool QueueTraverse(GraphLinkQueue LQ);

