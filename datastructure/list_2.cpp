#include "stdafx.h"
#include<stdio.h>  
#include <stdlib.h>
#include <malloc.h> 
#include "ch2.h"

using namespace std;


Position GetPos(List L, ElemType X)
{
	Position p = L; /* pָ��L�ĵ�1����� */

	while (p && p->Data != X)
		p = p->Next;

	/* ������������ return p; �滻 */
	if (p)
		return p;
	else
		return ERROR_PTR;
}

int GetPos1(List L, ElemType X)
{
	Position p = L; /* pָ��L�ĵ�1����� */
	int i = 0;
	while (p && p->Data != X) {
		p = p->Next;
		i++;
	}

	/* ������������ return p; �滻 */
	if (p)
		return i+1;
	else
		return ERROR;
}


//��ȡ˳���ĳ���  
int GetLength(List L)
{
	Position p = L; /* pָ��L�ĵ�1����� */
	int i = 0;
	while (p->Next) {
		p = p->Next;
		i++;
	}
	return i;
}

/* ��ͷ���Ĳ��� */
/*ע��:�ڲ���λ�ò���P����γ���Ƶ������ͬ���γ���Ƶ��i������λ�򣨴�1��ʼ��������P��������ָ�룬��P֮ǰ�����½�� */
bool Insert(List L, ElemType X, Position P)
{ /* ����Ĭ��L��ͷ��� */
	Position tmp, pre;

	/* ����P��ǰһ����� */
	for (pre = L; pre&&pre->Next != P; pre = pre->Next);
	if (pre == NULL) { /* P��ָ�Ľ�㲻��L�� */
		printf("����λ�ò�������\n");
		return false;
	}
	else { /* �ҵ���P��ǰһ�����pre */
		   /* ��Pǰ�����½�� */
		tmp = (Position)malloc(sizeof(struct LNode)); /* ���롢��װ��� */
		tmp->Data = X;
		tmp->Next = P;
		pre->Next = tmp;
		return true;
	}
}

/* ��ͷ����ɾ�� */
/*ע��:��ɾ��λ�ò���P����γ���Ƶ������ͬ���γ���Ƶ��i������λ�򣨴�1��ʼ��������P����ɾ�����ָ�� */
bool Delete(List L, Position P)
{ /* ����Ĭ��L��ͷ��� */
	Position tmp, pre;

	/* ����P��ǰһ����� */
	for (pre = L; pre&&pre->Next != P; pre = pre->Next);
	if (pre == NULL || P == NULL) { /* P��ָ�Ľ�㲻��L�� */
		printf("ɾ��λ�ò�������\n");
		return false;
	}
	else { /* �ҵ���P��ǰһ�����pre */
		   /* ��Pλ�õĽ��ɾ�� */
		pre->Next = P->Next;
		free(P);
		return true;
	}
}

bool Delete1(List L, int pos)
{ /* ����Ĭ��L��ͷ��� */
	Position tmp, pre;
	int i = 1;
  /* ����P��ǰһ����� */
	for (i = 1,pre = L; pre && (i < pos); ++i, pre = pre->Next);
	if (pre == NULL || pos <=0 ) { /* P��ָ�Ľ�㲻��L�� */
		printf("ɾ��λ�ò�������\n");
		return false;
	}
	else { /* �ҵ���P��ǰһ�����pre */
		   /* ��posλ�õĽ��ɾ�� */
		tmp = pre->Next;
		pre->Next = pre->Next->Next;
		free(tmp);
		return true;
	}
}


//˳���ֵ ȡ���ֵ��-100, 100��
void GiveValue_random(List L, int count)
{
	int value = 0;
	int i = 0;
	Position P = L;
	while (i++<count)
	{
		value = rand() % 100;
		value = (value % 3 > 0 ? 1 : -1)*value;
		Position tmp = (Position)malloc(sizeof(struct LNode)); /* ����һ���ս�� */
		tmp->Next = ERROR_PTR;
		P->Data = value;
		P->Next = tmp;
		P= P->Next;
	}
}

/* ��ʼ�� */
List MakeEmpty()
{
	List L;

	L = (List)malloc(sizeof(struct LNode));
	L->Next = ERROR_PTR;

	return L;
}
//��ʾ˳���  
void ShowList(List L)
{
	printf("The List show below:\n");
	for (Position P=L;P&&P->Next; P=P->Next)
	{
		printf("%d ", P->Data);
	}
}

//��ȡ˳���ĳ��λ�õ�ֵ  
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
	List L = MakeEmpty();//��ʼ��˳���  
	GiveValue_random(L, 20);//˳���ֵ  
	ShowList(L);//��ʾ���Ա�  

	while (1) {
		printf("\n\n");
		int flag;
		printf("******************************************************\n");
		printf("*************choose the operation of List*************\n");
		printf("*****************1-ָ��λ�ò���ֵ*********************\n");
		printf("*****************2-ָ��λ��ɾ��ֵ*********************\n");
		printf("*****************3-��ȡ˳���ĳ��ֵ��λ��*************\n");
		printf("*****************4-��ȡ˳���ĳ��λ���ϵ�ֵ*********\n");
		printf("*****************5-��ȡ˳�����*********************\n");
		printf("*****************0-�˳�*******************************\n");
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
			Position tmp = (Position)malloc(sizeof(struct LNode)); /* ���롢��װ��� */
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