#pragma once
#pragma warning(disable:4996)

#define MaxSize 100

typedef int ElementType;	//默认元素可以用非负整数表示
typedef int SetName;		//默认用根结点的下标作为集合名称

typedef ElementType SetType[MaxSize];

SetName Find(SetType S, ElementType X);
void Union(SetType S, SetName Root1, SetName Root2);