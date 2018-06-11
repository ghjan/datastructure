#include "stdafx.h"
#include <stdio.h> 
#include <stdbool.h>  
#include <stdlib.h>  
#include "binary_search.h" 

//���ֲ����㷨
int BinarySearch(StaticTable *Tbl, ElementType K)
{
	int left, right, mid, NoFound = -1;
	left = 1;				/*��ʼ����߽�*/
	right = Tbl->Length;	/*��ʼ���ұ߽�*/
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (K < Tbl->Element[mid])	right = mid - 1;
		else if(K > Tbl->Element[mid])left = mid + 1;
		else return mid;
	}
	return NoFound;

}