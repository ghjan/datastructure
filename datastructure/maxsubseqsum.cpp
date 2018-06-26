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
{ /* ����3�������е����ֵ */
	return A > B ? A > C ? A : C : B > C ? B : C;
}

int DivideAndConquer(int List[], int left, int right)
{ /* ���η���List[left]��List[right]��������к� */
	int MaxLeftSum, MaxRightSum; /* �������������Ľ� */
	int MaxLeftBorderSum, MaxRightBorderSum; /*��ſ�ֽ��ߵĽ��*/

	int LeftBorderSum, RightBorderSum;
	int center, i;

	if (left == right) { /* �ݹ����ֹ����������ֻ��1������ */
		if (List[left] > 0)  return List[left];
		else return 0;
	}

	/* ������"��"�Ĺ��� */
	center = (left + right) / 2; /* �ҵ��зֵ� */
								 /* �ݹ�����������е����� */
	MaxLeftSum = DivideAndConquer(List, left, center);
	MaxRightSum = DivideAndConquer(List, center + 1, right);

	/* �������ֽ��ߵ�������к� */
	MaxLeftBorderSum = 0; LeftBorderSum = 0;
	for (i = center; i >= left; i--) { /* ����������ɨ�� */
		LeftBorderSum += List[i];
		if (LeftBorderSum > MaxLeftBorderSum)
			MaxLeftBorderSum = LeftBorderSum;
	} /* ���ɨ����� */

	MaxRightBorderSum = 0; RightBorderSum = 0;
	for (i = center + 1; i <= right; i++) { /* ����������ɨ�� */
		RightBorderSum += List[i];
		if (RightBorderSum > MaxRightBorderSum)
			MaxRightBorderSum = RightBorderSum;
	} /* �ұ�ɨ����� */

	  /* ���淵��"��"�Ľ�� */
	return Max3(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);
}

//�㷨3���ֶ���֮
int MaxSubsequenceSum3(int A[], int NN)
{ /* ������ǰ2���㷨��ͬ�ĺ����ӿ� */
	return DivideAndConquer(A, 0, NN - 1);
}

//�㷨4�����ߴ���

int MaxSubsequenceSum4(int A[], int NN)
{
	int ThisSum, MaxSum;
	int i;
	ThisSum = MaxSum = 0;
	for (i = 0; i < NN; i++) {
		ThisSum += A[i];//�����ۼ�
		if (ThisSum>MaxSum)
			MaxSum = ThisSum; // ���ָ��������µ�ǰ���
		else if (ThisSum < 0)  // �����ǰ���к�Ϊ����
			ThisSum = 0; // �򲻿���ʹ���沿�ֺ���������֮
	}
	return MaxSum;

}
