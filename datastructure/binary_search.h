#pragma once
typedef struct TNode *Position;
typedef Position BinTree; /* ���������� */
typedef int ElementType;
#define SIZE  100

struct TNode { /* ����㶨�� */
	ElementType Data; /* ������� */
	BinTree Left;     /* ָ�������� */
	BinTree Right;    /* ָ�������� */
};
struct StaticTable {
	ElementType Element[SIZE];
	int Length;
};