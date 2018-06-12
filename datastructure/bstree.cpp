/**
* ����������(C����): C����ʵ�ֵĶ�����������
*
* @author skywang
* @date 2013/11/07
*/
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "bstree.h"
#include "queue_bstree.h"

/*
* ǰ�����"������"
*/
void preorder_bstree(BSTree tree)
{
	if (tree != NULL)
	{
		printf("%d ", tree->key);
		preorder_bstree(tree->left);
		preorder_bstree(tree->right);
	}
}

/*
* �������"������"
*/
void inorder_bstree(BSTree tree)
{
	if (tree != NULL)
	{
		inorder_bstree(tree->left);
		printf("%d ", tree->key);
		inorder_bstree(tree->right);
	}
}

/*
* �������"������"
*/
void postorder_bstree(BSTree tree)
{
	if (tree != NULL)
	{
		postorder_bstree(tree->left);
		postorder_bstree(tree->right);
		printf("%d ", tree->key);
	}
}


/*
* �㼶����"������"
*/
void levelorder_bstree(BSTree tree)
{
	LinkQueue_bst *Q = (LinkQueue_bst*)malloc(sizeof(LinkQueue_bst));
	BSTree T= tree;
	if (!tree)return;
	InitQueue(Q);
	EnQueue(Q, *T);
	while (!QueueEmpty(*Q)) {
		ElemType *elem=DeQueue(Q);
		printf("%d ", elem->key);
		if (elem->left)EnQueue(Q, *elem->left);
		if (elem->right)EnQueue(Q, *elem->right);
	}
	DestroyQueue(Q);
}

/*
* �������"������"��Ҷ�ӽ��
*/
void inorder_bstree_leaf(BSTree tree)
{
	if (tree != NULL)
	{
		inorder_bstree_leaf(tree->left);
		if(!tree->left && !tree->right)
			printf("%d ", tree->key);
		inorder_bstree_leaf(tree->right);
	}
}
/*
* (�ݹ�ʵ��)����"������x"�м�ֵΪkey�Ľڵ�
*/
BSTreeNode* bstree_search(BSTree x, Type key)
{
	if (x == NULL || x->key == key)
		return x;

	if (key < x->key)
		return bstree_search(x->left, key);
	else
		return bstree_search(x->right, key);
}

/*
* (�ǵݹ�ʵ��)����"������x"�м�ֵΪkey�Ľڵ�
*/
BSTreeNode* iterative_bstree_search(BSTree x, Type key)
{
	while ((x != NULL) && (x->key != key))
	{
		if (key < x->key)
			x = x->left;
		else
			x = x->right;
	}

	return x;
}

/*
* ������С��㣺����treeΪ�����Ķ���������С��㡣
*/
BSTreeNode* bstree_minimum(BSTree tree)
{
	if (tree == NULL)
		return NULL;

	while (tree->left != NULL)
		tree = tree->left;
	return tree;
}

/*
* ��������㣺����treeΪ�����Ķ�����������㡣
*/
BSTreeNode* bstree_maximum(BSTree tree)
{
	if (tree == NULL)
		return NULL;

	while (tree->right != NULL)
		tree = tree->right;
	return tree;
}

/*
* �ҽ��(x)�ĺ�̽�㡣��������"������������ֵ���ڸý��"��"��С���"��
*/
BSTreeNode* bstree_successor(BSTreeNode *x)
{
	// ���x�����Һ��ӣ���"x�ĺ�̽��"Ϊ "�����Һ���Ϊ������������С���"��
	if (x->right != NULL)
		return bstree_minimum(x->right);

	// ���xû���Һ��ӡ���x���������ֿ��ܣ�
	// (01) x��"һ������"����"x�ĺ�̽��"Ϊ "���ĸ����"��
	// (02) x��"һ���Һ���"�������"x����͵ĸ���㣬���Ҹø����Ҫ��������"���ҵ������"��͵ĸ����"����"x�ĺ�̽��"��
	BSTreeNode* y = x->parent;
	while ((y != NULL) && (x == y->right))
	{
		x = y;
		y = y->parent;
	}

	return y;
}

/*
* �ҽ��(x)��ǰ����㡣��������"������������ֵС�ڸý��"��"�����"��
*/
BSTreeNode* bstree_predecessor(BSTreeNode *x)
{
	// ���x�������ӣ���"x��ǰ�����"Ϊ "��������Ϊ���������������"��
	if (x->left != NULL)
		return bstree_maximum(x->left);

	// ���xû�����ӡ���x���������ֿ��ܣ�
	// (01) x��"һ���Һ���"����"x��ǰ�����"Ϊ "���ĸ����"��
	// (01) x��"һ������"�������"x����͵ĸ���㣬���Ҹø����Ҫ�����Һ���"���ҵ������"��͵ĸ����"����"x��ǰ�����"��
	BSTreeNode* y = x->parent;
	while ((y != NULL) && (x == y->left))
	{
		x = y;
		y = y->parent;
	}

	return y;
}

