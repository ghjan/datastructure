#include "stdafx.h"
#include<iostream>
#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#include<algorithm>
#include "polymath.h"
#include "sort.h"
#include "utils.h"

//�ŵ�β����
void Attach(int coef, int expon, Polynomial* PtrRear)
{
	/*�����ڱ���������Ҫ�ı䵱ǰ�ṹ���ʽβ��ָ���ֵ��*/
	/*���Ժ������ݽ������ǽ��ָ��ĵ�ַ��*PtrRearָ��β��*/

	Polynomial poly = (Polynomial)malloc(sizeof(PolyNode));/*�����½��*/
	poly->coef = coef;
	poly->expon = expon;
	/*��Pָ����½����뵽��ǰ������ʽβ��ĺ���*/
	(*PtrRear)->link = poly;
	*PtrRear = poly;/*�޸�PtrRearֵ*/
}

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


//����ʽ�˷�
Polynomial PolyMul(Polynomial P1, Polynomial P2)
{
	PolyNode *tail2 = P2;
	int len1 = sizeof(P1) / sizeof(PolyNode);
	int len2 = sizeof(P2) / sizeof(PolyNode);
	Polynomial *pp = new Polynomial[len2];
	int index = 0;
	while (tail2 != NULL) {
		PolyNode *tail1 = P1;
		Polynomial polynomial = (Polynomial)malloc(sizeof(PolyNode));
		Initialize(polynomial);
		PolyNode *tail = polynomial;
		pp[index++] = polynomial;

		for (int i = 0; tail1 != NULL && i < len1; ++i) {
			PolyNode * node = (PolyNode *)malloc(sizeof(PolyNode));
			node->coef = tail1->coef*tail2->coef;
			node->expon = tail1->expon + tail2->expon;
			node->link = NULL;
			tail->link = node;
			tail = node;
			tail1 = tail1->link;
		}
		tail = tail->link;
	}

	Polynomial sum = NULL;
	for (int k = 0; k < len2; k += 2)
	{
		if (k == 0) {
			sum = PolyAdd(pp[k], pp[k + 1]);
		}
		else {
			sum = PolyAdd(sum, pp[k]);
		}
	}
	return sum;
}

//��ʼ��
void Initialize(Polynomial polynomial) {
	PolyNode *head = (PolyNode *)malloc(sizeof(PolyNode));
	head->link = NULL;
	polynomial->link = head;
}


//����ϵ�������ָ�����󴴽�����ʽ����
Polynomial createPolynomial(int *coef, int *exp, int length) {
	Polynomial polynomial = (Polynomial)malloc(sizeof(PolyNode));
	Initialize(polynomial);
	PolyNode *tail = polynomial;


	for (int i = 0; i < length; ++i) {
		PolyNode * node = (PolyNode *)malloc(sizeof(PolyNode));
		node->coef = coef[i];
		node->expon = exp[i];
		node->link = NULL;
		tail->link = node;
		tail = node;
	}
	return polynomial->link;
}


//����һ���ڵ�
PolyNode * clonePolyNode(PolyNode source) {
	PolyNode *node = (PolyNode *)malloc(sizeof(PolyNode));
	node->coef = source.coef;
	node->expon = source.expon;
	return node;
}

//��ӡһ����
void printPolyNode(PolyNode node) {
	printf("%dx^%d", node.coef, node.expon);
}

//��ӡ����ʽ
void printPolynomial(Polynomial poly) {
	PolyNode *tail = poly;
	while (tail != NULL) {
		printPolyNode(*tail);
		tail = tail->link;
		if (tail != NULL) {
			printf(" + ");
		}
	}
	puts("\n");
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

int polymul_demo()
{
	//���
	Polynomial mul = PolyMul(p1, p2);
	printPolynomial(mul);
}
*/

int polyadd_demo()
{
	//ϵ��
	int coef1[5] = { 2, 3, 5, -3, 9 };
	//ָ��
	int exp1[5] = { 2, 5, 4, 7, 6 };

	int *new_order = new int[5];
	for (int i = 0; i < 5; i++) {
		new_order[i] = i;
	}
	sort_ordered(exp1, 5, new_order);
	printf("������exp1����Ϊ��\n");
	print_array(exp1, 5);
	int *coef1_o = clone_ordered(coef1, 5, new_order);
	printf("������coef1_o����Ϊ��\n");
	print_array(coef1_o, 5);
	Polynomial p1 = createPolynomial(coef1_o, exp1, 5);
	puts("------ p1: ------");
	printPolynomial(p1);

	int coef2[6] = { 5, 4, 5, -6, 1, 5 };
	int exp2[6] = { 3, 8, 4, 6, 2, 7 };

	int *new_order2 = new int[6];
	for (int i = 0; i < 6; i++) {
		new_order2[i] = i;
	}
	sort_ordered(exp2, 6, new_order2);
	printf("������exp2����Ϊ��\n");
	print_array(exp2, 6);
	int *coef2_o = clone_ordered(coef2, 6, new_order2);
	printf("������coef2_o����Ϊ��\n");
	print_array(coef2_o, 6);
	Polynomial p2 = createPolynomial(coef2_o, exp2, 6);
	puts("------ p2: ------");
	printPolynomial(p2);

	puts("===== (p1+p2) =====");
	//���
	Polynomial sum = PolyAdd(p1, p2);
	printPolynomial(sum);
	return 0;
}

int polymath_demo()
{

	polyadd_demo();
	return 0;
}
