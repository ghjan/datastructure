// main.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include <stdio.h> 
#include <stdlib.h>
#include <time.h> 
#include "ch1.h"
using namespace std;

#define MAXK 1e7 /*最大重复次数*/
#define N 10000

/*小于100的随机数函数*/ 
int random_int() 
{ 
	//改变随机数种子 
	srand(time(0));
	int result = rand() % 100;
	int sig = result % 3 >0 ? 1 : -1;
	if (sig < 0)
		result = result/2;
	return result * sig;
}

int main()
{
	//printN1(100000);
	//printN2(100000);
	//polynomial(MAXK);

	int A[N];
	for (int i = 0;i < N;i++) {
		A[i] = rand() % 100;
		A[i] = (A[i] % 3 > 0 ? 1 : -1)*A[i];
	}
	double duration4 = count_tick_2(MaxSubsequenceSum4, A, N);
	printf("duration4 = %10.5e\n", duration4);
	double duration3 = count_tick_2(MaxSubsequenceSum3, A, N);
	printf("duration3 = %10.5e\n", duration3);
	double duration2 = count_tick_2(MaxSubsequenceSum2, A, N);
	printf("duration2 = %10.5e\n", duration2);
	double duration1 = count_tick_2(MaxSubsequenceSum1, A, N);
	printf("duration1 = %10.5e\n", duration1);

	system("pause");
	return 0;
}