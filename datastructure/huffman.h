#pragma once
/** ������������ **/
#include<stdio.h>
#include<stdlib.h> 
#define LENGTH 6

typedef int ElemType;

typedef struct HuffmanTreeNode {
	ElemType data;  //���������нڵ��Ȩֵ
	struct HuffmanTreeNode* left;
	struct HuffmanTreeNode* right;
}HuffmanTreeNode, *PtrHuffman;
