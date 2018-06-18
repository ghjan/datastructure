#include "stdafx.h"
#include <stdio.h>  
#include <stdlib.h>  

#include"set.h"

//����ĳ��Ԫ�����ڵļ��ϣ��ø�����ʾ��
int Find(SetType S[], ElementType X)
{ /* ������S�в���ֵΪX��Ԫ�������ļ��� */
  /* MaxSize��ȫ�ֱ�����Ϊ����S����󳤶� */
	int i;
	for (i = 0; i < MaxSize && S[i].Data != X; i++);
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
