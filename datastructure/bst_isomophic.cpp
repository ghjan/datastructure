#include "stdafx.h"
#include<stdio.h>  
#include "bst_isomophic.h"

Tree BuildTree(struct TreeNode T[], int N)
{
	int Root = -1;
	char cl, cr, a[10], b[10], c[10];
	if (N)
	{
		int *check = new int[N];
		for (int i = 0; i<N; i++)
			check[i] = 0;
		for (int i = 0; i<N; i++)
		{
			scanf("%s %s %s", a, b, c);
			T[i].Element = a[0];
			cl = b[0];
			cr = c[0];
			if (cl != '-')
			{
				T[i].Left = cl - '0';
				check[T[i].Left] = 1;
			}
			else
				T[i].Left = Null;
			if (cr != '-')
			{
				T[i].Right = cr - '0';
				check[T[i].Right] = 1;
			}
			else
				T[i].Right = Null;
		}
		for (int i = 0; i<N; i++)
		{
			if (!check[i])
			{
				Root = i;
				break;
			}
		}
	}
	return Root;
}

int Isomorphic(TreeNode T1[], TreeNode T2[], Tree R1, Tree R2)
{
	if ((R1 == Null) && (R2 == Null))
		return 1;
	else if (((R1 == Null) && (R2 != Null)) || ((R1 != Null) && (R2 == Null)))
		return 0;
	else if (T1[R1].Element != T2[R2].Element)
		return 0;
	else if ((T1[R1].Left == Null) && (T2[R2].Left == Null))
		return Isomorphic(T1, T2, T1[R1].Right, T2[R2].Right);
	else if (((T1[R1].Left != Null) && (T2[R2].Left != Null)) &&
		((T1[T1[R1].Left].Element) == (T2[T2[R2].Left].Element)))
		return (Isomorphic(T1, T2, T1[R1].Left, T2[R2].Left) && Isomorphic(T1, T2, T1[R1].Right, T2[R2].Right));
	else if ((T1[T1[R1].Left].Element == T2[T2[R2].Right].Element) && (T1[T1[R1].Right].Element == T2[T2[R2].Left].Element))
		return ((Isomorphic(T1, T2, T1[R1].Left, T2[R2].Right)) && (Isomorphic(T1, T2, T1[R1].Right, T2[R2].Left)));
	else
		return 0;
}

int bst_isomophic_demo()
{
	int n, m;
	TreeNode T1[MaxTree], T2[MaxTree];
	Tree R1, R2;
	while (scanf("%d", &n) != EOF)
	{
		R1 = BuildTree(T1, n);
		scanf("%d", &m);
		R2 = BuildTree(T2, m);
		if (Isomorphic(T1, T2, R1, R2))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}