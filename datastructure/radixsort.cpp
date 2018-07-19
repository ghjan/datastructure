#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "radixsort.h"
#include "array.h"

const int RADIX_FLAGS[] = { 10, 100, 1000, 10000, 100000, 1000000 };
const int NEG_RADIX_FLAGS[] = { -10, -100, -1000, -10000, -100000, -1000000 };

/* 基数排序 - 次位优先 */

/* 默认次位D=1, 主位D<=MaxDigit */
int GetDigit(int X, int D, bool isNeg)
{
	int d, i;

	for (i = 1; i <= D; i++) {
		d = X % Radix;
		X /= Radix;
	}
	if (isNeg) {
		d = -1 * d;
	}
	return d;
}

////////////////基数排序 - 次位优先///////////////

PtrToRadixNode lsdRadixSort(PtrToRadixNode List, bool isNeg) {
	int D, Di, i;
	Bucket bucket;
	PtrToRadixNode tmp, p;
	for (i = 0; i < Radix; i++) /* 初始化每个桶为空链表 */
		bucket[i].head = bucket[i].tail = NULL;

	bool shouldEnd = false;
	bool toMaxD = false;
	for (D = 1; !toMaxD && !shouldEnd && D <= MaxDigit; D++) { /* 对数据的每一位循环处理 */
										  /* 下面是分配的过程 */
		p = List;
		toMaxD = true;
		while (p) {
			Di = GetDigit(p->key, D, isNeg); /* 获得当前元素的当前位数字 */
									  /* 从List中摘除 */
			tmp = p; p = p->next;
			if (!isNeg) {
				toMaxD = toMaxD && tmp->key < RADIX_FLAGS[D - 1];// pow(10, D);

				/* 插入B[Di]号桶尾 */
				tmp->next = NULL;
				if (bucket[Di].head == NULL)
					bucket[Di].head = bucket[Di].tail = tmp;
				else {
					bucket[Di].tail->next = tmp;
					bucket[Di].tail = tmp;
				}
			}
			else {//负数
				toMaxD = toMaxD && tmp->key > NEG_RADIX_FLAGS[D - 1];// pow(10, D);
				//作为新的桶头
				tmp->next = bucket[Di].head;
				if (bucket[Di].head == NULL)
					bucket[Di].head = bucket[Di].tail = tmp;
				else {
					bucket[Di].head = tmp;
				}
			}

		}
		if (!toMaxD) {
			//是否应该停止循环了，也就是说所有的数都集中在bucket[0]里面了
			shouldEnd = bucket[0].head != NULL;
			for (i = 1; i < Radix && shouldEnd; i++) {
				shouldEnd = shouldEnd && bucket[i].head == NULL;
			}
		}

		/* 下面是收集的过程 */
		List = NULL;
		if (!isNeg) {
			for (Di = Radix - 1; Di >= 0; Di--) { /* 将每个桶的元素顺序收集入List */
				if (bucket[Di].head) { /* 如果桶不为空 */
									   /* 整桶插入List表头 */
					bucket[Di].tail->next = List;
					List = bucket[Di].head;
					bucket[Di].head = bucket[Di].tail = NULL; /* 清空桶 */
				}
			}
		}
		else { //负数
			for (Di = 0; Di < Radix; Di++) { /* 将每个桶的元素顺序收集入List */
				if (bucket[Di].head) { /* 如果桶不为空 */
									   /* 整桶插入List表头 */
					bucket[Di].tail->next = List;
					List = bucket[Di].head;
					bucket[Di].head = bucket[Di].tail = NULL; /* 清空桶 */
				}
			}
		}
	}
	return List;
}

