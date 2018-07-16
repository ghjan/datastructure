#pragma once
#pragma warning(disable:4996)

typedef int ElementType;

typedef struct Node *PtrToNode;
struct Node {
	ElementType Data; /* 存储结点数据 */
	PtrToNode   Next; /* 指向下一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 */

List Read();
void Print(List L); /* 空链表将输出NULL */

//两个链表表示的递增整数序列合并为一个非递减的整数序列
List Merge(List L1, List L2);
