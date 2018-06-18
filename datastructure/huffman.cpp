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
{ /* 假设H->Size个权值已经存在H->Elements[]->Weight里 */
	int i; HuffmanTree T;
	H = BuildMinHeap(H); /*将H->Elements[]按权值调整为最小堆*/
	for (i = 1; i < H->size; i++) { /*做H->Size-1次合并*/
		T = (TreeNode *)malloc(sizeof(struct TreeNode)); /*建立新结点*/
		T->Left = (TreeNode *)malloc(sizeof(struct TreeNode));
		T->Left->Weight = deleteMin(H);
		/*从最小堆中删除一个结点，作为新T的左子结点*/
		T->Right = (TreeNode *)malloc(sizeof(struct TreeNode));
		T->Right->Weight = deleteMin(H);
		/*从最小堆中删除一个结点，作为新T的右子结点*/
		T->Weight = T->Left->Weight + T->Right->Weight;
		/*计算新权值*/
		insert(T->Weight, H); /*将新T插入最小堆*/
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