#pragma once
#pragma warning(disable:4996)

#define MaxSize 100

typedef int ElementType;	//Ĭ��Ԫ�ؿ����÷Ǹ�������ʾ
typedef int SetName;		//Ĭ���ø������±���Ϊ��������

typedef ElementType SetType[MaxSize];

SetName Find(SetType S, ElementType X);
void Union(SetType S, SetName Root1, SetName Root2);