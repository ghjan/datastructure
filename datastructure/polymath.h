#pragma once
typedef struct PolyNode
{
	int coef;       //ϵ��  
	int expon;  //ָ��  
	struct PolyNode *link;  //ָ����һ������ָ��  
} *Polynomial;
void Initialize(Polynomial polynomial);
void Attach(int coef, int expon, Polynomial* PtrRear);
Polynomial PolyAdd(Polynomial P1, Polynomial P2);
Polynomial PolyMul(Polynomial P1, Polynomial P2);
int polyadd_demo();
int polymath_demo();