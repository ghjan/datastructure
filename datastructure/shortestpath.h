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
} GNodeLinkQueue;

/* 构造一个空队列 */
bool InitQueue(GNodeLinkQueue *Lp);
/* 销毁队列,包括头节点 */
bool DestroyQueue(GNodeLinkQueue *Lp);
/* 清为空队列，保留头节点 */
bool ClearQueue(GNodeLinkQueue *Lp);
bool QueueEmpty(GNodeLinkQueue LQ);
int QueueLength(GNodeLinkQueue LQ);
bool GetHead(GNodeLinkQueue LQ, ElemType *pe);
/* 插入元素Elem为队列的新的队尾元素 */
bool EnQueue(GNodeLinkQueue *Lp, ElemType Elem);
/*删除队列的队头元素,用*pe返回其值 */
bool DeQueue(GNodeLinkQueue *Lp, ElemType *pe);
/* 从队头到队尾依次对队列中每个元素输出 */
bool QueueTraverse(GNodeLinkQueue LQ);

