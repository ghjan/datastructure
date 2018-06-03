#pragma once
#define maxsize 10  
typedef int datatype_sc;

//Sequence Stack_chain ʵ��˳��ջ��ʹ��������ʵ��  
struct stack_chain
{
	datatype_sc *data;
	int top;
};

typedef struct stack_chain Stack_chain;
//����ջ  

int realsize = maxsize;


//��ʼ��ջ  
void init_sc(Stack_chain *s);
//�ж�ջ�Ƿ�Ϊ�� 
bool Empty_sc(Stack_chain *s);
//�ж�ջ�Ƿ�������  
void full_sc(Stack_chain *s);
//��ջ  
void Push_sc(Stack_chain *s, datatype_sc element);

//��ջ  
void Pop_sc(Stack_chain *s);
//ȡջ��Ԫ��  
datatype_sc Top_sc(Stack_chain *s);
//����ջ  
void Destroy_sc(Stack_chain *s);
int demo_stack_chain();
