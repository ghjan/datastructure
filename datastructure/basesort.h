#pragma once

#define ElementType long



//冒泡排序
void Bubble_Sort(ElementType A[], int N);
//插入排序
void InsertionSort(ElementType A[], int N);

//希尔排序
void ShellSort(ElementType A[], int N);
void ShellSortSedgewick(int* array, int length);//使用Sedgewick增长序列的希尔排序

//选择排序和堆排序
int ScanForMin(ElementType A[], int start, int end); //扫描最小值位置
void SelectionSort(ElementType A[], int N); //选择排序
void Swap(ElementType *a, ElementType *b);//交换两个元素
void PercDown(ElementType A[], int p, int N);//构造最大堆
void HeapSort(ElementType A[], int N);//堆排序

void MergeSort1(ElementType A[], int N); //归并排序（递归实现）
void MergeSort2(ElementType A[], int N); //归并排序（循环实现）