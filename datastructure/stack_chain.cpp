#include "stdafx.h"
#include <stdio.h> 
#include <stdbool.h>  
#include <stdlib.h>  
#include <assert.h>
#include "DynamicStack1.0.h"  

//��ʼ��ջ  
void init_sc(Stack_chain *s)
{
	s->data = (datatype_sc *)malloc(sizeof(datatype_sc)*maxsize_sc);
	s->top = -1;
}

//�ж�ջ�Ƿ�Ϊ��  
bool Empty_sc(Stack_chain *s)
{
	if (s->top == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//�ж�ջ�Ƿ�������  
void full_sc(Stack_chain *s)
{
	if (s->top == realsize - 1)
	{
		realsize++;
		s->data = (datatype_sc *)realloc(s->data, realsize * sizeof(datatype_sc));
	}
}

//��ջ  
void Push_sc(Stack_chain *s, datatype_sc element)
{
	full_sc(s);
	s->top++;
	s->data[s->top] = element;
}

//��ջ  
void Pop_sc(Stack_chain *s)
{
	if (!Empty_sc(s))
	{
		s->top--;
	}
	else
	{
		printf("ջ��\n");
	}
}

//ȡջ��Ԫ��  
datatype_sc Top_sc(Stack_chain *s)
{
	assert(!Empty_sc(s));

	return s->data[s->top];
}

//����ջ  
void Destroy_sc(Stack_chain *s)
{
	s->top = -1;
	// free(s.data); //���׵���ʧ��  
}


int demo_stack_chain()
{
	int i = 0;
	Stack_chain p;
	Stack_chain *s;
	s = &p;
	// struct stack s;  
	//��ʼ��ջ  
	printf("\n###########��ʼ��ջ###########\n");
	init_sc(s);
	printf("----------------------------------");
	//��ջ����  
	printf("\n###########��ջ����###########\n");
	for (i = 0;i <= 10;i++)
	{
		Push_sc(s, i);
	}
	printf("----------------------------------");
	//ȡջ��Ԫ��  
	printf("\n###########ȡջ��Ԫ��###########\n");
	if (!Empty_sc(s))
	{
		printf("%d\n", Top_sc(s));
	}
	else
	{
		printf("ջ��\n");
	}
	printf("----------------------------------");
	//��ջ����  
	printf("\n###########��ջ����###########\n");
	for (i = 0;i <= 12;i++)
	{
		Pop_sc(s);
	}
	printf("----------------------------------");
	//ȡջ��Ԫ��      
	printf("\n###########ȡջ��Ԫ��###########\n");
	Top_sc(s);
	printf("----------------------------------");
	//����ջ  
	printf("\n###########����ջ###########\n");
	Push_sc(s, 10);
	Destroy_sc(s);
	Top_sc(s);
	return 0;
}