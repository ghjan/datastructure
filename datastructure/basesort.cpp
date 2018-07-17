#include "basesort.h"

//交换两个元素
void Swap(ElementType A[], int i, int j)
{
	ElementType tmp = A[i];
	A[i] = A[j];
	A[j] = tmp;

}

//冒泡排序 最小的泡泡放到上面 好处：非常简单 性能不好，是 O(N*N)
//如果待排元素在链表里面，冒泡排序比较适合这种数据结构
void Bubble_Sort(ElementType A[], int N)
{
	for (int P = N - 1; P >= 0; P--) { //最多N趟
		int flag = 0;  //0表示没有执行交换
		for (int i = 0; i < P; i++) { /* 一趟冒泡 确保最大的沉到最下面 */
			if (A[i] > A[i + 1]) { //相邻泡泡比较大小，小泡泡向上冒
				Swap(A, i, i + 1);
				flag = 1; /* 标识发生了交换*/
			}
		}
		if (flag == 0) break; /* 全程无交换*/
	}
}

//插入排序 一手纸牌 
void InsertionSort(ElementType A[], int N)
{ /* 插入排序 */
	int P, i;
	ElementType Tmp;

	for (P = 1; P < N; P++) {
		Tmp = A[P]; /* 取出未排序序列中的第一个元素 摸下一张牌*/
		for (i = P; i > 0 && A[i - 1] > Tmp; i--)
			A[i] = A[i - 1]; /*依次与已排序序列中元素比较并右移  移出空位*/
		A[i] = Tmp; /* 放进合适的位置  新牌落位*/
	}
}