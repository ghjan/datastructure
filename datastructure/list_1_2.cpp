#include "stdafx.h"
#include<stdio.h>  
#include <stdlib.h>
#include "ch2.h"


/* 初始化 */
List1 MakeEmpty()
{
	List1 L;

	L = (List1)malloc(sizeof(struct LNode1));
	L->Last = -1;

	return L;
}

//获取顺序表的长度  
int GetLength(List1 L)
{
	return L->Last+1;
}

Position1 GetPos(List1 L, ElemType X)
{
	Position1 i = 0;

	while (i <= L->Last && L->Data[i] != X)
		i++;
	if (i > L->Last)  return ERROR; /* 如果没找到，返回错误信息 */
	else  return i+1;  /* 找到后返回的是存储位置 */
}

//获取顺序表某个位置的值  
ElemType GetValue(List1 L, int i)
{
	ElemType e;
	if (i>L->Last || i<1)
		return ERROR;

	int k = 0;
	for (k = 0;k<L->Last;k++)
	{
		if (k == i - 1)
			e = L->Data[k];
	}
	return e;
}

/* 插入 */
/*注意:在插入位置参数P上与课程视频有所不同，课程视频中i是序列位序（从1开始），这里P是存储下标位置（从0开始），两者差1*/
bool Insert(List1 L, ElemType X, Position1 P)
{ /* 在L的指定位置P前插入一个新元素X */
	Position1 i;

	if (L->Last == MAXSIZE - 1) {
		/* 表空间已满，不能插入 */
		printf("表满");
		return false;
	}
	if (P<0 || P>L->Last + 1) { /* 检查插入位置的合法性 */
		printf("位置不合法");
		return false;
	}
	for (i = L->Last; i >= P; i--)
		L->Data[i + 1] = L->Data[i]; /* 将位置P及以后的元素顺序向后移动 */
	L->Data[P] = X;  /* 新元素插入 */
	L->Last++;       /* Last仍指向最后元素 */
	return true;
}

/* 删除 */
/*注意:在删除位置参数P上与课程视频有所不同，课程视频中i是序列位序（从1开始），这里P是存储下标位置（从0开始），两者差1*/
bool Delete(List1 L, Position1 P)
{ /* 从L中删除指定位置P的元素 */
	Position1 i;

	if (P<0 || P>L->Last) { /* 检查空表及删除位置的合法性 */
		printf("位置%d不存在元素", P);
		return false;
	}
	for (i = P + 1; i <= L->Last; i++)
		L->Data[i - 1] = L->Data[i]; /* 将位置P+1及以后的元素顺序向前移动 */
	L->Last--; /* Last仍指向最后元素 */
	return true;
}


//顺序表赋值 取随机值（-100, 100）
void GiveValue_random(List1 L, int count)
{
	int value = 0;
	int i = 0;
	while (i<count)
	{
		value = rand() % 100;
		value = (value % 3 > 0 ? 1 : -1)*value;

		L->Data[i++] = value;
		L->Last++;
	}
}

//显示顺序表  
void ShowList(List1 L)
{
	int i;
	printf("The List show below:\n");
	for (i = 0;i<=L->Last;i++)
	{
		printf("%d ", L->Data[i]);
	}
}


int demo_list_1_2()
{
	List1 L= MakeEmpty();//初始化顺序表  
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
			Insert(L, pos, value);
			ShowList(L);
			break;
		}
		case 2:
		{
			printf("Please input the position:\n");
			scanf_s("%d", &pos);
			printf("Delete value in pos=%d\n", pos);
			Delete(L, pos);
			ShowList(L);
			break;
		}
		case 3:
		{
			printf("Please input the value:\n");
			scanf_s("%d", &value);
			pos = GetPos(L, value);
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