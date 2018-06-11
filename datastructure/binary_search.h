#pragma once
typedef struct TNode *Position;
typedef Position BinTree; /* 二叉树类型 */
typedef int ElementType;
#define SIZE  100

struct TNode { /* 树结点定义 */
	ElementType Data; /* 结点数据 */
	BinTree Left;     /* 指向左子树 */
	BinTree Right;    /* 指向右子树 */
};
struct StaticTable {
	ElementType Element[SIZE];
	int Length;
};