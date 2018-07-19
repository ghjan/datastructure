#pragma once
#include "array.h"



//冒泡排序
void Bubble_Sort(ElementType A[], int N);
//插入排序
void InsertionSort(ElementType A[], int N);

//希尔排序
void ShellSort(ElementType A[], int N);
void ShellSortSedgewick(ElementType array[], int N);//使用Sedgewick增长序列的希尔排序

//选择排序和堆排序
void SelectionSort(ElementType A[], int N); //选择排序
void Swap(ElementType *a, ElementType *b);//交换两个元素
void HeapSort(ElementType A[], int N);//堆排序

//归并排序
void MergeSort1(ElementType A[], int N); //归并排序（递归实现）
void MergeSort2(ElementType A[], int N); //归并排序（循环实现）

//快速排序
void QuickSort(ElementType A[], int N);

