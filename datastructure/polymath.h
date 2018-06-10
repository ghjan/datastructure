#pragma once
typedef struct PolyNode
{
	int coef;       //系数  
	int expon;  //指数  
	struct PolyNode *link;  //指向下一个结点的指针  
} *Polynomial;

void Attach(int coef, int expon, Polynomial* PtrRear);
Polynomial PolyAdd(Polynomial P1, Polynomial P2);
int polymath_demo();