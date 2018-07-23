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
	/* 保证散列表最大长度是素数，具体见代码5.3 */
	H->TableSize = NextPrime(TableSize);
	/* 以下分配链表头结点数组 */
	H->Heads = (List)malloc(H->TableSize * sizeof(struct LNode));
	/* 初始化表头结点 */
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

	Pos = HashByTableSize(Key, H->TableSize); /* 初始散列位置 */
	P = H->Heads[Pos].Next; /* 从该链表的第1个结点开始 */
							/* 当未到表尾，并且Key未找到时 */
	while (P && P->Key!=Key)
		P = P->Next;
	return P; /* 此时P或者指向找到的结点，或者为NULL */
}
bool Insert(LinkedHashTable H, ElementType Key, ValueType Value)
{
	Position P, NewCell;
	Index Pos;

	P = Find(H, Key);
	if (!P) { /* 关键词未找到，可以插入 */
		NewCell = (Position)malloc(sizeof(struct LNode));
		NewCell->Key = Key;
		strcpy(NewCell->Value, Value);
		Pos = HashByTableSize(Key, H->TableSize); /* 初始散列位置 */
									   /* 将NewCell插入为H->Heads[Pos]链表的第1个结点 */
		NewCell->Next = H->Heads[Pos].Next;
		H->Heads[Pos].Next = NewCell;
		return true;
	}
	else { /* 关键词已存在 */
		//printf("键值已存在");
		return false;
	}
}
void DestroyTable(LinkedHashTable H)
{
	int i;
	Position P, Tmp;

	/* 释放每个链表的结点 */
	for (i = 0; i<H->TableSize; i++) {
		P = H->Heads[i].Next;
		while (P) {
			Tmp = P->Next;
			free(P);
			P = Tmp;
		}
	}
	free(H->Heads); /* 释放头结点数组 */
	free(H);        /* 释放散列表结点 */
}