#include "stdafx.h"
#include <stdio.h>  
#include <stdlib.h>  
#include "minheap.h"
#include "huffman.h"

MinPriorityQueue BuildMinHeap(MinPriorityQueue H)
{
	MinPriorityQueue queue = buildHeap_percolate(H->elements, H->size);
	return queue;
}

HuffmanTree Huffman(MinPriorityQueue H)
{ /* ����H->Size��Ȩֵ�Ѿ�����H->Elements[]->Weight�� */
	int i; HuffmanTree T;
	H = BuildMinHeap(H); /*��H->Elements[]��Ȩֵ����Ϊ��С��*/
	for (i = 1; i < H->size; i++) { /*��H->Size-1�κϲ�*/
		T = (TreeNode *)malloc(sizeof(struct TreeNode)); /*�����½��*/
		T->Left = (TreeNode *)malloc(sizeof(struct TreeNode));
		T->Left->Weight = deleteMin(H);
		/*����С����ɾ��һ����㣬��Ϊ��T�����ӽ��*/
		T->Right = (TreeNode *)malloc(sizeof(struct TreeNode));
		T->Right->Weight = deleteMin(H);
		/*����С����ɾ��һ����㣬��Ϊ��T�����ӽ��*/
		T->Weight = T->Left->Weight + T->Right->Weight;
		/*������Ȩֵ*/
		insert(T->Weight, H); /*����T������С��*/
	}
	T = (TreeNode *)malloc(sizeof(struct TreeNode));
	T->Weight = deleteMin(H);
	return T;
}

int huffman_demo()
{
	int a[9] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };

	MinPriorityQueue pqueue_ins = buildHeap_insert(a, 9);
	HuffmanTree hft = Huffman(pqueue_ins);
	return 0;
}