#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listmerge.h"

int listmerge_demo()
{
	List L1, L2, L;
	L1 = Read();
	L2 = Read();
	L = Merge(L1, L2);
	Print(L);
	Print(L1);
	Print(L2);
	return 0;
}

List Read()
{
	int N;
	scanf("%d", &N);
	char *strNumbers = NULL;
	//char *number = NULL;
	int data;
	PtrToNode head = NULL, prev = NULL;
	head = (PtrToNode)malloc(sizeof(NodeWithkeys));
	head->Next = NULL;
	int count = 0;
	bool isFirst = true;
	while (scanf("%d", &data) != EOF) {
		PtrToNode node = (PtrToNode)malloc(sizeof(NodeWithkeys));
		node->Data = data;
		node->Next = NULL;
		if (isFirst) { //第一个node就是head
			head->Next = node;
			isFirst = false;
		}
		else if (prev != NULL) {
			prev->Next = node;
		}
		prev = node;
		if (++count == N) {
			break;
		}
	}

	return head;
}

void Print(List L) {
	if (L == NULL || L->Next == NULL) {
		printf("NULL\n");
		return;
	}
	NodeWithkeys* node;
	bool isHead = true;
	for (node = L->Next; node != NULL; node = node->Next) {
		printf("%d ", node->Data);
	}
	printf("\n");
}
//两个链表表示的递增整数序列合并为一个非递减的整数序列
List Merge(List L1, List L2)
{
	if ((L1 == NULL && L2 == NULL) || (L1 != NULL && L2 != NULL && L1->Next == NULL && L2->Next == NULL)) {
		return NULL;
	}
	PtrToNode head = NULL, prev = NULL, node = NULL;
	PtrToNode node1, node2;
	bool isFirst = true; // head == NULL && node == NULL;
	for (node1 = L1->Next, node2 = L2->Next; node1 != NULL || node2 != NULL; ) {
		if (node1 == NULL) {
			node = node2;
			node2 = node2->Next;
		}
		else if (node2 == NULL) {
			node = node1;
			node1 = node1->Next;
		}
		else {
			if (node1->Data <= node2->Data) {
				node = node1;
				node1 = node1->Next;
			}
			else {
				node = node2;
				node2 = node2->Next;
			}
		}
		if (isFirst) {
			head = (PtrToNode)malloc(sizeof(NodeWithkeys));
			prev = head->Next = node;
			isFirst = false;
		}
		else {
			prev->Next = node;
			prev = node;
		}
	}
	L1->Next = NULL;
	L2->Next = NULL;
	return head;
}
