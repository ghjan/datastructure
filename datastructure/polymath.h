#pragma once
typedef struct PolyNode
{
	int coef;       //ϵ��  
	int expon;  //ָ��  
	struct PolyNode *link;  //ָ����һ������ָ��  
} *Polynomial;
void Initialize(Polynomial polynomial);

//�ŵ�����ʽβ����
void Attach(int coef, int expon, Polynomial* PtrRear);
//��ʼ��
void Initialize(Polynomial polynomial);
//����ϵ�������ָ�����󴴽�����ʽ����
Polynomial createPolynomial(int *coef, int *exp, int length);
//����һ���ڵ�
PolyNode * clonePolyNode(PolyNode source);
//����ʽ�ӷ�
Polynomial PolyAdd(Polynomial P1, Polynomial P2);
//����ʽ�˷�
Polynomial PolyMul(Polynomial P1, Polynomial P2);
//�ӱ�׼����������ʽ
Polynomial ReadPoly();
//��ӡһ����
void printPolyNode(PolyNode node);
//��ӡ����ʽ
void printPolynomial(Polynomial poly);
