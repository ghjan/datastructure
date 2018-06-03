#pragma once
#define maxsize 10  
typedef int datatype_ss;

//Sequence Stack_ss ʵ��˳��ջ��ʹ��������ʵ��  
struct stack_ss
{
	datatype_ss data[maxsize];
	int top;
};

typedef struct stack_ss Stack_ss;
//����ջ  

//��ʼ��ջ 
void init_ss(Stack_ss *s);

//�ж�ջ�Ƿ�Ϊ��  
bool Empty_ss(Stack_ss *s);
//�ж�ջ�Ƿ������� 
bool full_ss(Stack_ss *s);
//��ջ  
void Push_ss(Stack_ss *s, datatype_ss element);
//��ջ  
void Pop_ss(Stack_ss *s);
//ȡջ��Ԫ��  
datatype_ss Top_ss(Stack_ss *s);
//����ջ  
void Destroy_ss(Stack_ss *s);
int demo_stack_array();