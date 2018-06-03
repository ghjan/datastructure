#include "stdafx.h"
#include<stdio.h>  
#include <stdlib.h>
#include "ch2.h"

using namespace std;


//˳����ʼ��  
void InitList(sqlist *L)
{
	L->length = 0;
	return;
}

//��ȡ˳���ĳ���  
int GetLength(sqlist *L)
{
	return L->length;
}

//˳���ֵ  
void GiveValue(sqlist *L)
{
	int value=-1;
	int i = 0;
	while (value != 0)
	{
		printf("Please input %d valueL-------(exit until value equal 0)\n", i + 1);
		scanf_s("%d", &value);
		if (value != 0)
		{
			L->data[i++] = value;
			L->length++;
		}
	}
}

//˳���ֵ ȡ���ֵ��-100, 100��
void GiveValue_random(sqlist *L, int count)
{
	int value = 0;
	int i = 0;
	while (i<count)
	{
		value = rand() % 100;
		value = (value % 3 > 0 ? 1 : -1)*value;

		L->data[i++] = value;
		L->length++;
	}
}



//��ȡ˳���ĳ��λ�õ�ֵ  
ElemType GetValue(sqlist *L, int i)
{
	ElemType e;
	if (i>L->length || i<1)
		return ERROR;

	int k = 0;
	for (k = 0;k<L->length;k++)
	{
		if (k == i - 1)
			e = L->data[k];
	}
	return e;
}

//��ȡ˳���ĳ��ֵ��λ��  
int GetPos(sqlist *L, ElemType value)
{
	int pos;
	int judeflag = 1;
	int i;
	for (i = 0;i<L->length;i++)
	{
		if (L->data[i] == value)
		{
			pos = i + 1;
			break;
		}
		judeflag++;
	}

	if (judeflag >= L->length)
		return ERROR;

	return pos;
}

//��˳���ָ��λ�ò����µ�ֵ  
int Insert(sqlist *L, int pos, ElemType value)
{
	if (pos<1 || pos>L->length)
		return ERROR;

	int i;
	for (i = L->length - 1;i>pos - 2;i--)
	{
		L->data[i + 1] = L->data[i];
	}

	L->data[pos] = value;
	L->length++;
	return pos;
}

//��˳�����ָ��λ��ɾ��ֵ  
int Delete(sqlist *L, int pos)
{
	if (pos<1 || pos>L->length)
		return ERROR;

	int i;
	for (i = pos;i<L->length;i++)
	{
		L->data[i - 1] = L->data[i];
	}

	L->length--;
	return pos;
}

//��ʾ˳���  
void ShowList(sqlist *L)
{
	int i;
	printf("The List show below:\n");
	for (i = 0;i<L->length;i++)
	{
		printf("%d ", L->data[i]);
	}
}



int demo_list_1()
{
	sqlist L;
	InitList(&L);//��ʼ��˳���  
	//GiveValue(&L);//˳���ֵ  
	GiveValue_random(&L, 20);//˳���ֵ  
	ShowList(&L);//��ʾ���Ա�  

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
			Insert(&L, pos, value);
			ShowList(&L);
			break;
		}
		case 2:
		{
			printf("Please input the position:\n");
			scanf_s("%d", &pos);
			printf("Delete value in pos=%d\n", pos);
			Delete(&L, pos);
			ShowList(&L);
			break;
		}
		case 3:
		{
			printf("Please input the value:\n");
			scanf_s("%d", &value);
			pos = GetPos(&L, value);
			printf("Get value=%d's position is %d\n", value, pos);
			ShowList(&L);
			break;
		}
		case 4:
		{
			printf("Please input the position:\n");
			scanf_s("%d", &pos);
			value = GetValue(&L, pos);
			if(pos<0)
				printf("cannot GetPos %d in the list!\n", value);
			else
				printf("Get value=%d from pos=%d\n", value, pos);
			ShowList(&L);
			break;
		}
		case 5:
		{
			len = GetLength(&L);
			printf("the length of List is %d\n", len);
			ShowList(&L);
			break;
		}
		case 0:
			printf("you choose to exit\nGoodbye!\n");
			return 0;
		}
	}
	return 0;
}