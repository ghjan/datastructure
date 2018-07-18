#pragma once
#include "array.h"

#define CUTOFF 100
struct Node {
	ElementType key1, key2;
};

void PrintArray(int data[], int size);//��ӡ����
void PrintNode(Node data[], int size);//��ӡ�ڵ�

//ð������
void Bubble_Sort(ElementType A[], int N);
//��������
void InsertionSort(ElementType A[], int N);

//ϣ������
void ShellSort(ElementType A[], int N);
void ShellSortSedgewick(ElementType array[], int N);//ʹ��Sedgewick�������е�ϣ������

//ѡ������Ͷ�����
void SelectionSort(ElementType A[], int N); //ѡ������
void Swap(ElementType *a, ElementType *b);//��������Ԫ��
void HeapSort(ElementType A[], int N);//������

//�鲢����
void MergeSort1(ElementType A[], int N); //�鲢���򣨵ݹ�ʵ�֣�
void MergeSort2(ElementType A[], int N); //�鲢����ѭ��ʵ�֣�

//��������
void QuickSort(ElementType A[], int N);
