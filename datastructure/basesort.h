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

////////排序使用的比较函数////////////

//一般情况下，对结构体Node中的某几个键值keys排序
int CompareKeys(const void *a, const void *b, int countKeys, int sorts[]);

/* 比较两种键值：按key1降序排列；如果key1相等，则按key2升序排列 */
int Compare2Keys(const void *a, const void *b);

/* 比较三种键值：按key1降序，key2降序，key3升序排列 */
int Compare3Keys(const void *a, const void *b);

