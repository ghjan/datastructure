#include "stdafx.h"
#include <iostream>
using namespace std;
#include "BinarySearchTree.h"
//���ҷ������ݹ飩
BinarySearchTree *find(myType element, BinarySearchTree *T)
{
	if (T == NULL)
		return NULL;
	if (strcmp(element, T->element) < 0)   //���С�ڸ��ڵ�ֵ��ȥ���Ӳ���
		return find(element, T->lchild);
	else if (strcmp(element, T->element) > 0)//������ڸ��ڵ�ֵ��ȥ���Ӳ���
		return find(element, T->rchild);
	else
		return T;
}

//���ҷ�����������
BinarySearchTree *iter_find(myType element, BinarySearchTree *T)
{
	while (T) {
		if (strcmp(element, T->element) < 0)   //���С�ڸ��ڵ�ֵ��ȥ���Ӳ���
			T = T->lchild;
		else if (strcmp(element, T->element) > 0)//������ڸ��ڵ�ֵ��ȥ���Ӳ���
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
	else if (strcmp(element, T->element) < 0) {
		T->lchild = remove(element, T->lchild);
	}
	else if (strcmp(element, T->element) > 0) {
		T->rchild = remove(element, T->rchild);
		//�ҵ���Ԫ�أ���ʼɾ��
	}
	else if (T->lchild && T->rchild) {
		//���������������
		tmpNode = findMin(T->rchild);//����������Сֵ
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
void middleOrder(BinarySearchTree *T) {
	if (T == NULL) {
		return;
	}
	else {

		middleOrder(T->lchild);
		printf("%s ", T->element);
		middleOrder(T->rchild);
	}
}

//����������������  
//��Ϊ�������+������� ����Ψһȷ��һ���������¿�����֤���Ƿ���ȷ  
void preOrder(BinarySearchTree *T) {

	if (T == NULL) {
		return;
	}
	else {

		printf("%s ", T->element);
		preOrder(T->lchild);
		preOrder(T->rchild);
	}
}

void examine(BinarySearchTree *root) {
	printf("����������������,��ӡ��Ӧ����һ������������\n");
	middleOrder(root);
	printf("\n �������\n");
	preOrder(root);
	printf("\n");
	printf("findMax:%s\n", findMax(root)->element);
	printf("findMin:%s\n", findMin(root)->element);

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
	examine(root);

	remove(month[2],root);
	examine(root);
	remove(month[3], root);
	examine(root);
	remove(month[8], root);
	examine(root);

	return 0;
}
