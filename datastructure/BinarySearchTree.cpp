#include "stdafx.h"
#include <iostream>
using namespace std;
#include "BinarySearchTree.h"
//���ҷ������ݹ飩
BinarySearchTree *find(myType element, BinarySearchTree *T)
{
	if (T == NULL)
		return NULL;
	if (element < T->element)   //���С�ڸ��ڵ�ֵ��ȥ���Ӳ���
		return find(element, T->lchild);
	else if (element > T->element)//������ڸ��ڵ�ֵ��ȥ���Ӳ���
		return find(element, T->rchild);
	else
		return T;
}

//���ҷ�����������
BinarySearchTree *iter_find(myType element, BinarySearchTree *T)
{
	while (T) {
		if (element < T->element)   //���С�ڸ��ڵ�ֵ��ȥ���Ӳ���
			T = T->lchild;
		else if (element > T->element)//������ڸ��ڵ�ֵ��ȥ���Ӳ���
			T = T->rchild;
		else
			return T;
	}
	return NULL;
}

//��Сֵ���ݹ飩
BinarySearchTree *findMin(BinarySearchTree *T)
{
	if (T == NULL)
		return NULL;
	else if (T->lchild == NULL)
		return T;
	else
		return findMin(T->lchild);
}

//���ֵ��������
BinarySearchTree *findMax(BinarySearchTree *T)
{
	if (T != NULL)
		while (T->rchild != NULL)
			T = T->rchild;
	return T;
}

//���루�ݹ飩
BinarySearchTree *insert(myType element, BinarySearchTree *T)
{
	if (T == NULL) {
		T = (BinarySearchTree *)malloc(sizeof(struct treeNode));
		T->element = element;
		T->lchild = NULL;
		T->rchild = NULL;
	}
	else if (strcmp(element, T->element) < 0) {
		T->lchild = insert(element, T->lchild);
	}
	else if (strcmp(element, T->element) > 0) {
		T->rchild = insert(element, T->rchild);
	}

	return T;
}

//ɾ��(�ݹ�)
BinarySearchTree *remove(myType element, BinarySearchTree *T)
{
	BinarySearchTree *tmpNode;

	if (T == NULL) {
		printf("NOT FOUNT\n");
	}
	else if (element < T->element) {
		T->lchild = remove(element, T->lchild);
	}
	else if (element > T->element) {
		T->rchild = remove(element, T->rchild);
		//�ҵ���Ԫ�أ���ʼɾ��
	}
	else if (T->lchild && T->rchild) {
		//���������������
		tmpNode = findMin(T->rchild);
		T->element = tmpNode->element;
		T->rchild = remove(T->element, T->rchild);
	}
	else {
		//��һ����û�����������
		tmpNode = T;
		if (T->lchild == NULL)
			T = T->rchild;  //�ƹ���ɾ���Ľڵ�
		else if (T->rchild == NULL)
			T = T->lchild;
		free(tmpNode);
	}

	return T;
}
//���ϴ�����ɾ�����������������Ч�ʲ��ߣ���Ϊ���Һ�ɾ������������С�Ľڵ���������ˡ�

//����������������  
//��ӡ��Ӧ����һ������������  
void MiddleOrder(BinarySearchTree *T) {
	if (T == NULL) {
		return;
	}
	else {

		MiddleOrder(T->lchild);
		printf("%s ", T->element);
		MiddleOrder(T->rchild);
	}
}

//����������������  
//��Ϊ�������+������� ����Ψһȷ��һ���������¿�����֤���Ƿ���ȷ  
void PreOrder(BinarySearchTree *T) {

	if (T == NULL) {
		return;
	}
	else {

		printf("%s ", T->element);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}

int BinarySearchTree_demo()
{
	const char   *month[] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
	BinarySearchTree *root = NULL;
	for (int i = 0; i < 12; i++) {
		if (i == 0)
			root = insert(month[i], root);
		else {
			BinarySearchTree *tree = root;
			insert(month[i], tree);
		}
	}

	printf("����������������,��ӡ��Ӧ����һ������������\n");
	MiddleOrder(root);
	printf("\n �������\n");
	PreOrder(root);
	printf("\n");
	printf("findMax:%s\n", findMax(root)->element);
	printf("findMin:%s\n", findMin(root)->element);

	return 0;
}
