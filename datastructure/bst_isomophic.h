#pragma once
#pragma warning(disable:4996)
#define MaxTree 10  
#define ElementType char  
#define Position int   //����һ������λ��index ��0��ʼ
#define Null -1  
struct TreeNode
{
	ElementType Element;

	Position Left;
	Position Right;
};

Position BuildTree(struct TreeNode T[], int N);
int Isomorphic(TreeNode T1[], TreeNode T2[], Position R1, Position R2);