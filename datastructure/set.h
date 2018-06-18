#pragma once
#pragma warning(disable:4996)

//数组中每个元素的类型描述为： 
#define ElementType int  
#define MaxSize 100

typedef struct {
	ElementType Data;
	int Parent;
} SetType;

int Find(SetType S[], ElementType X);
void Union(SetType S[], ElementType X1, ElementType X2);