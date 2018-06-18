#pragma once
typedef struct TreeNode *HuffmanTree;
struct TreeNode {
	int Weight;
	HuffmanTree Left, Right;
};
MinPriorityQueue BuildMinHeap(MinPriorityQueue H);