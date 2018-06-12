/**
* 二叉搜索树(C语言): C语言实现的二叉搜索树。
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
* 前序遍历"二叉树"
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
* 中序遍历"二叉树"
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
* 后序遍历"二叉树"
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
* 层级遍历"二叉树"
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
* 中序遍历"二叉树"的叶子结点
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
* (递归实现)查找"二叉树x"中键值为key的节点
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
* (非递归实现)查找"二叉树x"中键值为key的节点
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
* 查找最小结点：返回tree为根结点的二叉树的最小结点。
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
* 查找最大结点：返回tree为根结点的二叉树的最大结点。
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
* 找结点(x)的后继结点。即，查找"二叉树中数据值大于该结点"的"最小结点"。
*/
BSTreeNode* bstree_successor(BSTreeNode *x)
{
	// 如果x存在右孩子，则"x的后继结点"为 "以其右孩子为根的子树的最小结点"。
	if (x->right != NULL)
		return bstree_minimum(x->right);

	// 如果x没有右孩子。则x有以下两种可能：
	// (01) x是"一个左孩子"，则"x的后继结点"为 "它的父结点"。
	// (02) x是"一个右孩子"，则查找"x的最低的父结点，并且该父结点要具有左孩子"，找到的这个"最低的父结点"就是"x的后继结点"。
	BSTreeNode* y = x->parent;
	while ((y != NULL) && (x == y->right))
	{
		x = y;
		y = y->parent;
	}

	return y;
}

/*
* 找结点(x)的前驱结点。即，查找"二叉树中数据值小于该结点"的"最大结点"。
*/
BSTreeNode* bstree_predecessor(BSTreeNode *x)
{
	// 如果x存在左孩子，则"x的前驱结点"为 "以其左孩子为根的子树的最大结点"。
	if (x->left != NULL)
		return bstree_maximum(x->left);

	// 如果x没有左孩子。则x有以下两种可能：
	// (01) x是"一个右孩子"，则"x的前驱结点"为 "它的父结点"。
	// (01) x是"一个左孩子"，则查找"x的最低的父结点，并且该父结点要具有右孩子"，找到的这个"最低的父结点"就是"x的前驱结点"。
	BSTreeNode* y = x->parent;
	while ((y != NULL) && (x == y->left))
	{
		x = y;
		y = y->parent;
	}

	return y;
}

/*
* 创建并返回二叉树结点。
*
* 参数说明：
*     key 是键值。
*     parent 是父结点。
*     left 是左孩子。
*     right 是右孩子。
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
* 将结点插入到二叉树中
*
* 参数说明：
*     tree 二叉树的根结点
*     z 插入的结点
* 返回值：
*     根节点
  说明：先寻找插入位置parent节点，再作为left或者right子节点
*/
static BSTreeNode* bstree_insert(BSTree tree, BSTreeNode *z)
{
	BSTreeNode *y = NULL;
	BSTreeNode *x = tree;

	// 查找z的插入位置
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
* 新建结点(key)，并将其插入到二叉树中
* 插入操作的对外接口，它的作用是：在树中新增节点，key是节点的值；并返回插入节点后的根节点
* 参数说明：
*     tree 二叉树的根结点
*     key 插入结点的键值
* 返回值：
*     根节点
*/
BSTreeNode* insert_bstree(BSTree tree, Type key)
{
	BSTreeNode *z;    // 新建结点

				// 如果新建结点失败，则返回。
	if ((z = create_bstree_BSTreeNode(key, NULL, NULL, NULL)) == NULL)
		return tree;

	return bstree_insert(tree, z);
}

/*
* 删除结点(z)，并返回根节点
*
* 参数说明：
*     tree 二叉树的根结点
*     z 删除的结点
* 返回值：
*     根节点
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
* 删除结点(key为节点的键值)，并返回根节点
*
* 参数说明：
*     tree 二叉树的根结点
*     z 删除的结点
* 返回值：
*     根节点
*/
BSTreeNode* delete_bstree(BSTree tree, Type key)
{
	BSTreeNode *z;

	if ((z = bstree_search(tree, key)) != NULL)
		tree = bstree_delete(tree, z);

	return tree;
}

/*
* 销毁二叉树
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
* 打印"二叉树"
*
* tree       -- 二叉树的节点
* key        -- 节点的键值
* direction  --  0，表示该节点是根节点;
*               -1，表示该节点是它的父结点的左孩子;
*                1，表示该节点是它的父结点的右孩子。
*/
void print_bstree(BSTree tree, Type key, int direction)
{
	if (tree != NULL)
	{
		if (direction == 0)    // tree是根节点
			printf("%2d is root\n", tree->key);
		else                // tree是分支节点
			printf("%2d is %2d's %6s child\n", tree->key, key, direction == 1 ? "right" : "left");

		print_bstree(tree->left, tree->key, -1);
		print_bstree(tree->right, tree->key, 1);
	}
}

/*
* 二叉树的高度
*/
int height(BSTree tree)
{
	int hl, hr, maxH;
	if (tree != NULL)
	{
		hl = height(tree->left);	//左子树高度
		hr = height(tree->right);	//右子树高度
		maxH = (hl > hr) ? hl : hr;
		return (maxH + 1);
	}

	return 0;
}
