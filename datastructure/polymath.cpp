#include "stdafx.h"
#include<iostream>
#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#include<algorithm>
#include "polymath.h"
#include "sort.h"
#include "utils.h"

//�ŵ�����ʽβ����
void Attach(int coef, int expon, Polynomial* PtrRear)
{
	/*�����ڱ���������Ҫ�ı䵱ǰ�ṹ���ʽβ��ָ���ֵ��*/
	/*���Ժ������ݽ������ǽ��ָ��ĵ�ַ��*PtrRearָ��β��*/

	Polynomial poly = (Polynomial)malloc(sizeof(PolyNode));/*�����½��*/
	poly->coef = coef;
	poly->expon = expon;
	poly->link = NULL;
	/*��Pָ����½����뵽��ǰ������ʽβ��ĺ���*/
	(*PtrRear)->link = poly;
	*PtrRear = poly;/*�޸�PtrRearֵ*/
}

//����ʽ�ӷ�
Polynomial PolyAdd(Polynomial P1, Polynomial P2)
{
	Polynomial front, rear, temp;
	int sum;
	rear = (Polynomial)malloc(sizeof(PolyNode));
	front = rear; /*��front��¼�������ʽ����ͷ���*/
	while (P1 && P2)/*����������ʽ���з����������ʱ*/
	{
		switch (Compare(P1->expon, P2->expon))
		{
		case 1://P1�е�������ָ���ϴ�
			Attach(P1->coef, P1->expon, &rear);
			P1 = P1->link;
			break;
		case -1://P2�е�������ָ���ϴ�
			Attach(P2->coef, P2->expon, &rear);
			P2 = P2->link;
			break;
		case 0:
			sum = P1->coef + P2->coef;
			if (sum)
			{
				Attach(sum, P1->expon, &rear);
				P1 = P1->link;
				P2 = P2->link;
				break;
			}
		}
	}
	/*��δ���������һ������ʽ�����нڵ����θ��Ƶ��������ʽ��ȥ*/
	for (; P1; P1 = P1->link) Attach(P1->coef, P1->expon, &rear);
	for (; P2; P2 = P2->link) Attach(P2->coef, P2->expon, &rear);
	rear->link = NULL;
	temp = front;
	front = front->link;/*��frontָ��������ʽ��һ��������*/
	free(temp);/*�ͷ���ʱ�ձ�ͷ���*/
	return front;
}

//�ӱ�׼����������ʽ
Polynomial ReadPoly()
{
	Polynomial p, rear, t;
	int c, e, N;
#ifdef  _DEBUG
	printf("�������ʽ��Ŀ��\n");
	printf("�������ʽ���ϵ�� ָ��\n");
#endif
	scanf_s("%d", &N, 5);
	p = (Polynomial)malloc(sizeof(PolyNode));
	p->link = NULL;
	rear = p;
	while (N--) {
		scanf_s("%d %d", &c, &e, 10);
		Attach(c, e, &rear);
	}
	t = p; p = p->link; free(t);//�ͷ���ʱͷ�ڵ�
#ifdef  _DEBUG
	printPolynomial(p, false);
#endif
	return p;
}

//����ʽ�˷�
Polynomial PolyMul(Polynomial P1, Polynomial P2)
{
	PolyNode *tail2 = P2;

	int index = 0;
	Polynomial result = NULL;
	bool flag = false;
	while (tail2 != NULL) {
		PolyNode *tail1 = P1;
		Polynomial polynomial = (Polynomial)malloc(sizeof(PolyNode));
		Initialize(polynomial);
		PolyNode *tail = polynomial;

		for (int i = 0; tail1 != NULL; ++i) {
			PolyNode * node = (PolyNode *)malloc(sizeof(PolyNode));
			node->coef = tail1->coef*tail2->coef;
			node->expon = tail1->expon + tail2->expon;
			node->link = NULL;
			tail->link = node;
			tail = node;
			tail1 = tail1->link;
		}
		tail = polynomial; polynomial = polynomial->link; free(tail);//�ͷ���ʱ��ͷ
		if (!flag) {
			result = polynomial;
			flag = true;
		}
		else {
			result = PolyAdd(result, polynomial);
		}
		tail2 = tail2->link;

	}

	return result;
}

//��ʼ��
void Initialize(Polynomial polynomial) {
	PolyNode *head = (PolyNode *)malloc(sizeof(PolyNode));
	head->link = NULL;
	polynomial->link = head;
}


//����ϵ�������ָ�����󴴽�����ʽ����
Polynomial createPolynomial(int *coef, int *exp, int length) {

	int *new_order = new int[length];
	for (int i = 0; i < length; i++) {
		new_order[i] = i;
	}
	sort_ordered(exp, length, new_order);
	printf("������exp����Ϊ��\n");
	print_array(exp, length);
	int *coef_o = clone_ordered(coef, length, new_order);
	printf("������coef_o����Ϊ��\n");
	print_array(coef_o, length);

	Polynomial polynomial = (Polynomial)malloc(sizeof(PolyNode));
	Initialize(polynomial);
	PolyNode *tail = polynomial;


	for (int i = 0; i < length; ++i) {
		PolyNode * node = (PolyNode *)malloc(sizeof(PolyNode));
		node->coef = coef_o[i];
		node->expon = exp[i];
		node->link = NULL;
		tail->link = node;
		tail = node;
	}
	delete[]new_order;
	delete[]coef_o;
	return polynomial->link;
}

