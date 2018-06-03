#include "stdafx.h"
#include<stdio.h>  
#include <stdlib.h>
#include <malloc.h> 
#include "ch2.h"

using namespace std;


Position GetPos(List L, ElemType X)
{
	Position p = L; /* p指向L的第1个结点 */

	while (p && p->Data != X)
		p = p->Next;

	/* 下列语句可以用 return p; 替换 */
	if (p)
		return p;
	else
		return ERROR_PTR;
}

int GetPos1(List L, ElemType X)
{
	Position p = L; /* p指向L的第1个结点 */
	int i = 0;
	while (p && p->Data != X) {
		p = p->Next;
		i++;
	}

	/* 下列语句可以用 return p; 替换 */
	if (p)
		return i+1;
	else
		return ERROR;
}


//获取顺序表的长度  
int GetLength(List L)
{
	Position p = L; /* p指向L的第1个结点 */
	int i = 0;
	while (p->Next) {
		p = p->Next;
		i++;
	}
	return i;
}

/* 带头结点的插入 */
/*注意:在插入位置参数P上与课程视频有所不同，课程视频中i是序列位序（从1开始），这里P是链表结点指针，在P之前插入新结点 */
bool Insert(List L, ElemType X, Position P)
{ /* 这里默认L有头结点 */
	Position tmp, pre;

	/* 查找P的前一个结点 */
	for (pre = L; pre&&pre->Next != P; pre = pre->Next);
	if (pre == NULL) { /* P所指的结点不在L中 */
		printf("插入位置参数错误\n");
		return false;
	}
	else { /* 找到了P的前一个结点pre */
		   /* 在P前插入新结点 */
		tmp = (Position)malloc(sizeof(struct LNode)); /* 申请、填装结点 */
		tmp->Data = X;
		tmp->Next = P;
		pre->Next = tmp;
		return true;
	}
}

/* 带头结点的删除 */
/*注意:在删除位置参数P上与课程视频有所不同，课程视频中i是序列位序（从1开始），这里P是拟删除结点指针 */
bool Delete(List L, Position P)
{ /* 这里默认L有头结点 */
	Position tmp, pre;

	/* 查找P的前一个结点 */
	for (pre = L; pre&&pre->Next != P; pre = pre->Next);
	if (pre == NULL || P == NULL) { /* P所指的结点不在L中 */
		printf("删除位置参数错误\n");
		return false;
	}
	else { /* 找到了P的前一个结点pre */
		   /* 将P位置的结点删除 */
		pre->Next = P->Next;
		free(P);
		return true;
	}
}

bool Delete1(List L, int pos)
{ /* 这里默认L有头结点 */
	Position tmp, pre;
	int i = 1;
  /* 查找P的前一个结点 */
	for (i = 1,pre = L; pre && (i < pos); ++i, pre = pre->Next);
	if (pre == NULL || pos <=0 ) { /* P所指的结点不在L中 */
		printf("删除位置参数错误\n");
		return false;
	}
	else { /* 找到了P的前一个结点pre */
		   /* 将pos位置的结点删除 */
		tmp = pre->Next;
		pre->Next = pre->Next->Next;
		free(tmp);
		return true;
	}
}


//顺序表赋值 取随机值（-100, 100）
void GiveValue_random(List L, int count)
{
	int value = 0;
	int i = 0;
	Position P = L;
	while (i++<count)
	{
		value = rand() % 100;
		value = (value % 3 > 0 ? 1 : -1)*value;
		Position tmp = (Position)malloc(sizeof(struct LNode)); /* 申请一个空结点 */
		tmp->Next = ERROR_PTR;
		P->Data = value;
		P->Next = tmp;
		P= P->Next;
	}
}

/* 初始化 */
List MakeEmpty()
{
	List L;

	L = (List)malloc(sizeof(struct LNode));
	L->Next = ERROR_PTR;

	return L;
}
//显示顺序表  
void ShowList(List L)
{
	printf("The List show below:\n");
	for (Position P=L;P&&P->Next; P=P->Next)
	{
		printf("%d ", P->Data);
	}
}

//获取顺序表某个位置的值  
ElemType GetValue(List L, int i)
{
	ElemType e;
	if ( i<1)
		return ERROR;

	int k = 0;
	for (Position P=L;P->Next;P=P->Next,k++)
	{
		if (k == i - 1)
			e = P->Data;
	}
	return e;
}

int demo_list_2()
{
	List L = MakeEmpty();//初始化顺序表  
	GiveValue_random(L, 20);//顺序表赋值  
	ShowList(L);//显示线性表  

	while (1) {
		printf("\n\n");
		int flag;
		printf("******************************************************\n");
		printf("*************choose the operation of List*************\n");
		printf("*****************1-指定位置插入值*********************\n");
		printf("*****************2-指定位置删除值*********************\n");
		printf("*****************3-获取顺序表某个值得位置*************\n");
		printf("*****************4-获取顺序表某个位置上的值*********\n");
		printf("*****************5-获取顺序表长度*********************\n");
		printf("*****************0-退出*******************************\n");
		printf("******************************************************\n");
		printf("\n\n");

		printf("Input the value Flag:\n");
		scanf_s("%d", &flag);

		printf("flag=%d\n", flag);

		int pos, value, len;

		switch (flag) {
		case 1:
		{
			printf("Please input the value and position:\n");
			scanf_s("%d %d", &value, &pos);
			printf("Insert value=%d in pos=%d\n", value, pos + 1);
			Position tmp = (Position)malloc(sizeof(struct LNode)); /* 申请、填装结点 */
			tmp->Data = value;
			Insert(L, pos, tmp);
			ShowList(L);
			break;
		}
		case 2:
		{
			printf("Please input the position:\n");
			scanf_s("%d", &pos);
			printf("Delete value in pos=%d\n", pos);
			Delete1(L, pos);
			ShowList(L);
			break;
		}
		case 3:
		{
			printf("Please input the value:\n");
			scanf_s("%d", &value);
			pos = GetPos1(L, value);
			printf("Get value=%d's position is %d\n", value, pos);
			ShowList(L);
			break;
		}
		case 4:
		{
			printf("Please input the position:\n");
			scanf_s("%d", &pos);
			value = GetValue(L, pos);
			if (pos<0)
				printf("cannot GetPos %d in the list!\n", value);
			else
				printf("Get value=%d from pos=%d\n", value, pos);
			ShowList(L);
			break;
		}
		case 5:
		{
			len = GetLength(L);
			printf("the length of List is %d\n", len);
			ShowList(L);
			break;
		}
		case 0:
			printf("you choose to exit\nGoodbye!\n");
			return 0;
		}
	}
	return 0;
}