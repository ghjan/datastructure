#pragma once

typedef int Type;

//��������� binary search tree
typedef struct BSTreeNode {
	Type   key;                    // �ؼ���(��ֵ)
	struct BSTreeNode *left;    // ����
	struct BSTreeNode *right;    // �Һ���
	struct BSTreeNode *parent;    // �����
}BSTreeNode, *BSTree;

// ǰ�����"������"
void preorder_bstree(BSTree tree);
// �������"������"
void inorder_bstree(BSTree tree);
// �������"������"
void postorder_bstree(BSTree tree);
//�㼶����"������"
void levelorder_bstree(BSTree tree);

//�������"������"��Ҷ�ӽ��
void inorder_bstree_leaf(BSTree tree);

// (�ݹ�ʵ��)����"������x"�м�ֵΪkey�Ľڵ�
BSTreeNode* bstree_search(BSTree x, Type key);
// (�ǵݹ�ʵ��)����"������x"�м�ֵΪkey�Ľڵ�
BSTreeNode* iterative_bstree_search(BSTree x, Type key);

// ������С��㣺����treeΪ�����Ķ���������С��㡣
BSTreeNode* bstree_minimum(BSTree tree);
// ��������㣺����treeΪ�����Ķ�����������㡣
BSTreeNode* bstree_maximum(BSTree tree);

// �ҽ��(x)�ĺ�̽�㡣��������"������������ֵ���ڸý��"��"��С���"��
BSTreeNode* bstree_successor(BSTreeNode *x);
// �ҽ��(x)��ǰ����㡣��������"������������ֵС�ڸý��"��"�����"��
BSTreeNode* bstree_predecessor(BSTreeNode *x);

// �������뵽�������У������ظ��ڵ�
BSTreeNode* insert_bstree(BSTree tree, Type key);

// ɾ�����(keyΪ�ڵ��ֵ)�������ظ��ڵ�
BSTreeNode* delete_bstree(BSTree tree, Type key);

// ���ٶ�����
void destroy_bstree(BSTree tree);

// ��ӡ������
void print_bstree(BSTree tree, Type key, int direction);

int height(BSTree tree);