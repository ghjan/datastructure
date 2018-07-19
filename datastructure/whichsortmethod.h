#pragma once
#pragma warning(disable:4996)
#include "array.h"
int IsInsertSort(ElementType A[], ElementType B[], int N);
int IsMergeSort(ElementType A[], ElementType B[], int N);
int IsHeapSort(ElementType A[], ElementType B[], int N);
bool IsSortSuccess(ElementType A[], int start, int end);