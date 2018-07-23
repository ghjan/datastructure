#include "stdafx.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"
#include "linkedhashtable.h"
using namespace std;
#pragma warning(disable:4996)

int HashByTableSize(ElementType Key, int tableSize) {
	return Key % tableSize;
}

LinkedHashTable CreateLinkedHashTable(int TableSize)
{
	LinkedHashTable H;
	int i;
	H = (LinkedHashTable)malloc(sizeof(struct TblNode));
	/* ��֤ɢ�б���󳤶������������������5.3 */
	H->TableSize = NextPrime(TableSize);
	/* ���·�������ͷ������� */
	H->Heads = (List)malloc(H->TableSize * sizeof(struct LNode));
	/* ��ʼ����ͷ��� */
	for (i = 0; i<H->TableSize; i++) {
		H->Heads[i].Value[0] = '\0';
		H->Heads[i].Next = NULL;
	}
	return H;
}
Position Find(LinkedHashTable H, ElementType Key)
{
	Position P;
	Index Pos;

	Pos = HashByTableSize(Key, H->TableSize); /* ��ʼɢ��λ�� */
	P = H->Heads[Pos].Next; /* �Ӹ�����ĵ�1����㿪ʼ */
							/* ��δ����β������Keyδ�ҵ�ʱ */
	while (P && P->Key!=Key)
		P = P->Next;
	return P; /* ��ʱP����ָ���ҵ��Ľ�㣬����ΪNULL */
}
bool Insert(LinkedHashTable H, ElementType Key, ValueType Value)
{
	Position P, NewCell;
	Index Pos;

	P = Find(H, Key);
	if (!P) { /* �ؼ���δ�ҵ������Բ��� */
		NewCell = (Position)malloc(sizeof(struct LNode));
		NewCell->Key = Key;
		strcpy(NewCell->Value, Value);
		Pos = HashByTableSize(Key, H->TableSize); /* ��ʼɢ��λ�� */
									   /* ��NewCell����ΪH->Heads[Pos]����ĵ�1����� */
		NewCell->Next = H->Heads[Pos].Next;
		H->Heads[Pos].Next = NewCell;
		return true;
	}
	else { /* �ؼ����Ѵ��� */
		//printf("��ֵ�Ѵ���");
		return false;
	}
}
void DestroyTable(LinkedHashTable H)
{
	int i;
	Position P, Tmp;

	/* �ͷ�ÿ������Ľ�� */
	for (i = 0; i<H->TableSize; i++) {
		P = H->Heads[i].Next;
		while (P) {
			Tmp = P->Next;
			free(P);
			P = Tmp;
		}
	}
	free(H->Heads); /* �ͷ�ͷ������� */
	free(H);        /* �ͷ�ɢ�б��� */
}