/*
* ���������ض�������㡣
*
* ����˵����
*     key �Ǽ�ֵ��
*     parent �Ǹ���㡣
*     left �����ӡ�
*     right ���Һ��ӡ�
*/
static BSTreeNode* create_bstree_BSTreeNode(Type key, BSTreeNode *parent, BSTreeNode *left, BSTreeNode* right)
{
	BSTreeNode* p;

	if ((p = (BSTreeNode *)malloc(sizeof(BSTreeNode))) == NULL)
		return NULL;
	p->key = key;
	p->left = left;
	p->right = right;
	p->parent = parent;

	return p;
}

/*
* �������뵽��������
*
* ����˵����
*     tree �������ĸ����
*     z ����Ľ��
* ����ֵ��
*     ���ڵ�
  ˵������Ѱ�Ҳ���λ��parent�ڵ㣬����Ϊleft����right�ӽڵ�
*/
static BSTreeNode* bstree_insert(BSTree tree, BSTreeNode *z)
{
	BSTreeNode *y = NULL;
	BSTreeNode *x = tree;

	// ����z�Ĳ���λ��
	while (x != NULL)
	{
		y = x;
		if (z->key < x->key)
			x = x->left;
		else
			x = x->right;
	}

	z->parent = y;
	if (y == NULL)
		tree = z;
	else if (z->key < y->key)
		y->left = z;
	else
		y->right = z;

	return tree;
}

/*
* �½����(key)����������뵽��������
* ��������Ķ���ӿڣ����������ǣ������������ڵ㣬key�ǽڵ��ֵ�������ز���ڵ��ĸ��ڵ�
* ����˵����
*     tree �������ĸ����
*     key ������ļ�ֵ
* ����ֵ��
*     ���ڵ�
*/
BSTreeNode* insert_bstree(BSTree tree, Type key)
{
	BSTreeNode *z;    // �½����

				// ����½����ʧ�ܣ��򷵻ء�
	if ((z = create_bstree_BSTreeNode(key, NULL, NULL, NULL)) == NULL)
		return tree;

	return bstree_insert(tree, z);
}

/*
* ɾ�����(z)�������ظ��ڵ�
*
* ����˵����
*     tree �������ĸ����
*     z ɾ���Ľ��
* ����ֵ��
*     ���ڵ�
*/
static BSTreeNode* bstree_delete(BSTree tree, BSTreeNode *z)
{
	BSTreeNode *x = NULL;
	BSTreeNode *y = NULL;

	if ((z->left == NULL) || (z->right == NULL))
		y = z;
	else
		y = bstree_successor(z);

	if (y->left != NULL)
		x = y->left;
	else
		x = y->right;

	if (x != NULL)
		x->parent = y->parent;

	if (y->parent == NULL)
		tree = x;
	else if (y == y->parent->left)
		y->parent->left = x;
	else
		y->parent->right = x;

	if (y != z)
		z->key = y->key;

	if (y != NULL)
		free(y);

	return tree;
}

/*
* ɾ�����(keyΪ�ڵ�ļ�ֵ)�������ظ��ڵ�
*
* ����˵����
*     tree �������ĸ����
*     z ɾ���Ľ��
* ����ֵ��
*     ���ڵ�
*/
BSTreeNode* delete_bstree(BSTree tree, Type key)
{
	BSTreeNode *z;

	if ((z = bstree_search(tree, key)) != NULL)
		tree = bstree_delete(tree, z);

	return tree;
}

/*
* ���ٶ�����
*/
void destroy_bstree(BSTree tree)
{
	if (tree == NULL)
		return;

	if (tree->left != NULL)
		destroy_bstree(tree->left);
	if (tree->right != NULL)
		destroy_bstree(tree->right);

	free(tree);
}

/*
* ��ӡ"������"
*
* tree       -- �������Ľڵ�
* key        -- �ڵ�ļ�ֵ
* direction  --  0����ʾ�ýڵ��Ǹ��ڵ�;
*               -1����ʾ�ýڵ������ĸ���������;
*                1����ʾ�ýڵ������ĸ������Һ��ӡ�
*/
void print_bstree(BSTree tree, Type key, int direction)
{
	if (tree != NULL)
	{
		if (direction == 0)    // tree�Ǹ��ڵ�
			printf("%2d is root\n", tree->key);
		else                // tree�Ƿ�֧�ڵ�
			printf("%2d is %2d's %6s child\n", tree->key, key, direction == 1 ? "right" : "left");

		print_bstree(tree->left, tree->key, -1);
		print_bstree(tree->right, tree->key, 1);
	}
}

/*
* �������ĸ߶�
*/
int height(BSTree tree)
{
	int hl, hr, maxH;
	if (tree != NULL)
	{
		hl = height(tree->left);	//�������߶�
		hr = height(tree->right);	//�������߶�
		maxH = (hl > hr) ? hl : hr;
		return (maxH + 1);
	}

	return 0;
}
