#pragma once
//���ŵ�ַ����ɢ�б�
#define MAXTABLESIZE 100000 /* �����ٵ����ɢ�б��� */
typedef int Index;          /* ɢ�е�ַ���� */
typedef Index Position;     /* ��������λ����ɢ�е�ַ��ͬһ���� */
							/* ɢ�е�Ԫ״̬���ͣ��ֱ��Ӧ���кϷ�Ԫ�ء��յ�Ԫ������ɾ��Ԫ�� */
typedef enum { Legitimate, Empty, Deleted } EntryType;
//���ش���N�Ҳ�����MAXTABLESIZE����С����
int NextPrime(int N);