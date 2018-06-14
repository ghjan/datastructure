#pragma once
typedef const char * myType;

typedef struct treeNode
{
	myType element;             //ֵ��Ԫ��
	struct treeNode *lchild;    //������
	struct treeNode *rchild;    //������
}BinarySearchTree;

//���ҷ������ݹ飩
BinarySearchTree *find(myType data, BinarySearchTree *T);

//���ҷ�����������
BinarySearchTree *iter_find(myType data, BinarySearchTree *T);

//��Сֵ���ݹ飩
BinarySearchTree *findMin(BinarySearchTree *T);

//���ֵ��������
BinarySearchTree *findMax(BinarySearchTree *T);

//���루�ݹ飩
BinarySearchTree *insert(myType data, BinarySearchTree *T);

//ɾ��(�ݹ�)
BinarySearchTree *remove(myType data, BinarySearchTree *T);

//����������������  
//��ӡ��Ӧ����һ������������  
void middleOrder(BinarySearchTree *T);

//����������������  
//��Ϊ�������+������� ����Ψһȷ��һ���������¿�����֤���Ƿ���ȷ  
void preOrder(BinarySearchTree *T);
