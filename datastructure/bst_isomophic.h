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
}T1[MaxTree], T2[MaxTree];

Tree BuildTree(struct TreeNode T[], int N);
int Isomorphic(Tree R1, Tree R2);