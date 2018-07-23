#pragma once
#define VALUELENGTH 16                   /* value�ַ�������󳤶� */
typedef int ElementType;				 /* key������ */
typedef char ValueType[VALUELENGTH+1];  /* value������ */

typedef int Index;                      /* ɢ�е�ַ���� */
/******** �����ǵ�����Ķ��� ********/
typedef struct LNode *PtrToLNode;
struct LNode {
    //ElementType Data;
	ElementType Key;  //���key
	ValueType Value; /* ���value */
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;
/******** �����ǵ�����Ķ��� ********/
typedef struct TblNode *LinkedHashTable; /* ɢ�б����� */
struct TblNode {   /* ɢ�б��㶨�� */
    int TableSize; /* �����󳤶� */
    List Heads;    /* ָ������ͷ�������� */
};

int HashByTableSize(ElementType Key, int tableSize);
LinkedHashTable CreateLinkedHashTable(int TableSize);
Position Find(LinkedHashTable H, ElementType Key);
bool Insert(LinkedHashTable H, ElementType Key, ValueType Value);
void DestroyTable(LinkedHashTable H);