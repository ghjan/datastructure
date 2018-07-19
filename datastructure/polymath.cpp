#include "stdafx.h"
#include<iostream>
#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#include<algorithm>
#include "polymath.h"
#include "sort.h"
#include "utils.h"

//放到多项式尾巴上
void Attach(int coef, int expon, Polynomial* PtrRear)
{
	/*由于在本函数中需要改变当前结构表达式尾项指针的值，*/
	/*所以函数传递进来的是结点指针的地址，*PtrRear指向尾项*/

	Polynomial poly = (Polynomial)malloc(sizeof(PolyNode));/*申请新结点*/
	poly->coef = coef;
	poly->expon = expon;
	poly->link = NULL;
	/*将P指向的新结点插入到当前结果表达式尾项的后面*/
	(*PtrRear)->link = poly;
	*PtrRear = poly;/*修改PtrRear值*/
}

//多项式加法
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

//从标准输入读入多项式
Polynomial ReadPoly()
{
	Polynomial p, rear, t;
	int c, e, N;
#ifdef  _DEBUG
	printf("输入多项式项目数\n");
	printf("输入多项式各项：系数 指数\n");
#endif
	scanf_s("%d", &N, 5);
	p = (Polynomial)malloc(sizeof(PolyNode));
	p->link = NULL;
	rear = p;
	while (N--) {
		scanf_s("%d %d", &c, &e, 10);
		Attach(c, e, &rear);
	}
	t = p; p = p->link; free(t);//释放临时头节点
#ifdef  _DEBUG
	printPolynomial(p, false);
#endif
	return p;
}

//多项式乘法
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
		tail = polynomial; polynomial = polynomial->link; free(tail);//释放临时的头
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

//初始化
void Initialize(Polynomial polynomial) {
	PolyNode *head = (PolyNode *)malloc(sizeof(PolyNode));
	head->link = NULL;
	polynomial->link = head;
}


//根据系数矩阵和指数矩阵创建多项式链表
Polynomial createPolynomial(int *coef, int *exp, int length) {

	int *new_order = new int[length];
	for (int i = 0; i < length; i++) {
		new_order[i] = i;
	}
	sort_ordered(exp, length, new_order);
	printf("排序后的exp数组为：\n");
	print_array(exp, length);
	int *coef_o = clone_ordered(coef, length, new_order);
	printf("排序后的coef_o数组为：\n");
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
	printf("排序后的exp数组为：\n");
	print_array(exp, length);
	printf("排序后的coef_o数组为：\n");
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


//复制一个节点
PolyNode * clonePolyNode(PolyNode source) {
	PolyNode *node = (PolyNode *)malloc(sizeof(PolyNode));
	node->coef = source.coef;
	node->expon = source.expon;
	return node;
}

//打印一个项
void printPolyNode(PolyNode node, bool simple) {
	if (simple) {
		printf("%d %d ", node.coef, node.expon);
	}
	else {
		printf("%dx^%d", node.coef, node.expon);
	}
}

//打印多项式
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

*/

int polyadd_demo(Polynomial p1, Polynomial p2)
{
	/*
	//系数
	int coef1[5] = { 2, 3, 5, -3, 9 };
	//指数
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
	//相加
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

	//相乘
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
