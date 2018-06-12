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
	NodePtr front;/* 队头、队尾指针 */
	NodePtr rear;
} LinkQueue_bst;

/* 构造一个空队列 */
bool InitQueue(LinkQueue_bst *Lp);
/* 销毁队列,包括头节点 */
bool DestroyQueue(LinkQueue_bst *Lp);
/* 清为空队列，保留头节点 */
bool ClearQueue(LinkQueue_bst *Lp);
bool QueueEmpty(LinkQueue_bst LQ);
int QueueLength(LinkQueue_bst LQ);
bool GetHead(LinkQueue_bst LQ, ElemType *pe);
/* 插入元素Elem为队列的新的队尾元素 */
bool EnQueue(LinkQueue_bst *Lp, ElemType Elem);
/*删除队列的队头元素,用*pe返回其值 */
ElemType * DeQueue(LinkQueue_bst *Lp);
/* 从队头到队尾依次对队列中每个元素输出 */
bool QueueTraverse(LinkQueue_bst LQ);

