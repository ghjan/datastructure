#include "stdafx.h"
#include <stdio.h>  
#include <stdlib.h>  

#include"set.h"

//查找某个元素所在的集合（用根结点表示）
int Find(SetType S[], ElementType X)
{ /* 在数组S中查找值为X的元素所属的集合 */
  /* MaxSize是全局变量，为数组S的最大长度 */
	int i;
	for (i = 0; i < MaxSize && S[i].Data != X; i++); //效率低
	if (i >= MaxSize) return -1; /* 未找到X，返回-1 */
	for (; S[i].Parent >= 0; i = S[i].Parent);
	return i; /* 找到X所属集合，返回树根结点在数组S中的下标 */
}

//集合并运算（改进方法，可以采用小树合并到大树中的方法，parent是-1修改为 -size
void Union(SetType S[], ElementType X1, ElementType X2)
{
	int Root1, Root2;
	Root1 = Find(S, X1);
	Root2 = Find(S, X2);
	if( Root1 != Root2 )
		S[Root2].Parent = Root1;
}


void PrintSet(SetType S[],int n)
{
	printf("-----------\n");
	for (int i = 0; i < n; i++) {
		printf("%d %d\n", S[i].Data, S[i].Parent);
	}
}
void set_demo()
{
	int n;
	int x, p;
	scanf("%d", &n);
	SetType *set1 = (SetType *)malloc(n*sizeof(SetType));
	for (int i = 0; i<n; i++) { /* */
		scanf("%d %d", &x, &p);
		set1[i].Data = x;
		set1[i].Parent = p;
	}

	PrintSet(set1, n);

	int pos1 = Find(set1, 8);
	printf("find root for 8 at %d\n", pos1);

	pos1 = Find(set1, 7);
	printf("find root for 7 at %d\n", pos1);

	Union(set1, 8, 7);
	PrintSet(set1, n);
}