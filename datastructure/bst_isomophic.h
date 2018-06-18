#pragma once
#pragma warning(disable:4996)
#define MaxTree 10  
#define ElementType char  
#define Tree int  
#define Null -1  
struct TreeNode
{
	ElementType Element;

	Tree Left;
	Tree Right;
};

Tree BuildTree(struct TreeNode T[], int N);
int Isomorphic(TreeNode T1, TreeNode T2, Tree R1, Tree R2);