void LSDRadixSort(ElementType A[], int N)
{ /* 基数排序 - 次位优先 */

	PtrToRadixNode tmp, List = NULL, ListNeg = NULL;

	for (int i = 0; i < N; i++) { /* 将原始序列逆序存入初始链表List */
		tmp = (PtrToRadixNode)malloc(sizeof(struct RadixNode));
		tmp->key = A[i];
		if (A[i] >= 0) { //非负数
			tmp->next = List;
			List = tmp;
		}
		else { //负数
			tmp->next = ListNeg;
			ListNeg = tmp;
		}
	}
	/* 下面开始排序 */
	List = lsdRadixSort(List, false);
	ListNeg = lsdRadixSort(ListNeg, true);

	/* 将List倒入A[]并释放空间 */
	int i = 0;
	for (; i < N; i++) {
		tmp = ListNeg;
		ListNeg = ListNeg->next;
		A[i] = tmp->key;
		if (ListNeg == NULL) {
			break;
		}
		free(tmp);
	}
	for (; i < N; i++) {
		tmp = List;
		List = List->next;
		A[i] = tmp->key;
		if (List == NULL) {
			break;
		}
		free(tmp);
	}

}


void MSD(ElementType A[], int L, int R, int D, bool isNeg)
{ /* 核心递归函数: 对A[L]...A[R]的第D位数进行排序 */
	int Di, i, j;
	Bucket B;
	PtrToRadixNode tmp, p, List = NULL;
	if (D == 0) return; /* 递归终止条件 */

	for (i = 0; i < Radix; i++) /* 初始化每个桶为空链表 */
		B[i].head = B[i].tail = NULL;
	for (i = L; i <= R; i++) { /* 将原始序列逆序存入初始链表List */
		tmp = (PtrToRadixNode)malloc(sizeof(struct RadixNode));
		tmp->key = A[i];
		tmp->next = List;
		List = tmp;
	}
	/* 下面是分配的过程 */
	p = List;
	while (p) {
		Di = GetDigit(p->key, D, isNeg); /* 获得当前元素的当前位数字 */
								  /* 从List中摘除 */
		tmp = p; p = p->next;
		/* 插入B[Di]号桶 */
		if (B[Di].head == NULL) B[Di].tail = tmp;
		tmp->next = B[Di].head;
		B[Di].head = tmp;
	}
	/* 下面是收集的过程 */
	i = j = L; /* i, j记录当前要处理的A[]的左右端下标 */
	for (Di = 0; Di < Radix; Di++) { /* 对于每个桶 */
		if (B[Di].head) { /* 将非空的桶整桶倒入A[], 递归排序 */
			p = B[Di].head;
			while (p) {
				tmp = p;
				p = p->next;
				A[j++] = tmp->key;
				free(tmp);
			}
			/* 递归对该桶数据排序, 位数减1 */
			MSD(A, i, j - 1, D - 1, isNeg);
			i = j; /* 为下一个桶对应的A[]左端 */
		}
	}
}

void MSDRadixSort(ElementType A[], int N)
{ /* 统一接口 */
	MSD(A, 0, N - 1, MaxDigit, false);
}

void RadixSortDemo() {
	int BaseA[] = { 100, -300, -32, -29, 6, 2, 19, 25, 15, 55,
		35, 5, 110, 120, -240 };
	int A[15];
	int N = 15;
	Copy(BaseA, A, 15);
	LSDRadixSort(A, N);
	PrintArray(A, 15);

	//Copy(BaseA, A, 15);
	//MSDRadixSort(A, N);
	//PrintArray(A, 15);

	//ElementType BaseA[MaxN], A[MaxN];
	//int dataset = 5;
	//GenerateArray(BaseA, MaxN, dataset);
	//printf("---------dataset:%d\n", dataset);
	//int N = MaxN;
	//Copy(BaseA, A, MaxN);
	//LSDRadixSort(A, N);
	//PrintArray(A, 100);

	//Copy(BaseA, A, 15);
	//MSDRadixSort(A, N);
	//PrintArray(A, 100);
	//for (int D = 1; D <= MaxDigit; D++) {
	//	printf("%d ", GetDigit(125, D, false));
	//}

	//for (int D = 1; D <= MaxDigit; D++) {
	//	printf("%d ", GetDigit(-125, D, true));
	//}
}


