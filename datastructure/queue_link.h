#pragma once

typedef int ElemType;

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
int queue_link_demo(void);