Polynomial clonePolymialOrdered(Polynomial poly)
{
	int length = 0;
	PolyNode *tail = poly;
	while (tail != NULL) {
		length++;
	}

	int *new_order = new int[length];
	for (int i = 0; i < length; i++) {
		new_order[i] = i;
	}
	int *exp = new int[length],
		*coef = new int[length];
	tail = poly;
	for (int i = 0; i < length && tail; i++) {
		exp[i] = tail->expon;
		coef[i] = tail->coef;
		tail = tail->link;
	}
	delete[]new_order;
	Polynomial  polyCreated = createPolynomial(coef, exp, length);
	delete[]exp;
	delete[]coef;
	return polyCreated;
}

void PolySort(Polynomial poly) {
	int length = 0;
	PolyNode *tail = poly;
	while (tail != NULL) {
		length++;
		tail = tail->link;
	}

	int *new_order = new int[length];
	for (int i = 0; i < length; i++) {
		new_order[i] = i;
	}
	int *exp = new int[length],
		*coef = new int[length];
	tail = poly;
	for (int i = 0; i < length && tail; i++) {
		exp[i] = tail->expon;
		coef[i] = tail->coef;
		tail = tail->link;
	}

	sort_ordered(exp, length, new_order);
	int *coef_o = clone_ordered(coef, length, new_order);
#ifdef  _DEBUG
	printf("������exp����Ϊ��\n");
	print_array(exp, length);
	printf("������coef_o����Ϊ��\n");
	print_array(coef_o, length);
#endif

	tail = poly;
	for (int i = 0; i < length && tail; i++) {
		tail->expon = exp[i];
		tail->coef = coef_o[i];
		tail = tail->link;
	}
	delete[]new_order;
	delete[]exp;
	delete[]coef;
	delete[]coef_o;
}


//����һ���ڵ�
PolyNode * clonePolyNode(PolyNode source) {
	PolyNode *node = (PolyNode *)malloc(sizeof(PolyNode));
	node->coef = source.coef;
	node->expon = source.expon;
	return node;
}

//��ӡһ����
void printPolyNode(PolyNode node, bool simple) {
	if (simple) {
		printf("%d %d ", node.coef, node.expon);
	}
	else {
		printf("%dx^%d", node.coef, node.expon);
	}
}

//��ӡ����ʽ
void printPolynomial(Polynomial poly, bool simple) {
	PolyNode *tail = poly;
	while (tail != NULL) {
		printPolyNode(*tail, simple);
		tail = tail->link;
		if (tail != NULL && !simple) {
			printf(" + ");
		}
	}
	printf("\n");
}

/*
//����������ʽ���
void subPolynomial(Polynomial listA, Polynomial listB) {
	//��������ʽA��ָ��
	PolyNode * PolyNodeA = listA->link;
	//��������ʽB��ָ��
	PolyNode * PolyNodeB = listB->link;

	while (PolyNodeB != NULL) {
		//ϵ����Ϊ�෴���ٲ��룬�ﵽ�����Ч��
		PolyNodeB->coef *= -1;
		//����ڵ㣬��PolyNodeA���µ����ڲ���λ�õĽڵ�
		PolyNodeA = insertPolyNode(PolyNodeA, PolyNodeB);
		//PolyNodeBָ�����
		PolyNodeB = PolyNodeB->link;
	}
}

*/

int polyadd_demo(Polynomial p1, Polynomial p2)
{
	/*
	//ϵ��
	int coef1[5] = { 2, 3, 5, -3, 9 };
	//ָ��
	int exp1[5] = { 2, 5, 4, 7, 6 };

	Polynomial p1 = createPolynomial(coef1, exp1, 5);
	puts("------ p1: ------");
	#ifdef  _DEBUG
	printPolynomial(p1, false);
	#else
	printPolynomial(p1, true);
	#endif

	int coef2[6] = { 5, 4, 5, -6, 1, 5 };
	int exp2[6] = { 3, 8, 4, 6, 2, 7 };

	Polynomial p2 = createPolynomial(coef2, exp2, 6);
	puts("------ p2: ------");
	#ifdef  _DEBUG
	printPolynomial(p2, false);
	#else
	printPolynomial(p2, true);
	#endif
	puts("===== (p1+p2) =====");
	*/
	//���
	Polynomial sum = PolyAdd(p1, p2);
#ifdef  _DEBUG
	printPolynomial(sum, false);
#else
	printPolynomial(sum, true);
#endif
	return 0;
}

int polymul_demo(Polynomial p1, Polynomial p2)
{

	//���
	Polynomial mul = PolyMul(p1, p2);
#ifdef  _DEBUG
	printPolynomial(mul, false);
#else
	printPolynomial(mul, true);
#endif
	return 0;
}

int polymath_demo()
{
	Polynomial p1 = ReadPoly();
	Polynomial p2 = ReadPoly();
	PolySort(p1);
	PolySort(p2);
#ifdef  _DEBUG
	printf("--------polymul_demo----");
#endif
	polymul_demo(p1, p2);

#ifdef  _DEBUG
	printf("--------polyadd_demo----");
#endif
	polyadd_demo(p1, p2);
	return 0;
}
