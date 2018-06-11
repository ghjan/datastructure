#include "stdafx.h"
#include<iostream>
#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#include<algorithm>
#include "polymath.h"
#include "sort.h"
#include "utils.h"

//放到尾巴上
void Attach(int coef, int expon, Polynomial* PtrRear)
{
	/*由于在本函数中需要改变当前结构表达式尾项指针的值，*/
	/*所以函数传递进来的是结点指针的地址，*PtrRear指向尾项*/

	Polynomial poly = (Polynomial)malloc(sizeof(PolyNode));/*申请新结点*/
	poly->coef = coef;
	poly->expon = expon;
	/*将P指向的新结点插入到当前结果表达式尾项的后面*/
	(*PtrRear)->link = poly;
	*PtrRear = poly;/*修改PtrRear值*/
}

Polynomial PolyAdd(Polynomial P1, Polynomial P2)
{
	Polynomial front, rear, temp;
	int sum;
	rear = (Polynomial)malloc(sizeof(PolyNode));
	front = rear; /*由front记录结果多项式链表头结点*/
	while (P1 && P2)/*当两个多项式都有非零项待处理时*/
	{
		switch (Compare(P1->expon, P2->expon))
		{
		case 1://P1中的数据项指数较大
			Attach(P1->coef, P1->expon, &rear);
			P1 = P1->link;
			break;
		case -1://P2中的数据项指数较大
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
	/*将未处理完的另一个多项式的所有节点依次复制到结果多项式中去*/
	for (; P1; P1 = P1->link) Attach(P1->coef, P1->expon, &rear);
	for (; P2; P2 = P2->link) Attach(P2->coef, P2->expon, &rear);
	rear->link = NULL;
	temp = front;
	front = front->link;/*令front指向结果多项式第一个非零项*/
	free(temp);/*释放临时空表头结点*/
	return front;
}


//多项式乘法
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

//初始化
void Initialize(Polynomial polynomial) {
	PolyNode *head = (PolyNode *)malloc(sizeof(PolyNode));
	head->link = NULL;
	polynomial->link = head;
}


//跟据系数矩阵和指数矩阵创建多项式链表
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


//复制一个节点
PolyNode * clonePolyNode(PolyNode source) {
	PolyNode *node = (PolyNode *)malloc(sizeof(PolyNode));
	node->coef = source.coef;
	node->expon = source.expon;
	return node;
}

//打印一个项
void printPolyNode(PolyNode node) {
	printf("%dx^%d", node.coef, node.expon);
}

//打印多项式
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
//将两个多项式相减
void subPolynomial(Polynomial listA, Polynomial listB) {
	//操作多项式A的指针
	PolyNode * PolyNodeA = listA->link;
	//操作多项式B的指针
	PolyNode * PolyNodeB = listB->link;

	while (PolyNodeB != NULL) {
		//系数变为相反数再插入，达到相减的效果
		PolyNodeB->coef *= -1;
		//插入节点，将PolyNodeA更新到处于插入位置的节点
		PolyNodeA = insertPolyNode(PolyNodeA, PolyNodeB);
		//PolyNodeB指针后移
		PolyNodeB = PolyNodeB->link;
	}
}

int polymul_demo()
{
	//相乘
	Polynomial mul = PolyMul(p1, p2);
	printPolynomial(mul);
}
*/

int polyadd_demo()
{
	//系数
	int coef1[5] = { 2, 3, 5, -3, 9 };
	//指数
	int exp1[5] = { 2, 5, 4, 7, 6 };

	int *new_order = new int[5];
	for (int i = 0; i < 5; i++) {
		new_order[i] = i;
	}
	sort_ordered(exp1, 5, new_order);
	printf("排序后的exp1数组为：\n");
	print_array(exp1, 5);
	int *coef1_o = clone_ordered(coef1, 5, new_order);
	printf("排序后的coef1_o数组为：\n");
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
	printf("排序后的exp2数组为：\n");
	print_array(exp2, 6);
	int *coef2_o = clone_ordered(coef2, 6, new_order2);
	printf("排序后的coef2_o数组为：\n");
	print_array(coef2_o, 6);
	Polynomial p2 = createPolynomial(coef2_o, exp2, 6);
	puts("------ p2: ------");
	printPolynomial(p2);

	puts("===== (p1+p2) =====");
	//相加
	Polynomial sum = PolyAdd(p1, p2);
	printPolynomial(sum);
	return 0;
}

int polymath_demo()
{

	polyadd_demo();
	return 0;
}
