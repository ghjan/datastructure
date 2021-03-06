#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "bst_eq.h"

/*
判断两棵二叉搜索树是否一致
需求：比较是否为相同的二叉搜索树
我们知道的是：给定一个插入序列可以唯一的确定一棵二叉搜索树
但是对于相同的一个二叉搜索树，不一定有同一个插入序列
例如{2 3 1}和{2 1 3}就是相同的二叉搜索树

输入要求：
4 2     源二叉搜索树的节点个数N 有L个二叉搜索树需要和源二叉搜索进行比较
3 1 4 2 源二叉搜索树
3 4 1 2 需要进行比较的二叉搜索树
3 2 4 1 被比较的二叉搜索树
2 1     源二叉搜索树的节点个数 有几个二叉搜索树需要和源二叉搜索进行比较
2 1     源二叉搜索树
1 2     需要进行比较的二叉搜索树
0       程序结束的标志

输出
### 输出样例:
Yes
No
No

算法思路
我们先使用源二叉树的节点建立一棵二叉搜索树
然后在源二叉树中国对每个目的二叉树的每个元素进行查找

如果每次搜索所经过的结点在前面均出现过，则一致
否则（某次搜索中遇到前面未出现的结点），则不一致

程序设计的思路：
int main(){
读入N和L
建立源二叉树T
比较T是否和L个二叉树一致，并打印结果
return 0;
}

需要设计的主要函数
1.读数据建树T
2.判断一个序列是否和T构成相同的搜索树
*/

pTree newNode(int element) {
	pTree tree = (pTree)malloc(sizeof(tre));
	tree->element = element;
	tree->left = tree->right = NULL;
	//设置初始的标记位都为0，没有被访问
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

//返回0表示不同
int check(pTree tree, elementType element) {
	if (tree->flag) { //已经是不同了，继续下去是为了输入完完整的树
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

//返回1表示相同
int judge(pTree tree, int N) {
	int elemen, i, flag = 0; //flag为1表示发现了不同
	scanf("%d", &elemen);
	if (elemen != tree->element) {
		flag = 1;
	}
	else {
		tree->flag = 1;
	}
	for (i = 1; i<N; i++) {
		scanf("%d", &elemen);
		/*当已经判断出该二叉搜索树和源二叉搜索树不一致时，
		需要继续把数据读完，不然未读完的数据就会变成下一个树的元素*/
		if ((!flag) && (!check(tree, elemen))) {
			flag = 1;
		}
	}
	if (flag) {
		return 0;
	}
	else { //相同
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


int SolveBSTEqual() {
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
		/*释放已经判断过的二叉搜索树*/
		freeTree(tree);
		scanf("%d", &N);
	}
	return 0;
}