#pragma once
//���ŵ�ַ����ɢ�б�
#define MAXTABLESIZE 100000 /* �����ٵ����ɢ�б��� */
typedef int Index;          /* ɢ�е�ַ���� */
typedef enum { Legitimate, Empty, Deleted } EntryType;
//���ش���N�Ҳ�����MAXTABLESIZE����С����
int NextPrime(int N);