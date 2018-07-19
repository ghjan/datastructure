#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "time.h"
#include "basesort.h"


//冒泡排序 最小的泡泡放到上面 好处：非常简单 性能不好，是 O(N*N)
//如果待排元素在链表里面，冒泡排序比较适合这种数据结构
void Bubble_Sort(ElementType A[], int N)
{
	for (int P = N - 1; P >= 0; P--) { //最多N趟
		int flag = 0;  //0表示没有执行交换
		for (int i = 0; i < P; i++) { /* 一趟冒泡 确保最大的沉到最下面 */
			if (A[i] > A[i + 1]) { //相邻泡泡比较大小，小泡泡向上冒
				Swap(&A[i], &A[i + 1]);
				flag = 1; /* 标识发生了交换*/
			}
		}
		if (flag == 0) break; /* 全程无交换*/
	}
}

//插入排序 一手纸牌 
//相比较冒泡排序 插入排序相对来说 比冒泡排序中的交换步数少
void InsertionSort(ElementType A[], int N)
{ /* 插入排序 */
	int P, i;
	ElementType Tmp;

	for (P = 1; P < N; P++) {
		//插入排序的特点：0~P-1已经排序完毕
		Tmp = A[P]; /* 取出未排序序列中的第一个元素 摸下一张牌*/
		for (i = P; i > 0 && A[i - 1] > Tmp; i--) //从最后一张牌 向前比较
			A[i] = A[i - 1]; /*依次与已排序序列中元素比较并右移  类似于搓牌移出空位*/
		A[i] = Tmp; /* 放进合适的位置  新牌落位*/
	}
}

////////////////希尔排序/////////////

//原始shell排序
void ShellSort(ElementType A[], int N)
{
	for (int D = N / 2; D > 0; D /= 2) { /* 希尔增量序列*/
		for (int P = D; P < N; P++) { /* 插入排序*/
			ElementType Tmp = A[P];
			int i;
			for (i = P; i >= D && A[i - D] > Tmp; i -= D)
				A[i] = A[i - D];
			A[i] = Tmp;
		}
	}
}

//Sedgewick增长序列
// 对增量序列赋值 和 找出所需要的最大轮数.
// 如 Rebort Sedgewick(罗伯特·塞奇威克) 提出的 increment = 9*4^i - 9*2^i +1  或 increment = 4^i - 3*2^i +1;
// incrementSeq[] 起点从 0 开始.
//https://blog.csdn.net/PacosonSWJTU/article/details/52093398
int incrementSeqFunc(int* incrementSeq, int length)
{
	int i, startup1 = 0, startup2 = 2;

	for (i = 0; i < length; i++)
	{
		if (i % 2 == 0)
		{
			incrementSeq[i] = 9 * pow(4, startup1) - 9 * pow(2, startup1) + 1;
			startup1++;
		}
		else
		{
			incrementSeq[i] = pow(4, startup2) - 3 * pow(2, startup2) + 1;
			startup2++;
		}
		if (incrementSeq[i] >= length)
		{
			break;
		}
	}
	return i; // 排序轮数，每轮都使用（比上一轮）缩小的增量序列
}

//使用Sedgewick增长序列的希尔排序
void ShellSortSedgewick(ElementType array[] , int N)
{
	int incrementSeq[255]; // 增量序列(startup == 0).
	int i, j, round = incrementSeqFunc(incrementSeq, N);
	int increment, temp;

	for (; round >= 1; round--)
	{
		increment = incrementSeq[round - 1];
		for (i = 1 * increment; i < N; i += increment) // 默认地,array[0*increment]有序，所以从1*increment开始.
		{
			temp = array[i]; // 第1个无序成员.
			for (j = i - increment; j >= 0; j -= increment) // j 在有序部分进行滑动.
			{
				if (temp < array[j])
				{
					array[j + increment] = array[j];
				}
				else
				{
					break;
				}
			}
			array[j + increment] = temp;
		}
	}
}

int ShellSortSedgewickDemo()
{
	int array[] = { 100, 1000, 100, 10, 6, 2, 19, 25, 15, 55,
		35, 5, 110, 120, 119 };
	int length = 15;

	ShellSortSedgewick(array, length);
	PrintArray(array, length);
	return 0;
}
////////////////////选择排序和堆排序//////////////

