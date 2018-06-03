#pragma once
/*
** ��ջģ��Ľӿ� stack.h
*/
#include<stdlib.h>  

#define STACK_TYPE int /* ��ջ���洢��ֵ���������� */  

/*
** ����ԭ�ͣ�create_stack
** ������ջ������ָ����ջ���Ա�����ٸ�Ԫ�ء�
** ע�⣺�˺���ֻ�����ڶ�̬����������ʽ�Ķ�ջ��
*/
void create_stack(size_t size);

/*
** ����ԭ�ͣ�destroy_stack
** ����һ����ջ���ͷŶ�ջ�����õ��ڴ档
** ע�⣺�˺���ֻ�����ڶ�̬�����������ʽ�ṹ�Ķ�ջ��
*/
void destroy_stack(void);

/*
** ����ԭ�ͣ�push
** ��һ����ֵѹ���ջ�У������Ǳ�ѹ���ֵ��
*/
void push(STACK_TYPE value);

/*
** ����ԭ�ͣ�pop
** ������ջ��ջ����һ��ֵ����������
*/
void pop(void);

/*
** ����ԭ�ͣ�top
** ���ض�ջ����Ԫ�ص�ֵ�������ı��ջ�ṹ��
*/
STACK_TYPE top(void);

/*
** ����ԭ�ͣ�is_empty
** �����ջΪ�գ�����TRUE,���򷵻�FALSE��
*/
int is_empty(void);

/*
** ����ԭ�ͣ�is_full
** �����ջΪ��������TRUE,���򷵻�FALSE��
*/
int is_full(void);
///////////////
int demo_stack_static(void);
int demo_stack_dynamic(void);
//////////////