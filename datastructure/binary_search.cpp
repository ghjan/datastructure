#include "stdafx.h"
#include <stdio.h> 
#include <stdbool.h>  
#include <stdlib.h>  
#include "binary_search.h" 

//二分查找算法
int binary_search(int aim, int data[], int size) {
	int det = -1;
	int left = 0;//定义left整数变量  
	int right = size - 1;//定义right  
	while (left <= right) {//在while循环中直到有一个条件结束搜索   
		int mid = (left + right) / 2;
		if (data[mid]<aim) {
			left = mid + 1;
		}
		else if (data[mid]>aim) {
			right = mid - 1;
		}
		else {
			det = mid;
			break;//一定要break跳出循环   
		}
	}
	return det;
}
int BinarySearch_demo() {
	int data[] = { 5,7,9,11,13,17,24,47,68,72,89,90,112 };
	printf("%d\n", binary_search(14, data, 13));//希望输出14所对应的索引号   
	printf("%d\n", binary_search(13, data, 13));//希望输出13所对应的索引号   
	return 0;

}