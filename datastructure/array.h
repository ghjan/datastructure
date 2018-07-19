#pragma once


#define ElementType int
#define MaxN 100000

#define CUTOFF 100
struct Node {
	ElementType key1, key2;
};


void Copy(ElementType source[], ElementType target[], int N);
void Reverse(ElementType BaseA[], int N);
void GenerateArray(ElementType BaseA[], int N, int dataset);


void PrintArray(int data[], int size);//��ӡ����
void PrintNode(Node data[], int size);//��ӡ�ڵ