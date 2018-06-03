/*
** 动态分配数组实现的堆栈程序 d_stack.c
** 堆栈的长度在创建堆栈的函数被调用时候给出，该函数必须在任何其他操作堆栈的函数被调用之前条用。
*/
#include "stdafx.h"

#include<stdio.h>  
#include<malloc.h>  
#include<assert.h>  
#include "stack_dynamic.h"

/*
** 用于存储堆栈元素的数组和指向堆栈顶部元素的指针
*/
static STACK_TYPE *stack;
static int        stack_size;
static int        top_element = -1;

/* create_stack */
void create_stack_dynamic(size_t size)
{
	assert(stack_size == 0);
	stack_size = size;
	stack = (STACK_TYPE *)malloc(stack_size * sizeof(STACK_TYPE));
	if (stack == NULL)
		perror("malloc分配失败");
}

/* destroy */
void destroy_stack_dynamic(void)
{
	assert(stack_size > 0);
	stack_size = 0;
	free(stack);
	stack = NULL;
}

/* push */
void push_dynamic(STACK_TYPE value)
{
	assert(!is_full_dynamic());
	top_element += 1;
	stack[top_element] = value;
}

/* pop */
void pop_dynamic(void)
{
	assert(!is_empty_dynamic());
	top_element -= 1;
}

/* top */
STACK_TYPE top_dynamic(void)
{
	assert(!is_empty_dynamic());
	return stack[top_element];
}

/* is_empty */
int is_empty_dynamic(void)
{
	assert(stack_size > 0);
	return top_element == -1;
}

/* is_full_dynamic */
int is_full_dynamic(void)
{
	assert(stack_size > 0);
	return top_element == stack_size - 1;
}


/*
** 定义一个print函数，用来打印堆栈里面的元素。
*/
void print_dynamic(void)
{
	int i;
	i = top_element;
	printf("打印出动态数组堆栈里面的值: ");
	if (i == -1)
		printf("这是个空堆栈\n");
	while (i != -1)
		printf("%d ", stack[i--]);
	printf("\n");
}
int demo_stack_dynamic(void)
{
	create_stack_dynamic(50);
	print_dynamic();
	push_dynamic(10); push_dynamic(9); push_dynamic(7); push_dynamic(6); push_dynamic(5);
	push_dynamic(4);  push_dynamic(3); push_dynamic(2); push_dynamic(1); push_dynamic(0);
	printf("push压入数值后：\n");
	print_dynamic();
	printf("\n");
	pop_dynamic();
	pop_dynamic();
	printf("经过pop弹出几个元素后的堆栈元素:\n");
	print_dynamic();
	printf("\n");
	printf("top_dynamic()调用出来的值: %d\n", top_dynamic());
	destroy_stack_dynamic();
	return 1;
}