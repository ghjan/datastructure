#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "time.h"
#include "array.h"
#include "basesort.h"

void Copy(ElementType source[], ElementType target[], int N)
{
	for (int i = 0; i < N; i++) {
		target[i] = source[i];
	}
}

void Reverse(ElementType BaseA[], int N) {
	for (int i = 0; i < N && i < N - i; i++) {
		Swap(&BaseA[i], &BaseA[N - i]);
	}
}

void GenerateArray(ElementType BaseA[], int N, int dataset)
{
	srand(time(NULL));//设置随机数种子。
	for (int i = 0; i < N; i++) {
		BaseA[i] = rand();
		switch (dataset) {
		case 5: //随机整数
		case 6: //顺序整数
		case 7: //逆序整数
		case 8: //基本有序的整数
			BaseA[i] = (BaseA[i] % 2 > 0 ? 1 : -1)*BaseA[i];
			break;
		case 9: //随机正整数，每个数字不超过1000
			BaseA[i] = BaseA[i] % 1000;
			break;
		}
	}
	switch (dataset) {
	case 6: //顺序整数
		MergeSort2(BaseA, N); //使用归并排序
		break;
	case 7: //逆序整数
		MergeSort2(BaseA, N); //使用归并排序
		Reverse(BaseA, N);    //倒序
		break;
	case 8: //基本有序的整数
		MergeSort2(BaseA, N); //使用归并排序
		srand(time(NULL));//设置随机数种子
		int count1 = sqrt(N) / 3;
		for (int i = 0; i < count1; i++) {
			int index = rand();
			int index2 = rand();
			Swap(&BaseA[index], &BaseA[index2]);
		}
		break;
	}
}