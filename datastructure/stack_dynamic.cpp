/*
** ��̬��������ʵ�ֵĶ�ջ���� d_stack.c
** ��ջ�ĳ����ڴ�����ջ�ĺ���������ʱ��������ú����������κ�����������ջ�ĺ���������֮ǰ���á�
*/
#include "stdafx.h"

#include<stdio.h>  
#include<malloc.h>  
#include<assert.h>  
#include "stack_dynamic.h"

/*
** ���ڴ洢��ջԪ�ص������ָ���ջ����Ԫ�ص�ָ��
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
		perror("malloc����ʧ��");
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
** ����һ��print������������ӡ��ջ�����Ԫ�ء�
*/
void print_dynamic(void)
{
	int i;
	i = top_element;
	printf("��ӡ����̬�����ջ�����ֵ: ");
	if (i == -1)
		printf("���Ǹ��ն�ջ\n");
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
	printf("pushѹ����ֵ��\n");
	print_dynamic();
	printf("\n");
	pop_dynamic();
	pop_dynamic();
	printf("����pop��������Ԫ�غ�Ķ�ջԪ��:\n");
	print_dynamic();
	printf("\n");
	printf("top_dynamic()���ó�����ֵ: %d\n", top_dynamic());
	destroy_stack_dynamic();
	return 1;
}