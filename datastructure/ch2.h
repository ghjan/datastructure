#pragma once
/* ���� */
#define ERROR -1

#define InitSize 20 //˳���ĳ�ʼ��С  

typedef int ElemType;
///////////////////
typedef struct {
	ElemType data[InitSize];
	int length;
}sqlist;
int demo_list_1();

/////////
#define MAXSIZE 10000

typedef int Position1;
typedef struct LNode1 *List1;
struct LNode1 {
	ElemType Data[MAXSIZE];
	Position1 Last;
};
int demo_list_1_2();
//////////
typedef struct LNode *PtrToLNode;
struct LNode {
	ElemType Data;
	PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

/* ���� */
#define ERROR_PTR NULL
int demo_list_2();
///////////////////////