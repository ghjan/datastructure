#include "stdafx.h"
#include <stdio.h> 
#include <stdbool.h>  
#include <stdlib.h>  
#include "binary_search.h" 

//���ֲ����㷨
int binary_search(int aim, int data[], int size) {
	int det = -1;
	int left = 0;//����left��������  
	int right = size - 1;//����right  
	while (left <= right) {//��whileѭ����ֱ����һ��������������   
		int mid = (left + right) / 2;
		if (data[mid]<aim) {
			left = mid + 1;
		}
		else if (data[mid]>aim) {
			right = mid - 1;
		}
		else {
			det = mid;
			break;//һ��Ҫbreak����ѭ��   
		}
	}
	return det;
}
int BinarySearch_demo() {
	int data[] = { 5,7,9,11,13,17,24,47,68,72,89,90,112 };
	printf("%d\n", binary_search(14, data, 13));//ϣ�����14����Ӧ��������   
	printf("%d\n", binary_search(13, data, 13));//ϣ�����13����Ӧ��������   
	return 0;

}