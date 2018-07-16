#include "stdafx.h"
#include <stdio.h>  
#include <stdlib.h>  

#include"set.h"

//����ĳ��Ԫ�����ڵļ��ϣ��ø�����ʾ��
int Find(SetType S[], ElementType X)
{ /* ������S�в���ֵΪX��Ԫ�������ļ��� */
  /* MaxSize��ȫ�ֱ�����Ϊ����S����󳤶� */
	int i;
	for (i = 0; i < MaxSize && S[i].Data != X; i++); //Ч�ʵ�
	if (i >= MaxSize) return -1; /* δ�ҵ�X������-1 */
	for (; S[i].Parent >= 0; i = S[i].Parent);
	return i; /* �ҵ�X�������ϣ������������������S�е��±� */
}

//���ϲ����㣨�Ľ����������Բ���С���ϲ��������еķ�����parent��-1�޸�Ϊ -size
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