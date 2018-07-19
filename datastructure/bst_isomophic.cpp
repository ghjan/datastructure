#include "stdafx.h"
#include<stdio.h>  
#include "bst_isomophic.h"

Position BuildTree(struct TreeNode T[], int N)
{
	int Root = -1;
	char cl, cr, a[10], b[10], c[10];
	if (N)
	{
		int *check = new int[N];
		for (int i = 0; i < N; i++)
			check[i] = 0;
		for (int i = 0; i < N; i++)
		{
			//输入三个字符 节点本身，left， right
			//left和right可以输入-或者数字 ，输入-表示空节点,输入数字，表示第几个节点
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
		for (int i = 0; i < N; i++)
		{
			if (!check[i])  //只有root节点才满足 !check[i] 
			{
				Root = i;
				break;
			}
		}
		delete[]check;
	}
	return Root;
}

int Isomorphic(TreeNode T1[], TreeNode T2[], Position R1, Position R2)
{
	if ((R1 == Null) || (R2 == Null)) //只要有一个是Null,就检查是否都Null
		return (R1 == Null) && (R2 == Null);
	else if (T1[R1].Element != T2[R2].Element) //节点本身不一样，就不算同构
		return 0;
	else if ((T1[R1].Left == Null) && (T2[R2].Left == Null)) //如果左边全部是Null，那么就只要检查是否右子树同构
		return Isomorphic(T1, T2, T1[R1].Right, T2[R2].Right);
	else if (((T1[R1].Left != Null) && (T2[R2].Left != Null)) &&
		((T1[T1[R1].Left].Element) == (T2[T2[R2].Left].Element))) //如果左边都不是Null，而且left本身相等，那么检查左子树同构和右子树同构
		return (Isomorphic(T1, T2, T1[R1].Left, T2[R2].Left) && Isomorphic(T1, T2, T1[R1].Right, T2[R2].Right));
	else if ((T1[T1[R1].Left].Element == T2[T2[R2].Right].Element) && 
		(T1[T1[R1].Right].Element == T2[T2[R2].Left].Element)) //如果左子树和右子树元素相同，而且右子树和左子树元素相同，那么就检查左子树和右子树是否同构
		return ((Isomorphic(T1, T2, T1[R1].Left, T2[R2].Right)) && (Isomorphic(T1, T2, T1[R1].Right, T2[R2].Left)));
	else  //其他情况都非同构
		return 0;
}

int bst_isomophic_demo()
{
	int n, m;
	TreeNode T1[MaxTree], T2[MaxTree];
	Position R1, R2;
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