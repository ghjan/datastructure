#pragma once

#define ElementType long



//ð������
void Bubble_Sort(ElementType A[], int N);
//��������
void InsertionSort(ElementType A[], int N);

//ϣ������
void ShellSort(ElementType A[], int N);
void ShellSortSedgewick(int* array, int length);//ʹ��Sedgewick�������е�ϣ������

//ѡ������Ͷ�����
int ScanForMin(ElementType A[], int start, int end); //ɨ����Сֵλ��
void SelectionSort(ElementType A[], int N); //ѡ������
void Swap(ElementType *a, ElementType *b);//��������Ԫ��
void PercDown(ElementType A[], int p, int N);//��������
void HeapSort(ElementType A[], int N);//������

void MergeSort1(ElementType A[], int N); //�鲢���򣨵ݹ�ʵ�֣�
void MergeSort2(ElementType A[], int N); //�鲢����ѭ��ʵ�֣