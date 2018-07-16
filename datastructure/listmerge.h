#pragma once
#pragma warning(disable:4996)

typedef int ElementType;

typedef struct Node *PtrToNode;
struct Node {
	ElementType Data; /* �洢������� */
	PtrToNode   Next; /* ָ����һ������ָ�� */
};
typedef PtrToNode List; /* ���嵥�������� */

List Read();
void Print(List L); /* ���������NULL */

//���������ʾ�ĵ����������кϲ�Ϊһ���ǵݼ�����������
List Merge(List L1, List L2);
