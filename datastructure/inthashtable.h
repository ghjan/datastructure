#pragma once
#include "hashtable.h"

typedef Index Position;     /* ��������λ����ɢ�е�ַ��ͬһ���� */
							/* ɢ�е�Ԫ״̬���ͣ��ֱ��Ӧ���кϷ�Ԫ�ء��յ�Ԫ������ɾ��Ԫ�� */

typedef int ElementType;    /* �ؼ������������� */
typedef struct HashEntry Cell; /* ɢ�б�Ԫ���� */
struct HashEntry {
	ElementType Data; /* ���Ԫ�� */
	EntryType Info;   /* ��Ԫ״̬ */
};
typedef struct IntTblNode *IntHashTable; /* ɢ�б����� */
struct IntTblNode {   /* ɢ�б��㶨�� */
	int TableSize; /* �����󳤶� */
	Cell *Cells;   /* ���ɢ�е�Ԫ���ݵ����� */
};


//������ϣ��
Position Hash(ElementType Key, int tableSize);
Position Find(IntHashTable H, ElementType Key);
Position Insert(IntHashTable H, ElementType Key);
IntHashTable CreateHashTable(int TableSize);
void DestroyHashTable(IntHashTable table);