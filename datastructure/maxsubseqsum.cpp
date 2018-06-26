#include "stdafx.h"
#include <math.h>
#include "ch1.h"
using namespace std;

int MaxSubsequenceSum1(int A[], int NN)
{
	int ThisSum, MaxSum = 0;
	int i, j, k;
	for (i = 0;i < NN;i++) {
		for (j = i;j < NN;j++) {
			ThisSum = 0;
			for (k = i;k <= j;k++)
				ThisSum += A[k];
				if(ThisSum > MaxSum)
					MaxSum = ThisSum;
		}
	}
	return MaxSum;
}

int MaxSubsequenceSum2(int A[], int NN)
{
	int ThisSum, MaxSum = 0;
	int i, j, k;
	for (i = 0;i < NN;i++) {
		ThisSum = 0;
		for (j = i;j < NN;j++) {
			ThisSum += A[j];
			if (ThisSum > MaxSum)
				MaxSum = ThisSum;
		}
	}
	return MaxSum;
}


int Max3(int A, int B, int C)
{ /* 返回3个整数中的最大值 */
	return A > B ? A > C ? A : C : B > C ? B : C;
}

int DivideAndConquer(int List[], int left, int right)
{ /* 分治法求List[left]到List[right]的最大子列和 */
	int MaxLeftSum, MaxRightSum; /* 存放左右子问题的解 */
	int MaxLeftBorderSum, MaxRightBorderSum; /*存放跨分界线的结果*/

	int LeftBorderSum, RightBorderSum;
	int center, i;

	if (left == right) { /* 递归的终止条件，子列只有1个数字 */
		if (List[left] > 0)  return List[left];
		else return 0;
	}

	/* 下面是"分"的过程 */
	center = (left + right) / 2; /* 找到中分点 */
								 /* 递归求得两边子列的最大和 */
	MaxLeftSum = DivideAndConquer(List, left, center);
	MaxRightSum = DivideAndConquer(List, center + 1, right);

	/* 下面求跨分界线的最大子列和 */
	MaxLeftBorderSum = 0; LeftBorderSum = 0;
	for (i = center; i >= left; i--) { /* 从中线向左扫描 */
		LeftBorderSum += List[i];
		if (LeftBorderSum > MaxLeftBorderSum)
			MaxLeftBorderSum = LeftBorderSum;
	} /* 左边扫描结束 */

	MaxRightBorderSum = 0; RightBorderSum = 0;
	for (i = center + 1; i <= right; i++) { /* 从中线向右扫描 */
		RightBorderSum += List[i];
		if (RightBorderSum > MaxRightBorderSum)
			MaxRightBorderSum = RightBorderSum;
	} /* 右边扫描结束 */

	  /* 下面返回"治"的结果 */
	return Max3(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);
}

//算法3：分而治之
int MaxSubsequenceSum3(int A[], int NN)
{ /* 保持与前2种算法相同的函数接口 */
	return DivideAndConquer(A, 0, NN - 1);
}

//算法4：在线处理

int MaxSubsequenceSum4(int A[], int NN)
{
	int ThisSum, MaxSum;
	int i;
	ThisSum = MaxSum = 0;
	for (i = 0; i < NN; i++) {
		ThisSum += A[i];//向右累加
		if (ThisSum>MaxSum)
			MaxSum = ThisSum; // 发现更大和则更新当前结果
		else if (ThisSum < 0)  // 如果当前子列和为负数
			ThisSum = 0; // 则不可能使后面部分和增大，抛弃之
	}
	return MaxSum;

}
