#include "stdafx.h"
#include<stdio.h>  
#include <stdlib.h>
#include "ch2.h"


/* ��ʼ�� */
List1 MakeEmpty()
{
	List1 L;

	L = (List1)malloc(sizeof(struct LNode1));
	L->Last = -1;

	return L;
}

//��ȡ˳���ĳ���  
int GetLength(List1 L)
{
	return L->Last+1;
}

Position1 GetPos(List1 L, ElemType X)
{
	Position1 i = 0;

	while (i <= L->Last && L->Data[i] != X)
		i++;
	if (i > L->Last)  return ERROR; /* ���û�ҵ������ش�����Ϣ */
	else  return i+1;  /* �ҵ��󷵻ص��Ǵ洢λ�� */
}

//��ȡ˳���ĳ��λ�õ�ֵ  
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

/* ���� */
/*ע��:�ڲ���λ�ò���P����γ���Ƶ������ͬ���γ���Ƶ��i������λ�򣨴�1��ʼ��������P�Ǵ洢�±�λ�ã���0��ʼ�������߲�1*/
bool Insert(List1 L, ElemType X, Position1 P)
{ /* ��L��ָ��λ��Pǰ����һ����Ԫ��X */
	Position1 i;

	if (L->Last == MAXSIZE - 1) {
		/* ��ռ����������ܲ��� */
		printf("����");
		return false;
	}
	if (P<0 || P>L->Last + 1) { /* ������λ�õĺϷ��� */
		printf("λ�ò��Ϸ�");
		return false;
	}
	for (i = L->Last; i >= P; i--)
		L->Data[i + 1] = L->Data[i]; /* ��λ��P���Ժ��Ԫ��˳������ƶ� */
	L->Data[P] = X;  /* ��Ԫ�ز��� */
	L->Last++;       /* Last��ָ�����Ԫ�� */
	return true;
}

/* ɾ�� */
/*ע��:��ɾ��λ�ò���P����γ���Ƶ������ͬ���γ���Ƶ��i������λ�򣨴�1��ʼ��������P�Ǵ洢�±�λ�ã���0��ʼ�������߲�1*/
bool Delete(List1 L, Position1 P)
{ /* ��L��ɾ��ָ��λ��P��Ԫ�� */
	Position1 i;

	if (P<0 || P>L->Last) { /* ���ձ�ɾ��λ�õĺϷ��� */
		printf("λ��%d������Ԫ��", P);
		return false;
	}
	for (i = P + 1; i <= L->Last; i++)
		L->Data[i - 1] = L->Data[i]; /* ��λ��P+1���Ժ��Ԫ��˳����ǰ�ƶ� */
	L->Last--; /* Last��ָ�����Ԫ�� */
	return true;
}


//˳���ֵ ȡ���ֵ��-100, 100��
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

//��ʾ˳���  
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
	List1 L= MakeEmpty();//��ʼ��˳���  
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