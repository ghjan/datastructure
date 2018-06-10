#pragma once
typedef struct PolyNode
{
	int coef;       //ϵ��  
	int expon;  //ָ��  
	struct PolyNode *link;  //ָ����һ������ָ��  
} *Polynomial;

void Attach(int coef, int expon, Polynomial* PtrRear);
Polynomial PolyAdd(Polynomial P1, Polynomial P2);
int polymath_demo();