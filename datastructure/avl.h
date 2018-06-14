#pragma once
typedef int ElemType;
//每个结点的平均值  
typedef enum
{
	EH = 0,
	LH = 1,
	RH = -1
}bh_t;

typedef enum
{
	FALSE = 0,
	TRUE = 1
}bool_t;

//定义平衡二叉树  
typedef struct BSTNode
{
	ElemType key;                                //平衡值  
	int bf;
	struct BSTNode *lchild, *rchild;
}BSTNode, *BSTree;


//中序遍历  
void InOrderTraverse(BSTree root);
//前序遍历  
void PreOrderTraverse(BSTree root);
//单向右旋转  
void R_Rotate(BSTree *p);
//单向左旋转  
void L_Rotate(BSTree *p);
//先左旋后右旋平衡旋转  
void LeftBalance(BSTree *T);
//先右旋后左旋平衡旋转  
void RightBalance(BSTree *T);
//插入元素  
bool_t InsertAVL(BSTree *t, ElemType e, bool_t *taller);
//查找
BSTree searchAVL(BSTree t, ElemType key);
//释放
static void destroy(BSTree *t);
void destroyAVL(BSTree root);