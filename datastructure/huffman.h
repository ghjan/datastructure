#pragma once
/** 哈夫曼树编码 **/
#include<stdio.h>
#include<stdlib.h> 
#define LENGTH 6

typedef int ElemType;

typedef struct HuffmanTreeNode {
	ElemType data;  //哈夫曼树中节点的权值
	struct HuffmanTreeNode* left;
	struct HuffmanTreeNode* right;
}HuffmanTreeNode, *PtrHuffman;
