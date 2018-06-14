#pragma once
typedef int ElemType;
//ÿ������ƽ��ֵ  
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

//����ƽ�������  
typedef struct BSTNode
{
	ElemType key;                                //ƽ��ֵ  
	int bf;
	struct BSTNode *lchild, *rchild;
}BSTNode, *BSTree;


//�������  
void InOrderTraverse(BSTree root);
//ǰ�����  
void PreOrderTraverse(BSTree root);
//��������ת  
void R_Rotate(BSTree *p);
//��������ת  
void L_Rotate(BSTree *p);
//������������ƽ����ת  
void LeftBalance(BSTree *T);
//������������ƽ����ת  
void RightBalance(BSTree *T);
//����Ԫ��  
bool_t InsertAVL(BSTree *t, ElemType e, bool_t *taller);
//����
BSTree searchAVL(BSTree t, ElemType key);
//�ͷ�
static void destroy(BSTree *t);
void destroyAVL(BSTree root);