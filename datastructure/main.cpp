// main.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h> 

#include <time.h> 
//#include "ch1.h"
//#include "ch2.h"
//#include "stack_static.h"
//#include "stack_dynamic.h"
//#include "SequenceStack1.0.h"
#include "DynamicStack1.0.h"  
using namespace std;

#define MAXK 1e7 /*最大重复次数*/

int main()
{
	//printN1(100000);
	//printN2(100000);sss
	//polynomial(MAXK);

	//demo_polynomial();
	//demo_list_1();
	//demo_list_1_2();
	//demo_list_2();
	//demo_stack_static();
	//demo_stack_dynamic();
	//demo_stack_array();
	demo_stack_chain();
	return 0;
}
