// main.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include "ch1.h"
using namespace std;
#define MAXK 1e7 /*最大重复次数*/

int main()
{
	//printN1(100000);
	//printN2(100000);
	polynomial(MAXK);
	return 0;
}