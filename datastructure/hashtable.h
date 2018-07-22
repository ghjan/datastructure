#pragma once
//���ŵ�ַ����ɢ�б�
#define MAXTABLESIZE 100000 /* �����ٵ����ɢ�б��� */
typedef int ElementType;    /* �ؼ������������� */
typedef int Index;          /* ɢ�е�ַ���� */
typedef Index Position;     /* ��������λ����ɢ�е�ַ��ͬһ���� */
							/* ɢ�е�Ԫ״̬���ͣ��ֱ��Ӧ���кϷ�Ԫ�ء��յ�Ԫ������ɾ��Ԫ�� */
typedef enum { Legitimate, Empty, Deleted } EntryType;
typedef struct HashEntry Cell; /* ɢ�б�Ԫ���� */
struct HashEntry {
	ElementType Data; /* ���Ԫ�� */
	EntryType Info;   /* ��Ԫ״̬ */
};
typedef struct TblNode *HashTable; /* ɢ�б����� */
struct TblNode {   /* ɢ�б��㶨�� */
	int TableSize; /* �����󳤶� */
	Cell *Cells;   /* ���ɢ�е�Ԫ���ݵ����� */
};

//���ش���N�Ҳ�����MAXTABLESIZE����С����
int NextPrime(int N);
//������ϣ��
HashTable CreateTable(int TableSize);
Position Hash(ElementType Key, int tableSize);
Position Find(HashTable H, ElementType Key);
bool Insert(HashTable H, ElementType Key);
