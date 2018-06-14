#pragma once
#pragma warning(disable:4996)
typedef int elementType;

/*define a binary tree*/
typedef struct node {
	elementType element;
	struct node *left;
	struct node *right;
	int flag;/*Ϊ�˱��ĳ���ڵ����Լ������ʹ� 1��ʾ�Լ������ʹ��ˣ�0��ʾû�б����ʹ�*/
}tre, *pTree;

/*�������������
@param N �����������ڵ�ĸ���
@return ����һ�������������ĸ��ڵ�
*/
pTree buildTree(int N);

/*
��һ���ڵ���������������
@param tree �Ѿ����ڵĶ���������
@param element ��Ҫ���뵽������������Ԫ��
*/
pTree insert(pTree tree, elementType element);

/*
����һ�����Ľڵ�
@param element ��Ҫ�������ڵ��Ԫ��ֵ
*/
pTree newNode(int element);

/*�Զ����������������
@param tree ��Ҫ������������Ķ�����
*/
void preOrderTraversal(pTree tree);
/*
�ж�һ�ö������Ƿ��Դ������һ��
@param tree Դ����������
@param N �����������Ľڵ����
@return �����ͬ ����1�����򷵻�0
*/
int judge(pTree tree, int N);

/*�Ѷ�����������flag��־ȫ����0
@param tree ��Ҫ��flagȫ����0�Ķ���������
*/
void  resetTree(pTree tree);

/*
����Ԫ���Ƿ��ǰ���Դ��������˳����������
�ڶ�������������Ԫ�أ����֮ǰ��������Ԫ��flag��Ϊ1����flag��Ϊ1ʱ
����element==tree->element.��ʾ�˽ڵ�Ϊ��ȷ����ڵ㣬�����Ϊ�������ڵ�
@param tree Դ��������
@param element ��Ҫ����Ԫ��
@return Ԫ����ȷ���� ����1 ���򷵻�0
*/
int check(pTree tree, elementType element);

/*�ͷ�tree
@param tree ��Ҫ���ͷŵ�tree
*/
void freeTree(pTree tree);
