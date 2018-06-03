#pragma once
#define maxsize 10  
typedef int datatype_sc;

//Sequence Stack_chain 实现顺序栈，使用数组来实现  
struct stack_chain
{
	datatype_sc *data;
	int top;
};

typedef struct stack_chain Stack_chain;
//创建栈  

int realsize = maxsize;


//初始化栈  
void init_sc(Stack_chain *s);
//判断栈是否为空 
bool Empty_sc(Stack_chain *s);
//判断栈是否已满了  
void full_sc(Stack_chain *s);
//入栈  
void Push_sc(Stack_chain *s, datatype_sc element);

//出栈  
void Pop_sc(Stack_chain *s);
//取栈顶元素  
datatype_sc Top_sc(Stack_chain *s);
//销毁栈  
void Destroy_sc(Stack_chain *s);
int demo_stack_chain();
