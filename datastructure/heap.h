#pragma once
#pragma warning(disable:4996)
#define MAX_SIZE 10  
int heap[MAX_SIZE];
void max_Heap_insert(int *heap, int *n, int item);
int max_Heap_delete(int *heap, int *n);
