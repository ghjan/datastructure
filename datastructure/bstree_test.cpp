/**
* C ����: ���������
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
	printf("== �������: \n");
	for (i = 0; i<ilen; i++)
	{
		printf("%d ", arr[i]);
		root = insert_bstree(root, arr[i]);
	}
	return root;
}
int queue_bstree_demo(void)
{
	//����һ��������
	int ilen = TBL_SIZE(arr);
	BSTree root = init_bst_demo(arr, ilen);
	printf("\n��ʾ�㼶���������� \n");
	levelorder_bstree(root);
	// ���ٶ�����
	destroy_bstree(root);

	return 0;
}
void bstree_demo()
{
	//����һ��������
	int ilen = TBL_SIZE(arr);
	BSTree root = init_bst_demo(arr, ilen);
	printf("\n== ǰ�����: ");
	preorder_bstree(root);

	printf("\n== �������: ");
	inorder_bstree(root);

	printf("\n== �������: ");
	postorder_bstree(root);
	printf("\n");

	printf("== ��Сֵ: %d\n", bstree_minimum(root)->key);
	printf("== ���ֵ: %d\n", bstree_maximum(root)->key);
	printf("== ������ϸ��Ϣ: \n");
	print_bstree(root, root->key, 0);

	printf("\n== ɾ���ڵ�: %d", arr[3]);
	root = delete_bstree(root, arr[3]);

	printf("\n== �������: ");
	inorder_bstree(root);
	printf("\n");

	// ���ٶ�����
	destroy_bstree(root);
}