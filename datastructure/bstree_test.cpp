/**
* C 语言: 二叉查找树
*
* @author skywang
* @date 2013/11/07
*/
#include "stdafx.h"
#include<iostream>
#include <stdio.h>
#include "queue_bstree.h"
#include "bstree.h"

static int arr[] = { 1,5,4,3,2,6 };
#define TBL_SIZE(a) ( (sizeof(a)) / (sizeof(a[0])) )

BSTree init_bst_demo(int arr[], int ilen) {
	int i;
	BSTree root = NULL; // (BSTreeNode *)malloc(sizeof(BSTreeNode));
	printf("== 依次添加: \n");
	for (i = 0; i<ilen; i++)
	{
		printf("%d ", arr[i]);
		root = insert_bstree(root, arr[i]);
	}
	return root;
}
int queue_bstree_demo(void)
{
	//创建一个二叉树
	int ilen = TBL_SIZE(arr);
	BSTree root = init_bst_demo(arr, ilen);
	printf("\n演示层级遍历二叉树 \n");
	levelorder_bstree(root);
	// 销毁二叉树
	destroy_bstree(root);

	return 0;
}
void bstree_demo()
{
	//创建一个二叉树
	int ilen = TBL_SIZE(arr);
	BSTree root = init_bst_demo(arr, ilen);
	printf("\n== 前序遍历: ");
	preorder_bstree(root);

	printf("\n== 中序遍历: ");
	inorder_bstree(root);

	printf("\n== 后序遍历: ");
	postorder_bstree(root);
	printf("\n");

	printf("== 最小值: %d\n", bstree_minimum(root)->key);
	printf("== 最大值: %d\n", bstree_maximum(root)->key);
	printf("== 树的详细信息: \n");
	print_bstree(root, root->key, 0);

	printf("\n== 删除节点: %d", arr[3]);
	root = delete_bstree(root, arr[3]);

	printf("\n== 中序遍历: ");
	inorder_bstree(root);
	printf("\n");

	// 销毁二叉树
	destroy_bstree(root);
}