//扫描最小值位置
int scanForMin(ElementType A[], int start, int end) {
	return 0;
}
//选择排序
void SelectionSort(ElementType A[], int N)
{
	for (int i = 0; i < N; i++) {
		int MinPosition = scanForMin(A, i, N - 1);
		/* 从A[i]到A[N–1]中找最小元，并将其位置赋给MinPosition */
		Swap(&A[i], &A[MinPosition]);
		/* 将未排序部分的最小元换到有序部分的最后位置*/
	}
}
//交换两个元素
void Swap(ElementType *a, ElementType *b)
{
	ElementType t = *a; *a = *b; *b = t;
}

//最大堆
void percDown(ElementType A[], int p, int N)
{ /* 改编代码4.24的percDown( MaxHeap H, int p )    */
  /* 将N个元素的数组中以A[p]为根的子堆调整为最大堆 */
	int Parent, Child;
	ElementType X;

	X = A[p]; /* 取出根结点存放的值 */
	for (Parent = p; (Parent * 2 + 1) < N; Parent = Child) {
		Child = Parent * 2 + 1;
		if ((Child != N - 1) && (A[Child] < A[Child + 1]))
			Child++;  /* Child指向左右子结点的较大者 */
		if (X >= A[Child]) break; /* 找到了合适位置 */
		else  /* 下滤X */
			A[Parent] = A[Child];
	}
	A[Parent] = X;
}

/* 堆排序 */
void HeapSort(ElementType A[], int N)
{
	int i;

	for (i = N / 2 - 1; i >= 0; i--)/* 建立最大堆 */
		percDown(A, i, N);

	for (i = N - 1; i > 0; i--) {
		/* 删除最大堆顶 */
		Swap(&A[0], &A[i]); /* 见代码7.1 */
		percDown(A, 0, i);
	}
}

//////////////////归并排序/////////////////
/* 归并排序 - 递归实现 */

/* L = 左边起始位置, R = 右边起始位置, RightEnd = 右边终点位置*/
void merge(ElementType A[], ElementType TmpA[], int L, int R, int RightEnd)
{ /* 将有序的A[L]~A[R-1]和A[R]~A[RightEnd]归并成一个有序序列 */
	int LeftEnd, NumElements, Tmp;
	int i;

	LeftEnd = R - 1; /* 左边终点位置 */
	Tmp = L;         /* 有序序列的起始位置 */
	NumElements = RightEnd - L + 1;

	while (L <= LeftEnd && R <= RightEnd) {
		if (A[L] <= A[R])
			TmpA[Tmp++] = A[L++]; /* 将左边元素复制到TmpA */
		else
			TmpA[Tmp++] = A[R++]; /* 将右边元素复制到TmpA */
	}

	while (L <= LeftEnd)
		TmpA[Tmp++] = A[L++]; /* 直接复制左边剩下的 */
	while (R <= RightEnd)
		TmpA[Tmp++] = A[R++]; /* 直接复制右边剩下的 */

	for (i = 0; i < NumElements; i++, RightEnd--)
		A[RightEnd] = TmpA[RightEnd]; /* 将有序的TmpA[]复制回A[] */
}

void msort(ElementType A[], ElementType TmpA[], int L, int RightEnd)
{ /* 核心递归排序函数 */
	int Center;

	if (L < RightEnd) {
		Center = (L + RightEnd) / 2;
		msort(A, TmpA, L, Center);              /* 递归解决左边 */
		msort(A, TmpA, Center + 1, RightEnd);     /* 递归解决右边 */
		merge(A, TmpA, L, Center + 1, RightEnd);  /* 合并两段有序序列 */
	}
}

void MergeSort1(ElementType A[], int N)
{ /* 归并排序 */
	ElementType *TmpA;
	TmpA = (ElementType *)malloc(N * sizeof(ElementType));

	if (TmpA != NULL) {
		msort(A, TmpA, 0, N - 1);
		free(TmpA);
	}
	else printf("空间不足");
}

/* 归并排序 - 循环实现 */
/* 这里merge函数在递归版本中给出 */
/* length = 当前有序子列的长度*/
void merge_pass(ElementType A[], ElementType TmpA[], int N, int length)
{ /* 两两归并相邻有序子列 */
	int i, j;

	for (i = 0; i <= N - 2 * length; i += 2 * length)
		merge(A, TmpA, i, i + length, i + 2 * length - 1);
	if (i + length < N) /* 归并最后2个子列*/
		merge(A, TmpA, i, i + length, N - 1);
	else /* 最后只剩1个子列*/
		for (j = i; j < N; j++) TmpA[j] = A[j];
}

