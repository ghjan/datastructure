#include "stdafx.h"
#include<iostream>  
#include "sort.h"
using namespace std;

void quickSort(int s[], int l, int r)
{
	if (l < r)
	{
		int i = l, j = r, x = s[l];
		while (i < j)
		{
			while (i < j && s[j] >= x) // 从右向左找第一个小于x的数  
				j--;
			if (i < j)
				s[i++] = s[j];
			while (i < j && s[i] < x) // 从左向右找第一个大于等于x的数  
				i++;
			if (i < j)
				s[j--] = s[i];
		}
		s[i] = x;
		quickSort(s, l, i - 1); // 递归调用  
		quickSort(s, i + 1, r);
	}
}

void sort_ordered(int* a, int length, int* b)
{
	int i, j, t1, t;
	for (j = 0; j < length; j++)
		for (i = 0; i < length - 1 - j; i++)
			if (a[i] < a[i + 1])
			{
				t = a[i];
				a[i] = a[i + 1];
				a[i + 1] = t;


				t1 = b[i];
				b[i] = b[i + 1];
				b[i + 1] = t1;
			}
}

void print_array(int a[], int length)
{
	for (int i = 0; i < length; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int * clone_ordered(int *a, int length, int* order)
{
	int *result = new int[length];
	for (int i = 0; i < length; i++)
	{
		result[i] = a[order[i]];
	}
	return result;

}

int sort_demo()
{
	int array[] = { 34,65,12,43,67,5,78,10,3,70 }, k;
	int len = sizeof(array) / sizeof(int);
	cout << "The orginal array are:" << endl;
	for (k = 0; k < len; k++)
		cout << array[k] << ",";
	cout << endl;
	quickSort(array, 0, len - 1);
	cout << "The sorted array are:" << endl;
	for (k = 0; k < len; k++)
		cout << array[k] << ",";
	cout << endl;
	return 0;
}


int sort_ordered_demo()
{
	int a[] = { 6,5,13,8,24,2,1 };
	int b[7] = { 0,1,2,3,4,5,6 };//用来保存原数组对应的下标以及排序后的下标
	printf("排序前的数组为：\n");
	print_array(a, 7);
	sort_ordered(a, 7, b);
	printf("排序后的数组为：\n");
	print_array(a, 7);

	printf("排序后的数组对应的下标：\n");
	print_array(b, 7);

	int exp1[7] = { 2, 5, 4, 7, 6 , 0, 8 };
	int *exp1_o = clone_ordered(exp1, 7, b);
	printf("另外一个数组，和上面下标同样调整以后的结果是：\n");
	print_array(exp1_o, 7);
	return 0;

}