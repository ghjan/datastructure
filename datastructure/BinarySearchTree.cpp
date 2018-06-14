#include "stdafx.h"
#include <iostream>
using namespace std;
#include "BinarySearchTree.h"
//查找方法（递归）
BinarySearchTree *find(myType element, BinarySearchTree *T)
{
	if (T == NULL)
		return NULL;
	if (strcmp(element, T->element) < 0)   //如果小于根节点值则去左孩子查找
		return find(element, T->lchild);
	else if (strcmp(element, T->element) > 0)//如果大于根节点值则去左孩子查找
		return find(element, T->rchild);
	else
		return T;
}

//查找方法（迭代）
BinarySearchTree *iter_find(myType element, BinarySearchTree *T)
{
	while (T) {
		if (strcmp(element, T->element) < 0)   //如果小于根节点值则去左孩子查找
			T = T->lchild;
		else if (strcmp(element, T->element) > 0)//如果大于根节点值则去左孩子查找
			T = T->rchild;
		else
			return T;
	}
	return NULL;
}

//最小值（递归）
BinarySearchTree *findMin(BinarySearchTree *T)
{
	if (T == NULL)
		return NULL;
	else if (T->lchild == NULL)
		return T;
	else
		return findMin(T->lchild);
}

//最大值（迭代）
BinarySearchTree *findMax(BinarySearchTree *T)
{
	if (T != NULL)
		while (T->rchild != NULL)
			T = T->rchild;
	return T;
}

//插入（递归）
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

//删除(递归)
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
		//找到该元素，开始删除
	}
	else if (T->lchild && T->rchild) {
		//有两个子树的情况
		tmpNode = findMin(T->rchild);//右子树的最小值
		T->element = tmpNode->element;
		T->rchild = remove(T->element, T->rchild);
	}
	else {
		//有一个或没有子树的情况
		tmpNode = T;
		if (T->lchild == NULL)
			T = T->rchild;  //绕过被删除的节点
		else if (T->rchild == NULL)
			T = T->lchild;
		free(tmpNode);
	}

	return T;
}
//以上代码在删除有两个子树的情况效率不高，因为查找和删除右子树中最小的节点遍历了两趟。

//中序遍历二叉查找树  
//打印的应该是一个递增的序列  
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

//先序遍历二叉查找树  
//因为先序遍历+中序遍历 可以唯一确定一棵树，等下可以验证树是否正确  
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
	printf("中序遍历二叉查找树,打印的应该是一个递增的序列\n");
	middleOrder(root);
	printf("\n 先序遍历\n");
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
