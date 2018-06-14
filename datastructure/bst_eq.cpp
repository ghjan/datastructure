#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "bst_eq.h"

/*
�ж����ö����������Ƿ�һ��
���󣺱Ƚ��Ƿ�Ϊ��ͬ�Ķ���������
����֪�����ǣ�����һ���������п���Ψһ��ȷ��һ�ö���������
���Ƕ�����ͬ��һ����������������һ����ͬһ����������
����{2 3 1}��{2 1 3}������ͬ�Ķ���������

����Ҫ��
4 2     Դ�����������Ľڵ����N ��L��������������Ҫ��Դ�����������бȽ�
3 1 4 2 Դ����������
3 4 1 2 ��Ҫ���бȽϵĶ���������
3 2 4 1 ���ȽϵĶ���������
2 1     Դ�����������Ľڵ���� �м���������������Ҫ��Դ�����������бȽ�
2 1     Դ����������
1 2     ��Ҫ���бȽϵĶ���������
0       ��������ı�־

���
### �������:
Yes
No
No

�㷨˼·
������ʹ��Դ�������Ľڵ㽨��һ�ö���������
Ȼ����Դ�������й���ÿ��Ŀ�Ķ�������ÿ��Ԫ�ؽ��в���

���ÿ�������������Ľ����ǰ������ֹ�����һ��
����ĳ������������ǰ��δ���ֵĽ�㣩����һ��

������Ƶ�˼·��
int main(){
����N��L
����Դ������T
�Ƚ�T�Ƿ��L��������һ�£�����ӡ���
return 0;
}

��Ҫ��Ƶ���Ҫ����
1.�����ݽ���T
2.�ж�һ�������Ƿ��T������ͬ��������
*/

pTree newNode(int element) {
	pTree tree = (pTree)malloc(sizeof(tre));
	tree->element = element;
	tree->left = tree->right = NULL;
	//���ó�ʼ�ı��λ��Ϊ0��û�б�����
	tree->flag = 0;
	return tree;
}

pTree insert(pTree tree, elementType element) {
	if (!tree) {
		tree = newNode(element);
	}
	else {/**/
		if (element<tree->element) {
			tree->left = insert(tree->left, element);
		}
		else if (element>tree->element) {
			tree->right = insert(tree->right, element);
		}
	}
	return tree;
}


pTree buildTree(int N) {
	int ele, i;
	pTree tree;
	scanf("%d", &ele);
	tree = newNode(ele);
	for (i = 1; i<N; i++) {
		scanf("%d", &ele);
		tree = insert(tree, ele);
	}
	return tree;
}

void preOrderTraversal(pTree tree) {
	if (tree) {
		printf("%d ", tree->element);
		preOrderTraversal(tree->left);
		preOrderTraversal(tree->right);
	}
}

int check(pTree tree, elementType element) {
	if (tree->flag) {
		if (element<tree->element) {
			check(tree->left, element);
		}
		else if (element>tree->element) {
			check(tree->right, element);
		}
		else {
			return 0;
		}
	}
	else {
		if (tree->element == element) {
			tree->flag = 1;
			return 1;
		}
		else {
			return 0;
		}
	}
}


int judge(pTree tree, int N) {
	int elemen, i, flag = 0;
	scanf("%d", &elemen);
	if (elemen != tree->element) {
		flag = 1;
	}
	else {
		tree->flag = 1;
	}
	for (i = 1; i<N; i++) {
		scanf("%d", &elemen);
		/*���Ѿ��жϳ��ö�����������Դ������������һ��ʱ����Ҫ���������ݶ��꣬��Ȼδ��������ݾͻ�����һ������Ԫ��*/
		if ((!flag) && (!check(tree, elemen))) {
			flag = 1;
		}
	}
	if (flag) {
		return 0;
	}
	else {
		return 1;
	}

}

void  resetTree(pTree tree) {
	if (tree->left) {
		resetTree(tree->left);
	}
	if (tree->right) {
		resetTree(tree->right);
	}
	tree->flag = 0;
}

void freeTree(pTree tree) {
	if (tree->left) {
		freeTree(tree->left);
	}
	if (tree->right) {
		free(tree->right);
	}
	free(tree);
}


int bst_eq_demo() {
	int N, L;
	int i;
	scanf("%d", &N);
	while (N) {
		scanf("%d", &L);
		pTree tree = buildTree(N);
		//preOrderTraversal(tree);
		for (i = 0; i<L; i++) {
			if (judge(tree, N)) {
				printf("Yes\n");
			}
			else {
				printf("No\n");
			}
			resetTree(tree);
		}
		/*�ͷ��Ѿ��жϹ��ö���������*/
		freeTree(tree);
		scanf("%d", &N);
	}
	return 0;
}