#include "stdafx.h"
#include <stdio.h>  
#include <stdbool.h>  
#include <assert.h>
#include "SequenceStack1.0.h"  

//��ʼ��ջ  
void init_ss(Stack_ss *s)
{
	s->top = -1;
}

//�ж�ջ�Ƿ�Ϊ��  
bool Empty_ss(Stack_ss *s)
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
bool full_ss(Stack_ss *s)
{
	if (s->top == maxsize - 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//��ջ  
void Push_ss(Stack_ss *s, datatype_ss element)
{
	if (!full_ss(s))
	{
		s->top++;
		s->data[s->top] = element;
	}
	else
	{
		printf("ջ��\n");
	}
}

//��ջ  
void Pop_ss(Stack_ss *s)
{
	if (!Empty_ss(s))
	{
		s->top--;
	}
	else
	{
		printf("ջ��\n");
	}
}

//ȡջ��Ԫ��  
datatype_ss Top_ss(Stack_ss *s)
{
	assert(!Empty_ss(s));
	return s->data[s->top];
 
}

//����ջ  
void Destroy_ss(Stack_ss *s)
{
	s->top = -1;
}

int demo_stack_array()
{
	int i = 0;
	Stack_ss p;
	Stack_ss *s;
	s = &p;
	// struct stack s;  
	//��ʼ��ջ  
	printf("\n###########��ʼ��ջ###########\n");
	init_ss(s);
	printf("----------------------------------");
	//��ջ����  
	printf("\n###########��ջ����###########\n");
	for (i = 0;i <= 10;i++)
	{
		Push_ss(s, i);
	}
	printf("----------------------------------");
	//ȡջ��Ԫ��  
	printf("\n###########ȡջ��Ԫ��###########\n");
	if(!Empty_ss(s))
	{
		printf("%d\n", Top_ss(s));
	}else
		printf("ջ��\n");
	
	printf("----------------------------------");
	//��ջ����  
	printf("\n###########��ջ����###########\n");
	for (i = 0;i <= 12;i++)
	{
		Pop_ss(s);
	}
	printf("----------------------------------");
	//ȡջ��Ԫ��      
	printf("\n###########ȡջ��Ԫ��###########\n");
	Top_ss(s);
	printf("----------------------------------");
	//����ջ  
	printf("\n###########����ջ###########\n");
	Push_ss(s, 10);
	Destroy_ss(s);
	Top_ss(s);
	return 0;
}