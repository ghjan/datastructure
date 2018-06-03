#include "stdafx.h"
#include"stack_static.h"  
#include<assert.h>  
#include<stdio.h>  
/*
**
** ��̬����ʵ�ֶ�ջ���� a_stack.c �����鳤����#defineȷ��
*/



#define STACK_SIZE 100 /* ��ջ�������Ԫ������ */  

/*
** �洢��ջ�е������һ��ָ���ջ����Ԫ�ص�ָ��
*/
static STACK_TYPE stack[STACK_SIZE];
static int top_element = -1;

/* push */
void push(STACK_TYPE value)
{
	assert(!is_full()); /* ѹ���ջ֮ǰ���ж��Ƿ��ջ����*/
	top_element += 1;
	stack[top_element] = value;
}

/* pop */
void pop(void)
{
	assert(!is_empty()); /* ������ջ֮ǰ���ж��Ƿ��ջ�ѿ� */
	top_element -= 1;
}

/* top */
STACK_TYPE top(void)
{
	assert(!is_empty());
	return stack[top_element];
}

/* is_empty */
int is_empty(void)
{
	return top_element == -1;
}

/* is_full */
int is_full(void)
{
	return top_element == STACK_SIZE - 1;
}

/*
** ����һ��print������������ӡ��ջ�����Ԫ�ء�
*/
void print(void)
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
int demo_stack_static(void)
{
	print();
	push(10); push(9); push(7); push(6); push(5);
	push(4);  push(3); push(2); push(1); push(0);
	printf("pushѹ����ֵ��\n");
	print();
	printf("\n");
	pop();
	pop();
	printf("����pop��������Ԫ�غ�Ķ�ջԪ��:\n");
	print();
	printf("\n");
	printf("top()���ó�����ֵ: %d\n", top());
	return 1;
}
