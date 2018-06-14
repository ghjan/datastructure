#pragma once
typedef const char * myType;

typedef struct treeNode
{
	myType element;             //值域元素
	struct treeNode *lchild;    //左子树
	struct treeNode *rchild;    //右子树
}BinarySearchTree;

//查找方法（递归）
BinarySearchTree *find(myType data, BinarySearchTree *T);

//查找方法（迭代）
BinarySearchTree *iter_find(myType data, BinarySearchTree *T);

//最小值（递归）
BinarySearchTree *findMin(BinarySearchTree *T);

//最大值（迭代）
BinarySearchTree *findMax(BinarySearchTree *T);

//插入（递归）
BinarySearchTree *insert(myType data, BinarySearchTree *T);

//删除(递归)
BinarySearchTree *remove(myType data, BinarySearchTree *T);

