#pragma once
#pragma warning(disable:4996)
typedef int elementType;

/*define a binary tree*/
typedef struct node {
	elementType element;
	struct node *left;
	struct node *right;
	int flag;/*为了标记某个节点是以及被访问过 1表示以及被访问过了，0表示没有被访问过*/
}tre, *pTree;

/*构造二叉搜索树
@param N 二叉搜索树节点的个数
@return 返回一个二叉搜索树的根节点
*/
pTree buildTree(int N);

/*
把一个节点插入二叉搜索树中
@param tree 已经存在的二叉搜索树
@param element 需要插入到二叉搜索树的元素
*/
pTree insert(pTree tree, elementType element);

/*
创建一个树的节点
@param element 需要创建树节点的元素值
*/
pTree newNode(int element);

/*对二叉树进行先序遍历
@param tree 需要进行先序遍历的二叉树
*/
void preOrderTraversal(pTree tree);
/*
判断一棵二叉树是否和源二叉树一致
@param tree 源二叉搜索树
@param N 二叉搜索树的节点个数
@return 如果相同 返回1，否则返回0
*/
int judge(pTree tree, int N);

/*把二叉搜索树的flag标志全部置0
@param tree 需要把flag全部置0的二叉搜索树
*/
void  resetTree(pTree tree);

/*
检查该元素是否是按照源二叉树的顺序插入二叉树
在二叉树中搜索该元素，如果之前搜索到的元素flag都为1，当flag不为1时
正是element==tree->element.表示此节点为正确插入节点，否则就为错误插入节点
@param tree 源二叉搜索
@param element 需要检测的元素
@return 元素正确插入 返回1 否则返回0
*/
int check(pTree tree, elementType element);

/*释放tree
@param tree 需要被释放的tree
*/
void freeTree(pTree tree);
