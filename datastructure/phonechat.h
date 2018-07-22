#pragma once
#include "hashtable.h"
typedef char * StrElementType;    /* �ؼ������������� */

typedef struct StringHashEntry StringCell; /* ɢ�б�Ԫ���� */
struct StringHashEntry {
	StrElementType Data; /* ���Ԫ�� */
	EntryType Info;   /* ��Ԫ״̬ */
	int Count; //�ظ��������
			   //char *Mobile; //��Ӧ���ֻ�����
};
typedef struct StringTblNode *StringHashTable; /* ɢ�б����� */
struct StringTblNode {   /* ɢ�б��㶨�� */
	int TableSize; /* �����󳤶� */
	StringCell *Cells;   /* ���ɢ�е�Ԫ���ݵ����� */
};

char* GetSubstring(const char *strSource, const unsigned int uStartPos, const unsigned int uEndPos);

//������ϣ��
StringHashTable CreateStringHashTable(int TableSize);
Position HashStringKey(StrElementType Key, int tableSize);
Position FindStringKey(StringHashTable H, StrElementType Key);
bool InsertStringHashTable(StringHashTable H, StrElementType Key);
void DestroyStringHashTable(StringHashTable table);