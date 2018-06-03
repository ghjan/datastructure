#include "stdafx.h"
#include <stdio.h>  
#include <stdbool.h>  
#include <assert.h>
#include "SequenceStack1.0.h"  

//初始化栈  
void init_ss(Stack_ss *s)
{
	s->top = -1;
}

//判断栈是否为空  
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

//判断栈是否已满了  
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

//入栈  
void Push_ss(Stack_ss *s, datatype_ss element)
{
	if (!full_ss(s))
	{
		s->top++;
		s->data[s->top] = element;
	}
	else
	{
		printf("栈满\n");
	}
}

//出栈  
void Pop_ss(Stack_ss *s)
{
	if (!Empty_ss(s))
	{
		s->top--;
	}
	else
	{
		printf("栈空\n");
	}
}

//取栈顶元素  
datatype_ss Top_ss(Stack_ss *s)
{
	assert(!Empty_ss(s));
	return s->data[s->top];
 
}

//销毁栈  
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
	//初始化栈  
	printf("\n###########初始化栈###########\n");
	init_ss(s);
	printf("----------------------------------");
	//入栈操作  
	printf("\n###########入栈操作###########\n");
	for (i = 0;i <= 10;i++)
	{
		Push_ss(s, i);
	}
	printf("----------------------------------");
	//取栈顶元素  
	printf("\n###########取栈顶元素###########\n");
	if(!Empty_ss(s))
	{
		printf("%d\n", Top_ss(s));
	}else
		printf("栈空\n");
	
	printf("----------------------------------");
	//出栈操作  
	printf("\n###########出栈操作###########\n");
	for (i = 0;i <= 12;i++)
	{
		Pop_ss(s);
	}
	printf("----------------------------------");
	//取栈顶元素      
	printf("\n###########取栈顶元素###########\n");
	Top_ss(s);
	printf("----------------------------------");
	//销毁栈  
	printf("\n###########销毁栈###########\n");
	Push_ss(s, 10);
	Destroy_ss(s);
	Top_ss(s);
	return 0;
}