//归并排序 - 循环实现
void MergeSort2(ElementType A[], int N)
{
	int length;
	ElementType *TmpA;

	length = 1; /* 初始化子序列长度*/
	TmpA = (ElementType *)malloc(N * sizeof(ElementType));

	if (TmpA != NULL) {
		while (length < N) {
			merge_pass(A, TmpA, N, length);
			length *= 2;
			merge_pass(TmpA, A, N, length);
			length *= 2;
		}
		free(TmpA);
	}
	else printf("空间不足");
}


/////////////快速排序//////////
/* 快速排序 - 直接调用库函数 */
/*---------------简单整数排序--------------------*/
int compare(const void *a, const void *b)
{ /* 比较两整数。非降序排列 */
	return (*(int*)a - *(int*)b);
}

void QsortWithLibDemo1() {

	/* 调用接口 */
	/*---------------简单整数排序--------------------*/
	int A[] = { 100, 1000, 100, 10, 6, 2, 19, 25, 15, 55,
		35, 5, 110, 120, 119 };
	int N = 15;
	qsort(A, N, sizeof(int), compare);
	PrintArray(A, 15);
}

/*--------------- 一般情况下，对结构体Node中的某键值key排序 ---------------*/

int compare2keys(const void *a, const void *b)
{ /* 比较两种键值：按key1非升序排列；如果key1相等，则按key2非降序排列 */
	int k;
	if (((const struct Node*)a)->key1 < ((const struct Node*)b)->key1)
		k = 1;
	else if (((const struct Node*)a)->key1 >((const struct Node*)b)->key1)
		k = -1;
	else { /* 如果key1相等 */
		if (((const struct Node*)a)->key2 < ((const struct Node*)b)->key2)
			k = -1;
		else
			k = 1;
	}
	return k;
}


void QsortWithLibDemo2() {

	/* 调用接口 */
	/*--------------- 对结构体Node中的键值key1,key2排序 ---------------*/
	int N = MaxN;
	ElementType *A = new int[N];
	ElementType *B = new int[N];
	int dataset = 5; //随机整数
	GenerateArray(A, N, dataset);
	GenerateArray(B, N, dataset);
	Node *nodesA = new Node[N];
	for (int i = 0; i < N; i++) {
		nodesA[i].key1 = A[i];
		nodesA[i].key2 = B[i];
	}
	/* 调用接口 */
	qsort(nodesA, N, sizeof(struct Node), compare2keys);
	PrintNode(nodesA, N);

	delete[]A;
	delete[]B;
	delete []nodesA;
}


/* 快速排序-自实现 */

ElementType Median3(ElementType A[], int Left, int Right)
{
	int Center = (Left + Right) / 2;
	if (A[Left] > A[Center])
		Swap(&A[Left], &A[Center]);
	if (A[Left] > A[Right])
		Swap(&A[Left], &A[Right]);
	if (A[Center] > A[Right])
		Swap(&A[Center], &A[Right]);
	/* 此时A[Left] <= A[Center] <= A[Right] */
	Swap(&A[Center], &A[Right - 1]); /* 将基准Pivot藏到右边*/
									 /* 只需要考虑A[Left+1] … A[Right-2] */
	return  A[Right - 1];  /* 返回基准Pivot */
}

void Qsort(ElementType A[], int Left, int Right)
{ /* 核心递归函数 */
	int Pivot, Cutoff, Low, High;
	Cutoff = CUTOFF;
	if (Cutoff <= Right - Left) { /* 如果序列元素充分多，进入快排 */
		Pivot = Median3(A, Left, Right); /* 选基准 */
		Low = Left; High = Right - 1;

		//while (1) { /*将序列中比基准小的移到基准左边，大的移到右边*/
		//	while (A[++Low] < Pivot);
		//	while (A[--High] > Pivot);
		//	if (Low < High) Swap(&A[Low], &A[High]);
		//	else break;
		//}
		//分割数组，将序列中比基准小的移到基准左边，大的移到右边
		SplitArrayWithPivot(A, Left, Right-1, Pivot);

		Swap(&A[Low], &A[Right - 1]);   /* 将基准换到正确的位置 */
		Qsort(A, Left, Low - 1);    /* 递归解决左边 */
		Qsort(A, Low + 1, Right);   /* 递归解决右边 */
	}
	else InsertionSort(A + Left, Right - Left + 1); /* 元素太少，用简单排序 */
}

void QuickSort(ElementType A[], int N)
{ /* 统一接口 */
	Qsort(A, 0, N - 1);
}

void QuickSortDemo() {
	int N = MaxN;
	ElementType *A = new int[N];
	int dataset = 5; //随机整数
	GenerateArray(A, N, dataset);
	QuickSort(A, N);
	PrintArray(A, N);
}
