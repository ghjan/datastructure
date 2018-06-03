#pragma once
#define maxsize 10  
typedef int datatype_ss;

//Sequence Stack_ss 实现顺序栈，使用数组来实现  
struct stack_ss
{
	datatype_ss data[maxsize];
	int top;
};

typedef struct stack_ss Stack_ss;
//创建栈  

//初始化栈 
void init_ss(Stack_ss *s);

//判断栈是否为空  
bool Empty_ss(Stack_ss *s);
//判断栈是否已满了 
bool full_ss(Stack_ss *s);
//入栈  
void Push_ss(Stack_ss *s, datatype_ss element);
//出栈  
void Pop_ss(Stack_ss *s);
//取栈顶元素  
datatype_ss Top_ss(Stack_ss *s);
//销毁栈  
void Destroy_ss(Stack_ss *s);
int demo_stack_array();