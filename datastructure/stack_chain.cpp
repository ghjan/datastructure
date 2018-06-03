#include "stdafx.h"
#include <stdio.h> 
#include <stdbool.h>  
#include <stdlib.h>  
#include <assert.h>
#include "DynamicStack1.0.h"  

//初始化栈  
void init_sc(Stack_chain *s)
{
	s->data = (datatype_sc *)malloc(sizeof(datatype_sc)*maxsize_sc);
	s->top = -1;
}

//判断栈是否为空  
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

//判断栈是否已满了  
void full_sc(Stack_chain *s)
{
	if (s->top == realsize - 1)
	{
		realsize++;
		s->data = (datatype_sc *)realloc(s->data, realsize * sizeof(datatype_sc));
	}
}

//入栈  
void Push_sc(Stack_chain *s, datatype_sc element)
{
	full_sc(s);
	s->top++;
	s->data[s->top] = element;
}

//出栈  
void Pop_sc(Stack_chain *s)
{
	if (!Empty_sc(s))
	{
		s->top--;
	}
	else
	{
		printf("栈空\n");
	}
}

//取栈顶元素  
datatype_sc Top_sc(Stack_chain *s)
{
	assert(!Empty_sc(s));

	return s->data[s->top];
}

//销毁栈  
void Destroy_sc(Stack_chain *s)
{
	s->top = -1;
	// free(s.data); //容易导致失败  
}


int demo_stack_chain()
{
	int i = 0;
	Stack_chain p;
	Stack_chain *s;
	s = &p;
	// struct stack s;  
	//初始化栈  
	printf("\n###########初始化栈###########\n");
	init_sc(s);
	printf("----------------------------------");
	//入栈操作  
	printf("\n###########入栈操作###########\n");
	for (i = 0;i <= 10;i++)
	{
		Push_sc(s, i);
	}
	printf("----------------------------------");
	//取栈顶元素  
	printf("\n###########取栈顶元素###########\n");
	if (!Empty_sc(s))
	{
		printf("%d\n", Top_sc(s));
	}
	else
	{
		printf("栈空\n");
	}
	printf("----------------------------------");
	//出栈操作  
	printf("\n###########出栈操作###########\n");
	for (i = 0;i <= 12;i++)
	{
		Pop_sc(s);
	}
	printf("----------------------------------");
	//取栈顶元素      
	printf("\n###########取栈顶元素###########\n");
	Top_sc(s);
	printf("----------------------------------");
	//销毁栈  
	printf("\n###########销毁栈###########\n");
	Push_sc(s, 10);
	Destroy_sc(s);
	Top_sc(s);
	return 0;
}