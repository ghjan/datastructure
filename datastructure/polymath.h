#pragma once
typedef struct PolyNode
{
	int coef;       //系数  
	int expon;  //指数  
	struct PolyNode *link;  //指向下一个结点的指针  
} *Polynomial;
void Initialize(Polynomial polynomial);

//放到多项式尾巴上
void Attach(int coef, int expon, Polynomial* PtrRear);
//初始化
void Initialize(Polynomial polynomial);
//根据系数矩阵和指数矩阵创建多项式链表
Polynomial createPolynomial(int *coef, int *exp, int length);
//复制一个节点
PolyNode * clonePolyNode(PolyNode source);
//多项式加法
Polynomial PolyAdd(Polynomial P1, Polynomial P2);
//多项式乘法
Polynomial PolyMul(Polynomial P1, Polynomial P2);
//从标准输入读入多项式
Polynomial ReadPoly();
//打印一个项
void printPolyNode(PolyNode node);
//打印多项式
void printPolynomial(Polynomial poly);
